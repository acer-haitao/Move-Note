
1添加驱动文件
将实验代码 Led_test/fs4412_led_drv.c 拷贝到 drivers/char 

2drivers/char/Kconfig修改
在 menu "Character devices"下面
config FS4412_LED
	tristate "FS4412_LED Deivce  Support"
	depends on ARCH_EXYNOS4
	help
	support led device on board
	
 3. 修改 drivers/char/Makefile
 obj-$(CONFIG_FS4412_LED) += fs4412_led_drv.o
 
 4 将 s5pv210_led_app.c 拷贝到 Linux 任意目录下并交叉编译测试程序
 $ arm-none-linux-gnueabi-gcc fs4412_led_app.c –o fs4412_led_app
   sudo cp fs4412_led_app /source/rootfs
  
 5. 编译 LED 
 
  【1】配置内核时按“空格”选择，配置完成后保存退出
$ make menuconfig
Device Drivers --->
Character devices --->
<*>FS4412 LED Device Support
 
 【2】保存退出，重新编译后把 uImage 拷贝到 tftpboot 下
 $ make uImage
$ cp arch/arm/boot/uImage/tftpboot
重新启动开发板，加载内核并运行。在终端下执行下面操作
 【3】创建设备节点
# mknod /dev/led c 500 0
 【4】运行测试程序并观察现象
# ./fs4412_led_app

6. 编译 LED  驱动为模块

【1】配置内核时按“空格”选择，配置完成后保存退出
$ make menuconfig
Device Drivers --->
Character devices --->
<M>FS4412 LED Device Support
【2】保存退出，重新编译后把 zImage 拷贝到 tftpboot 下，把驱动模块拷贝到/source/rootfs 下
$ make uImage modules
$ cp arch/arm/boot/uImage /tftpboot/
$ cp drivers/char/fs4412_led_drv.ko /source/rootfs/
重新启动开发板，linux 运行起来后在终端下操作
【3】创建设备节点
# mknod /dev/led c 500 0
【4】加载 LED 驱动模块
#insmod fs4412_led_drv.ko
【5】运行测试程序并观察现象
# ./fs4412_led_app