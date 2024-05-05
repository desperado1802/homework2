#include <iostream>
#include <fstream>
#include <string>
#include <deque>

void printTail(std::istream& input, int numLines) {
    std::string line;
    std::deque<std::string> lines;
    while (std::getline(input, line)) {
        lines.push_back(line);
        if (lines.size() > numLines) {
            lines.pop_front();
        }
    }

    for (const std::string& l : lines) {
        std::cout << l << std::endl;
    }
}

int main(int argc, char* argv[]) {
    int numLines = 10; 
    std::string filename;

 
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-n" && i + 1 < argc) {
            numLines = std::stoi(argv[++i]); 
        } else {
            filename = arg;
        }
    }

    if (!filename.empty()) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return 1;
        }
        printTail(file, numLines);
        file.close();
    } else {
        
        printTail(std::cin, numLines);
    }

    return 0;
}
