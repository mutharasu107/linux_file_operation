// write a program to split a file into 2 half. 

// header file
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <error.h>
#include <stdio.h>
#define BUF 100000

// main program
int main(int argc, char *argv[])
{
     int openfd, count=0,count1 = 0, div, creatfd, creatfd1;
     ssize_t readfd, readfd1;
     char buf[BUF]; 
     char buf1[BUF];
     int bytes;
     off_t set;

// open file
     // int open(const char *pathname, int flags);
     openfd = open( argv[1], O_RDONLY);

// read file content
     //  ssize_t read(int fd, void *buf, size_t count);
     readfd = read( openfd, buf, sizeof(buf));

// create first file
     // int creat(const char *pathname, mode_t mode);
     creatfd = creat(argv[2], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH );

// create second file
     // int creat(const char *pathname, mode_t mode);
     creatfd1 = creat(argv[3], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH );

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
// write file in to first half
    // ssize_t write(int fd, const void *buf, size_t count);
    write( creatfd, buf, bytes);
    
    // off_t lseek(int fd, off_t offset, int whence);
    set = lseek( openfd, bytes, SEEK_SET);

    //  ssize_t read(int fd, void *buf, size_t count);
    readfd1 = read( openfd, buf1, BUF);

// write file in to second half
    // ssize_t write(int fd, const void *buf, size_t count);
    write( creatfd1, buf1, readfd1);

// close filedescripter
     close(openfd);
     close(readfd);
     close(readfd1);
     close(creatfd);
     close(creatfd1);
}
