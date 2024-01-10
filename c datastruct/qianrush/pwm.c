#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
static int fd = -1;
int pwm()
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
ioctl(fd,1,NULL);
close(fd);
return 0;
}