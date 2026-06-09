#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        char buffer[10];
        read(fd, buffer, 5);
        buffer[5] = '\0';
        printf("Child read: %s\n", buffer);
    } else {
        wait(NULL);
        char buffer[10];
        read(fd, buffer, 5);
        buffer[5] = '\0';
        printf("Parent read: %s\n", buffer);
    }
    close(fd);
    return 0;
}
Commands to Execute:
vi program_name.c (type program here)
vi file_name.txt (type some content here)
cc program_name.c
./a.out
