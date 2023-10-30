//   write a progam for print battery capacity using systm call.

// header file
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <sys/syscall.h>

#define BUF 50

int main()
{
     int openfd, newfile, creatfd;
     ssize_t readfd, writefd;
     char buf[BUF];
     char per[] = "Battery percentage : ";

     // opening file
     // int open(const char *pathname, int flags);
     openfd = open("/sys/class/power_supply/BAT1/capacity", O_RDONLY);
          perror("open");

     // read file content
     // ssize_t read(int fd, void *buf, size_t count);
     readfd = read(openfd, buf, 50);
          perror("read()");
     
     writefd = write(1, per, sizeof(per));   // write  1 menas STDOUT filedescriptor value print
     
     // writeing inside of sample file
     // ssize_t write(int fd, const void *buf, size_t count);
     writefd = write(1, buf, readfd);   // write  1 menas STDOUT filedescriptor value print
          perror("write()");
     
     close(openfd);
}
