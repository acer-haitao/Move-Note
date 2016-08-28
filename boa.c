一、交叉编译环境 arm-linux-gcc-3.4.1的建立
1.下载arm-linux-gcc-3.4.1.tar.bz2
URL: ftp://ftp.handhelds.org/projects/toolchain/arm-linux-gcc-3.4.1.tar.bz2
ftp://ftp.handhelds.org/projects/toolchain/arm-linux-gcc-3.4.1.tar.bz2
2.复制，解压
＃ cd /
＃ tar -xvjf  /tmp/arm-linux-gcc-3.4.1.tar.bz2
3.导出/usr/local/arm/3.4.1/bin 到环境变量
在/etc/profile 最后添加  PATH=$PATH:/usr/local/arm/3.4.1 /bin
二、下载源码：http://www.boa.org/
[root@localhost ~]# cd /usr/src
[root@localhost src]# tar zxvf boa-0.94.13.tar.tar
[root@localhost src]# cd boa-0.94.13/src
[root@localhost src]# ./configure
在./configure过程中如果出现错误，请转换到root目录下重新编译。本来是root的也要转换下！我在此卡了三、四天，后来无意中过了。

三、编译前修改的文件：
1.  修改Makefile文件，找到CC=gcc和CPP=gcc -E，分别将其改为交叉编译器安装的路径:
CC=/usr/local/arm/3.4.1/bin/arm-linux-gcc
CPP=/usr/local/arm/3.4.1/bin/arm-linux-gcc –E
保存退出。

2. 修改编译方式:
 LDFLAGS = -g –static
注: 使用静态编译可以让目标文件自动的包含所需要的
库文件，而动态编译需要手工拷贝库文件。
3.修改/src/defines.h文件：

#define SERVER_ROOT "/etc/boa"

4 修改boa-0.94/src/ util.c文件
修改char *get_commonlog_time(void)函数。
time_offset = 0;

5. 修改src/config.c：加Current_uid=1（可以不用修改，反正我没改，编译也成功了）

6. 修改compat.h： 把第120 行的
#define
TIMEZONE_OFFSET(foo)foo##->tm_gmtoff
修改为:
#define
TIMEZONE_OFFSET(foo)foo->tm_gmtoff
7.修改/src/boa.c,注释掉下面两行：
 /* if (setuid(0) != -1) {
            DIE("icky Linux kernel bug!");
        } */

/*if (passwdbuf == NULL) {
            DIE("getpwuid");
        }*/

8 gethostbyname:: Resource temporarily unavailable 
这个问题我也遇到过，我只是把src文件夹下的config.c里的if(!server_name){..........}（大概在266行到286行之间）注释掉，就能运行在板子上运行boa，到现在为止没有遇到过是么问题。但不知道以后会不会有问题。
解决：config.c
 /*if (!server_name) {
        struct hostent *he;
        char temp_name[100];

        if (gethostname(temp_name, 100) == -1) {
            perror("gethostname:");
            exit(1);
        }

        he = gethostbyname(temp_name);
        if (he == NULL) {
            perror("gethostbyname:");
            exit(1);
        }

        server_name = strdup(he->h_name);
        if (server_name == NULL) {
            perror("strdup:");
            exit(1);
        }
    }*/

9. /src/log.c中的修改：注释掉：
/*     if (dup2(error_log, STDERR_FILENO) == -1) {
            DIE("unable to dup2 the error log");
        } */
                                                           
10. 在boa.conf中的修改：
  （1） ServerName的设置
    修改#ServerName www.your.org.here
    为 ServerName www.your.org.here
     注意：该项默认为未打开，执行Boa会异常退出，提示“gethostbyname::No such file  or directory”,所以必须打开。其它默认设置即可。   
    注意:以下是为改为下面这样的：
  （2）User与Group的修改：
    User 0
    Group 0
 （3）ErrorLog /var/log/boa/error_log
    AccessLog /var/log/boa/access_log
 （4）DocumentRoot /var/www
 （5）DirectoryIndex index.html
 （6）KeepAliveMax 1000
    KeepAliveTimeout 10
 （7）MimeTypes /etc/mime.types
 （8）ScriptAlias /cgi-bin/ /var/www/cgi-bin/

四、运行make进行编译，得到可执行的程序boa
     [root@localhost boa-0.94.13]# cd /arms3c2410/boa/boa-0.94.13/src
     [root@localhost src]# make clean
     rm -f y.tab.o lex.yy.o alias.o boa.o buffer.o cgi.o cgi_header.o config.o escape.o         get.o hash.o ip.o log.o mmap_cache.o pipe.o queue.o read.o request.o response.o select.o signals.o util.o sublog.o timestamp.o  boa core lex.yy.c y.tab.c y.tab.h *~ boa_indexer index_dir.o   
     [root@localhost src]# make 

    去掉调试信息: #/usr/local/arm/2.95.3/bin/arm-linux-strip boa（有的文章说可以使boa 的大小简化到60k左右，但是我只能从600多简化到500多，不知道什么原因？有知道的可以告诉我下。）

五、配置文件的修改：
    1. 我用的是NFS共享文件方式，在将PC机新建一个目录：/nfs,在redhat启动nfs服          务将/nfs和/home设置为与目标板可以共享的目录。
NFS服务器的安装：
 检查linux系统中是否安装了nfs-utils和portmap两个软件包
 （RHEL4系统默认已经安装了这两个软件包）
命令#rpm –q nfs-utils portmap
查看NFS服务器是否启动：
  命令#service nfs starus
#service portmap status
如果服务器没有启动，则开启服务（默认服务下nfs没有完全开启）
  命令#service nfs start
#service portmap start
指定NFS服务器的配置文件：
 NFS服务器的配置文件保存“/etc/”目录中，文件名称是“exports”，该文件用于被NFS服务器提供的目录共享
  命令#vi /etc/exports
  配置“exports”文件格式如下
/home    *(sync，rw）
/nfs    *(sync，rw）
  home nfs：共享目录名
*：表示所有主机
重新输出共享目录：
  Exportfs管理工具可以对“exports”文件进行管理
  命令#exportfs –rv 可以让新设置的“exports”文件内容生效
2. 在/nfs下新建log和www目录：
   [root@localhost ~] # mkdir /nfs/log
   [root@localhost ~] # mkdir /nfs/www
   [root@localhost ~] # mkdir /nfs/log/boa
   [root@localhost ~] # mkdir /nfs/www/cgi-bin
 将静态网页存入根文件系统的/var/www目录下（/usr/share/doc/HTML目录下的img目录和index.html文件拷到/nsf/www下）
   [root@localhost ~] # chmod 777 /nfs/log/*
   [root@localhost ~] # chmod 777 /nfs/www/*
3. 在/home下新建目录boa
[root@localhost ~] # mkdir /home/boa
 将编译得出的可执行文件/boa-0.94.13/src中的boa文件， /boa-0.94.13/src中的defines.h文件，/boa-0.94.13中的boa.conf还有mime.types文件拷到/home/boa下
[root@localhost ~] # chmod 777 /home/*

4. 将/nfs和/home/boa分别mount到目标板上的/var和/etc/boa上:
  [root@(none) /]# ifconfig eth0 192.192.192.190 （开发板的IP）
[root@(none) /]# mkdir /etc/boa
[root@(none) /]#chmod 777 /etc/boa
[root@(none) /]#  mount -o nolock -t nfs 192.192.192.11:/home/boa  /etc/boa        （PC机的IP）
[root@(none) var]# mount -o nolock -t nfs 192.192.192.11:/nfs  /var 
六、运行            
在开发板上，将/home/boa里的mime.types文件cp到/etc
cd /etc/boa  ./boa
错误，boa没有运行。
 
错误提示：boa.c:194 - unable to bind: Address already in use
解决方法：ps一下，看那个进程占用了port ,直接kill就可以了。
 
./boa
[01/Feb/1904:09:11:20 +0000] boa: server version Boa/0.94.13 
[01/Feb/1904:09:11:20 +0000] boa:server built Oct 24 2009 at 10:34:09
[01/Feb/1904:09:11:20 +0000] boa:strating server pid=73,port 80
成功了。现在可以在你的PC机互联网中输入地址，我的是http://192.192.192.190
开发板出现[01/Feb/1904:09:12:03 +0000] request from 192.192.192.11 "GET lindexy
PC机互联网上出现了redhat欢迎界面。终于成功了。搞了几天了！郁闷，问题一堆，又不是很懂！继续努力！
 
常见错误：
 1>. 错误1: gethostbyname:: No such file or directory
     解决办法: 修改boa.conf   去掉 ServerName www.your.org.here 前的注释符号(#)
 2>. 错误1: util.c:100:1: error: pasting "t" and "->" does not give a valid preprocessing token make: *** [util.o]
     解决办法: 修改 src/compat.h
　　 找到
　　 #define TIMEZONE_OFFSET(foo) foo## ->tm_gmtoff
　　 修改成
　　 #define TIMEZONE_OFFSET(foo) foo->tm_gmtoff
 3>. 错误2: boa.c:211 - getpwuid: No such file or directory
     解决办法: 修改src/boa.c
　　 注释掉下面这段程序:
 　　if (passwdbuf == NULL) {
　　 DIE(”getpwuid”);
　　 }
　　 if (initgroups(passwdbuf->pw_name, passwdbuf->pw_gid) == -1) {
 　　DIE(”initgroups”);
 　　}
　　即修改为:
　　#if 0
 　　if (passwdbuf == NULL) {
　 　DIE(”getpwuid”);
　　 }
　　 if (initgroups(passwdbuf->pw_name, passwdbuf->pw_gid) == -1) {
　　 DIE(”initgroups”);
　　 }
　　#endif
 4>. 错误3: boa.c:228 - icky Linux kernel bug!: No such file or directory
    解决办法: 修改src/boa.c
　　注释掉下面语句:
　　if (setuid(0) != -1) {
　　DIE(”icky Linux kernel bug!”);
　　}
　　即修改为:
　　#if 0
　　 if (setuid(0) != -1) {
 　　DIE(”icky Linux kernel bug!”);
 　　}
　　#endif
 5>. 错误4: log.c:73 unable to dup2 the error log:bad file descriptor
    解决方法:
    方法1> 确定日志目录对与所有用户都具有可读/写的权限
    方法2> 修改src/log.c (建议采用方法1)
　　注释掉
　　if (dup2(error_log, STDERR_FILENO) == -1) {
　　DIE("unable to dup2 the error log");
　　}
　　即修改为:
　　#if 0
     if (dup2(error_log, STDERR_FILENO) == -1) {
　　 DIE("unable to dup2 the error log");
　　 }
    #endif
 
 
本次移植的主要参考资料来源：http://blog.163.com/mazidao2000/blog/static/10200537720095641427620/
http://www.52rd.com/Blog/Detail_RD.Blog_farsight2009_20437.html
在此衷心的感谢文章作者！！