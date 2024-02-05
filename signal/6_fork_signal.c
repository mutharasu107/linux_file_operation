#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <wait.h>
 
void s_int()
{
        write(STDOUT_FILENO,"I got signal from interrupt\n",27);
        pid_t pid;
        pid = fork();
        if(pid == -1)
        {
                printf("error creating fork()\n");       
        }
        else if(pid == 0)
        {
                printf("i am child process\n");
                execl("/bin/ls", "/bin/ls", "-l", "-i", NULL);
        }
        else if(pid > 0)
        {
                printf("parent process\n");
                sleep(5);       
        }
}

int main()
{
        signal(SIGINT,s_int);
        pid_t pid;
        
        pid=fork();

        if(pid == -1)
        {
                printf("error creating erroed\n");       
        }

        else if(pid == 0)       
        {
                printf("it is child process\n");
                execl("/bin/ls", "/bin/ls", "-l", NULL);
        }

        else if(pid > 0)
        {       
                printf("it is parent processs\n");
                wait(NULL);
        }
       
        while(1)
        {
                printf("school of linux\n");
                sleep(1);
        }
}
