/*******************************************************************/
/*	Name	    : Mutharasu R				   */
/*	Date	    : 8/11/2023					   */
/*	File name   : unlink.c					   */
/*	Description : deletes  a name from the filesystem	   */
/*******************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>

int main(int argc, char *argv[])
{
   int un_link;
   int ret_val = EXIT_SUCCESS;

// first add any one text file in this directory(ex git_command_history.txt)
// argv[1] delets a name from the filesystem
   // int unlink(const char *pathname);
   un_link = unlink(argv[1]);
   if( un_link == -1 )
   {
      ret_val = errno;
      perror("No such file or directory\n");
      exit(-ret_val);
   }
}
