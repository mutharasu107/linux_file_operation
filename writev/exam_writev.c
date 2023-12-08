/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 06/12/2023                                                                               */
/*   File name      : exam_writev.c                                                                            */
/*   Description    : Take 5 different text files  Read the contents of 5 files and write                      */
/*                    it in a new file using writev() Also print the file position                             */
/****************************************************************************************************************/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUF 55
int main(int argc, char *argv[])
{
    struct iovec gather_arr[5];
    int fd1, fd2,fd3, fd4, fd5, d_fd1, d_fd2;
    char buf1[BUF] = {'\0'};
    char buf2[BUF] = {'\0'};
    char buf3[BUF] = {'\0'};
    char buf4[BUF] = {'\0'};
    char buf5[BUF] = {'\0'};

    if(argc < 7)
    {
       sprintf("Please atteached 5 different text file"\n);
       exit(-15);
    }
    //  int open(const char *pathname, int flags);
    fd1 = open(argv[1], O_RDWR);
    if( fd1 < 0 )
    {
       perror("open : Error opening a argv[1] file\n");
       exit(-6);
    }
    printf("fd1 : %d\n",fd1);

    //  int open(const char *pathname, int flags);
    fd2	= open(argv[2], O_RDWR);
    if( fd2 < 0 )
    {
       perror("open : Error opening a argv[2] file\n");
       exit(-7);
    }
    printf("fd2 : %d\n",fd2);
    
    //  int open(const char *pathname, int flags);
    fd3 = open(argv[3], O_RDWR);
    if( fd3 < 0 )
    {
       perror("open : Error opening a arg[3] file\n");
       exit(-8);
    }
    printf("fd3 : %d\n",fd3);
    
    //  int open(const char *pathname, int flags);
    fd4 = open(argv[4], O_RDWR);
    if( fd4 < 0 )
    {
       perror("open : Error opening a argv[4] file\n");
       exit(-9);
    }
    printf("fd4 : %d\n",fd4);
    
    //  int open(const char *pathname, int flags);
    fd5 = open(argv[5], O_RDWR);
    if( fd5 < 0 )
    {
       perror("open : Error opening argv[5] file\n");
       exit(-10);
    }
    printf("fd5 : %d\n",fd5);
    
    gather_arr[0].iov_base = buf1;
    gather_arr[0].iov_len  = 5;

    gather_arr[1].iov_base = buf2;
    gather_arr[1].iov_len  = 2;

    gather_arr[2].iov_base = buf3;
    gather_arr[2].iov_len  = 8;
    
    gather_arr[3].iov_base = buf4;
    gather_arr[3].iov_len  = 3;
    
    gather_arr[4].iov_base = buf5;
    gather_arr[4].iov_len  = 6;

    // ssize_t read(int fd, void *buf, size_t count);
    ssize_t read_v1 = read(fd1, buf1, 31);
    if( read_v1 < 0 )
    {
       perror("read: error reading buf2");
       exit(-1);
       goto close_fd;
    }

    // ssize_t read(int fd, void *buf, size_t count);
    ssize_t read_v2 = read(fd2, buf2, 45);
    if( read_v2 < 0 )
    {
       perror("read: error reading buf2");
       exit(-2);
       goto close_fd;
    }

    // ssize_t read(int fd, void *buf, size_t count);
    ssize_t read_v3 = read(fd3, buf3, 42);
    if( read_v3 < 0 )
    {
       perror("read: error reading buf3");
       exit(-3);
       goto close_fd;
    }
    
    // ssize_t read(int fd, void *buf, size_t count);
    ssize_t read_v4 = read(fd4, buf4, 53);
    if( read_v4 < 0 )
    {
       perror("read: error reading buf4");
       exit(-4);
       goto close_fd;
    }
    
    // ssize_t read(int fd, void *buf, size_t count);
    ssize_t read_v5 = read(fd5, buf5, 32);
    if( read_v5 < 0 )
    {
       perror("read: error reading buf5");
       exit(-5);
       goto close_fd;
    }

    // ssize_t writev(int fd, const struct iovec *iov, int iovcnt);
    ssize_t write_v = writev( STDOUT_FILENO, gather_arr, 5 );
    if( write_v < 0 )
    {
       perror("writev: Error write in to file\n");
       exit(-11);
       goto close_fd;
    }

/*    // off_t lseek(int fd, off_t offset, int whence);
    off_t sek = lseek( fd5, fd5, SEEK_SET);
    if( sek < 0 )
    {
       perror("lseek: Error file offset\n");
       exit(-12);
    }
    printf("file position : %ld\n", sek);*/

close_fd:
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
    close(fd5);

    printf("\nbuf1 : %s\n", buf1);
    printf("buf2 : %s\n", buf2);
    printf("buf3 : %s\n", buf3);
    printf("buf4 : %s\n", buf4);
    printf("buf5 : %s\n", buf5);
    
    exit(0);
}
