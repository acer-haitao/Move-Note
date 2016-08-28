1、 源码下载
我们选择的版本是 busybox-1.22.1.tar.bz2 下载路径为：
http://busybox.net/downloads/
2、 解压源码
$ tar xvf busybox-1.22.1.tar.bz2
3、 进入源码目录
$ cd busybox-1.22.1
4、 配置源码
$ make menuconfig
Busybox Settings --->
Build Options --->
[*] Build BusyBox as a static binary (no shared libs)
[ ] Force NOMMU build
[ ] Build with Large File Support (for accessing files > 2 GB)
(arm-none-linux-gnueabi-) Cross Compiler prefix
()Additional CFLAGS
5、 编译
$ make
6、 安装
busybox 默认安装路径为源码目录下的_install
$ make install
7、 进入安装目录下
$ cd _install
$ ls
bin linuxrc sbin usr
8、 创建其他需要的目录
$ mkdir dev etc mnt proc var tmp sys root
9、 添加库
? 将工具链中的库拷贝到_install 目录下
$cp /home/linux/toolchain/gcc-4.6.4/arm-arm1176jzfssf-linux-gnueabi/lib/ . -a
? 删除静态库和共享库文件中的符号表
$ sudo rm lib/*.a
$ arm-none-linux-gnueabi-strip lib/*
? 删除不需要的库，确保所有库大小不超过 8M
$ du -mh lib/
10、添加系统启动文件
在 etc 下添加文件 inittab，文件内容如下：
#this is run first except when booting in single-user mode.
::sysinit:/etc/init.d/rcS
# /bin/sh invocations on selected ttys
# start an "askfirst" shell on the console (whatever that may be)
::askfirst:-/bin/sh
# stuff to do when restarting the init process
::restart:/sbin/init 
# stuff to do before rebooting
::ctrlaltdel:/sbin/reboot
在 etc 下添加文件 fstab，文件内容如下：
#device mount-point type options dump fsck order
proc /proc proc defaults 0 0
tmpfs /tmp tmpfs defaults 0 0
sysfs /sys sysfs defaults 0 0
tmpfs /dev tmpfs defaults 0 0
这里我们挂载的文件系统有三个 proc、sysfs 和 tmpfs。在内核中 proc 和 sysfs 默认都支持，而
tmpfs 是没有支持的，我们需要添加 tmpfs 的支持
11 修改内核配置：
$ make menuconfig
File systems --->
Pseudo filesystems --->
[*] Virtual memory file system support (former shm fs)
[*] Tmpfs POSIX Access Control Lists
重新编译内核
在 etc 下创建 init.d 目录，并在 init.d 下创建 rcS 文件，rcS 文件内容为：
#!/bin/sh
# This is the first script called by init process
/bin/mount -a
echo /sbin/mdev > /proc/sys/kernel/hotplug
/sbin/mdev -s
为 rcS 添加可执行权限：
$ chmod +x init.d/rcS
在 etc 下添加 profile 文件，文件内容为：
#!/bin/sh
export HOSTNAME=farsight
export USER=root
export HOME=root
export PS1="[$USER@$HOSTNAME \W]\# "
PATH=/bin:/sbin:/usr/bin:/usr/sbin
LD_LIBRARY_PATH=/lib:/usr/lib:$LD_LIBRARY_PATH
export PATH LD_LIBRARY_PATH
重要：新制作的文件系统尺寸若超出 8M ，删除不需要的库文件

二、NFS  测试
1、删除原先的/source/rootfs
$ sudo rm -rf /source/rootfs
2、将我们新建的根文件系统拷贝到/source/rootfs 目录下
$sudo mkdir /source/rootfs
$ sudo cp _install/* /source/rootfs –a
3、设置 uboot 环境变量
#setenv serverip 192.168.9.120
#setenv ipaddr 192.168.9.233
#setenv bootcmd tftp 41000000 uImage\;tftp 42000000 exynos4412-fs4412.dtb\;bootm 41000000
– 42000000
#setenv bootargs root=/dev/nfs nfsroot=192.168.9.120:/source/rootfs rw
console=ttySAC2,115200 init=/linuxrc ip=192.168.9.233
# saveenv
重新启动开发板，查看是否能够正常挂载，功能是否正常


三、制作 ramdisk  文件系统
通过 NFS 测试以后，就可以制作 ramdisk 文件系统了，具体如下：
1、制作一个大小为 8M 的镜像文件
$ cd ~
$ dd if=/dev/zero of=ramdisk bs=1k count=8192 （ramdisk 为 8M）
2、格式化这个镜像文件为 ext2
$ mkfs.ext2 -F ramdisk
3、在 mount 下面创建 initrd 目录作为挂载点
$ sudo mkdir /mnt/initrd
4、将这个磁盘镜像文件挂载到/mnt/initrd 下
注意这里的 ramdisk 不能存放在 rootfs 目录中
$ sudo mount -t ext2 ramdisk /mnt/initrd
5、将我们的文件系统复制到 ramdisk 中
将测试好的文件系统里的内容全部拷贝到 /mnt/initrd 目录下面
$ sudo cp/source/rootfs/* /mnt/initrd –a

6、卸载 initrd
$ sudo umount /mnt/initrd

7、压缩 ramdisk 为 ramdisk.gz 并拷贝到/tftpboot 下
$ gzip --best -c ramdisk>ramdisk.gz
8、格式化为 uboot 识别的格式
$ mkimage -n "ramdisk" -A arm -O linux -T ramdisk -C gzip -d ramdisk.gz ramdisk.img
$ cp ramdisk.img /tftpboot
9、配置内核支持 RAMDISK
制作完 ramdisk.img 后，需要配置内核支持 RAMDISK 作为启动文件系统
make menuconfig
File systems --->
<*> Second extended fs support
Device Drivers
SCSI device support --->
<*> SCSI disk support
Block devices --->
<*>RAM block device support
(16)Default number of RAM disks
(8192) Default RAM disk size (kbytes) (修改为 8M)
General setup --->
[*] Initial RAM filesystem and RAM disk (initramfs/initrd) support
重新编译内核，复制到/tftpboot

10、在 U-BOOT 命令行重新设置启动参数：
#setenv bootcmd tftp 41000000 uImage\;tftp 42000000 exynos4412-fs4412.dtb\;tftp 43000000
ramdisk.img\;bootm 41000000 43000000 42000000
# saveenv
重新启动开发板查看能否正常启动

四、ext4  文件系统制作
1、格式化工具制作
拷贝 e2fsprogs-1.42.5.tar.xz 到 Linux 下
解压
$ tar xvfe2fsprogs-1.42.5.tar.xz
进入工程
$ cde2fsprogs-1.42.5
创建脚本 build.sh 并添加如下内容：
$ vim build.sh
#!/bin/sh
CC=arm-none-linux-gnueabi-gcc
./configure --enable-elf-shlibs --host=arm-none-linux-gnueabi \
--prefix=/home/linux/tools
make
make install
执行脚本
./build.sh
在编译到最后可能会有个错误如下：
make[1]: [libext2fs.dvi] Error 1 (ignored)
这个不要紧其实我们需要的文件都编译好了
拷贝可执行文件和库到文件系统中
$ cp /home/linux/tools/sbin/mkfs.ext3 /source/rootfs/sbin
$ cp/home/linux/tools/lib/* /source/rootfs/lib
2、修改 u-boot 启动参数
先将开发板的启动方式设置成为 网络启动方式。
即 setenv boocmd
setenv bootargs
setenv bootargs root=/dev/nfs rwnfsroot=192.168.9.120:/source/rootfs init=/linuxrc
console=ttySAC2,115200 ip=192.168.9.233
注意：192.168.9.120 对应 Ubuntu 的 ip
192.168.9.233 对应板子的 ip
这两个 ip 应该根据自己的实际情况适当修改
3、分区
启动开发板在倒计时期间按任意键结束启动，执行如下命令
# fdisk -c 0
4、格式化
重新启动开发板进入系统后执行
# mkfs.ext3 -F /dev/mmcblk0p2
5、修改我们/source/rootfs/etc/fstab
在最后添加如下内容
/dev/mmcblk0p2 /mnt ext3 defaults 0 0
重新启动系统系统在启动最后会挂载 mmcblk0p2 作为用户文件系统