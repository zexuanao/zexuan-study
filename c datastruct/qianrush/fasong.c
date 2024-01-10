#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MYPORT 4950 // The port users will be connecting to
#define MAXBUFLEN 100
int scan(char *program,int mode);
int main(int argc, char *argv[]) 
{
    int sockfd;
    struct sockaddr_in their_addr; // Connector's address information
    struct hostent *he;
    int numbytes;

    char send_buf[MAXBUFLEN];

    /* Parameters check */
    if (argc != 2) {
        fprintf(stderr, "Usage: talker hostname\n");
        exit(1);
    }

    /* argv[1] = server IP address */
    if ((he = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    /* Setup socket */
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    their_addr.sin_family = AF_INET; // Host byte order
    their_addr.sin_port = htons(MYPORT); // Short, network byte order
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(their_addr.sin_zero), '\0', 8); // Zero the rest of the struct
    int exit_flag = 0;
    while (!exit_flag) {
        char program[MAXBUFLEN];
        int mode=0;
        printf("Menu  :\n");
        printf("gpio  :GPIO debugging\n");
        printf("seg   :LED debugging\n");
        printf("led   :Running LED debugging\n");
        printf("step  :Stepper motor debugging\n");
        printf("matrix:Matrixled debugging\n");
        printf("pwm   :Pwm debugging\n");
        printf("all   :all programs together\n");
        printf("Enter program name (gpio,led,seg,step,matrix,pwm,all) and mode(or exit to quit):\n");
        scanf("%s", program);
    
        if (strcmp(program, "exit") == 0) 
        {
        exit_flag = 1;  // 如果用户输入'exit'，则设置退出标志并退出循环
        } 
        else
        scanint(&mode);

        // 验证输入是否有效
            while (!scan(program, mode)) 
            {
                printf("please enter program and mode again!\n");
                // 清空输入缓冲区，以便下一次重新输入
                scanf("%s", program);
                if (strcmp(program, "exit") == 0) 
                {
                exit_flag = 1;  // 如果用户输入'exit'，则设置退出标志并退出循环
                } 
                else
                scanint(&mode);
            }
        sprintf(send_buf, "%s %d", program, mode);
        if (strcmp(program, "exit") )
        {
        printf("you are in program %s and mode %d now!\n",program,mode);
        }
        if ((numbytes = sendto(sockfd, send_buf, strlen(send_buf), 0,
        (struct sockaddr *)&their_addr, sizeof(struct sockaddr))) == -1) 
                {
                    perror("sendto");
                    exit(1);
                }
        
        
        }

    close(sockfd);
    return 0;
}
int scan(char *program,int mode)
{
    if (strcmp(program, "gpio") == 0 ) {
        if(mode<0||mode>4)
        {
            printf("gpio's mode needs in 0-4\n");
            return 0;
        }
        return 1;
    } 
    else if (strcmp(program, "seg") == 0 ) {
        if(mode<1||mode>9)
        {
            printf("seg's mode needs in 1-9\n");
            return 0;
        }
        return 1;
    } 
    else if (strcmp(program, "fangwei") == 0 ) {
        if(mode<1||mode>9)
        {
            printf("fangwei's mode needs in 1-9\n");
            return 0;
        }
        return 1;
    } 
    else if (strcmp(program, "led") == 0 ) {
        if(mode<=0)
        {
            printf("led's mode needs greater than 0 ");
            return 0;
        }
        return 1;
    } 
    else if (strcmp(program, "step") == 0 ) {
        if(mode<=0)
        {
            printf("step's mode needs greater than 0 ");
            return 0;
        }
        return 1;
    } 
    else if (strcmp(program, "matrix") == 0 ) {
       if(mode<1||mode >8)
        {
            printf("matrix's mode needs in 1-8 ");
            return 0;
        }
       return 1; 
    } 
    else if (strcmp(program, "pwm") == 0 ) {
        if(mode<=0)
        {
            printf("pwm's mode needs greater than 0 ");
            return 0;
        }
        return 1;
    } 
    else if (strcmp(program, "exit") == 0) {
        return 1;

    }
    else if (strcmp(program, "all") == 0 ) {
        if(mode<=0)
        {
            printf("all's mode needs greater than 0 ");
            return 0;
        }
        return 1;
    }  
    else {
        printf("Invalid program.\n");
        return 0;
    }
}
int scanint(int* input)
{
	while (scanf("%d", input) == 0 || getchar() != '\n')
	{
		printf("please input int\n");
		while (getchar() != '\n');
	}
	return 1;
}