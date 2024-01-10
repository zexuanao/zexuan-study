#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MYPORT 4950
#define MAXBUFLEN 100
static int fd = -1;

unsigned int xuehao[9]={
    0x2,0x0,0x8,0x2,0x1,0x0,0x6,0x3,0x4
};
int gpioledtest();
int segtest();
int main(void) {
    int sockfd;
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    int addr_len, numbytes;
    char buf[MAXBUFLEN];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(MYPORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(my_addr.sin_zero), '\0', 8);

    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    while (1) {
        addr_len = sizeof(struct sockaddr);
        if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN - 1, 0, (struct sockaddr *)&their_addr, &addr_len)) == -1) {
            perror("recvfrom");
            exit(1);
        }
        buf[numbytes] = '\0';
       char program[MAXBUFLEN];
    int mode=0;

    sscanf(buf, "%s %d", program, &mode);

    if (strcmp(program, "gpio") == 0 && mode >= 0 && mode <= 4) {
        gpioledtest(mode);//控制第几个灯亮
    } 
    else if (strcmp(program, "seg") == 0 && mode >= 1 && mode <= 9) {
        segtest(mode);//控制亮什么
    } 
    else if (strcmp(program, "fangwei") == 0 && mode >= 1 && mode <= 9) {
        fangwei(mode);//从第几个开始亮
    } 
    else if (strcmp(program, "led") == 0 && mode > 0) {
        cledtest(mode);//sleep多久
    } 
    else if (strcmp(program, "step") == 0 && mode > 0) {
        steppertest(mode);//控制转几圈
    } 
    else if (strcmp(program, "matrix") == 0 &&mode>0&& mode<=8 ) {
        matrixledtest(mode);//控制第几列亮
    } 
    else if (strcmp(program, "pwm") == 0 && mode > 0) {
        pwmtest(mode);//响几次
    } 
    else if (strcmp(program, "exit") == 0) {
        // 结束所有进程
    system("pkill jieshou");

    }
    else if(strcmp(program,"all")==0&& mode > 0)
    {
    system("/mnt/gpioledtest &");
    system("/mnt/ledtest &");
    system("/mnt/matrixledtest &");
    system("/mnt/pwmtest &");
    system("/mnt/segtest &");
    system("/mnt/steppertest &");
    sleep(mode);
    // 终止所有进程
    system("pkill gpioledtest");
    system("pkill ledtest");
    system("pkill matrixledtest");
    system("pkill pwmtest");
    system("pkill segtest");
    system("pkill steppertest");

    } 
    else {
        printf("Invalid command.\n");
    }
    }

    close(sockfd);
    return 0;
}

int gpioledtest(int mode)
{
int i=0;
fd=open("/dev/gled",O_RDWR);
if(fd<0)
{
printf("Can't open\n");
return -1;
}
else
{
printf("open OK 11%x\n", fd);
}
if(mode!=0)
{
ioctl(fd, 1, 0);
ioctl(fd, 1, 1);
ioctl(fd, 1, 2);
ioctl(fd, 1, 3);
sleep(1);
ioctl(fd, 0, mode-1);
}
else
{
ioctl(fd, 1, 0);
ioctl(fd, 1, 1);
ioctl(fd, 1, 2);
ioctl(fd, 1, 3);
sleep(1);
for(i= 0;i<4;i++)
{
ioctl(fd, 0, i);
sleep(1);
}
}
close(fd);
return 0;
}

int segtest(int mode)
{
int i=0;
fd=open("/dev/seg",O_RDWR);
if(fd<0)
{
printf("Can't open\n");
return -1;
}
else
{
printf("open OK %x\n", fd);
}
//ioctl(fd, 0, 0xf);
char hex_mode[10];
    sprintf(hex_mode, "%x", mode);
    unsigned int hex_value;
    sscanf(hex_mode, "%x", &hex_value);
    ioctl(fd, 0, hex_value); 
sleep(1);
close(fd);
return 0;
}
int fangwei(int mode)
{
int i=0;
fd=open("/dev/seg",O_RDWR);
if(fd<0)
{
printf("Can't open\n");
return -1;
}
else
{
printf("open OK %x\n", fd);
}
//ioctl(fd, 0, 0xf);
 for (i = mode-1; i < 9; i++) {
        ioctl(fd, 0,xuehao[i] );
        
        sleep(1);
    }
close(fd);
return 0;
}
int cledtest(int mode)
{
int i=0;
fd=open("/dev/cled",O_RDWR);
if(fd<0)
{
printf("Can't open\n");
return -1;
}
else
{
printf("open OK 11%x\n", fd);
}
for(i= 1;i<=256;i*=2)
{
ioctl(fd, 0, i);
sleep(mode);
}
close(fd);
return 0;
}
int steppertest(int mode)
{
int i=0,a;
fd=open("/dev/stepper",O_RDWR);
if(fd<0)
{
printf("Can't open\n");
return -1;
}
else
{
printf("open OK 11%x\n", fd);
}
for(a=0;a<5*mode;a++)
{
for(i= 0;i<4;i++)
{
ioctl(fd, 0, i);
usleep(100000);
}
}
close(fd);
return 0;
}

int pwmtest(int mode)
{
int i=0;
fd=open("/dev/pwm",O_RDWR);
if(fd<0)
{
printf("Can't open\n");
return -1;
}
else
{
printf("open OK 11%x\n", fd);
}
for(i=0;i<mode;i++)
{
    ioctl(fd,1,NULL);
    sleep(1);
}
close(fd);
return 0;
}
int matrixledtest(int mode)
{
int i=0;
fd=open("/dev/matrixled",O_RDWR);
if(fd<0)
{
printf("Can't open\n");
return -1;
}
else
{
printf("open OK 11%x\n", fd);
}
for(i= to2(mode);i<256;i*=2)
{
ioctl(fd, 0, i);
sleep(1);
}
close(fd);
return 0;
}
int to2(int yuan)
{   int i;
    int a=1;
    for(i=1;i<yuan;i++)
        a*=2;
    return a;
}