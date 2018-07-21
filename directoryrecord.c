

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])   //  command line arguments
{
if(argc!=5)
{
   printf("Arguments passed through command line " \
          "not equal to 5");
   return 1;
}

   printf("\n Program name  : %s \n", argv[0]);
   printf("1st arg  : %s \n", argv[1]);
   printf("2nd arg  : %s \n", argv[2]);
   printf("3rd arg  : %s \n", argv[3]);
   printf("4th arg  : %s \n", argv[4]);
   printf("5th arg  : %s \n", argv[5]);

return 0;
}
void printDirectoryHistory(){

  
}

/*
void get_popen()
    FILE *pf;
    char command[20];
    char data[512];

    // Execute a process listing
    sprintf(command, "ps aux wwwf");

    // Setup our pipe for reading and execute our command.
    pf = popen(command,"r");

    // Error handling

    // Get the data from the process execution
    fgets(data, 512 , pf);

    // the data is now in 'data'

    if (pclose(pf) != 0)
        fprintf(stderr," Error: Failed to close command stream \n");

    return;
}
*/
