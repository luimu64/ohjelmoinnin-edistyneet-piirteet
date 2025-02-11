#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Line {
    int line_nro;
    std::string line_data;
};

bool checkWord(std::string slice, std::string search, int pos) {
    bool same_word = true;

    for (int i = 0; i < (int)search.size(); i++) {
        if (!(slice[i] == search[i]))
            same_word = false;
    }

    return same_word;
}

// find and return first appearance of substring in another string
int findPos(std::string data_string, std::string search) {
    for (int i = 0; i < (int)data_string.size(); i++) {
        if (data_string[i] == search[0]) {
            if (checkWord(data_string.substr(i, search.size()), search, i)) {
                return i;
            }
        }
    }
    return -1;
}

std::vector<Line> findLines(std::string file_name, std::string search,
                            std::vector<Line>& lines) {
    std::ifstream input_file;
    std::string line;
    int pos;

    input_file.open(file_name);
    if (input_file.is_open()) {
        while (getline(input_file, line)) {
            pos = findPos(line, search);
            if (pos != -1) {
                lines.push_back({pos, line});
            }
        }
        input_file.close();
    }

    return lines;
}

void printResults(std::string data_string, std::string search, int pos) {
    if (pos != -1) {
        std::cout << "\"" + search + "\"" << " found in "
                  << "\"" + data_string + "\"" << " in position " << pos
                  << std::endl;
    } else {
        std::cout << "\"" + search + "\"" << " NOT found in "
                  << "\"" + data_string + "\"" << std::endl;
    }
}

void printResults(std::vector<Line> lines, std::string search,
                  std::string source, bool no_file = false) {
    // when no file is given the printing output needs to be different
    if (no_file && lines[0].line_nro != -1) {
        std::cout << "\"" + search + "\"" << " found in "
                  << "\"" + lines[0].line_data + "\"" << " in position "
                  << lines[0].line_nro << std::endl;

    } else if (lines.capacity() > 0) {
        for (const struct Line& i : lines)
            std::cout << i.line_data << std::endl;

    } else {
        std::cout << "\"" + search + "\"" << " NOT found in "
                  << "\"" + source + "\"" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    std::string search;
    std::string file_name;
    std::string data_string;
    std::vector<Line> lines;

    if (argc > 1) { // check whether commandline arguments were given
        search = argv[1];
        file_name = argv[2];

        // find lines with matching content and add them to lines vector
        findLines(file_name, search, lines);
        // print all found lines
        printResults(lines, search, file_name);

    } else { // no arguments given
        std::cout << "Give a string which to search for: ";
        std::getline(std::cin, data_string);

        std::cout << "Give search string: ";
        std::getline(std::cin, search);

        // print strings found
        lines.push_back({findPos(data_string, search), data_string});
        printResults(lines, search, data_string, true);
    }

    return 0;
}
