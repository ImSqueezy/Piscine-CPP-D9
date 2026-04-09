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

bool	BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7) continue;
		if (!isdigit(date[i])) return false;
	}

	int	year, month, day;
	std::istringstream(date.substr(0, 4)) >> year;
	std::istringstream(date.substr(5, 2)) >> month;
	std::istringstream(date.substr(8, 2)) >> day;

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			return false;
	}

	if (month == 2) {
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (isLeap ? 29 : 28))
		return false;
	}
	return true;
}

bool	BitcoinExchange::isValidValue(const std::string& value, float& val) const {
	if (value.empty() || value.find_first_not_of(" \t\r\n") == std::string::npos)
		return false;
	char* endptr;
	val = strtof(value.c_str(), &endptr);
	while (*endptr != '\0' && isspace(*endptr))
		endptr++;
	return (*endptr == '\0');
}

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
		size_t		last = date.find_last_not_of(" \t\r\n");
		if (last != std::string::npos)
			date = date.substr(0, last + 1);

		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		std::string valStr = line.substr(pipePos + 1);
		float val;
		if (!isValidValue(valStr, val)) {
			std::cout << "Error: bad input => " << valStr << std::endl;
			continue;
		}
		
		if (val < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (val > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

	}
	file.close();
}
