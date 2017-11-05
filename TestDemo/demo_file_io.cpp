#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv)
{
    printf("------------- demo file io -------------\n");

    int fd = 0;
    fd = open("./demo_test.txt", O_RDWR);
    if (-1==fd)
    {
        fprintf(stderr, "open file failed. reason: %s\n", strerror(errno));
        return 1;
    }

    off_t size = lseek(fd, 0, SEEK_END);
    char writeBuf[BUFFER_SIZE];
    memset(writeBuf, 97, BUFFER_SIZE);
    writeBuf[BUFFER_SIZE-2] = '\r';
    writeBuf[BUFFER_SIZE-1] = '\n';

    ssize_t retValue = write(fd, writeBuf, BUFFER_SIZE);
    if (-1 == retValue)
    {
        fprintf(stderr, "write file failed. reason: %s\n", strerror(errno));
        return 1;
    }

    printf("size=%lld writeBuf=%s write %ld bytes\r", size, writeBuf, retValue);

    close(fd);

    return 0;
}
