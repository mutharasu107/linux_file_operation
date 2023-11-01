// write a program to take the line numbers which are multiples of 10.

// header files
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF 100000

// main program 
int main(int argc, char *argv[])
{
     int openfd, creatfd, a, d=1, count, count1, addbyte=0;
     ssize_t readfd, readfd1;
     char buf[BUF];
     char buf1[BUF];
     int bytes, j=0, bytes2;
     off_t set;

// open argv[1] in text file
     // int open(const char *pathname, int flags);
     openfd = open( argv[1], O_RDONLY );
     
// read file in to opeingfd and store in to buf
     //  ssize_t read(int fd, void *buf, size_t count);
     readfd = read( openfd, buf, BUF);

// create a new file in to write the vlues
     // int creat(const char *pathname, mode_t mode);
     creatfd = creat( argv[3], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
     
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
// using lseek set to the file offset is set to offset bytes.
               // off_t lseek(int fd, off_t offset, int whence);
               lseek( openfd, bytes, SEEK_SET);
               
// read the open text file file and store in to the buf1
               //  ssize_t read(int fd, void *buf, size_t count);
               readfd1 = read( openfd, buf1, BUF);

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
               write( creatfd, buf1, bytes2);

               addbyte = addbyte + bytes2;

// using lseek set to the file offset is set to offset bytes.
               // off_t lseek(int fd, off_t offset, int whence);
               lseek( creatfd, addbyte, SEEK_SET);

               bytes2 = 0;    // ones writing the lines means bytes2 valu 0 staring from 0
               d++;
          }
     }
}
