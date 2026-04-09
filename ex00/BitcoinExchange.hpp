#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <sstream>
# include <cstdlib>

class	BitcoinExchange {
	private:
		std::map<std::string, float> database;

    public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool    loadDatabase(const std::string& filename);
		void    processInput(const std::string& filename);
};

#endif