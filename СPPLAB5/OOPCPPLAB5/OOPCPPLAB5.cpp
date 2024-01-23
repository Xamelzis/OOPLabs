#include <iostream>
#include <fstream>
#include <string>




int main() {




    std::ifstream file("C:/Users/Xamelzi/Desktop/OOP/СPPLAB5/FileLAB5.txt");

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            size_t start = line.find("\"");
            size_t end = line.find("\"", start + 1);
            if (start != std::string::npos && end != std::string::npos) {
                std::string quote = line.substr(start + 1, end - start - 1);
                std::cout << quote << std::endl;
            }
        }

        file.close();
    }
    else {
        std::cout << "Не удалось открыть файл." << std::endl;
    }

    return 0;
}