#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>

struct Data {
    int     btc;
    float   er; // exchange_rate
    int     year;
    int     month;
    int     day;
};

#endif