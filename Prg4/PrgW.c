#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h> // for ‘mkfifo()’ and permission modes.
#include <unistd.h>
int main()
{
    int fd; // declare file descriptor
    char buf[1024];
    /* create the FIFO (named pipe) */
    char *myfifo = "./myfifo"; // defining the path of FIFO
    mkfifo(myfifo, 0666);          // Create named pipe with read and write permissions.
    printf("Run Reader process to read the FIFO File\n");
    fd = open(myfifo, O_WRONLY);   // opens FIFO for write operation
    write(fd, "Hi", sizeof("Hi")); // write the string “Hi” to the FIFO
    close(fd);                     // close the file descriptor
    unlink(myfifo);                // remove the FIFO
    return 0;
}