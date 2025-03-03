#include <algorithm>
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

std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return str;
}

void findLinesFromFile(std::vector<Line>& lines, InputData idata) {
    std::ifstream input_file;
    std::string line;
    std::size_t pos;
    int lineNum = 1;

    // do this here instead of in the loop because the search string doesn't
    // change unlike the line which is read one by one from the file
    if (idata.ignore_case)
        idata.search = toLower(idata.search);

    input_file.open(idata.file_name);
    if (input_file.is_open()) {
        while (getline(input_file, line)) {

            if (idata.ignore_case)
                line = toLower(line);

            pos = line.find(idata.search);

            if (pos == std::string::npos && idata.reverse_search) {
                lines.push_back({lineNum, line});
            } else if (pos != std::string::npos && !idata.reverse_search) {
                lines.push_back({lineNum, line});
            }
            lineNum++;
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
                case 'r':
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
        findLinesFromFile(lines, idata);
        // print all found lines
        printResults(lines, idata);

    } else { // no arguments given
        std::cout << "Give a string which to search for: ";
        std::getline(std::cin, idata.data_string);

        std::cout << "Give search string: ";
        std::getline(std::cin, idata.search);

        // print strings found
        lines.push_back(
            {(int)idata.data_string.find(idata.search), idata.data_string});
        printResults(lines, idata, true);
    }

    return 0;
}
