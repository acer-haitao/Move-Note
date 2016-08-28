1��JPEG 
 tar xvf jpegsrc.v8b.tar.gz
$ cd jpeg-8b
linux@ubuntu:~/Farsight/jpeg-8b$ ./configure --prefix=/home/linux/Farsight/jpeg --host=arm-none-linux-gnueabi
--prefix ����ָ�����������İ�װ·��

linux@ubuntu:~/Farsight/jpeg-8b$ make
make[1]: Leaving directory `/home/linux/Farsight/jpeg-8b'



linux@ubuntu:~/Farsight/jpeg-8b$ make install

re/man/man1"
 /usr/bin/install -c -m 644 cjpeg.1 djpeg.1 jpegtran.1 rdjpgcom.1 wrjpgcom.1 '/home/linux/Farsight/jpeg/share/man/man1'
make[1]: Leaving directory `/home/linux/Farsight/jpeg-8b'

d) ������õĿ��ļ����������ļ�ϵͳ��
linux@ubuntu:~/Farsight/jpeg$ cd lib/
linux@ubuntu:~/Farsight/jpeg/lib$ ls
libjpeg.a  libjpeg.la  libjpeg.so  libjpeg.so.8  libjpeg.so.8.0.2
// cp /jpeg/lib/* /source/rootfs/lib


2 �� mjpg-streamer  ��ֲ
a) ���� mjpg-streamer Դ�룺
ͨ�������ַ���� mjpg-streamer Դ�����
http://sourceforge.net/projects/mjpg-streamer/
b) ���� mjpg-streamer Դ�룺
�޸� Makefile  �ļ�
�޸Ķ���Ŀ¼��������Ŀ¼�е� Makefile �ļ���
�޸�
CC = gcc
Ϊ
CC = arm-none-linux-gnueabi-gcc

�ٴ��޸� plugin/input_uvc/Makefile  �ļ�
CC = arm-none-linux-gnueabi-gcc

OTHER_HEADERS = ../../mjpg_streamer.h ../../utils.h ../output.h ../input.h

CFLAGS += -O2 -DLINUX -D_GNU_SOURCE -Wall -shared -fPIC
#CFLAGS += -DDEBUG
LFLAGS += -lpthread -ldl
�ڵ� 16 ����ӱ���ʱ��Ҫ�� jpeg ͷ�ļ���·��

CFLAGS += -l /home/linux/Farsight/jpeg/include

�ڵ� 24 ����ӱ���ʱ��Ҫ�� jpeg ���·��
�޸�
input_uvc.so: $(OTHER_HEADERS) input_uvc.c v4l2uvc.lo jpeg_utils.lo dynctrl.lo
$(CC) $(CFLAGS) -ljpeg -L /home/linux/Farsight/jpeg/lib -


o $@ input_uvc.c v4l2uvc.lo jpeg_utils.lo dynctrl.lo

�޸� plugins/input_uvc/v4l2uvc.c
���Ŀ¼��֧�� uvc ����ͷ�ģ������ǵ� FS4412 ������ͷʹ�õ� samsung �� FIMC
�ܹ���������Ӧ�ó�����ʱ�е�ϸ΢���������Ҫ�����Щ�����һЩ�Ķ�:



�޸� static int init_v4l2(struct vdIn *vd)����
��
/*
   * set format in
   */
  int input = 0;
  ret = ioctl(vd->fd, VIDIOC_S_INPUT, &input);
  if (ret < 0)
  {
	  perror("Unable to set Input");
	  goto fatal;
  }


  ��
/ *
* set framerate
*/
ǰ���
 vd->fmt.type = 0x80;
  ret = ioctl(vd->fd, VIDIOC_S_FMT, &vd->fmt);
  if (ret < 0)
  {
	  perror("Unable to set format");
	  goto fatal;
  }

ע�����´���

/*
* set framerate
*/
struct v4l2_streamparm *setfps;
setfps = (struct v4l2_streamparm *) calloc(1, sizeof(struct v4l2_streamparm));
memset(setfps, 0, sizeof(struct v4l2_streamparm));
setfps->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
setfps->parm.capture.timeperframe.numerator = 1;
setfps->parm.capture.timeperframe.denominator = vd->fps;
ret = ioctl(vd->fd, VIDIOC_S_PARM, setfps);
�޸�
vd->buf.length, PROT_READ, MAP_SHARED, vd->fd,
if (debug)
      fprintf(stderr, "length: %u offset: %u\n", vd->buf.length, vd->buf.m.offset);

    vd->mem[i] = mmap(0 /* start anywhere */ ,
                      vd->buf.length, PROT_READ |  PROT_WRITE, MAP_SHARED, vd->fd,
                      vd->buf.m.offset);

�޸� int uvcGrab(struct vdIn *vd)����

�޸�
ret = ioctl(vd->fd, VODIOC_DQBUF, &vd->buf);
if (ret < 0) {
perror(��Unable to dequeue buffer��);
goto err;
}
Ϊ
retry:
  ret = ioctl(vd->fd, VIDIOC_DQBUF, &vd->buf);
  if (ret < 0)
  {
	 usleep(10000);
	  goto fatal;
  }

�޸�
memcpy(vd->framebuffer, vd->mem[vd->buf.index], (size_t) vd->bytesused);
Ϊ
memcpy(vd->framebuffer, vd->mem[vd->buf.index], (size_t) vd->framesizeIn);


�޸� static int video_enable(struct vdIn *vd)����
��
vd->isstreaming = 1;
ǰ���
sleep(1);

d) �������򼰿⵽���ļ�ϵͳ��
$ cp *.so /source/rootfs/mjpg
$ cp mjpg-streamer /source/rootfs/bin

�� FS4412 ����������������ָ�
mjpg_streamer -i "/mjpg/input_uvc.so -y -d /dev/video0" -o "/mjpg/output_http.so -w 192.168.2.2:8080"


[root@farsight /]#mjpg_streamer -i "/mjpg/input_uvc.so -y -d /dev/video0" -o "/m
jpg/output_http.so -w 192.168.2.2:8080"
MJPG-streamer [1017]: starting application
MJPG Streamer Version.: 2.0
MJPG-streamer [1017]: MJPG Streamer Version.: 2.0

 i: Using V4L2 dev[  179.235341] s3c-fimc0: FIMC0 1 opened.
ice.: /dev/video0
MJPG-streamer [1017]: Using V4L2 device.: /dev/video0

 i: Desired Resolution: 640 x 480
MJPG-streamer [1017]: Desired Resolution: 640 x 480

 i: Frames Per Second.: 5
MJPG-streamer [1017]: Frames Per Second.: 5

 i: Format............: YUV
MJPG-streamer [1017]: F[  179.269374] OV3640 7-003c: fetching platform data
[  179.273429] OV3640 7-003c: parallel mode
[  179.277335] OV3640 7-003c: ov3640 has been probed
[  179.282418] OV3640 7-003c: ov3640_init: camera initialization start
[  179.288266] leesheen : sensor is power on
ormat............: YUV

 i: JPEG Quality......: 80
MJPG-streamer [1017]: JPEG Quality......: 80

[  179.370386] ov3640_s_mbus_fmt
[  179.371874] ov3640_s_mbus_fmt
[  179.374825] ov3640_s_mbus_fmt
 o: www-folder-pat[  179.389099] ov3640_enum_framesizes
[  179.391754] s_stream: mode = 1
[  179.394773] ov3640_s_stream: do nothing(movie on)!!
h...: 192.168.2.2:8080/
MJPG-streamer [1017]: www-folder-path...: 192.168.2.2:8080/

 o: HTTP TCP port.....: 8080
MJPG-streamer [1017]: HTTP TCP port.....: 8080

 o: username:password.: disabled
MJPG-streamer [1017]: username:password.: disabled

 o: commands..........: enabled
MJPG-streamer [1017]: commands..........: enabled

MJPG-streamer [1017]: starting input plugin
MJPG-streamer [1017]: starting output plugin: /mjpg/output_http.so (ID: 00)


������ϵ�ַ�������������ݣ�

http://192.168.2.2:8080/?action=snapshot
http://192.168.2.2:8080/?action=stream


�� 96 �� ���� void *worker_thread(void *arg) ���м������´���
 /* ��Ӵ��� */
  char buf[10]; //���ڴ�Ŵӹܵ���ȡ������
  int flags = 0; //���ձ�־��1����ʾ 11 ����Ƭ��2����ʾ 1 ����Ƭ
  int fd_com = 0; //�򿪹ܵ����ļ�������
  int stop_num = 0; //���ռ���  
  if(access("/tmp/webcom", F_OK) < 0)
  {
	  if ((mkfifo("/tmp/webcom", 0666)) < 0)
	  {
		  printf("photo fifo create failed\n");
	  }
  }


  fd_com = open("/tmp/webcom", O_RDONLY, 0666);
  if(fd_com < 0)
  {
	  perror("open the file webcom error");
  }
  
 //while( ok >= 0 && !pglobal->stop){ �����
 /* ������� */
  if (flags == 0)
  {
	  while(1)
	  {
		  read(fd_com,buf,sizeof(buf));
		  if (strncmp(buf, "danger", 6) == 0)
		  {
			  flags = 1;
			  bzero(buf, sizeof(buf));
			  break;
		  }
		  if (strncmp(buf, "one", 3) == 0)
		  {
			  flags = 2; 
			  bzero(buf, sizeof(buf));
			  break;
		  }
	  }
  }







�� if (delay > 0){
usleep(1000*delay);
}�����

stop_num++
if (flags == 1) //�ж����յ�����
{
if ( stop_num > 9)
{
stop_num = 0;
flags = 0;
}
}
else if (flags == 2)
{
stop_num = 0;
flags = 0;
}
����ֻҪ�������ܵ�/tmp/webcom д�� danger �������� 11 ����Ƭ��д�� one ��
��һ����Ƭ��
 echo one > tmp/webcom
 echo danger > tmp/webcom
 mjpg_streamer -i "/mjpg/input_uvc.so -y" -o "/mjpg/output_http.so -w /www" -o "/mjpg/output_file.so -f /pice -d 15000" &
 
 sudo find ./* -name "*.c"  |xargs cat|grep "DIRNAME"
 photoname