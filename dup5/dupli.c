/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 04/12/2023                                                                               */
/*   File name      : dupli.c                                                                                  */
/*   Description    : call dup() pread using                                                                   */
/***************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF 20

int main(int argc, char *argv[])
{
   int fd, du;
   off_t sek, sek1;
   ssize_t read_bytes, read_bytes2;
   char buf[BUF];
   char buf1[BUF];

   if( argc < 2 )
   {
      printf("pleace pass some txt file\n");
      exit(-7);
   }

   // int open(const char *pathname, int flags);
   fd = open( argv[1], O_RDONLY );
   if( fd < 0 )
   {
      perror("open : Error opening a file");
      exit(-1);
   }
   
   // ssize_t pread(int fd, void *buf, size_t count, off_t offset);
   read_bytes = pread( fd, buf, 20, 0 );
   if( read_bytes < 0 )
   {
      perror("read : Error reading bytes");
      close(fd);
      exit(-2);
   }
   printf("first time read 20 bytes : %s\n", buf);

   //  off_t lseek(int fd, off_t offset, int whence);
   sek = lseek( fd, 20, SEEK_CUR);
   if(sek < 0)
   {
      perror("Error lseek reposition\n");
      close(fd);
      exit(-5);
   }
   printf("first time fileposition : %ld\n", sek);

   //  int dup(int oldfd);
   du = dup(fd);
   if( du < 0 )
   {
      perror("dup : error duplicat file descriptor");
      close(fd);
      exit(-4);
   }

   // ssize_t pread(int fd, void *buf, size_t count, off_t offset);
   read_bytes2 = pread( du, buf1, 20, 0 );
   if( read_bytes2 < 0 )
   {
      perror("read : Error second time reading file");
      close(fd);
      exit(-2);
   }
   printf("second time read 20 bytes : %s\n", buf1);

   //  off_t lseek(int fd, off_t offset, int whence);
   sek1 = lseek( fd, 20, SEEK_CUR);
   if(sek1 < 0)
   {
      perror("Error lseek reposition\n");
      close(fd);
      exit(-5);
   }
   printf("second tine fileposition : %ld\n", sek1);

   close(fd);
   close(du);

   exit(0);
}
