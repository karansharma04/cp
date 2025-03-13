#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        return EXIT_FAILURE;
    }
    pid_t pid = fork();
    if (pid == 0) {
        cout << "Child Process running, pid: " << pid << endl;
        close(pipefd[1]);
        char buffer[100];
        read(pipefd[0] , buffer , sizeof(buffer));
        close(pipefd[0]);
        cout << buffer << endl;
    }
    else {
        sleep(1);
        cout << "Parent Process running, pid: " << pid << endl;
        close(pipefd[0]);
        cout << "Writing into the buffer" << endl;
        write(pipefd[1] , "Hello World!" , 12);
        close(pipefd[1]);
    }
    return 0;
}