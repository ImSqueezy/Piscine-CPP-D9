#include "BitcoinExchange.hpp"

void	ft_validate_date(std::vector<Data> data) {
    std::vector<Data>::iterator it;
    for (it = data.begin(); it != data.end(); ++it) {
        Data& element = *it;

    }
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: The program takes two arguments!" << std::endl;
        return (1);
    }

	std::ifstream		iFile(av[1]);
	if (!iFile.is_open()) {
		std::cerr << "Error opening the file!" << std::endl;
		return 1;
	}
	std::string			line;
	std::vector<Data>	data;

    for (std::string line; std::getline(iFile, line);) {
		if (line.empty() || line == "date | value")
			continue;

		std::istringstream	iss(line);
		Data				new_data;
		char				dash0, dash1, pipe;
		std::cout << line << std::endl;
		
		iss >> new_data.year >> dash0 >> new_data.month >> dash1 >> new_data.day;
		if (dash0 != '-' || dash1 != '-')
			new_data.valid_input = false;
		if (iss >> pipe && pipe == '|') {
			if (!(iss >> new_data.btc)) {
				new_data.valid_btc = false;
			} else
				new_data.valid_btc = true;
		} else {
			new_data.valid_input = false;
		}

        data.push_back(new_data);
    }
	iFile.close();
	ft_validate_date(data);
    return 0;
}
