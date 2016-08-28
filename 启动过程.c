U-Boot 2010.03 (Jun 13 2016 - 18:24:22) For Farsight FS4412 eMMC

        APLL = 1000MHz, MPLL = 800MHz
        ARM_CLOCK = 1000MHz
PMIC:   Pls check the i2c @ pmic, id = 21,error
Board:  FS4412
DRAM:    1 GB
MMC:   max_emmc_clock:40 MHZ
Set CLK to 400 KHz
EMMC CLOCK OUTPUT:: 400KHz -[div:50]
response timeout error : 00000104 cmd 8
response timeout error : 00000104 cmd 55
max_emmc_clock:40 MHZ
Input CLK [ 50 MHz] is higher than limit [40 MHZ]
Set CLK to 40000 KHz
EMMC clock output: 40000 KHz
max_emmc_clock:40 MHZ
Input CLK [ 50 MHz] is higher than limit [40 MHZ]
Set CLK to 40000 KHz
EMMC clock output: 40000 KHz
MMC0:   3728 MB
SD sclk_mmc is 400K HZ
MMC1:   0 MB
0 MB
env_valid = 1
In:    serial
Out:   serial
Err:   serial

MMC read: dev # 0, block # 48, count 16 ...16 blocks read: OK


Checking Boot Mode ... EMMC4.41
Net:   dm9000
dm9000 i/o: 0x5000000, id: 0x90000a46 
DM9000: running in 16 bit mode
MAC: 11:22:33:44:55:66
Hit any key to stop autoboot:  0 
Using dm9000 device
TFTP from server 192.168.2.158; our IP address is 192.168.2.2
Filename 'zImage'.
Load address: 0x41000000
Loading: #################################################################
         #################################################################
         #################################################################
         #################################################################
         ##########################
done
Bytes transferred = 4192904 (3ffa88 hex)
Boot with zImage

Starting kernel ...

Uncompressing Linux... done, booting the kernel.
[    0.000000] Initializing cgroup subsys cpu
[    0.000000] Linux version 3.0.15 (linux@ubuntu) (gcc version 4.5.1 (Sourcery G++ Lite 2010.09-50) ) #8 SMP PREEMPT Mon Jun 20 21:00:38 PDT 2016
[    0.000000] CPU: ARMv7 Processor [413fc090] revision 0 (ARMv7), cr=10c5387d
[    0.000000] CPU: VIPT nonaliasing data cache, VIPT aliasing instruction cache
[    0.000000] Machine: SMDK4X12
[    0.000000] NR_BANKS too low, ignoring high memory
[    0.000000] **************************
[    0.000000] reserve_panic_dump_area!!
[    0.000000] **************************
[    0.000000] Memory policy: ECC disabled, Data cache writealloc
[    0.000000] CPU EXYNOS4412 (id 0xe4412011)
[    0.000000] S3C24XX Clocks, Copyright 2004 Simtec Electronics
[    0.000000] s3c_register_clksrc: clock audiocdclk has no registers set
[    0.000000] audiocdclk: no parent clock specified
[    0.000000] s3c_register_clksrc: clock armclk has no registers set
[    0.000000] EXYNOS4: PLL settings, A=1000000000, M=800000000, E=96000000 V=350000000
[    0.000000] EXYNOS4: ARMCLK=1000000000, DMC=400000000, ACLK200=24000000
[    0.000000] ACLK160=160000000, ACLK133=133333333, ACLK100=100000000
[    0.000000] EXYNOS4: ACLK400=24000000 ACLK266=800000000
[    0.000000] uclk1: source is mout_mpll_user (6), rate is 100000000
[    0.000000] uclk1: source is mout_mpll_user (6), rate is 100000000
[    0.000000] uclk1: source is mout_mpll_user (6), rate is 100000000
[    0.000000] uclk1: source is mout_mpll_user (6), rate is 100000000
[    0.000000] sclk_csis: source is xusbxti (1), rate is 1500000
[    0.000000] sclk_csis: source is xusbxti (1), rate is 1500000
[    0.000000] sclk_cam0: source is xusbxti (1), rate is 1500000
[    0.000000] sclk_cam1: source is xusbxti (1), rate is 1500000
[    0.000000] sclk_fimc: source is xusbxti (1), rate is 1500000
[    0.000000] sclk_fimc: source is xusbxti (1), rate is 1500000
[    0.000000] sclk_fimc: source is xusbxti (1), rate is 1500000
[    0.000000] sclk_fimc: source is xusbxti (1), rate is 1500000
[    0.000000] sclk_fimd: source is xusbxti (1), rate is 1500000
[    0.000000] sclk_fimd: source is xusbxti (1), rate is 1500000
[    0.000000] sclk_mfc: source is mout_mfc0 (0), rate is 200000000
[    0.000000] sclk_g3d: source is mout_g3d0 (0), rate is 41666666
[    0.000000] sclk_pwi: source is xusbxti (1), rate is 1500000
[    0.000000] PERCPU: Embedded 7 pages/cpu @c1140000 s6208 r8192 d14272 u32768
[    0.000000] Built 1 zonelists in Zone order, mobility grouping on.  Total pages: 251650
[    0.000000] Kernel command line: console=ttySAC2,115200 root=/dev/nfs nfsroot=192.168.2.158:/source/rootfs ip=192.168.2.2:192.168.2.158::255.255.255.0::eth0:off console=ttySAC2,115200 init=/linuxrc
[    0.000000] log_buf_len: 524288
[    0.000000] early log buf free: 127584(97%)
[    0.000000] PID hash table entries: 4096 (order: 2, 16384 bytes)
[    0.000000] Dentry cache hash table entries: 131072 (order: 7, 524288 bytes)
[    0.000000] Inode-cache hash table entries: 65536 (order: 6, 262144 bytes)
[    0.000000] Memory: 736MB 255MB = 991MB total
[    0.000000] Memory: 614464k/614464k available, 400320k reserved, 261120K highmem
[    0.000000] Virtual kernel memory layout:
[    0.000000]     vector  : 0xffff0000 - 0xffff1000   (   4 kB)
[    0.000000]     fixmap  : 0xfff00000 - 0xfffe0000   ( 896 kB)
[    0.000000]     DMA     : 0xfea00000 - 0xffe00000   (  20 MB)
[    0.000000]     vmalloc : 0xee800000 - 0xf6000000   ( 120 MB)
[    0.000000]     lowmem  : 0xc0000000 - 0xee000000   ( 736 MB)
[    0.000000]     pkmap   : 0xbfe00000 - 0xc0000000   (   2 MB)
[    0.000000]     modules : 0xbf000000 - 0xbfe00000   (  14 MB)
[    0.000000]       .init : 0xc0008000 - 0xc00d6000   ( 824 kB)
[    0.000000]       .text : 0xc00d6000 - 0xc084b000   (7636 kB)
[    0.000000]       .data : 0xc084c000 - 0xc08f5300   ( 677 kB)
[    0.000000]        .bss : 0xc08f7910 - 0xc0936f98   ( 254 kB)
[    0.000000] SLUB: Genslabs=13, HWalign=32, Order=0-3, MinObjects=0, CPUs=4, Nodes=1
[    0.000000] Preemptible hierarchical RCU implementation.
[    0.000000] NR_IRQS:456
[    0.000000] Calibrating delay loop... 1992.29 BogoMIPS (lpj=4980736)
[    0.045000] pid_max: default: 32768 minimum: 301
[    0.045000] Mount-cache hash table entries: 512
[    0.045000] Initializing cgroup subsys debug
[    0.045000] Initializing cgroup subsys cpuacct
[    0.045000] Initializing cgroup subsys freezer
[    0.045000] CPU: Testing write buffer coherency: ok
[    0.045000] **********panic_dump_test****************
[    0.045000] There is no valid panic information in memory
[    0.045000] **************************
[    0.045000] L310 cache controller enabled
[    0.045000] l2x0: 16 ways, CACHE_ID 0x4100c4c8, AUX_CTRL 0x7e470001, Cache size: 1048576 B
[    0.075000] CPU1: Booted secondary processor
[    0.095000] CPU2: Booted secondary processor
[    0.115000] CPU3: Booted secondary processor
[    0.115000] Brought up 4 CPUs
[    0.115000] SMP: Total of 4 processors activated (7969.17 BogoMIPS).
[    0.120000] print_constraints: dummy: 
[    0.120000] NET: Registered protocol family 16
[    0.120000] sensor_hw_init: line = 299
[    0.130000] #################leesheen add###################### smdk4x12_machine_init
[    0.130000] exynos4_pmu_init: PMU supports 4412(96)
[    0.130000] EXYNOS4: Initializing architecture
[    0.130000] panic_file create OK !!
[    0.130000] s3c-adc exynos4412-adc: attached adc driver
[    0.130000] samsung-pd samsung-pd.0: power domain registered
[    0.130000] samsung-pd samsung-pd.1: power domain registered
[    0.130000] samsung-pd samsung-pd.2: power domain registered
[    0.130000] samsung-pd samsung-pd.5: power domain registered
[    0.130000] samsung-pd samsung-pd.4: power domain registered
[    0.130000] samsung-pd samsung-pd.6: power domain registered
[    0.130000] samsung-pd samsung-pd.7: power domain registered
[    0.130000] s3c24xx-pwm s3c24xx-pwm.1: tin at 100000000, tdiv at 100000000, tin=divclk, base 8
[    0.130000] s3c24xx-pwm s3c24xx-pwm.0: tin at 100000000, tdiv at 100000000, tin=divclk, base 0
[    0.130000] UMP: UMP device driver  loaded
[    0.150000] bio: create slab <bio-0> at 0
[    0.155000] SCSI subsystem initialized
[    0.155000] s3c64xx_spi_probe(969)
[    0.155000] s3c64xx_spi_probe(1092)
[    0.155000] s3c64xx_spi_probe(1113)
[    0.155000] usbcore: registered new interface driver usbfs
[    0.155000] usbcore: registered new interface driver hub
[    0.155000] usbcore: registered new device driver usb
[    0.155000] s3c-i2c s3c2440-i2c.1: slave address 0x10
[    0.155000] s3c-i2c s3c2440-i2c.1: bus frequency set to 97 KHz
[    0.155000] s3c-i2c s3c2440-i2c.1: S3C2410_IICCON=0xa0
[    0.155000] +s5m8767_pmic_probe()
[    0.155000] print_constraints: vdd_mif range: 900 <--> 1100 mV at 1000 mV 
[    0.160000] print_constraints: vdd_arm range: 850 <--> 1450 mV at 1100 mV 
[    0.160000] print_constraints: vdd_int range: 875 <--> 1200 mV at 1000 mV 
[    0.160000] print_constraints: vdd_g3d range: 750 <--> 1500 mV at 1000 mV 
[    0.160000] print_constraints: vdd_m12 range: 750 <--> 1500 mV at 1200 mV 
[    0.160000] print_constraints: vdd12_5m range: 750 <--> 1500 mV at 1200 mV 
[    0.160000] print_constraints: vddf28_emmc range: 750 <--> 3000 mV at 2850 mV 
[    0.175000] print_constraints: VDDQ_M12: 1500 mV 
[    0.175000] print_constraints: VDD18_2M: 1800 mV 
[    0.175000] print_constraints: VDD10_MIPI: 1000 mV 
[    0.190000] print_constraints: VDD33_LCD: 3300 mV 
[    0.190000] print_constraints: VDD18_MIPI: 1800 mV 
[    0.200000] print_constraints: VDD33_UOTG: 3300 mV 
[    0.205000] print_constraints: VDD10_USH: 1000 mV 
[    0.205000] print_constraints: VDD18_HSIC: 1800 mV 
[    0.220000] print_constraints: DC33V_TP: 3300 mV 
[    0.220000] print_constraints: VDD28_CAM: 2800 mV 
[    0.220000] print_constraints: VDD28_AF: 2800 mV 
[    0.220000] print_constraints: VDDA28_2M: 2800 mV 
[    0.225000] print_constraints: VDD28_TF: 2800 mV 
[    0.235000] print_constraints: VDD33_A31: 3300 mV 
[    0.255000] print_constraints: VDD18_CAM: 1800 mV 
[    0.260000] print_constraints: VDD18_A31: 1800 mV 
[    0.260000] print_constraints: GPS_1V8: 1800 mV 
[    0.260000] print_constraints: DVDD12: 1200 mV 
[    0.265000] -s5m8767_pmic_probe()
[    0.265000] s5m87xx 1-0066: S5M87xx MFD probe done!!! 
[    0.265000] s3c-i2c s3c2440-i2c.1: i2c-1: S3C I2C adapter
[    0.265000] s3c-i2c s3c2440-i2c.3: slave address 0x10
[    0.265000] s3c-i2c s3c2440-i2c.3: bus frequency set to 97 KHz
[    0.265000] s3c-i2c s3c2440-i2c.3: S3C2410_IICCON=0xa0
[    0.265000] s3c-i2c s3c2440-i2c.3: i2c-3: S3C I2C adapter
[    0.265000] s3c-i2c s3c2440-i2c.4: slave address 0x10
[    0.265000] s3c-i2c s3c2440-i2c.4: bus frequency set to 97 KHz
[    0.265000] s3c-i2c s3c2440-i2c.4: S3C2410_IICCON=0xa0
[    0.265000] s3c-i2c s3c2440-i2c.4: i2c-4: S3C I2C adapter
[    0.265000] s3c-i2c s3c2440-i2c.5: slave address 0x10
[    0.265000] s3c-i2c s3c2440-i2c.5: bus frequency set to 97 KHz
[    0.265000] s3c-i2c s3c2440-i2c.5: S3C2410_IICCON=0xa0
[    0.265000] s3c-i2c s3c2440-i2c.5: i2c-5: S3C I2C adapter
[    0.265000] s3c-i2c s3c2440-i2c.7: slave address 0x10
[    0.265000] s3c-i2c s3c2440-i2c.7: bus frequency set to 97 KHz
[    0.265000] s3c-i2c s3c2440-i2c.7: S3C2410_IICCON=0xa0
[    0.265000] s3c-i2c s3c2440-i2c.7: i2c-7: S3C I2C adapter
[    0.265000] Advanced Linux Sound Architecture Driver Version 1.0.24.
[    0.265000] Bluetooth: Core ver 2.16
[    0.265000] NET: Registered protocol family 31
[    0.265000] Bluetooth: HCI device and connection manager initialized
[    0.265000] Bluetooth: HCI socket layer initialized
[    0.265000] Bluetooth: L2CAP socket layer initialized
[    0.265000] Bluetooth: SCO socket layer initialized
[    0.265000] Switching to clocksource mct-frc
[    0.266605] Switched to NOHz mode on CPU #0
[    0.266810] NET: Registered protocol family 2
[    0.266828] Switched to NOHz mode on CPU #2
[    0.266835] Switched to NOHz mode on CPU #3
[    0.266842] Switched to NOHz mode on CPU #1
[    0.266966] IP route cache hash table entries: 32768 (order: 5, 131072 bytes)
[    0.267532] TCP established hash table entries: 131072 (order: 8, 1048576 bytes)
[    0.269033] TCP bind hash table entries: 65536 (order: 7, 786432 bytes)
[    0.269837] TCP: Hash tables configured (established 131072 bind 65536)
[    0.269853] TCP reno registered
[    0.269867] UDP hash table entries: 512 (order: 2, 16384 bytes)
[    0.269903] UDP-Lite hash table entries: 512 (order: 2, 16384 bytes)
[    0.270178] NET: Registered protocol family 1
[    0.270459] RPC: Registered named UNIX socket transport module.
[    0.270475] RPC: Registered udp transport module.
[    0.270487] RPC: Registered tcp transport module.
[    0.270499] RPC: Registered tcp NFSv4.1 backchannel transport module.
[    0.270693] PMU: registered new PMU device of type 0
[    0.270814] Exynos4 : ARM Clock down on idle mode is enabled
[    0.271585] regulator_consumer_probe: loading tc4-regulator-consumer
[    0.271604]  Register vdd_consumer_early_suspend done
[    0.271722] s5p_init_pmic_vibrator()
[    0.272420] Loaded driver for PL330 DMAC-0 s3c-pl330
[    0.272436]  DBUFF-64x8bytes Num_Chans-8 Num_Peri-1 Num_Events-32
[    0.272543] Loaded driver for PL330 DMAC-1 s3c-pl330
[    0.272559]  DBUFF-32x4bytes Num_Chans-8 Num_Peri-32 Num_Events-32
[    0.272657] Loaded driver for PL330 DMAC-2 s3c-pl330
[    0.272672]  DBUFF-32x4bytes Num_Chans-8 Num_Peri-32 Num_Events-32
[    0.279841] highmem bounce pool size: 64 pages
[    0.280042] ashmem: initialized
[    0.288675] fuse init (API version 7.16)
[    0.289002] msgmni has been set to 690
[    0.289677] io scheduler noop registered
[    0.289691] io scheduler deadline registered
[    0.289751] io scheduler cfq registered (default)
[    0.294451] 
[    0.294454]  CPU type: 
[    0.294465]  Exynos 4412
[    0.300917] parent clock: 800000000, vclk: 45049000, vclk div: 18
[    0.300939] (s3cfb_backlight_on, 304): VLED_ON
[    0.306952] ************************add by leesheen
[    0.311964] (s3cfb_backlight_on, 361): TP1_EN_ON
[    0.316977] s3cfb s3cfb.0: registered successfully
[    0.317305] Serial: 8250/16550 driver, 4 ports, IRQ sharing disabled
[    0.665280] s5pv210-uart.0: ttySAC0 at MMIO 0x13800000 (irq = 16) is a S3C6400/10
[    0.745060] s5pv210-uart.1: ttySAC1 at MMIO 0x13810000 (irq = 20) is a S3C6400/10
[    0.825055] s5pv210-uart.2: ttySAC2 at MMIO 0x13820000 (irq = 24) is a S3C6400/10
[    1.928634] console [ttySAC2] enabled
[    2.005060] s5pv210-uart.3: ttySAC3 at MMIO 0x13830000 (irq = 28) is a S3C6400/10
[    2.086035] SI GPS Initialize
[    2.087799] max485_ctl Initialize
[    2.097490] brd: module loaded
[    2.102260] loop: module loaded
[    2.103953] pmem: 0 init
[    2.106765] pmem_gpu1: 0 init
[    2.110093] i2c i2c-5: mpu_probe: 0
[    2.112862] i2c i2c-5: mpu_probe: irq:379
[    2.116869] <6>mldl_cfg:Reset MPU6050 B1
[    2.142657] mldl_cfg:Force to use default sensitivity(131,16384)
[    2.151287] i2c i2c-5: Installing irq using 379
[    2.154342] i2c i2c-5: Module Param interface = mpuirq
[    2.159742] i2c i2c-5: inv_mpu_register_slave: +mpu6050 Type 1: Addr: 68 IRQ: 379, Adapt:  5
[    2.168336] i2c i2c-5: Installing accelirq irq using 379
[    2.173342] i2c i2c-5: mpu_probe: init successfully.
[    2.178239] i2c-core: driver [mpu6050B1] using legacy suspend method
[    2.184472] i2c-core: driver [mpu6050B1] using legacy resume method
[    2.190730] mpu_init: Probe name mpu6050B1
[    2.195570] CAN device driver interface
[    2.198651] #####################leesheen add############## mcp251x_ioSetup
[    2.205566] mcp251x: setup gpio pins CS and External Int
[    2.221960] mcp251x spi2.0: probed
[    2.223995] PPP generic driver version 2.4.2
[    2.228411] PPP Deflate Compression module registered
[    2.233184] PPP BSD Compression module registered
[    2.238266] PPP MPPE Compression module registered
[    2.242674] NET: Registered protocol family 24
[    2.247093] dm9000 Ethernet Driver, V1.31
[    2.252353] eth0: dm9000a at ee838000,ee83a008 IRQ 358 MAC: 00:09:c0:ff:ec:48 (platform data)
[    2.259782] usbcore: registered new interface driver dm9601
[    2.265278] ehci_hcd: USB 2.0 'Enhanced' Host Controller (EHCI) Driver
[    2.271735] 
[    2.271738] 
[    2.271740]  [usb_host_phy_init]++++++++++++++
[    2.279195] s5p-ehci s5p-ehci: S5P EHCI Host Controller
[    2.284236] s5p-ehci s5p-ehci: new USB bus registered, assigned bus number 1
[    2.291364] s5p-ehci s5p-ehci: irq 134, io mem 0x12580000
[    2.305037] s5p-ehci s5p-ehci: USB 0.0 started, EHCI 1.00
[    2.309060] usb usb1: New USB device found, idVendor=1d6b, idProduct=0002, bcdDevice=0300
[    2.317132] usb usb1: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    2.324335] usb usb1: New USB device Class: Class=9, SubClass=0, Protocol=0
[    2.331278] usb usb1: Product: S5P EHCI Host Controller
[    2.336484] usb usb1: Manufacturer: Linux 3.0.15 ehci_hcd
[    2.341865] usb usb1: SerialNumber: s5p-ehci
[    2.346619] hub 1-0:1.0: USB hub found
[    2.349849] hub 1-0:1.0: 3 ports detected
[    2.354440] usbcore: registered new interface driver cdc_acm
[    2.359487] cdc_acm: USB Abstract Control Model driver for USB modems and ISDN adapters
[    2.367584] usbcore: registered new interface driver cdc_wdm
[    2.373114] Initializing USB Mass Storage driver...
[    2.378117] usbcore: registered new interface driver usb-storage
[    2.383964] USB Mass Storage support registered.
[    2.388806] usbcore: registered new interface driver usbserial
[    2.394485] USB Serial support registered for generic
[    2.399530] usbcore: registered new interface driver usbserial_generic
[    2.405925] usbserial: USB Serial Driver core
[    2.410367] USB Serial support registered for ch341-uart
[    2.415675] usbcore: registered new interface driver ch341
[    2.421129] USB Serial support registered for FTDI USB Serial Device
[    2.427509] usbcore: registered new interface driver ftdi_sio
[    2.433092] ftdi_sio: v1.6.0:USB FTDI Serial Converters Driver
[    2.439009] USB Serial support registered for GSM modem (1-port)
[    2.445057] usbcore: registered new interface driver option
[    2.450538] option: v0.7.2:USB Driver for GSM modems
[    2.455506] USB Serial support registered for pl2303
[    2.460469] usbcore: registered new interface driver pl2303
[    2.465903] pl2303: Prolific PL2303 USB to serial adaptor driver
[    2.472092] s3c-udc : S3C HS USB OTG Device Driver,(c) 2008-2009 Samsung Electronics
[    2.472098] s3c-udc : version 15 March 2009
[    2.485918] android_usb gadget: Mass Storage Function, version: 2009/09/11
[    2.491330] android_usb gadget: Number of LUNs=3
[    2.495929]  lun0: LUN: removable file: (no medium)
[    2.500788]  lun1: LUN: removable file: (no medium)
[    2.505648]  lun2: LUN: removable file: (no medium)
[    2.510804] android_usb gadget: android_usb ready
[    2.515344] mousedev: could not register psaux device, error: -16
[    2.521273] mousedev: PS/2 mouse device common for all mice
[    2.527422] input: gpio-keys as /devices/platform/gpio-keys/input/input0
[    2.534152] input: samsung-keypad as /devices/platform/samsung-keypad/input/input1
[    2.541452] usbcore: registered new interface driver xpad
[    2.546562] usbcore: registered new interface driver usb_acecad
[    2.552367] acecad: v3.2:USB Acecad Flair tablet driver
[    2.557698] usbcore: registered new interface driver aiptek
[    2.563111] aiptek: v2.3 (May 2, 2007):Aiptek HyperPen USB Tablet Driver (Linux 2.6.x)
[    2.571009] aiptek: Bryan W. Headley/Chris Atenasio/Cedric Brun/Rene van Paassen
[    2.578508] usbcore: registered new interface driver gtco
[    2.583769] GTCO usb driver version: 2.00.0006
[    2.588139] usbcore: registered new interface driver hanwang
[    2.593955] usbcore: registered new interface driver kbtab
[    2.599306] kbtab: v0.0.2:USB KB Gear JamStudio Tablet driver
[    2.605295] usbcore: registered new interface driver wacom
[    2.610503] wacom: v1.52:USB Wacom tablet driver
[    2.615102] ==ft5x0x_ts_init==
[    2.618152] [FTS] ft5x0x_ts_probe, driver version is 2.0.
[    2.623650] ft5x0x_ts_probe:request_irq irq=356 success!!!
[    2.629222] input: ft5x0x_ts as /devices/virtual/input/input2
[    2.660046] usb 1-3: new high speed USB device number 2 using s5p-ehci
[    2.795457] usb 1-3: New USB device found, idVendor=0424, idProduct=3503, bcdDevice=a1a0
[    2.802091] usb 1-3: New USB device strings: Mfr=0, Product=0, SerialNumber=0
[    2.809207] usb 1-3: New USB device Class: Class=9, SubClass=0, Protocol=2
[    2.816672] hub 1-3:1.0: USB hub found
[    2.819938] hub 1-3:1.0: 3 ports detected
[    2.884925] msg ft5x0x_read_reg i2c read error: -6
[    2.888248] +++++++++++++++++++ft5x02_Init_IC_Param=1342+++++++++++++++++++++++++
[    2.895838] ft5x02_i2c_Write i2c write error: -6
[    2.900313] ft5x0x_ts 3-0038: ft5x02_Init_IC_Param:enter factory mode failed.
[    2.907554] ft5x02_i2c_Write i2c write error: -6
[    2.912030] ft5x0x_ts 3-0038: ft5x02_Init_IC_Param:enter work mode failed.
[    2.921045] msg ft5x0x_read_reg i2c read error: -6
[    2.924361] +++++++++++++++++++ft5x02_Init_IC_Param=1342+++++++++++++++++++++++++
[    2.931972] ft5x02_i2c_Write i2c write error: -6
[    2.936439] ft5x0x_ts 3-0038: ft5x02_Init_IC_Param:enter factory mode failed.
[    2.943681] ft5x02_i2c_Write i2c write error: -6
[    2.948157] ft5x0x_ts 3-0038: ft5x02_Init_IC_Param:enter work mode failed.
[    2.957133] msg ft5x0x_read_reg i2c read error: -6
[    2.960456] +++++++++++++++++++ft5x02_Init_IC_Param=1342+++++++++++++++++++++++++
[    2.968045] ft5x02_i2c_Write i2c write error: -6
[    2.972525] ft5x0x_ts 3-0038: ft5x02_Init_IC_Param:enter factory mode failed.
[    2.979760] ft5x02_i2c_Write i2c write error: -6
[    2.984259] ft5x0x_ts 3-0038: ft5x02_Init_IC_Param:enter work mode failed.
[    2.993092] [FTS] FS210 1024x600 TouchScreen driver installed!
[    2.997569] ret=0
[    2.999854] input: pwm-beeper as /devices/platform/s3c24xx-pwm.0/pwm-beeper.0/input/input3
[    3.257424]  FS4412 PWM BEEPER Driver Installed! S3C24XX RTC, (c) 2004,2006 Simtec Electronics
[    3.264616] s3c-rtc s3c64xx-rtc: rtc disabled, re-enabling
[    3.270073] s3c_rtc_gettime() 2165-24-41 45:85:2
[    3.274973] using rtc device, s3c, for alarms
[    3.278823] s3c-rtc s3c64xx-rtc: rtc core: registered s3c as rtc0
[    3.287984] s5m_rtc_read_time: 2012/1/1 0:11:37(0)
[    3.292401] s5m_rtc_read_alarm: 2000/0/1 0:0:0(-1)
[    3.297605] s5m_rtc_read_time: 2012/1/1 0:11:37(0)
[    3.301101] s5m-rtc s5m-rtc: rtc core: registered s5m-rtc as rtc1
[    3.307402] s5m-rtc s5m-rtc: RTC CHIP NAME: s5m-rtc
[    3.311967] i2c /dev entries driver
[    3.316171] Linux media interface: v0.10
[    3.319557] lirc_dev: IR Remote Control driver registered, major 251 
[    3.325668] IR NEC protocol handler initialized
[    3.330178] IR RC5(x) protocol handler initialized
[    3.334941] IR RC6 protocol handler initialized
[    3.339465] IR JVC protocol handler initialized
[    3.343978] IR Sony protocol handler initialized
[    3.348579] IR RC5 (streamzap) protocol handler initialized
[    3.354135] IR LIRC bridge handler initialized
[    3.358610] Registered IR keymap rc-empty
[    3.362692] Allocated space for 256 keycode entries (2048 bytes)
[    3.368805] input: gpio_ir_recv as /devices/virtual/rc/rc0/input4
[    3.374771] rc0: gpio_ir_recv as /devices/virtual/rc/rc0
[    3.380136] rc rc0: lirc_dev: driver ir-lirc-codec (gpio-rc-recv) registered at minor = 0
[    3.388120] Registered chained gpio int handler for interrupt 110.
[    3.394249] Registered interrupt support for gpio group 17.
[    3.399797] s5p_gpioint_set_type irq:384 is at GPK1(0)
[    3.404972]  FS4412 IR Driver Installed
[    3.408865] Linux video capture interface: v2.00
[    3.414214] s3c-csis: Samsung MIPI-CSIS0 driver probed successfully
[    3.419607] s3c-csis: Samsung MIPI-CSIS1 driver probed successfully
[    3.425945] Initialize JPEG driver
[    3.429453] s5p-jpeg s5p-jpeg: JPEG driver is registered to /dev/video12
[    3.436049] s5p-jpeg s5p-jpeg: JPEG driver is registered to /dev/video11
[    3.442858] i2c-core: driver [s5p_ddc] using legacy suspend method
[    3.448749] i2c-core: driver [s5p_ddc] using legacy resume method
[    3.454826] S5P HPD Driver, (c) 2009 Samsung Electronics
[    3.460490] S5P CEC Driver, (c) 2009 Samsung Electronics
[    3.466235] MFC(Multi Function Codec - FIMV v5.x) registered successfully
[    3.472619] Samsung Graphics 2D driver, (c) 2011 Samsung Electronics
[    3.479022] Mali: init_mali_clock mali_clock c0867368 
[    3.507995] Mali: Mali device driver  loaded
[    3.512225] FS4412 ADC to Battery Driver Installed
[    3.515700] S3C2410 Watchdog Timer, (c) 2004 Simtec Electronics
[    3.521743] s3c2410-wdt s3c2410-wdt: watchdog inactive, reset disabled, irq enabled
[    3.529844] device-mapper: uevent: version 1.0.3
[    3.534063] device-mapper: ioctl: 4.20.0-ioctl (2011-02-02) initialised: dm-devel@redhat.com
[    3.542162] Bluetooth: HCI UART driver ver 2.2
[    3.546566] Bluetooth: HCI H4 protocol initialized
[    3.551337] Bluetooth: HCI BCSP protocol initialized
[    3.556284] Bluetooth: HCILL protocol initialized
[    3.560971] Bluetooth: HCIATH3K protocol initialized
[    3.565919] Bluetooth: Generic Bluetooth USB driver ver 0.6
[    3.571613] usbcore: registered new interface driver btusb
[    3.577477] cpuidle: using governor ladder
[    3.581920] cpuidle: using governor menu
[    3.585066] mshci: Mobile Storage Host Controller Interface driver
[    3.591091] mshci: Copyright (c) 2011 Samsung Electronics Co., Ltd
[    3.597336] clock source 0: sclk_dwmci (160000000 Hz)
[    3.602295] dw_mmc dw_mmc: clock source 0: sclk_dwmci (160000000 Hz)
[    3.608850] mmc0: Version ID 0x5342240a.
[    3.612531] mjdbg: cmu_max_clcok:800000000
[    3.616609] mjdbg: host->max_clk: 800000000
[    3.620993] mmc0: FIFO WMARK FOR RX 0x11 WX 0x1. ###########
[    3.627820] mmc0: MSHCI controller on samsung-mshci [dw_mmc] using IDMA
[    3.633204] sdhci: Secure Digital Host Controller Interface driver
[    3.639179] sdhci: Copyright(c) Pierre Ossman
[    3.641058] mmc0:mshci_set_clock, 400000@ration:4,11[mjdbg] cmu_set_clock: 400000
[    3.651058] s3c-sdhci s3c-sdhci.2: clock source 0: sclk_mmc (10666666 Hz)
[    3.655043] *******mmc0: inserted!!!!!******
[    3.662011] mmc0: cmd 52 response timeout error
[    3.667590] mmc1: no vmmc regulator found
[    3.670514] mmc0: cmd 52 response timeout error
[    3.676378] mmc1: SDHCI controller on samsung-hsmmc [s3c-sdhci.2] using ADMA
[    3.682103] wake enabled for irq 359
[    3.685877] s3c-sdhci s3c-sdhci.3: clock source 0: sclk_mmc (10666666 Hz)
[    3.692389] mmc0: cmd 8 response timeout error
[    3.697877] mmc2: no vmmc regulator found
[    3.700808] mmc0: cmd 5 response timeout error
[    3.706568] mmc2: SDHCI controller on samsung-hsmmc [s3c-sdhci.3] using ADMA
[    3.712265] mmc0: cmd 5 response timeout error
[    3.718487] mmc0: cmd 5 response timeout error
[    3.723255] mmc0: cmd 5 response timeout error
[    3.728044] mmc0: cmd 55 response timeout error
[    3.732920] mmc0: cmd 55 response timeout error
[    3.737797] mmc0: cmd 55 response timeout error
[    3.742670] mmc0: cmd 55 response timeout error
[    3.748374] usbcore: registered new interface driver usbhid
[    3.752524] usbhid: USB HID core driver
[    3.757115] logger: created 256K log 'log_main'
[    3.761010] logger: created 256K log 'log_events'
[    3.765656] logger: created 256K log 'log_radio'
[    3.770249] logger: created 256K log 'log_system'
[    3.776358] Samsung Audio Subsystem Driver, (c) 2011 Samsung Electronics
[    3.781656] audss_init: RCLK SRC[busclk]
[    3.803655] mmc0:mshci_set_clock, 50000000@ration:4,11[mjdbg] cmu_set_clock: 50000000
[    3.821384] mmc0: new high speed DDR MMC card at address 0001
[    3.826015] mmcblk0: mmc0:0001 4FPD3R 3.64 GiB 
[    3.832010]  mmcblk0: p1 p2 p3 p4
[    3.860059] *******mmc2: inserted!!!!!******
[    3.898512] asoc: wm8960-hifi <-> samsung-i2s.0 mapping ok
[    3.904175] asoc: wm8960-hifi <-> samsung-i2s.0 mapping ok
[    3.909140] Samsung SRP driver, (c) 2010 Samsung Electronics
[    3.913853] *******mmc2: inserted!!!!!******
[    3.934740] SRP: Driver successfully probed
[    3.937623] ALSA device list:
[    3.940429]   #0: iTOP-4412-Audio
[    3.943791] GACT probability NOT on
[    3.947208] Mirror/redirect action on
[    3.950827] u32 classifier
[    3.953504]     Actions configured
[    3.956902] Netfilter messages via NETLINK v0.30.
[    3.961627] nf_conntrack version 0.5.0 (9601 buckets, 38404 max)
[    3.968359] ctnetlink v0.93: registering with nfnetlink.
[    3.972900] NF_TPROXY: Transparent proxy support initialized, version 4.1.0
[    3.975033] *******mmc2: inserted!!!!!******
[    3.984093] NF_TPROXY: Copyright (c) 2006-2007 BalaBit IT Ltd.
[    3.990225] xt_time: kernel timezone is -0000
[    3.995722] ip_tables: (C) 2000-2006 Netfilter Core Team
[    3.999694] arp_tables: (C) 2002 David S. Miller
[    4.004224] TCP cubic registered
[    4.008286] NET: Registered protocol family 10
[    4.015909] Mobile IPv6
[    4.016900] ip6_tables: (C) 2000-2006 Netfilter Core Team
[    4.022471] IPv6 over IPv4 tunneling driver
[    4.030835] NET: Registered protocol family 17
[    4.033824] NET: Registered protocol family 15
[    4.038244] can: controller area network core (rev 20090105 abi 8)
[    4.040048] *******mmc2: inserted!!!!!******
[    4.048755] NET: Registered protocol family 29
[    4.053116] can: raw protocol (rev 20090105)
[    4.057440] can: broadcast manager protocol (rev 20090105 t)
[    4.063078] Bluetooth: RFCOMM TTY layer initialized
[    4.067858] Bluetooth: RFCOMM socket layer initialized
[    4.072969] Bluetooth: RFCOMM ver 1.11
[    4.076701] Bluetooth: BNEP (Ethernet Emulation) ver 1.3
[    4.082092] Bluetooth: BNEP filters: protocol multicast
[    4.087275] NET: Registered protocol family 35
[    4.091899] lib80211: common routines for IEEE802.11 drivers
[    4.097304] VFP support v0.3: implementor 41 architecture 3 part 30 variant 9 rev 4
[    4.104920] Registering SWP/SWPB emulation handler
[    4.109919] exynos4_pm_hotplug_device_init: 0
[    4.114020] EXYNOS4 PM-hotplug init function
[    4.121873] regulator_init_complete: VDD18_MIPI: incomplete constraints, leaving on
[    4.128504] regulator_init_complete: VDD10_MIPI: incomplete constraints, leaving on
[    4.136141] regulator_init_complete: VDD18_2M: incomplete constraints, leaving on
[    4.144892] regulator_init_complete: vdd_int range: incomplete constraints, leaving on
[    4.151782] regulator_init_complete: vdd_arm range: incomplete constraints, leaving on
[    4.159680] regulator_init_complete: vdd_mif range: incomplete constraints, leaving on
[    4.167462] USB_DEVICE_ATTACHED
[    4.171463] exynos_usb_Device: Exynos USB Device Driver
[    4.176581] s5m_rtc_read_time: 2012/1/1 0:11:38(0)
[    4.180260] s3c_rtc_settime() 2012-1-1 0:11:38
[    4.184679] s5m_rtc_set_time: 2012/1/1 0:11:38(0)
[    4.215045] s5m-rtc s5m-rtc: setting system clock to 2012-01-01 00:11:38 UTC (1325376698)
[    4.232152] FIMC0 registered successfully
[    4.234981] FIMC1 registered successfully
[    4.238988] FIMC2 registered successfully
[    4.242972] FIMC3 registered successfully
[    4.246840] S5P TVOUT Driver v3.0 (c) 2010 Samsung Electronics
[    4.320043] dm9000 dm9000: eth0: link up, 100Mbps, full-duplex, lpa 0xCDE1
[    4.340121] IP-Config: Complete:
[    4.341874]      device=eth0, addr=192.168.2.2, mask=255.255.255.0, gw=255.255.255.255,
[    4.349600]      host=192.168.2.2, domain=, nis-domain=(none),
[    4.355429]      bootserver=192.168.2.158, rootserver=192.168.2.158, rootpath=
[    4.382548] VFS: Mounted root (nfs filesystem) on device 0:11.
[    4.387097] Freeing init memory: 824K
[    4.935991] ioctl led done!
[   11.617648] rtusb init rt2870new --->
[   11.621177] usbcore: registered new interface driver rt2870new
[   15.647930] usbcore: deregistering interface driver rt2870new
[   15.653269] <--- rtusb exit
rmmod: module 'mt7601Usta' not found
[   23.897342] rtusb init rt2870 --->
[   23.900839] usbcore: registered new interface driver rt2870
ifconfig: SIOCGIFFLAGS: No such device
ifconfig: wlan0: error fetching interface information: Device not found
[01/Jan/2012:00:12:09 +0000] boa: server version Boa/0.94.13
[01/Jan/2012:00:12:09 +0000] boa: server built Aug 12 2014 at 10:26:12.
[01/Jan/2012:00:12:09 +0000] boa: starting server pid=999, port 80
msgqueue build success
open sqlite ok
table env already exists,so open it ok!
table collect_env already exist,so open it ok!
sqlite_CreateLinklist malloc 380 bytes
sqlite linklist build success
uart_send_cache linklist build success
open serial failed!: No such file or directory
failed to open USB_to_UART: No such file or directory
pthread_mutex_init over
pthread_cond_init over
pthread_sqlite OK
pthread_analysis [   37.693288] hey! led opened 
[   37.696285] hmm! led closed
is ok
pthread_uart_cmd is OK 
open /dev/ttyUSB0 error: No such file or directory
Cann't open /dev/buzzer
pthread_mutex_destroy over
pthread_cond_destroy over
msgctl cancel over
pthread_cancel over
All quit

Please press Enter to activate this console. 
[root@farsight /]#print
-/bin/sh: print: not found
[root@farsight /]#ls
bin           linuxrc       proc          tmp           www
dev           max_clk:      root          user.db
etc           mjpg          sbin          usr
farm_manage   mnt           smartfarm.db  var
lib           modules       sys           warehouse.db
[root@farsight /]#cd mjpg/
[root@farsight /mjpg]#ls
input_gspcav1.so      mjpg_streamer         output_http.so
input_testpicture.so  output_autofocus.so
input_uvc.so          output_file.so
[root@farsight /mjpg]#cd[   63.522905] failed to copy MFC F/W during init
 ..[   64.526151] CPU1: shutdown

[root@farsight /]#ls
bin           linuxrc       proc          tmp           www
dev           max_clk:      root          user.db
etc           mjpg          sbin          usr
farm_manage   mnt           smartfarm.db  var
lib           modules       sys           warehouse.db
[root@farsight /]#cd www
[root@farsight /www]#ls
cgi-bin        env2.html      images         main.html      setting2.html
control1.html  error_log      index.html     photo.html     top.html
control2.html  goods1.html    js             right.html     vedio.html
env1.html      goods2.html    left.html      setting1.html
[root@farsight /www]#cd ..
[root@farsight /]#ls
bin           linuxrc       proc          tmp           www
dev           max_clk:      root          user.db
etc           mjpg          sbin          usr
farm_manage   mnt           smartfarm.db  var
lib           modules       sys           warehouse.db
[root@farsight /]#cd mnt
[root@farsight /mnt]#ls
[root@farsight /mnt]#cd ..
[root@farsight /]#ls
bin           linuxrc       proc          tmp           www
dev           max_clk:      root          user.db
etc           mjpg          sbin          usr
farm_manage   mnt           smartfarm.db  var
lib           modules       sys           warehouse.db
[root@farsight /]#cd 
[root@farsight /root]#cd 
-/bin/sh: cd: can't cd to root
[root@farsight /root]#cd ..
[root@farsight /]#