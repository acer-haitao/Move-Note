1�� ��ѹ memwatch.-2.7.1.tar.gz���ڽ⿪��Ŀ¼����Ӵ��� memtest.c


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
2�� �޸� Makefile
Makefile �ļ�Ϊ��
memtest:
$(CC) -DMEMWATCH -DMW_STDIO memtest.cmemwatch.c


3������ make ����������ִ�� a.out��ִ�к������һ����¼�ļ� memwatch.log���������£�
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
//overflow: <3> memtest.c(12)�����������������ִ�е��� 12 �� free(ptr2)�ż�⵽�ģ�
512 bytes alloc'd at <1>memtest.c(8)
//��ʾ���������Ĵ�СΪ 512 �ֽڣ����� memtest.c �ĵ� 8 �з���ġ������׷��ִ����
ptr1[512]='A'���ִ���
double-free: <4> memtest.c(13), 0x1a7f4 was freed from memtest.c(12)
//double-free: <4> memtest.c(13)��һ��˫���ͷŵĴ��󣬱�ʾ����ִ�е� 13 �е�ʱ��ż�⵽��
0x1a7f4 was freed from memtest.c(12)
//��ʾ�׵�ַΪ 0x1a7f4 ���ڴ��� 12 ���Ѿ����ͷš�
Stopped at Wed Dec 31 19:00:38 1969
unfreed: <2> test.c(9), 512 bytes at 0x1a3e4 {FE FE FE FE FE FE FE FE
//��ʾһ���ڴ�û���ͷţ���ʾ����ڴ����� memtest.c �ĵ� 9 �з��䣬��СΪ 512 �ֽڣ��׵�ַ
Ϊ 0x1a3e4��
Memory usage statistics (global):
N)umber of allocations made: 2
L)argest memory usage : 1024
//�������ʱ�ܹ���ʹ�õ����̬�ڴ�
T)otal of all alloc() calls: 1024 //�ܹ�����Ķ�̬�ڴ�
U)nfreed bytes totals : 512
//��ʾδ�ͷŵ��ڴ�