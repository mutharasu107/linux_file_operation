#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>

void s_seg()
{
        write(STDOUT_FILENO,"I got signal from segmentaion falut\n",22);
        sleep(1);
}

int main()
{
        int a=10,*ptr;
        signal(SIGSEGV,s_seg);
        ptr=&a; 
        printf("value : %p\n",ptr);
}
