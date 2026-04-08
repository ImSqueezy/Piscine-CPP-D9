#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>

struct Data {
    float     btc;
    float     er;
    int     year;
    int     month;
    int     day;
    bool    valid_input = 1;
	bool	valid_btc = 1;
	bool	valid_data = 1;
};

#endif