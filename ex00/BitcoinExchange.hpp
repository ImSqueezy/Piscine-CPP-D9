#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <sstream>
# include <cstdlib>

class	BitcoinExchange {
	private:
		std::map<std::string, float>	database;
		int								_min_year;
		int								_max_year;	

		bool    isValidDate(const std::string& date) const;
		bool    isValidValue(const std::string& value, float& val) const;
		float   getExchangeRate(const std::string& date) const;

    public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool    loadDatabase(const std::string& filename);
		void    processInput(const std::string& filename);
};

#endif