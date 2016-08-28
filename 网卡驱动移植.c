1 设备树文件修改
vim arch/arm/boot/dts/exynos4412-fs4412.dts

添加如下代码
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
2 修改文件 driver/clk/clk.c
修改
static bool clk_ignore_unused;
为
static bool clk_ignore_unused = true;

3 配置内核：
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

4编译内核和设备树
$ make uImage
$ make dtbs
5 测试：
拷贝内核和设备树文件到/tftpboot 目录下
$ cp arm/arm/boot/uImage /tftpboot
$ cp arch/arm/boot/dts/exynos4412-fs4412.dtb /tftpboot/
启动开发板，修改内核启动参数，通过 NFS 方式挂载根文件系统