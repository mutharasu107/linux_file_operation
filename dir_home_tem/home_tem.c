#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1000
int main()
{
   int ret_val = EXIT_SUCCESS;
   int creatfd, creatfd1;
   int dir1, dir2,openfd, dir4, dir5, dir3, openfd1;
   ssize_t readfd, readfd1;
   const char *subdir = "Documents";
   char buf[1000];
   char buf1[1000];

   //int mkdir(const char *pathname, mode_t mode);
   dir1 = mkdir("home", 0775);
   if(dir1 == -1)
   {
      ret_val=errno;
      perror("Error all ready Document directory is there\n");
      exit(ret_val);
   }

   dir1 = mkdir("Downloads", 0775);
   if(dir2 == -1)
   {
      ret_val=errno;
      perror("Error all ready Downloads directory is there\n");
      exit(ret_val);
   }
   
   dir3 = mkdir("Music", 0775);
   if(dir3 == -1)
   {
      ret_val=errno;
      perror("Error all ready Music directory is there\n");
      exit(ret_val);
   }
   
   dir4 = mkdir("Pictures", 0775);
   if(dir4 == -1)
   {
      ret_val=errno;
      perror("Error all ready Pictures directory is there\n");
      exit(ret_val);
   }
   
   dir5 = mkdir("Videos", 0775);
   if(dir5 == -1)
   {
      ret_val=errno;
      perror("Error all ready Videos directory is there\n");
      exit(ret_val);
   }

   openfd = open("/home/mutharasu/.bashrc", O_RDONLY);
   if(openfd == -1)
   {
      ret_val = errno;
      perror("Error opening file");
      goto close_exit;
   }

   openfd1 = open("/home/mutharasu/.vimrc", O_RDONLY);
   if(openfd == -1)
   {
      ret_val = errno;
      perror("Error opening file");
      goto close_exit;
   }
   

   // int creat(const char *pathname, mode_t mode);
   creatfd = creat(".bashrc", 0644);
   if(creatfd < 0)
   {
      perror("create first file error\n");
      goto close_fd; 
   }

   // int creat(const char *pathname, mode_t mode);
   creatfd1 = creat(".vimrc", 0644);
   if(creatfd1 < 0)
   {
      perror("create first file error\n");
      goto close_fd1; 
   }
   
   readfd = read(openfd, buf, BUF_SIZE);
   if(readfd == -1)
   {
      ret_val = errno;
      perror("Error reading file");
      goto close_fd;
   }
   
   readfd1 = read(openfd1, buf1, BUF_SIZE);
   if(readfd1 == -1)
   {
      ret_val = errno;
      perror("Error reading file");
      goto close_fd1;
   }

   // ssize_t write(int fd, const void *buf, size_t count);
   write(creatfd, buf, readfd);
       
   write(creatfd1, buf, readfd1);
close_exit:
   exit(-ret_val);
close_fd:
   close(openfd);
close_fd1:
   close(openfd1);
}
