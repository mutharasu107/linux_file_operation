// write a program to take the line numbers which are multiples of 10.
/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 2/11/2023                                                                                */
/*   File name      : multi_line_num.c                                                                         */
/*   Description    : Take line numbers which are multiples of exame 10                                        */
/***************************************************************************************************************/

// header files inclusion
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>

#define BUF 100000

// main file
int main(int argc, char *argv[])
{
     int openfd, creatfd, a, d=1, count, count1, addbyte=0;
     ssize_t readfd, readfd1, writefd;
     char buf[BUF];
     char buf1[BUF];
     int bytes, j=0, bytes2;
     off_t set, seek_set;

// If argv[1] that text file there in this directory means open the text file and that text file read only.
// In my prorgam i am using first argv[1] text file name is git_command_history.txt.
     // int open(const char *pathname, int flags);
     openfd = open( argv[1], O_RDONLY );
     if(openfd == -1)
     {
          perror("open()");
          exit(1);
     }

// read the file content in to the txt file of the openfd file.
     //  ssize_t read(int fd, void *buf, size_t count);
     readfd = read( openfd, buf, BUF );
     if(readfd == -1)
     {
          perror("read()");
          close(openfd);
          exit(1);
     }

// create a new file and write to the new valuse i am give that creat file name is sam.
     // int creat(const char *pathname, mode_t mode);
     creatfd = creat( argv[3], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
     if(creatfd == -1)
     {
          perror("creat()");
          perror(openfd);
          perror(readfd);
          close();
     }
     
// using atoi convert string in to integer which line text number printing
     // int atoi(const char *nptr);
     a = atoi(argv[2]);
     
     for(int i=0; i<readfd; i++)
     {
          bytes++;  
          if(buf[i] == 10)    // count totalley how many lines there in text file
          {
               count++;
          }
          
          j = (a * d)-1;      // a is user value d is multiply with a
          if(count == j)      // if count value and line number maching means condition true
          {

// using lseek set to the cursor in openfd file how many bytes move and set to the cursor.
               // off_t lseek(int fd, off_t offset, int whence);
               set = lseek( openfd, bytes, SEEK_SET);
               if(set == -1)
               {
                    perror("lseek()");
                    close(openfd);
                    close(readfd);
                    close(creatfd);
                    exit(1);
               }
               
// read the open text file file and store in to the buf1
               //  ssize_t read(int fd, void *buf, size_t count);
               readfd1 = read( openfd, buf1, BUF);
               if(readfd1 == -1)
               {
                    perror("read()");
                    close(openfd);
                    close(readfd);
                    close(creatfd);
                    close(set);
                    exit(1);
               }

               for(int c=0; c<readfd1; c++)
               {
                    bytes2++;
                    if(buf1[c] == 10)   // count line ending and same buf1 and new line means break the statment
                    {
                         break;
                    }
               }

// wrtie the filedescriptor in to creat new file 
               // ssize_t write(int fd, const void *buf, size_t count);
               writefd = write( creatfd, buf1, bytes2);
               if(writefd1 == -1)
               {
                    perror("write()");
                    close(openfd);
                    close(readfd);
                    close(readfd1);
                    close(creatfd);
                    close(set);
                    exit(1);
               }

               addbyte = addbyte + bytes2;

// using lseek set to the file offset is set to offset bytes.
               // off_t lseek(int fd, off_t offset, int whence);
               seek_set = lseek( creatfd, addbyte, SEEK_SET);
               if(seek_set == -1)
               {
                    perror("lseek()");
                    close(openfd);
                    close(readfd);
                    close(readfd1);
                    close(creatfd);
                    close(set);
                    close(writefd);
                    exit(1);
               }

               bytes2 = 0;    // ones writing the lines means bytes2 valu 0 staring from 0
               d++;
          }
     }
     close(openfd);
     close(readfd);
     close(readfd1);
     close(creatfd);
     close(set);
     close(seek_set);
     close(writefd);
     exit(1);
}
