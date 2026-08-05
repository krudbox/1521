
#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
extern char **environ;

int main(int argc, char *argv[]) {
    pid_t pid;


    char *args[] = {"/bin/echo", "hello world", NULL};
    int return_value = posix_spawn(&pid, "/bin/echo", NULL, NULL, args, environ);
    if (return_value != 0) {
        perror("");
        exit(1);
    }

    int status;
    return_value = waitpid(pid, &status, 0);
    if (return_value == -1) {
        perror("");
        exit(1);
    }

    return 0;
}
