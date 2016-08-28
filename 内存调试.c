1、 解压 memwatch.-2.7.1.tar.gz，在解开的目录下添加代码 memtest.c


#include <stdlib.h>
#include <stdio.h>
#include "memwatch.h"
int main(int argc,char **argv)
{
char *ptr1;
char *ptr2;
ptr1 = malloc(512);
ptr2 = malloc(512);
ptr1[512]= 'A';
ptr2 = ptr1;
free(ptr2);
free(ptr1);
return 0;
}
2、 修改 Makefile
Makefile 文件为：
memtest:
$(CC) -DMEMWATCH -DMW_STDIO memtest.cmemwatch.c


3、运行 make 并在主机上执行 a.out，执行后会生成一个记录文件 memwatch.log，内容如下：
============= MEMWATCH 2.71 Copyright (C) 1992-1999 Johan Lindh =========
Started at Thu Jan 1 00:08:33 1970
Modes: __STDC__ 32-bit mwDWORD==(unsigned long)
mwROUNDALLOC==4 sizeof(mwData)==32 mwDataSize==32
overflow: <3> memtest.c(12), 512 bytes alloc'd at <1> memtest.c(8)
double-free: <4> memtest.c(13), 0x1a1b4 was freed from memtest.c(12)
Stopped at Thu Jan 1 00:08:33 1970
unfreed: <2> test.c(9), 512 bytes at 0x1a3e4 {FE FE FE FE FE FE FE FE FE FE FE FE FE
FE FE FE ................}
Memory usage statistics (global):
N)umber of allocations made: 2
L)argest memory usage : 1024
T)otal of all alloc() calls: 1024
U)nfreed bytes totals : 512
//overflow: <3> memtest.c(12)缓冲区溢出，当程序执行到第 12 行 free(ptr2)才检测到的；
512 bytes alloc'd at <1>memtest.c(8)
//表示出错缓冲区的大小为 512 字节，是在 memtest.c 的第 8 行分配的。很容易发现代码的
ptr1[512]='A'出现错误。
double-free: <4> memtest.c(13), 0x1a7f4 was freed from memtest.c(12)
//double-free: <4> memtest.c(13)是一个双重释放的错误，表示程序执行到 13 行的时候才检测到。
0x1a7f4 was freed from memtest.c(12)
//表示首地址为 0x1a7f4 的内存在 12 行已经被释放。
Stopped at Wed Dec 31 19:00:38 1969
unfreed: <2> test.c(9), 512 bytes at 0x1a3e4 {FE FE FE FE FE FE FE FE
//表示一块内存没有释放，表示这块内存是在 memtest.c 的第 9 行分配，大小为 512 字节，首地址
为 0x1a3e4。
Memory usage statistics (global):
N)umber of allocations made: 2
L)argest memory usage : 1024
//程序结束时能够是使用的最大动态内存
T)otal of all alloc() calls: 1024 //总共分配的动态内存
U)nfreed bytes totals : 512
//表示未释放的内存