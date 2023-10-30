//   write a progam for brightness level using systm call.

// header file
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define BUF 24000

int main()
{
     int openfd, newfile,a;
     ssize_t readfd, writefd;
     int buf[BUF];
     char brit[] = "Laptop brightness level : ";

     // opening file
     // int open(const char *pathname, int flags);
     openfd = open("/sys/class/backlight/intel_backlight/brightness", O_RDONLY);
     
     // read file content
     // ssize_t read(int fd, void *buf, size_t count);
     readfd = read(openfd, buf, 100);

     // write in terminal brightness
     // ssize_t write(int fd, const void *buf, size_t count);
     write(1, brit, sizeof(brit));

     // writeing inside of sample file
     // ssize_t write(int fd, const void *buf, size_t count);
     writefd = write(1, buf, 100);   // write  1 menas STDOUT filedescriptor value print
      
     close(openfd);
}
