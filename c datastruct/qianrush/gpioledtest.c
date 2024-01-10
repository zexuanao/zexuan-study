#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
static int fd = -1;
int gpioledtest()
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
while(1)
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