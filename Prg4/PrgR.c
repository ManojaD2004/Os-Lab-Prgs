#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int fd;
    char buf[1024];
    char *myfifo = "./myfifo";
    // Open the FIFO for reading
    fd = open(myfifo, O_RDONLY);
    // Read from the FIFO
    read(fd, buf, sizeof(buf));
    // Print the read message
    printf("Received: %s\n", buf);
    buf[sizeof(buf) - 1] = '\0'; 
    // initialize buf to zero to avoid unexpected result as buf contain previously stored data.
    close(fd);
    return 0;
}