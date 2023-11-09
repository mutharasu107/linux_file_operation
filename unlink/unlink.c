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

int main()
{
   int un_link;
   const char *file = "git_command_history.txt";
   int ret_val = EXIT_SUCCESS;

// first add any one text file in this directory(ex git_command_history.txt)
   // int unlink(const char *pathname);
   un_link = unlink(file);
   if( un_link == -1 )
   {
      ret_val = errno;
      perror("No such file or directory\n");
      goto close_exit;
   }

// close exit file
close_exit:
   close(-ret_val);
}
