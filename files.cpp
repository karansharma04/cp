#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    const string filename = "text.txt";
    streampos lastPos = 0;

    while (true) {
        // Open the file fresh on each iteration
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file: " << filename << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            continue;
        }

        // Seek to the end and get current file size
        file.seekg(0 , ios::end);
        streampos currentSize = file.tellg();

        // If the file was truncated or recreated, reset lastPos to zero.
        if (currentSize < lastPos) {
            lastPos = 0;
        }

        // If new data exists, read it
        if (currentSize > lastPos) {
            file.clear(); // Clear any EOF flag
            file.seekg(lastPos , ios::beg);

            string line;
            while (getline(file , line)) {
                cout << line << endl;
            }
            lastPos = file.tellg();
        }

        file.close();
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    return 0;
}
