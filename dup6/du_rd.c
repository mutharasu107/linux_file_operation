/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 05/12/2023                                                                               */
/*   File name      : du_rd.c                                                                                  */
/*   Description    : read 20 bytes using pread(),  and print 20 bytes with file position using lseek()        */
/***************************************************************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF 20

int main(int argc, char *argv[])
{
   int open_fd, dupli;
   ssize_t read_size, read_size1;
   off_t sek, sek1;
   char buf[BUF];
   char buf1[BUF];

   if( argc < 2 )
   {
      fprintf(stdout, "pleace attached any text file\n");
      exit(-2);
   }
   
   // int open(const char *pathname, int flags);
   open_fd = open( argv[1], O_RDONLY );
   if( open_fd < 0 )
   {
      perror("ope: Error opening a file\n");
      exit(-1);
   }
   
   // ssize_t pread(int fd, void *buf, size_t count, off_t offset);
   read_size = pread( open_fd, buf, 20, 0 );
   if( read_size < 0 )
   {
      perror("pread: Error reading a file descriptor\n");
      close(open_fd);
      exit(-3);
   }
   printf("read first time 20 bytes from text file : %s\n", buf);

   //  off_t lseek(int fd, off_t offset, int whence);
   sek = lseek( open_fd, 20, SEEK_CUR);
   if(sek < 0)
   {
      perror("Error lseek reposition\n");
      close(open_fd);
      exit(-5);
   }
   printf("first time fileposition : %ld\n", sek);
   
   // int dup2(int oldfd, int newfd);
   dupli = dup2( open_fd, 10 );
   if( dupli < 0 )
   {
      perror("dup2 : Error creating unused fd\n");
      close(open_fd);
      exit(-6);
   }

   // ssize_t pread(int fd, void *buf, size_t count, off_t offset);
   read_size1 = pread( dupli, buf1, 20, 0 );
   if( read_size1 < 0 )
   {
      perror("pread: Error reading a file descriptor\n");
      close(open_fd);
      exit(-3);
   }
   printf("read second 20 bytes from text file : %s\n", buf1);

   //  off_t lseek(int fd, off_t offset, int whence);
   sek1 = lseek( open_fd, 20, SEEK_CUR);
   if(sek1 < 0)
   {
      perror("Error lseek reposition\n");
      close(open_fd);
      exit(-5);
   }
   printf("second time fileposition : %ld\n", sek1);

}
