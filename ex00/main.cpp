#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: Invalid number of args." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    if (!btc.loadDatabase("data.csv"))
        return 1;
    
    btc.processInput(av[1]);
    return 0;
}
