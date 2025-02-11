#include <ios>
#include <iostream>
#include <limits>
#include <string>

bool checkWord(std::string slice, std::string search, int pos) {
    bool same_word = true;

    for (int i = 0; i < search.size(); i++) {
        if (!(slice[i] == search[i]))
            same_word = false;
    }

    return same_word;
}

int findPos(std::string data_string, std::string search) {
    int pos = -1;

    for (int i = 0; i < data_string.size(); i++) {
        if (data_string[i] == search[0]) {
            if (checkWord(data_string.substr(i, search.size()), search, i))
                pos = i;
        }
    }

    return pos;
}

int main() {
    std::string data_string;
    std::string search;
    std::string line;

    std::cout << "Give a string which to search for: ";
    std::cin >> data_string;

    // clear input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Give search string: ";
    std::cin >> search;

    int pos = findPos(data_string, search);

    if (pos != -1) {
        std::cout << "\"" + search + "\"" << " found in "
                  << "\"" + data_string + "\"" << " in position " << pos
                  << std::endl;
    } else {
        std::cout << "\"" + search + "\"" << " NOT found in "
                  << "\"" + data_string + "\"" << std::endl;
    }

    return 0;
}
