#include <iostream>
#include <fstream>
#include <string>

void printHead(std::istream& input, int numLines) {
    std::string line;
    int count = 0;
    while (count < numLines && std::getline(input, line)) {
        std::cout << line << std::endl;
        count++;
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
        printHead(file, numLines);
        file.close();
    } else {
      
        printHead(std::cin, numLines);
    }

    return 0;
}
