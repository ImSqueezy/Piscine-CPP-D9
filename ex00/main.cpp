#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: Invalid number of args." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    if (!btc.loadDatabase("data.csv"))
        return 1;
    
    try {
        btc.processInput(av[1]);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
