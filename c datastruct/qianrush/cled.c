#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
static int fd = -1;
int cledtest()
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
sleep(1);
}
close(fd);
return 0;
}