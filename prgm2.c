
#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char writeMsg[] = "Hello from parent!";
    char readMsg[50];

    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        close(pipefd[1]);
        read(pipefd[0], readMsg, sizeof(readMsg));
        printf("Child received: %s\n", readMsg);
        close(pipefd[0]);
    } else {
        close(pipefd[0]);
        write(pipefd[1], writeMsg, sizeof(writeMsg));
        close(pipefd[1]);
    }

    return 0;
}
