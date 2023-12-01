/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 01/12/2023                                                                               */
/*   File name      : dup.c                                                                                    */
/*   Description    : dup() is a system call which duplicates an fd.                                           */
/***************************************************************************************************************/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF 20

int main(int argc, char *argv[])
{
   int openfd, duplicate;
   ssize_t readbyte, readbyte1;
   char buf[BUF];
   char buf1[BUF];
   
   if(argc < 2)
   {
      // int fprintf(FILE *stream, const char *format, ...);
      fprintf(stderr, "pleace pass a file name\n");
      exit(-1);
   }
   // int open(const char *pathname, int flags);
   openfd = open(argv[1], O_RDONLY);
   if(openfd < 0)
   {
   	perror("filed to open a text file");
   	exit(-2);
   }
   
   // ssize_t read(int fd, void *buf, size_t count);
   readbyte = read( openfd, buf, 20 );
   if(readbyte < 0)
   {
   	perror("Error read byte\n");
   	close(openfd);
   	exit(-3);
   }
   printf("read 20 bytes in openfd file descriptor : %s\n", buf);

   // int dup(int oldfd);
   duplicate = dup(openfd);
   if(duplicate < 0)
   {
   	perror("Error opening duplicate file\n");
   	close(openfd);
   	exit(-4);
   }

   // ssize_t read(int fd, void *buf, size_t count);
   readbyte1 = read( duplicate, buf1, BUF );
   if(readbyte1 == -1)
   {
   	perror("Error read byte\n");
   	close(openfd);
   	exit(-3);
   }
   printf("read 20 bytes from duplicate file descriptor : %s\n", buf1);
}
