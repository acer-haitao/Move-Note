1. �޸��豸���ļ�
$ vim arch/arm/boot/dts/exynos4412-fs4412.dts
�����������
usbphy: usbphy@125B0000 {
#address-cells = <1>;
#size-cells = <1>;
compatible = "samsung,exynos4x12-usb2phy";
reg = <0x125B0000 0x100>;
ranges;
clocks = <&clock 2>, <&clock 305>;
clock-names = "xusbxti", "otg";
usbphy-sys {
reg = <0x10020704 0x8 0x1001021c 0x4>;
};
};
ehci@12580000 {
status = "okay";
usbphy = <&usbphy>;
};
usb3503@08 {
compatible = "smsc,usb3503";
reg = <0x08 0x4>;
connect-gpios = <&gpm3 3 1>;
intn-gpios = <&gpx2 3 1>;
reset-gpios = <&gpm2 4 1>;
initial-mode = <1>;
};
4. ���ԣ�
�����ں˺��豸���ļ���/tftpboot Ŀ¼��
$ cp arm/arm/boot/uImage /tftpboot
$ cp arch/arm/boot/dts/exynos4412-fs4412.dtb /tftpboot/
����Ŀ��岢��Ŀ�����������²�����
���� U ����ʾ����
[ 72.695000] usb 1-3.2: USB disconnect, device number 3
[ 74.435000] usb 1-3.2: new high-speed USB device number 4 using exynos-ehci
[ 74.555000] usb-storage 1-3.2:1.0: USB Mass Storage device detected
[ 74.560000] scsi1 : usb-storage 1-3.2:1.0
[ 75.645000] scsi 1:0:0:0: Direct-Access Kingston DataTraveler 160 PMAP PQ: 0 ANSI:
4
[ 75.660000] sd 1:0:0:0:Attached scsi generic sg0 type 0
[ 76.695000] sd 1:0:0:0: [sda] 15556608 512-byte logical blocks: (7.96 GB/7.41 GiB)
[ 76.700000] sd 1:0:0:0: [sda] Write Protect is off
[ 76.705000] sd 1:0:0:0: [sda] No Caching mode page found
[ 76.710000] sd 1:0:0:0: [sda]Assuming drive cache: write through
[ 76.725000] sd 1:0:0:0: [sda] No Caching mode page found
[ 76.730000] sd 1:0:0:0: [sda]Assuming drive cache: write through
[ 76.760000] sda: sda1 (sda ���豸�� sda1 �Ƿ�����)
[ 76.770000] sd 1:0:0:0: [sda] No Caching mode page found
[ 76.770000] sd 1:0:0:0: [sda]Assuming drive cache: write through
[ 76.780000] sd 1:0:0:0: [sda]Attached SCSI removable disk
���ն���ִ�й��ص��豸���ϱ���ʾ���
# mount -t vfat /dev/sda1 /mnt
# ls
���Բ鿴�� U �����ݣ������ʵ�顣