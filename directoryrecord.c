

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

//not including windows at the moment
//#ifdef _WIN32
//#include <Windows.h>
//#else
#include <unistd.h>
//#endif

//code from: https://embeddedartistry.com/blog/2017/4/6/circular-buffers-in-cc
typedef struct {
        char ** buffer;
        size_t head;
        size_t tail;
        size_t size; //of the buffer
} circular_buf_t;


/*got the template, will try my own implementation and modify as necessary
   https://embeddedartistry.com/blog/2017/4/6/circular-buffers-in-cc
 */
int circular_buf_reset(circular_buf_t * cbuf);
int circular_buf_put(circular_buf_t * cbuf, uint8_t data);
int circular_buf_get(circular_buf_t * cbuf, uint8_t * data);
bool circular_buf_empty(circular_buf_t cbuf);
bool circular_buf_full(circular_buf_t cbuf);

int circular_buf_reset(circular_buf_t * cbuf){
  //notice that only the pointers are being reset, because the size
  //will remain constant - "deleting" something is the same as not "knowing"
  int ret_val = -1;
  if(cbuf) {
        cbuf->head = 0;
        cbuf->tail = 0;
        ret_val = 0;
  }
  return ret_val;
}
int circular_buf_put(circular_buf_t * cbuf, char* data){
  //probably need to move all of the da data down...
  int idxToReplace = cbuf->head;
  cbuf->buffer[idxToReplace] = data;
  cbuf->head = cbuf->head + 1 % cbuf->size;;
  cbuf->tail = (cbuf->tail + 1) % cbuf->size;
  //uint_8t data;
  return 0;

}
int circular_buf_get(circular_buf_t * cbuf, char * data){

//  size_t head
  while(cbuf->head != cbuf->tail){


  }


}
bool circular_buf_empty(circular_buf_t cbuf){
  int ret_val = -1;
  if(cbuf.head && cbuf.tail){
      ret_val = 0;
  }
  return ret_val;

}
bool circular_buf_full(circular_buf_t  cbuf){
  if( (cbuf.head + 1 ) % cbuf.size  == cbuf.tail){
    return 0;
  }
  return 1;
}

//circular_buf_reset(&cbuf);



char quit[256];
int main(int argc, char *argv[])   //  command line arguments
{

        //char * cwd_out = popen ("pwd", "r");

        char buf[100];
        char *str = NULL;
        char *temp = NULL;
        unsigned int size = 1; // start with size of 1 to make room for null terminator
        unsigned int strlength;

        FILE *fp;
        char path[1035];

/* Open the command for reading. */
        //fp = popen("/bin/ls /etc/", "r");
        fp = popen("pwd", "r");
        if (fp == NULL) {
                printf("Failed to run command\n" );
                exit(1);
        }

/* Read the output a line at a time - output it. */
        while (fgets(path, sizeof(path)-1, fp) != NULL) {
                printf("%s", path);
        }

/* close */
        pclose(fp);
        printf("Hello, World\n"); // \n indicates a newline character



        int pollingDelay = 100;
                       //do stuff

                       //sleep:
                       //#ifdef _WIN32
                       //Sleep(pollingDelay);
                       //#elsex
                       usleep(pollingDelay*1000); /* sleep for 100 milliSeconds */
        //#endif

        //need this command to contniously run, probably look for quit messages
        scanf("%s", quit);


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

int start_cd_checker(){
        int mypid = fork();
        if( 0 == mypid ){
                printf( "lol child\n" );
              }
        else{
                printf( "lol parent\n" );
}
}
