#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

void s_child()
{
        write(STDOUT_FILENO,"I got signal from child processor\n",34);
}

int main()
{
        pid_t pid;

        pid = fork();

        if(pid == -1)
        {
                printf("error creating from fork()\n"); 
        }

        else if(pid == 0)
        {
                signal(SIGCHLD,s_child);
        }

        else if (pid > 0)
        {
                printf("it is parent process\n");       
        }

        while(1)
        {
                printf("school of linux\n");
                sleep(3);
        }
}
