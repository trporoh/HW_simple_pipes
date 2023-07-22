#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    char buff[32];

    mkfifo("/buffer", 0660);

    int fd = open("/buffer", O_RDONLY);
    read(fd, buff, 32);
    fprintf(stdout, "You get '%s' from main process\n", buff);

    exit(EXIT_SUCCESS);
}