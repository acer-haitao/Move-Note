1�� Դ������
����ѡ��İ汾�� busybox-1.22.1.tar.bz2 ����·��Ϊ��
http://busybox.net/downloads/
2�� ��ѹԴ��
$ tar xvf busybox-1.22.1.tar.bz2
3�� ����Դ��Ŀ¼
$ cd busybox-1.22.1
4�� ����Դ��
$ make menuconfig
Busybox Settings --->
Build Options --->
[*] Build BusyBox as a static binary (no shared libs)
[ ] Force NOMMU build
[ ] Build with Large File Support (for accessing files > 2 GB)
(arm-none-linux-gnueabi-) Cross Compiler prefix
()Additional CFLAGS
5�� ����
$ make
6�� ��װ
busybox Ĭ�ϰ�װ·��ΪԴ��Ŀ¼�µ�_install
$ make install
7�� ���밲װĿ¼��
$ cd _install
$ ls
bin linuxrc sbin usr
8�� ����������Ҫ��Ŀ¼
$ mkdir dev etc mnt proc var tmp sys root
9�� ��ӿ�
? ���������еĿ⿽����_install Ŀ¼��
$cp /home/linux/toolchain/gcc-4.6.4/arm-arm1176jzfssf-linux-gnueabi/lib/ . -a
? ɾ����̬��͹�����ļ��еķ��ű�
$ sudo rm lib/*.a
$ arm-none-linux-gnueabi-strip lib/*
? ɾ������Ҫ�Ŀ⣬ȷ�����п��С������ 8M
$ du -mh lib/
10�����ϵͳ�����ļ�
�� etc ������ļ� inittab���ļ��������£�
#this is run first except when booting in single-user mode.
::sysinit:/etc/init.d/rcS
# /bin/sh invocations on selected ttys
# start an "askfirst" shell on the console (whatever that may be)
::askfirst:-/bin/sh
# stuff to do when restarting the init process
::restart:/sbin/init 
# stuff to do before rebooting
::ctrlaltdel:/sbin/reboot
�� etc ������ļ� fstab���ļ��������£�
#device mount-point type options dump fsck order
proc /proc proc defaults 0 0
tmpfs /tmp tmpfs defaults 0 0
sysfs /sys sysfs defaults 0 0
tmpfs /dev tmpfs defaults 0 0
�������ǹ��ص��ļ�ϵͳ������ proc��sysfs �� tmpfs�����ں��� proc �� sysfs Ĭ�϶�֧�֣���
tmpfs ��û��֧�ֵģ�������Ҫ��� tmpfs ��֧��
11 �޸��ں����ã�
$ make menuconfig
File systems --->
Pseudo filesystems --->
[*] Virtual memory file system support (former shm fs)
[*] Tmpfs POSIX Access Control Lists
���±����ں�
�� etc �´��� init.d Ŀ¼������ init.d �´��� rcS �ļ���rcS �ļ�����Ϊ��
#!/bin/sh
# This is the first script called by init process
/bin/mount -a
echo /sbin/mdev > /proc/sys/kernel/hotplug
/sbin/mdev -s
Ϊ rcS ��ӿ�ִ��Ȩ�ޣ�
$ chmod +x init.d/rcS
�� etc ����� profile �ļ����ļ�����Ϊ��
#!/bin/sh
export HOSTNAME=farsight
export USER=root
export HOME=root
export PS1="[$USER@$HOSTNAME \W]\# "
PATH=/bin:/sbin:/usr/bin:/usr/sbin
LD_LIBRARY_PATH=/lib:/usr/lib:$LD_LIBRARY_PATH
export PATH LD_LIBRARY_PATH
��Ҫ�����������ļ�ϵͳ�ߴ������� 8M ��ɾ������Ҫ�Ŀ��ļ�

����NFS  ����
1��ɾ��ԭ�ȵ�/source/rootfs
$ sudo rm -rf /source/rootfs
2���������½��ĸ��ļ�ϵͳ������/source/rootfs Ŀ¼��
$sudo mkdir /source/rootfs
$ sudo cp _install/* /source/rootfs �Ca
3������ uboot ��������
#setenv serverip 192.168.9.120
#setenv ipaddr 192.168.9.233
#setenv bootcmd tftp 41000000 uImage\;tftp 42000000 exynos4412-fs4412.dtb\;bootm 41000000
�C 42000000
#setenv bootargs root=/dev/nfs nfsroot=192.168.9.120:/source/rootfs rw
console=ttySAC2,115200 init=/linuxrc ip=192.168.9.233
# saveenv
�������������壬�鿴�Ƿ��ܹ��������أ������Ƿ�����


�������� ramdisk  �ļ�ϵͳ
ͨ�� NFS �����Ժ󣬾Ϳ������� ramdisk �ļ�ϵͳ�ˣ��������£�
1������һ����СΪ 8M �ľ����ļ�
$ cd ~
$ dd if=/dev/zero of=ramdisk bs=1k count=8192 ��ramdisk Ϊ 8M��
2����ʽ����������ļ�Ϊ ext2
$ mkfs.ext2 -F ramdisk
3���� mount ���洴�� initrd Ŀ¼��Ϊ���ص�
$ sudo mkdir /mnt/initrd
4����������̾����ļ����ص�/mnt/initrd ��
ע������� ramdisk ���ܴ���� rootfs Ŀ¼��
$ sudo mount -t ext2 ramdisk /mnt/initrd
5�������ǵ��ļ�ϵͳ���Ƶ� ramdisk ��
�����Ժõ��ļ�ϵͳ�������ȫ�������� /mnt/initrd Ŀ¼����
$ sudo cp/source/rootfs/* /mnt/initrd �Ca

6��ж�� initrd
$ sudo umount /mnt/initrd

7��ѹ�� ramdisk Ϊ ramdisk.gz ��������/tftpboot ��
$ gzip --best -c ramdisk>ramdisk.gz
8����ʽ��Ϊ uboot ʶ��ĸ�ʽ
$ mkimage -n "ramdisk" -A arm -O linux -T ramdisk -C gzip -d ramdisk.gz ramdisk.img
$ cp ramdisk.img /tftpboot
9�������ں�֧�� RAMDISK
������ ramdisk.img ����Ҫ�����ں�֧�� RAMDISK ��Ϊ�����ļ�ϵͳ
make menuconfig
File systems --->
<*> Second extended fs support
Device Drivers
SCSI device support --->
<*> SCSI disk support
Block devices --->
<*>RAM block device support
(16)Default number of RAM disks
(8192) Default RAM disk size (kbytes) (�޸�Ϊ 8M)
General setup --->
[*] Initial RAM filesystem and RAM disk (initramfs/initrd) support
���±����ںˣ����Ƶ�/tftpboot

10���� U-BOOT ������������������������
#setenv bootcmd tftp 41000000 uImage\;tftp 42000000 exynos4412-fs4412.dtb\;tftp 43000000
ramdisk.img\;bootm 41000000 43000000 42000000
# saveenv
��������������鿴�ܷ���������

�ġ�ext4  �ļ�ϵͳ����
1����ʽ����������
���� e2fsprogs-1.42.5.tar.xz �� Linux ��
��ѹ
$ tar xvfe2fsprogs-1.42.5.tar.xz
���빤��
$ cde2fsprogs-1.42.5
�����ű� build.sh ������������ݣ�
$ vim build.sh
#!/bin/sh
CC=arm-none-linux-gnueabi-gcc
./configure --enable-elf-shlibs --host=arm-none-linux-gnueabi \
--prefix=/home/linux/tools
make
make install
ִ�нű�
./build.sh
�ڱ��뵽�����ܻ��и��������£�
make[1]: [libext2fs.dvi] Error 1 (ignored)
�����Ҫ����ʵ������Ҫ���ļ����������
������ִ���ļ��Ϳ⵽�ļ�ϵͳ��
$ cp /home/linux/tools/sbin/mkfs.ext3 /source/rootfs/sbin
$ cp/home/linux/tools/lib/* /source/rootfs/lib
2���޸� u-boot ��������
�Ƚ��������������ʽ���ó�Ϊ ����������ʽ��
�� setenv boocmd
setenv bootargs
setenv bootargs root=/dev/nfs rwnfsroot=192.168.9.120:/source/rootfs init=/linuxrc
console=ttySAC2,115200 ip=192.168.9.233
ע�⣺192.168.9.120 ��Ӧ Ubuntu �� ip
192.168.9.233 ��Ӧ���ӵ� ip
������ ip Ӧ�ø����Լ���ʵ������ʵ��޸�
3������
�����������ڵ���ʱ�ڼ䰴���������������ִ����������
# fdisk -c 0
4����ʽ��
�����������������ϵͳ��ִ��
# mkfs.ext3 -F /dev/mmcblk0p2
5���޸�����/source/rootfs/etc/fstab
����������������
/dev/mmcblk0p2 /mnt ext3 defaults 0 0
��������ϵͳϵͳ������������� mmcblk0p2 ��Ϊ�û��ļ�ϵͳ