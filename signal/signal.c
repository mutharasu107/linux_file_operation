#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

void s_stop()
{
                write(STDOUT_FILENO,"i got signal to stop\n",21);
}

void s_cont()
{
                write(STDOUT_FILENO,"i got signal to continue\n",25);
}

void s_term()
{
                write(STDOUT_FILENO,"i got signal to terminate\n",26);
}

void s_int()
{
                write(STDOUT_FILENO,"i got signal interrupt\n",22);
}

void s_invalid_memory()
{
                write(STDOUT_FILENO,"i got invalid memory space\n",26);
}

void main()
{
        signal(SIGINT,s_int);
        signal(SIGSTOP,s_stop);
        signal(SIGCONT,s_cont);
        signal(SIGTERM,s_term);
        signal(SIGSEGV,s_invalid_memory);
        while(1)
        {
                write(STDOUT_FILENO,"school of linux\n",16);
                sleep(1);
        }
}
