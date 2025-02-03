/*
Program that asks user for name and description then writes them into a html
file.
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    string description;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter description: ";
    getline(cin, description);

    ofstream htmlFile("index.html");

    if (!htmlFile.is_open()) {
        cerr << "Error: Could not open file 'index.html'." << endl;
        return 1;
    }

    htmlFile << "<!DOCTYPE html>\n";
    htmlFile << "<html>\n";
    htmlFile << "<head>\n";
    htmlFile << "</head>\n";
    htmlFile << "<body>\n";
    htmlFile << "<center>\n";
    htmlFile << "<h1>" << name << "</h1>\n";
    htmlFile << "</center>\n";
    htmlFile << "<hr>" << description << "</hr>\n";
    htmlFile << "</body>\n";
    htmlFile << "</html>\n";

    htmlFile.close();
}
