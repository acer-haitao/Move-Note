1. �޸��豸���ļ�
$ vim arch/arm/boot/dts/exynos4412-fs4412.dts
�޸�
sdhci@12530000 {
bus-width = <4>;
pinctrl-0 = <&sd2_clk &sd2_cmd &sd2_bus4 &sd2_cd>;
pinctrl-names = "default";
vmmc-supply = <&mmc_reg>;
status = "okay";
};
Ϊ:
sdhci@12530000 {
bus-width = <4>;
pinctrl-0 = <&sd2_clk &sd2_cmd &sd2_bus4>;
cd-gpios = <&gpx0 7 0>;
cd-inverted = <0>;
pinctrl-names = "default";
status = "okay"
2. �����ں�
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

3. �����ں˺��豸��
$ make uImage
$ make dtbs
4. ���ԣ�
�����ں˺��豸���ļ���/tftpboot Ŀ¼��
$ cp arch/arm/boot/uImage /tftpboot
$ cp arch/arm/boot/dts/exynos4412-fs4412.dtb /tftpboot/
�����������������������ʾ��
[ 1.620000] mmc0: new high speed SDHC card at address cd6d
[ 1.625000] mmcblk1: mmc0:cd6d SE08G 7.28 GiB
[ 1.630000] mmcblk1: p1(mmcblk1  Ϊ�豸�� p1  Ϊ������)
���أ� ע�ⲻҪ���� C EMMC  �ķ���
#mount -t vfat /dev/mmcblk1p1 /mnt
�鿴/mnt/Ŀ¼���ɿ��� sd ��������