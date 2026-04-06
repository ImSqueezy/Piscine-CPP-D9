#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: The program takes two arguments!" << std::endl;
        return (1);
    }

    std::fstream        file(av[1]);
    std::string         line;
    std::vector<Data>   data;

    std::getline(file, line);
    for (line; std::getline(file, line);) {
        std::istringstream  iss(line);
        std::string         word;
        Data                new_data;
        std::cout << "line: " << line << std::endl;

        std::getline(iss, word, '-');
        std::istringstream(word) >> new_data.year;
        
        std::getline(iss, word, '-');
        std::istringstream(word) >> new_data.month;

        std::getline(iss, word, '-');
        std::istringstream(word) >> new_data.day;

        std::getline(iss, word);
        std::istringstream(word) >> new_data.btc;

        data.push_back(new_data);
    }

    std::vector<Data>::iterator it;

    for (it = data.begin(); it != data.end(); ++it) {
        Data& element = *it;
        std::cout << "year " << element.year << std::endl;
        std::cout << "month " << element.month << std::endl;
        std::cout << "day " << element.day << std::endl;
    }
    
    return 0;
}
