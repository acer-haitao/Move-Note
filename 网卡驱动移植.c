1 �豸���ļ��޸�
vim arch/arm/boot/dts/exynos4412-fs4412.dts

������´���
	srom-cs1@5000000{
		compatible = "simple-bus";
		#address-cells = <1>;
		#size-cells = <1>;
		reg = <0x5000000 0x1000000>;
		ranges;
	ethernet@5000000{
		compatible = "davicom,dm9000";
		reg = <0x5000000 0x2 0x5000004 0x2>;
		interrupt-parent = <&gpx0>;
		interrupts = <6 4>;
		davicom,no-eeprom;
		mac-address = [00 0a 2d a6 55 a2];

	};
	};	
2 �޸��ļ� driver/clk/clk.c
�޸�
static bool clk_ignore_unused;
Ϊ
static bool clk_ignore_unused = true;

3 �����ںˣ�
make menuconfig
[*] Networking support --->
Networking options --->
<*> Packet socket
<*>Unix domain sockets
[*] TCP/IP networking
[*] IP: kernel level autoconfiguration
Device Drivers --->
[*] Network device support --->
[*] Ethernet driver support (NEW) --->
<*> DM9000 support
File systems --->
[*] Network File Systems (NEW) --->
<*> NFS client support
[*] NFS client support for NFS version 3
[*] NFS client support for the NFSv3 ACL protocol extension
[*] Root file system on NF

4�����ں˺��豸��
$ make uImage
$ make dtbs
5 ���ԣ�
�����ں˺��豸���ļ���/tftpboot Ŀ¼��
$ cp arm/arm/boot/uImage /tftpboot
$ cp arch/arm/boot/dts/exynos4412-fs4412.dtb /tftpboot/
���������壬�޸��ں�����������ͨ�� NFS ��ʽ���ظ��ļ�ϵͳ