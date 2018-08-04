

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
//not including windows at the moment
//#ifdef _WIN32
//#include <Windows.h>
//#else

#define MAX_CHAR_SIZE (1)
#define CHAR_PER_LINE (128)
#define LINES (100)
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
 struct Data { int a; double b; char c;};
 int ShmID;
 key_t Key;
 struct Data *p;


//DONE
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

//DONE
int circular_buf_put(circular_buf_t * cbuf, char* data){
        //probably need to move all of the da data down...
        int r = -1;

        if(cbuf)
        {
                cbuf->buffer[cbuf->head] = data;
                cbuf->head = (cbuf->head + 1) % cbuf->size;

                if(cbuf->head == cbuf->tail)
                {
                        cbuf->tail = (cbuf->tail + 1) % cbuf->size;
                }

                r = 0;
        }

        return r;

}
//DONE
int circular_buf_empty(circular_buf_t cbuf){
        return (cbuf.head == cbuf.tail);

}
//circular_buf_reset(&cbuf);
char quit[256];
char string[256];
void timer_handler (int signum)
{
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
}
//TODO:DONE
int circular_buf_get(circular_buf_t * cbuf, char * data){
        int r = -1;
        if(cbuf && data && !circular_buf_empty(*cbuf))
        {
                data = cbuf->buffer[cbuf->tail];
                cbuf->tail = (cbuf->tail + 1) % cbuf->size;
                r = 0;
        }
        return r;
}


int create_shared_memory(struct Data) {
  //this is a usecase for quickclip
  //#define MAX_CHAR_SIZE (1)
  //#define CHAR_PER_LINE (128)
  //#define LINES (100)

  key_t key;
  key = 1234567890;
  int size = MAX_CHAR_SIZE * CHAR_PER_LINE * LINES;
  //replaced with struct data, but can put size as well
  int shm_id = shmget(key,  sizeof(struct Data), IPC_CREAT | 0666);
  if ((int) p < 0) {
printf(“shmat() failed\n”); exit(1);
}
  return shm_id;
}


int circular_buf_full(circular_buf_t cbuf){
        if( (cbuf.head + 1 ) % cbuf.size  == cbuf.tail) {
                return 0;
        }
        return 1;
}


//be a good boy and take out the SRP, take out listening for quit messages
void start_pwd_grabber(){
  struct sigaction sa;
  struct itimerval timer;

  /* Install timer_handler as the signal handler for SIGVTALRM. */
  memset (&sa, 0, sizeof (sa));
  sa.sa_handler = &timer_handler;
  sigaction (SIGVTALRM, &sa, NULL);

  /* Configure the timer to expire after 250 msec... */
  timer.it_value.tv_sec = 0;
  timer.it_value.tv_usec = 250000;
  /* ... and every 250 msec after that. */
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 250000;
  /* Start a virtual timer. It counts down whenever this process is
  executing. */
  setitimer (ITIMER_VIRTUAL, &timer, NULL);

  /* Do busy work. */
  while (1);

}

int start_cd_checker(){
        int mypid = fork();
        if( 0 == mypid ) {
                printf( "lol child\n" );
        }
        else{
                printf( "lol parent\n" );
        }
}

void printDirectoryHistory(){


}


int main(int argc, char *argv[])   //  command line arguments
{
  if(strcmp(argv[1], "listener")){

      start_pwd_grabber();
         struct listitem* newItem = malloc(sizeof(struct listitem));
      int ShmID = create_shared_memory();
      //need to write out this to disk
      struct Data *p = (struct Data *) shmat(ShmID, NULL, 0);
      p->a = 1; p->b = 5.0; p->c = '.';
  }
  if(strcmp(argv[1], "v")){
    // dr v
    // show all the previous directories
  }

  if(strcmp(argv[1], "c")){
    // dr c
    // change to a new directory
  }



  char* parent_message = "hello";  // parent process will write this message
  char* child_message = "goodbye"; // child process will then write this one

  //we need to structure this to a circular buffer kind of scheme
  //number of characters * size of character * total number of line

        // char ** buffer;
        // size_t head;
        // size_t tail;
        // size_t size;


//         circular_buf_t * circ_buf;
//         circ_buf = malloc(sizeof(circular_buf_t));
//         circ_buf->size = 100;
//         circ_buf->head = 0;
//         circ_buf->tail = 0;
//
//         struct sigaction sa;
//         struct itimerval timer;
//
// /* Install pwd_handler as the signal handler for SIGVTALRM. */
//         memset (&sa, 0, sizeof (sa));
//         sa.sa_handler = &pwd_handler;
//         sigaction (SIGVTALRM, &sa, NULL);
//
// /* Configure the timer to expire after 250 msec... */
//         timer.it_value.tv_sec = 0;
//         timer.it_value.tv_usec = 1000000;
// /* ... and every 250 msec after that. */
//         timer.it_interval.tv_sec = 0;
//         timer.it_interval.tv_usec = 1000000;
// /* Start a virtual timer. It counts down whenever this process is
//    executing. */
//         setitimer (ITIMER_REAL, &timer, NULL);
//
// /* Do busy work. */
//         while (1);



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




//references:

//[timer logic]http://www.informit.com/articles/article.aspx?p=23618&seqNum=14
//[shared memory]https://stackoverflow.com/questions/5656530/how-to-use-shared-memory-with-linux-in-c
