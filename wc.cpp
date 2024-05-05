#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Count {
    int lines = 0;
    int words = 0;
    int characters = 0;
};

Count count(std::istream& input) {
    Count cnt;
    std::string line;
    while (std::getline(input, line)) {
        cnt.lines++;
        cnt.characters += line.length() + 1;

        bool inWord = false;
        for (char ch : line) {
            if (std::isspace(ch)) {
                if (inWord) {
                    cnt.words++;
                    inWord = false;
                }
            } else {
                inWord = true;
            }
        }
        if (inWord) cnt.words++;
    }
    return cnt;
}

int main(int argc, char* argv[]) {
    bool countLines = false, countWords = false, countChars = false;
    std::vector<std::string> files;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-l") countLines = true;
        else if (arg == "-w") countWords = true;
        else if (arg == "-c") countChars = true;
        else files.push_back(arg);
    }

  
    if (!countLines && !countWords && !countChars) {
        countLines = countWords = countChars = true;
    }

    for (const std::string& file : files) {
        std::ifstream input(file);
        if (!input.is_open()) {
            std::cerr << "Error: Could not open file " << file << std::endl;
            return 1;
        }

        Count cnt = count(input);

        if (countLines) std::cout <<  "Count of lines: " << cnt.lines << std::endl;
        if (countWords) std::cout << "Count of words: " << cnt.words << std::endl;
        if (countChars) std::cout << "Count of characters: " << cnt.characters << std::endl;
        std::cout << file << std::endl;

        input.close();
    }

    if (files.empty()) {
        Count cnt = count(std::cin);
        if (countLines) std::cout << cnt.lines << " ";
        if (countWords) std::cout << cnt.words << " ";
        if (countChars) std::cout << cnt.characters << " ";
        std::cout << std::endl;
    }

    return 0;
}
