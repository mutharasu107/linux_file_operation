/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 04/12/2023                                                                               */
/*   File name      : re_wr_dup.c                                                                              */
/*   Description    : call dup2() by passing fd from step 1 as old fd (fd1) and any unused fd as new fd (fd2)  */
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
   int open_fd, dup_2;
   ssize_t first_write_file, second_write_file, read_size1, read_size2;
   off_t set;
   char buf[BUF], buf1[BUF];

   if( argc < 2 )
   {
      printf("pleace pass some txt file\n");
      exit(-7);
   }
   
   // int open(const char *pathname, int flags);
   open_fd = open( argv[1], O_RDWR );
   if( open_fd < 0 )
   {
      perror("open : Error opening file");
      exit(-1);
   }

   // int dup2(int oldfd, int newfd);
   dup_2 = dup2( open_fd, 7 );
   if( dup_2 < 0 )
   {
      perror("dup2 : Error duplicate 2 file");
      close(open_fd);
      exit(-2);
   }

   // ssize_t write(int fd, const void *buf, size_t count);
   first_write_file = write( open_fd, "HI SCHOOL OF LINUX DH", 20 );
   if( first_write_file < 0)
   {
      perror("write : Error write first file");
      close(open_fd);
      exit(-3);
   }
   
   // ssize_t write(int fd, const void *buf, size_t count);
   second_write_file = write( dup_2, "hi chennai dharmapuri", 20 );
   if( second_write_file < 0)
   {
      perror("write : Error write second file");
      close(open_fd);
      exit(-3);
   }

   // off_t lseek(int fd, off_t offset, int whence);
   set = lseek( open_fd, 0, SEEK_SET);
   if( set < 0 )
   {
      perror("lseek : Error reposition file off set");
      close(open_fd);
      exit(-4);
   }

   // ssize_t read(int fd, void *buf, size_t count);
   read_size1 = read( open_fd, buf, 10 );
   if( read_size1 < 0 )
   {
      perror("read : Error first time reading fd file");
      close(open_fd);
      exit(-5);
   }
   printf("read first time open_fd : %s\n", buf);

   // ssize_t read(int fd, void *buf, size_t count);
   read_size2 = read( dup_2, buf1, 10 );
   if( read_size2 < 0 )
   {
      perror("read : Error first time reading duplicate file ");
      close(dup_2);
      exit(-6);
   }
   printf("read first time dup_2 : %s\n", buf1);

   // ssize_t read(int fd, void *buf, size_t count);
   read_size1 = read( open_fd, buf, 10 );
   if( read_size1 < 0 )
   {
      perror("read : Error read second time reading fd file ");
      close(open_fd);
      exit(-5);
   }
   printf("read second time open_fd : %s\n", buf);

   // ssize_t read(int fd, void *buf, size_t count);
   read_size2 = read( dup_2, buf1, 10 );
   if( read_size2 < 0 )
   {
      perror("read : Error read second time reading duplicate file ");
      close(dup_2);
      exit(-6);
   }
   printf("read second time dup_2 : %s\n", buf1);

   close(open_fd);
   close(dup_2);
   
   return 0;
}
