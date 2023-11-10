//   write a progam for brightness level using systm call.

/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 28/10/2023                                                                               */
/*   File name      : bright.c                                                                                 */
/*   Description    : Write a progam for brightness level using systm call.                                    */
/***************************************************************************************************************/


// header file inclusion
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#define BUF 24000

// main file
int main()
{
     int openfd, newfile,a;
     ssize_t readfd, writefd;
     int buf[BUF];
     char brit[] = "Laptop brightness level : ";

// open that path of the laptop brightness level(it may be change path in my laptop this path only there in brightness file)
     // int open(const char *pathname, int flags);
     openfd = open("/sys/class/backlight/intel_backlight/brightness", O_RDONLY);
     printf("open %d\n", openfd);
     if(openfd == -1)
     {
          perror("open()");
          exit(1);
     }
     
// read file content from the openfd file descriptor
     // ssize_t read(int fd, void *buf, size_t count);
     readfd = read(openfd, buf, 100);
     printf("%ld\n", readfd);
     if(readfd == -1)
     {
          
     }

     // write in terminal brightness
     // ssize_t write(int fd, const void *buf, size_t count);
     write(1, brit, sizeof(brit));

     // writeing inside of sample file
     // ssize_t write(int fd, const void *buf, size_t count);
     writefd = write(1, buf, 100);   // write  1 menas STDOUT filedescriptor value print
     printf("%ld\n", writefd);
      
     close(openfd);
}
