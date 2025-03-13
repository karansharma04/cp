#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

void sigint_handler(int sig_num) {
    cout << "Handling interrupt signal " << sig_num << endl;
}

void sigterm_handler(int sig_num) {
    cout << "Handling kill signal " << sig_num << endl;
}

int main() {
    signal(SIGINT , sigint_handler);
    signal(SIGTERM , sigint_handler);
    while (1) {
        cout << "Hello!" << endl;
        sleep(1);
    }
    return 0;
}
