// write a program to merge 2 files

// header file
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#define BUF 10000

// main program start
int main(int argc, char *argv[])
{
     int openfd, openfd1, creatfd;
     ssize_t readfd, readfd1;
     char buf[BUF];
     char buf1[BUF];
     off_t lseekfd;

// open first file
     // int open(const char *pathname, int flags);
     openfd = open( argv[1], O_RDONLY );

// read first file
     // ssize_t read(int fd, void *buf, size_t count);
     readfd = read( openfd, buf, BUF);

// open second file
     // int open(const char *pathname, int flags);
     openfd1 = open( argv[2], O_RDONLY );
     
// read second file
     // ssize_t read(int fd, void *buf, size_t count);
     readfd1 = read( openfd1, buf1, BUF);

// create new file merge 2 file
     // int creat(const char *pathname, mode_t mode);
     creatfd = creat( argv[3], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

// write first file content in merge file
     // ssize_t write(int fd, const void *buf, size_t count);
     write( creatfd, buf, readfd);

// lseek using cursor setting program end
     // off_t lseek(int fd, off_t offset, int whence);
     lseekfd = lseek( creatfd, 0, SEEK_END);

// write second file in end of merge file
     // ssize_t write(int fd, const void *buf, size_t count);
     write( creatfd, buf1, readfd1);

// close all file descriptor
     close(openfd);
     close(openfd1);
     close(readfd);
     close(readfd);
     close(creatfd);
     close(openfd);
}

/*
     this program using totally three argument vector 3;
      
     first argv[1] is first txt file name
     second argv[2] is second txt file name
     thrid argv[3] merge file name
*/
