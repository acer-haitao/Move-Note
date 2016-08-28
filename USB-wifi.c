1
将 USB-Wifi_driver 拷贝到工作目录中。
解压驱动源码包
tar -jxvf USB-Wifi_driver.bz2
2
2.1  修改 Makefile
2.1.1 修改 DPO_MT7601U_LinuxSTA_3.0.0.4_20130913 目录下的 Makefile
vi Makefile
修改 49 行中的
#PLATFORM = SMDK
为
PLATFORM = SMDK
275 ifeq ($(PLATFORM),SMDK)
276 LINUX_SRC = 
277 CROSS_COMPILE = 
278 endif
改为
ifeq ($(PLATFORM),SMDK)
LINUX_SRC = /home/linux/Farsight/linux-3.0-fs4412_V3/
CROSS_COMPILE = arm-none-linux-gnueabi-
endif
2.1.3 修改 include/rtmp_def.h 文件中第 1604 行
#define INF_MAIN_DEV_NAME		"wlan"
#define INF_MBSSID_DEV_NAME		"wlan"
2.1.4 查看 os/linux/config.mk 文件
linux@ubuntu:~/Farsight/DPO_MT7601U_LinuxSTA_3.0.0.4_20130913/os/linux$ vi config.mk

# Support AP-Client function
HAS_APCLI=n

# Support Wpa_Supplicant
# i.e. wpa_supplicant -Dralink
HAS_WPA_SUPPLICANT=y


# Support Native WpaSupplicant for Network Maganger
# i.e. wpa_supplicant -Dwext
HAS_NATIVE_WPA_SUPPLICANT_SUPPORT=y
其中生成的 mt7601Usta.ko 文件即是我们所需要的驱动程序
将/home/linux/work/4412/DPO_MT7601U_LinuxSTA_3.0.0.4_20130913/os/linux/mt7601Usta.ko 拷贝我们的根
文件系统中（开发板的根文件系统。

