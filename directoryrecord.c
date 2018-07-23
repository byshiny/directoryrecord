

#include <stdio.h>
#include <stdlib.h>


//code from: https://embeddedartistry.com/blog/2017/4/6/circular-buffers-in-cc
typedef struct {
    uint8_t * buffer;
    size_t head;
    size_t tail;
    size_t size; //of the buffer
} circular_buf_t;


int circular_buf_reset(circular_buf_t * cbuf);
int circular_buf_put(circular_buf_t * cbuf, uint8_t data);
int circular_buf_get(circular_buf_t * cbuf, uint8_t * data);
bool circular_buf_empty(circular_buf_t cbuf);
bool circular_buf_full(circular_buf_t cbuf);

int circular_buf_reset(cbuf){
}

circular_buf_t cbuf;
cbuf.size = 5;
cbuf.buffer = malloc(cbuf.size);
circular_buf_reset(&cbuf);



char chaine1[256];
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


        scanf("%s", chaine1);


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
