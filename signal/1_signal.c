#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

void s_stop()
{
          write(STDOUT_FILENO,"\ni got signal to stop\n",23);
}

void s_cont()
{
          write(STDOUT_FILENO,"\ni got signal to continue\n",27);
}

void s_term()
{
          write(STDOUT_FILENO,"\ni got signal to terminate\n",28);
}

void s_int()
{
         write(STDOUT_FILENO,"\ni got signal interrupt\n",24);
}

void s_invalid_memory()
{
        write(STDOUT_FILENO,"\ni got invalid memory space\n",28);
}

void s_child()
{
        write(STDOUT_FILENO,"\ni got gignal from child\n",26);
}

void s_segmentaction()
{
        write(STDOUT_FILENO,"\ni got signal from segmentaction falut\n",40);
}

int main()
{
        signal(SIGINT,s_int);
        signal(SIGSTOP,s_stop);
        signal(SIGCONT,s_cont);
        signal(SIGTERM,s_term);
        signal(SIGSEGV,s_invalid_memory);
        signal(SIGCHLD,s_child);
        signal(SIGSEGV,s_segmentaction);

        while(1)
        {
                write(STDOUT_FILENO,"\nschool of linux\n",18);
                sleep(1);
        }
}
