// write a program to split a file into 2 half. 
/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 1/11/2023                                                                                */
/*   File name      : split.c                                                                                  */
/*   Description    : write a program to split a file into 2 half                                              */
/***************************************************************************************************************/

// header file inclusion
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#define BUF 100000

// main file
int main(int argc, char *argv[])
{
     int openfd, count=0,count1 = 0, div, creatfd, creatfd1;
     ssize_t readfd, readfd1, writefd, writefd1;
     char buf[BUF]; 
     char buf1[BUF];
     int bytes;
     off_t set;

// If argv[1] that text file there in this directory means open the text file and that text file read only.
// In my prorgam i am using first argv[1] text file name is git_command_history.txt.
     // int open(const char *pathname, int flags);
     openfd = open( argv[1], O_RDONLY);
     if(openfd == -1)
     {
          perror("open()");
          exit(1);
     }

// read the txt file content using read system call if a any problem in reading file that time close the before opening file and exit to the program. 
     //  ssize_t read(int fd, void *buf, size_t count);
     readfd = read( openfd, buf, sizeof(buf));
     if(readfd == -1)
     {
          perror("read()");
          close(openfd);
          exit(1);
     }

// create a first new file i am giveing name is file1.txt, It's given in argv[2].
     // int creat(const char *pathname, mode_t mode);
     creatfd = creat(argv[2], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH );
     if(creatfd == -1)
     {
          close(openfd);
          close(readfd);
          exit(1);
     }
// create a second new file i am giveing name is file2.txt, It's given in argv[3].
     // int creat(const char *pathname, mode_t mode);
     creatfd1 = creat(argv[3], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH );
     if(creatfd1 == -1)
     {
          close(openfd);
          close(readfd);
          close(creatfd);
          exit(1);
     }

// if readfd file descriptor value is less thanor equal to zero means exqute the program
     if(readfd >= 0)
     {
          for(int i=0; i<readfd; i++)
          {
               if(buf[i] == 10)    // 10 decimal number is new line ascci value
               {
                    count++;  // frind totally how many lines there in text file
               }
          }

          div = count/2;      // divide in to 2 half of text file

          for(int j=0; j<readfd; j++)
          {
               bytes++;       // count how many bytes is there in txt file
               if(buf[j] == 10)
               {
                    count1++;
               }
               if(count1 == div)   // when count1 and divide to first half of last line maching that time exit the program 
               {
                    break;
               }
          }
          
          // write first half of content in to creafd(file1.txt)
          // ssize_t write(int fd, const void *buf, size_t count);
          writefd = write( creatfd, buf, bytes);
          if(writefd == -1)
          {
               perror("write()");
               close(openfd);
               close(readfd);
               close(creatfd);
               close(creatfd1);
               exit(1);
          }

          // using lseek move the cursor in to how many bytes read and write befor and set to the cursor on next byte.
          // off_t lseek(int fd, off_t offset, int whence);
          set = lseek( openfd, bytes, SEEK_SET);
          if(set == -1)
          {
                perror("lssek()");
                close(openfd);
                exit(1);
          }

          // read the second half content and store in to the buf1[];
          //  ssize_t read(int fd, void *buf, size_t count);
          readfd1 = read( openfd, buf1, BUF);
          if(readfd1  == -1)
          {
               perror("read()");
               close(openfd);
               close(readfd);
               close(creatfd);
               close(creatfd1);
               close(set);
               exit(1);
          }

          // write second half of content in to creafd1(file2.txt)
          // ssize_t write(int fd, const void *buf, size_t count);
          writefd1 = write( creatfd1, buf1, readfd1);
          if(writefd1 == -1)
          {
               perror("write()");
               close(openfd);
               close(readfd);
               close(readfd1);
               close(creatfd);
               close(creatfd1);
               close(set);
               exit(1);
          }
     }
     // close filedescripter
     close(openfd);
     close(readfd);
     close(readfd1);
     close(creatfd);
     close(creatfd1);
     close(writefd);
     close(writefd1);
     close(set);
     exit(1);
}
