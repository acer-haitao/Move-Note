
1��������ļ�
��ʵ����� Led_test/fs4412_led_drv.c ������ drivers/char 

2drivers/char/Kconfig�޸�
�� menu "Character devices"����
config FS4412_LED
	tristate "FS4412_LED Deivce  Support"
	depends on ARCH_EXYNOS4
	help
	support led device on board
	
 3. �޸� drivers/char/Makefile
 obj-$(CONFIG_FS4412_LED) += fs4412_led_drv.o
 
 4 �� s5pv210_led_app.c ������ Linux ����Ŀ¼�²����������Գ���
 $ arm-none-linux-gnueabi-gcc fs4412_led_app.c �Co fs4412_led_app
   sudo cp fs4412_led_app /source/rootfs
  
 5. ���� LED 
 
  ��1�������ں�ʱ�����ո�ѡ��������ɺ󱣴��˳�
$ make menuconfig
Device Drivers --->
Character devices --->
<*>FS4412 LED Device Support
 
 ��2�������˳������±����� uImage ������ tftpboot ��
 $ make uImage
$ cp arch/arm/boot/uImage/tftpboot
�������������壬�����ں˲����С����ն���ִ���������
 ��3�������豸�ڵ�
# mknod /dev/led c 500 0
 ��4�����в��Գ��򲢹۲�����
# ./fs4412_led_app

6. ���� LED  ����Ϊģ��

��1�������ں�ʱ�����ո�ѡ��������ɺ󱣴��˳�
$ make menuconfig
Device Drivers --->
Character devices --->
<M>FS4412 LED Device Support
��2�������˳������±����� zImage ������ tftpboot �£�������ģ�鿽����/source/rootfs ��
$ make uImage modules
$ cp arch/arm/boot/uImage /tftpboot/
$ cp drivers/char/fs4412_led_drv.ko /source/rootfs/
�������������壬linux �������������ն��²���
��3�������豸�ڵ�
# mknod /dev/led c 500 0
��4������ LED ����ģ��
#insmod fs4412_led_drv.ko
��5�����в��Գ��򲢹۲�����
# ./fs4412_led_app