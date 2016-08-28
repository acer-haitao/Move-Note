1. 修改设备树文件
$ vim arch/arm/boot/dts/exynos4412-fs4412.dts
修改
sdhci@12530000 {
bus-width = <4>;
pinctrl-0 = <&sd2_clk &sd2_cmd &sd2_bus4 &sd2_cd>;
pinctrl-names = "default";
vmmc-supply = <&mmc_reg>;
status = "okay";
};
为:
sdhci@12530000 {
bus-width = <4>;
pinctrl-0 = <&sd2_clk &sd2_cmd &sd2_bus4>;
cd-gpios = <&gpx0 7 0>;
cd-inverted = <0>;
pinctrl-names = "default";
status = "okay"
2. 配置内核
$ make menuconfig
Device Drivers --->
<*> MMC/SD/SDIO card support --->
<*> Secure Digital Host Controller Interface support
<*> SDHCI support on Samsung S3C SoC
File systems --->
DOS/FAT/NT Filesystems --->
<*> MSDOS fs support
<*> VFAT (Windows-95) fs support
(437) Default codepage for FAT
(iso8859-1) Default iocharset for FAT
-*- Native language support --->
<*> Codepage 437 (United States, Canada)
<*> Simplified Chinese charset (CP936, GB2312)
<*> ASCII (United States)
<*> NLS ISO 8859-1 (Latin 1; Western European Languages)
<*> NLS UTF-8

3. 编译内核和设备树
$ make uImage
$ make dtbs
4. 测试：
拷贝内核和设备树文件到/tftpboot 目录下
$ cp arch/arm/boot/uImage /tftpboot
$ cp arch/arm/boot/dts/exynos4412-fs4412.dtb /tftpboot/
启动开发板会有如下内容显示：
[ 1.620000] mmc0: new high speed SDHC card at address cd6d
[ 1.625000] mmcblk1: mmc0:cd6d SE08G 7.28 GiB
[ 1.630000] mmcblk1: p1(mmcblk1  为设备名 p1  为分区名)
挂载， 注意不要挂在 C EMMC  的分区
#mount -t vfat /dev/mmcblk1p1 /mnt
查看/mnt/目录即可看到 sd 卡中内容