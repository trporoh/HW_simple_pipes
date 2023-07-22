#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


int main() {
    char buff[32] = "hello fifocheck";

    mkfifo("/buffer", 0660);

    int fd = open("/buffer", O_WRONLY);
    write(fd, buff, 32);
    fprintf(stdout, "You send '%s' to other process\n", buff);

    exit(EXIT_SUCCESS);
}