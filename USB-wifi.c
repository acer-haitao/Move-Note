1
�� USB-Wifi_driver ����������Ŀ¼�С�
��ѹ����Դ���
tar -jxvf USB-Wifi_driver.bz2
2
2.1  �޸� Makefile
2.1.1 �޸� DPO_MT7601U_LinuxSTA_3.0.0.4_20130913 Ŀ¼�µ� Makefile
vi Makefile
�޸� 49 ���е�
#PLATFORM = SMDK
Ϊ
PLATFORM = SMDK
275 ifeq ($(PLATFORM),SMDK)
276 LINUX_SRC = 
277 CROSS_COMPILE = 
278 endif
��Ϊ
ifeq ($(PLATFORM),SMDK)
LINUX_SRC = /home/linux/Farsight/linux-3.0-fs4412_V3/
CROSS_COMPILE = arm-none-linux-gnueabi-
endif
2.1.3 �޸� include/rtmp_def.h �ļ��е� 1604 ��
#define INF_MAIN_DEV_NAME		"wlan"
#define INF_MBSSID_DEV_NAME		"wlan"
2.1.4 �鿴 os/linux/config.mk �ļ�
linux@ubuntu:~/Farsight/DPO_MT7601U_LinuxSTA_3.0.0.4_20130913/os/linux$ vi config.mk

# Support AP-Client function
HAS_APCLI=n

# Support Wpa_Supplicant
# i.e. wpa_supplicant -Dralink
HAS_WPA_SUPPLICANT=y


# Support Native WpaSupplicant for Network Maganger
# i.e. wpa_supplicant -Dwext
HAS_NATIVE_WPA_SUPPLICANT_SUPPORT=y
�������ɵ� mt7601Usta.ko �ļ�������������Ҫ����������
��/home/linux/work/4412/DPO_MT7601U_LinuxSTA_3.0.0.4_20130913/os/linux/mt7601Usta.ko �������ǵĸ�
�ļ�ϵͳ�У�������ĸ��ļ�ϵͳ��

