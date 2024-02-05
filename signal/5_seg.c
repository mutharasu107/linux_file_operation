#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

void s_int()
{
        write(STDOUT_FILENO,"I got signal form interrupt\n",24);
        execl("/bin/ls", "/bin/ls", "-l", NULL);
}

int main()
{
        signal(SIGINT,s_int);
        
        while(1)
        {
                printf("school of linux\n");
                sleep(1);
        }
}
