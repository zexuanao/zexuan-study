#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
static int fd = -1;
unsigned char x[]=
{
    0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08
};
int main()
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
for(i= 1;i<257;i*=2)
{
ioctl(fd, 0, i);
sleep(1);
}
close(fd);
return 0;
}
