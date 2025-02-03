#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    int num_lines = 0;
    int sum = 0;

    ifstream randomFile("Random.txt");

    // Check if the file opened successfully
    if (!randomFile.is_open()) {
        cerr << "Error: Could not open file 'Random.txt'." << endl;
        cerr << "Check if the file exists in the correct directory." << endl;
        return 1;
    }

    while (getline(randomFile, line)) {
        if (line.empty())
            continue;

        sum += stoi(line);
        num_lines++;
    }

    cout << "Number of lines: " << num_lines << endl;
    cout << "Sum of numbers: " << sum << endl;
    cout << "Average of numbers: " << sum / num_lines << endl;

    randomFile.close();
}
