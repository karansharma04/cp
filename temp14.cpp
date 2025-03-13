#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int pid;

void child_handler(int sig) {
    cout << "Child Handler here!" << endl;
    exit(0);
}

void parent_handler(int sig) {
    cout << "Parent Handler here!" << endl;
    sleep(10);
    kill(pid , SIGUSR2);
}

int main() {
    pid = fork();
    if (pid == 0) {
        // child
        cout << "child process here!" << endl;
        signal(SIGUSR2 , child_handler);
        sleep(1);
        kill(getppid() , SIGUSR1);
        while (true) {
            cout << "child process running" << endl;
            sleep(1);
        }
    }
    else {
        // parent
        cout << "parent process here!" << endl;
        signal(SIGUSR1 , parent_handler);
        wait(nullptr);
    }
    return 0;
}