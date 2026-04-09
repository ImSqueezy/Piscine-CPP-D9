#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->database = other.database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return false;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;

		std::string date = line.substr(0, commaPos);
		std::string rateStr = line.substr(commaPos + 1);

		float rate;
		std::istringstream(rateStr) >> rate;
		this->database[date] = rate;
	}
	file.close();
	return true;
}

void	BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: couldn't open the file." << std::endl;
		return;
	}

	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		
		size_t	pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	date = line.substr(0, pipePos);
		// Trim trailing spaces from date for validation
		size_t		last = date.find_last_not_of(" \t\r\n");
		if (last != std::string::npos)
			date = date.substr(0, last + 1);
		std::cout << "date: " << date << std::endl;
	}
	file.close();
}
