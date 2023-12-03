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
   off_t sek, sek1;

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
   
   // ssize_t pread(int fd, void *buf, size_t count, off_t offset);
   readbyte = pread( openfd, buf, 20, 0);
   if(readbyte < 0)
   {
   	perror("Error read byte\n");
   	close(openfd);
   	exit(-3);
   }

   printf("read 20 bytes in openfd file descriptor : %s\n", buf);
  
   //  off_t lseek(int fd, off_t offset, int whence);
   sek = lseek( openfd, 20, SEEK_CUR);
   if(sek < 0)
   {
      perror("Error lseek reposition\n");
      close(openfd);
      exit(-5);
   }
   printf("current fileposition : %ld\n", sek);

   //int dup2(int oldfd, int newfd);
   duplicate = dup2(openfd, 10);
   if(duplicate < 0)
   {
   	perror("Error opening duplicate file\n");
   	close(openfd);
   	exit(-4);
   }

   printf("%d\n", duplicate);
   // ssize_t pread(int fd, void *buf, size_t count, off_t offset);
   readbyte1 = pread( duplicate, buf1, 20, 0 );
   if(readbyte1 < 0)
   {
   	perror("Error read byte\n");
   	close(openfd);
   	exit(-3);
   }
   printf("read 20 bytes from duplicate file descriptor : %s\n", buf1);
   
   //  off_t lseek(int fd, off_t offset, int whence);
   sek1 = lseek( duplicate, 20, SEEK_CUR);
   if(sek < 0)
   {
      perror("Error lseek reposition\n");
      close(openfd);
      exit(-5);
   }
   printf("current fileposition : %ld\n", sek1);
   exit(0);
}
