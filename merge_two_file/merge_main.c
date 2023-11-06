// write a program to merge 2 files
/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 1/11/2023                                                                                */
/*   File name      : merge_main.c                                                                             */
/*   Description    : write a program to merge 2 files in to one file                                          */
/***************************************************************************************************************/

// header file inclusion
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#define BUF 10000

// main file start
int main(int argc, char *argv[])
{
     int openfd, openfd1, creatfd;
     ssize_t readfd, readfd1;
     ssize_t writefd, writefd1;
     char buf[BUF];
     char buf1[BUF];
     off_t lseekfd;

// If argv[1] that text file there in this directory means open the text file and that text file read only.
// In my prorgam i am using first argv[1] text file name is merge1.txt.
     // int open(const char *pathname, int flags);
     openfd = open( argv[1], O_RDONLY );
     if(openfd == -1)
     {
          perror("Error opening a first txt file");
          exit(1);
     }

// read the first txt file content using read system call if a any problem in reading file that time close the before opening file and exit to the program. 
     // ssize_t read(int fd, void *buf, size_t count);
     readfd = read( openfd, buf, BUF);
     if(readfd == -1)
     {
          perror("Error while I am reading first txt file");
          close(openfd);
          exit(2);
     }

// If argv[2] that text file there in this directory means open the text file and that text file read only.
// In my prorgam i am using second argv[2] text file name is merge2.txt.
     // int open(const char *pathname, int flags);
     openfd1 = open( argv[2], O_RDONLY );
     if(openfd1 == -1)
     {
          perror("Error opening a second txt file");
          close(openfd);
          close(readfd);
          exit(3);
     }
     
// read the second txt file content using read system call, if a any problem in reading file that time close the before opening file and exit to the program. 
// read second file
     // ssize_t read(int fd, void *buf, size_t count);
     readfd1 = read( openfd1, buf1, BUF);
     if(readfd1 == -1)
     {
          perror("Error while I am reading second txt file");
          close(openfd);
          close(openfd1);
          close(readfd);
          close(readfd1);
          exit(4);
     }

// create new file i am giveing name is merge2file, It's given in argv[3].
     // int creat(const char *pathname, mode_t mode);
     creatfd = creat( argv[3], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
     if(creatfd == -1)
     {
          perror("Error while I am createing a new file ");
          close(openfd);
          close(openfd1);
          close(readfd);
          close(readfd1);
          exit(5);
     }

// write first file content in merge2file
     // ssize_t write(int fd, const void *buf, size_t count);
     writefd = write( creatfd, buf, readfd);
     if(writefd == -1)
     {
          perror("Error while I am write first time");
          close(openfd);
          close(openfd1);
          close(readfd);
          close(readfd1);
          close(creatfd);
          exit(6);
     }

// lseek using cursor setting in end of the program in creatfd file
     // off_t lseek(int fd, off_t offset, int whence);
     lseekfd = lseek( creatfd, 0, SEEK_END);
     if(lseekfd == -1)
     {
          perror("Error while I am set cursor");
          close(creatfd);
          exit(7);
     }

// write second file content in merge2file
     // ssize_t write(int fd, const void *buf, size_t count);
     writefd1 = write( creatfd, buf1, readfd1);
     if(writefd1 == -1)
     {
          perror("Error while I am write second time");
          close(openfd);
          close(openfd1);
          close(readfd);
          close(readfd1);
          close(writefd);
          exit(8);
     }

// close all file descriptor
     close(openfd);
     close(openfd1);
     close(readfd);
     close(readfd1);
     close(creatfd);
     close(writefd);
     close(writefd1);
     exit(0);
}

/*
     this program using totally three argument vector 3;
      
     first argv[1] is first txt file name
     second argv[2] is second txt file name
     thrid argv[3] merge file name
*/
