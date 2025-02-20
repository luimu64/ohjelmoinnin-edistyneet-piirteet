#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Line {
    int line_nro;
    std::string line_data;
};

struct ProcessedArguments {
    std::string search;
    std::string file_name;
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

ProcessedArguments parseFlags(int argc, char* argv[]) {
    ProcessedArguments arguments;
    // start indexing from 1 because argv[0] is the program name
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'o') {
            switch (argv[i][2]) {
            case 'o':
                arguments.occurrences = true;
                break;
            case 'i':
                arguments.ignore_case = true;
                break;
            case 'v':
                arguments.reverse_search = true;
                break;
            case 'l':
                arguments.line_numbers = true;
                break;
            default:
                std::cout << "Invalid flag: " << argv[i][2] << std::endl;
                break;
            }
        } else {
            if (arguments.search == "")
                arguments.search = argv[i];
            else if (arguments.file_name == "")
                arguments.file_name = argv[i];
            else
                std::cout << "Too many arguments" << std::endl;
        }
    }
    return arguments;
}

int main(int argc, char* argv[]) {
    std::vector<Line> lines;

    if (argc > 1) { // check whether commandline arguments were given
        ProcessedArguments arguments = parseFlags(argc, argv);

        // find lines with matching content and add them to lines vector
        findLines(arguments.file_name, arguments.search, lines);
        // print all found lines
        printResults(lines, arguments.search, arguments.file_name);

    } else { // no arguments given
        std::string data_string;
        std::string search;

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
