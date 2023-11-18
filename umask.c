#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

#define PERMISION S_IRWXU|S_IRWXG|S_IROTH

int main(int arguc, char *arguv[])
{
    int r_mkdir;
     mode_t mode, mkdir_ret, old_mask, new_mask;

     mode = PERMISION;
     new_mask = 022;

     old_mask = umask(0);
     printf("Old umask : %o\n",old_mask);

     old_mask = umask(new_mask);
     printf("after changed umask : %o\n",old_mask);
     
    // int mkdir(const char *pathname, mode_t mode);
    r_mkdir = mkdir(arguv[1], new_mask);

    if(r_mkdir == 0) 
    {
        perror("mkdir() : ");
    }
    else if (r_mkdir == -1)
    {
        perror("mkdir() : ");
    }
}
