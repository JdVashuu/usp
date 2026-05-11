#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        printf("error\n");
    } else if (pid == 0) {
        if (execl("textinterpreter", "test", "myarg1", "myarg2", "myarg4",(char *)0) < 0)
            printf("error\n");
        if (waitpid(pid, NULL, 0) < 0)
            printf("error\n");
    }
    return 0;
}


/*

Commands to Execute :
    gcc -o echoall echoall.c
    chmod 777 textinterpreter
    gcc -o inter inter.c
    ./inter

 */
