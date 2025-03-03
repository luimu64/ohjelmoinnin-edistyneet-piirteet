#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Line {
    int line_nro;
    std::string line_data;
};

struct InputData {
    std::string search;
    std::string file_name;
    std::string data_string;
    bool ignore_case = false;
    bool reverse_search = false;
    bool line_numbers = false;
    bool occurrences = false;
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

void findLines(std::string file_name, std::string search,
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
    } else {
        std::cout << "Error opening file." << std::endl;
        exit(1);
    }
}

// disgusting looking function for printing out the results
void printResults(std::vector<Line> lines, InputData idata,
                  bool no_file = false) {
    // when no file is given the printing output needs to be different
    if (no_file && lines[0].line_nro != -1) {
        std::cout << "\"" + idata.search + "\"" << " found in "
                  << "\"" + lines[0].line_data + "\"" << " in position "
                  << lines[0].line_nro << std::endl;

    } else if (lines.capacity() > 0) {
        for (const struct Line& line : lines) {
            if (idata.line_numbers) {
                std::cout << line.line_nro << ":";
            }
            std::cout << line.line_data << std::endl;
        }
        if (idata.occurrences) {
            std::cout << "\nOccurrences of lines containing \"" << idata.search
                      << "\": " << lines.size() << std::endl;
        }
    } else {
        std::cout << "\"" + idata.search + "\"" << " NOT found in "
                  << "\"" + idata.data_string + "\"" << std::endl;
    }
}

InputData parseFlags(int argc, char* argv[]) {
    InputData idata;
    // start indexing from 1 because argv[0] is the program name
    for (int i = 1; i < argc; i++) {
    next_flag:
        if (argv[i][0] == '-' && argv[i][1] == 'o') {
            for (int j = 2; j < (int)std::string(argv[i]).length(); j++) {
                switch (argv[i][j]) {
                case ' ':
                    goto next_flag;
                case 'o':
                    idata.occurrences = true;
                    break;
                case 'i':
                    idata.ignore_case = true;
                    break;
                case 'v':
                    idata.reverse_search = true;
                    break;
                case 'l':
                    idata.line_numbers = true;
                    break;
                default:
                    std::cout << "Invalid flag: " << argv[i][j] << std::endl;
                    break;
                }
            }
        } else {
            if (idata.search == "")
                idata.search = argv[i];
            else if (idata.file_name == "")
                idata.file_name = argv[i];
            else
                std::cout << "Too many arguments" << std::endl;
        }
    }
    return idata;
}

int main(int argc, char* argv[]) {
    std::vector<Line> lines;
    InputData idata;

    if (argc > 1) { // check whether commandline arguments were given
        idata = parseFlags(argc, argv);
        // find lines with matching content and add them to lines vector
        findLines(idata.file_name, idata.search, lines);
        // print all found lines
        printResults(lines, idata);

    } else { // no arguments given
        std::cout << "Give a string which to search for: ";
        std::getline(std::cin, idata.data_string);

        std::cout << "Give search string: ";
        std::getline(std::cin, idata.search);

        // print strings found
        lines.push_back(
            {findPos(idata.data_string, idata.search), idata.data_string});
        printResults(lines, idata, true);
    }

    return 0;
}
