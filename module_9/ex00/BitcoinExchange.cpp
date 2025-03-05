#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    loadDictionary();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    (void) src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
    (void) rhs;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isNumber(const std::string &s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (!std::isdigit(s[i])) return false;
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10) return false; // Ensure length is exactly 10

    if (date[4] != '-' || date[7] != '-') return false; // Ensure '-' at correct positions

    std::string yearStr = date.substr(0, 4);  // Extract YYYY
    std::string monthStr = date.substr(5, 2); // Extract MM
    std::string dayStr = date.substr(8, 2);   // Extract DD

    if (!isNumber(yearStr) || !isNumber(monthStr) || !isNumber(dayStr)) return false;

    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (month < 1 || month > 12) return false;

    // Days in each month (ignoring leap years for simplicity)
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > daysInMonth[month - 1]) return false; // Check valid day

    return true;
}

bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int BitcoinExchange::getDaysInMonth(int year, int month) {
    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) return 29;
    return daysInMonth[month - 1];
}

// std::istringstream is a class from <sstream> in C++ that allows you 
// to treat a string like a stream, similar to reading from std::cin.
// It helps extract values from a formatted string.
// When using operator>>, it automatically parses numbers and stops when 
// it encounters a non-numeric character. It can extract characters and 
// strings, but operator>> only reads words separated by spaces
std::string BitcoinExchange::decrementDate(const std::string &dateStr)
{
    int year, month, day;
    //Parse YYYY-MM-DD
    char dash1, dash2;
    std::istringstream iss(dateStr);
    iss >> year >> dash1 >> month >> dash2 >> day;

    day--;

    //Handle underflow (e.g., going from 2024-03-01 to 2024-02-29)
    if (day == 0) {
        month--;
        if (month == 0) {
            year--;
            month = 12;
        }
        day = getDaysInMonth(year, month);
    }

    //Format bach to YYYY-MM-DD
    // ostringstream works like std::cout, but instead of printing 
    // to the console, it writes to a string.
    std::ostringstream result;  
    result << year << "-" 
           << std::setw(2) << std::setfill('0') << month << "-" 
           << std::setw(2) << std::setfill('0') << day;
    return result.str();
}

void BitcoinExchange::loadDictionary()
{
    // Open source file for reading
	std::ifstream file(CSV_FILE);
	if (!file) {
		std::cerr << "Fatal Error: Failed to load CSV file. Exiting program." << std::endl;
        std::exit(1);
	}

    std::string line;
    
    // Skip the first line
    if (!std::getline(file, line)) {
        std::cerr << "Error: File is empty." << std::endl;
        std::exit(1);
    }

    while (std::getline(file, line)) { 
        std::istringstream iss(line);
        std::string date, valueStr;
        float value;

        if (std::getline(iss, date, ',') &&
            std::getline(iss, valueStr)) {
            value = std::atof(valueStr.c_str());
            
            this->map[date] = value;
        } else {
            std::cerr << "Error: Invalid line format in the csv file." << std::endl;
            file.close();
            std::exit(1);
        }

    }
    file.close();
}

int BitcoinExchange::calculate(char *inputFile)
{
    // Open source file for reading
	std::ifstream file(inputFile);
	if (!file) {
		std::cerr << "Error opening source file: " << inputFile << std::endl;
        return 1;
	}

    std::string line;
    
    // Skip the first line
    if (!std::getline(file, line)) {
        std::cerr << "Error: File is empty." << std::endl;
        return 1;
    }

    while (std::getline(file, line)) {  // Read file line by line
        std::istringstream iss(line);
        std::string date, separator, valueStr;
        float value, exchangeRate;

        if (std::getline(iss, date, ' ') &&
            std::getline(iss, separator, '|') &&
            std::getline(iss, valueStr)) {
            value = std::atof(valueStr.c_str());  // Convert to float

            if (value < 0 || value > 1000) {
                std::cerr << date << " => " 
                    << std::fixed << std::setprecision(value == (int)value ? 0 : 1) << value 
                    << " => Error: Value must be positive and less than 1000." << std::endl;
                continue;
            }

            if (!isValidDate(date)) {
                std::cerr << date << " => " 
                    << std::fixed << std::setprecision(value == (int)value ? 0 : 1) << value 
                    << " => Error: Invalid date format '" << date << "'. Expected YYYY-MM-DD." << std::endl;
                continue;
            }

            if (dateIsBeforeFirstDate(date)) {
                std::cerr << date << " => " 
                    << std::fixed << std::setprecision(value == (int)value ? 0 : 1) << value 
                    << " => Error: Date is before the first date in the dictionary." << std::endl;
                continue;
            }
            
            exchangeRate = getExchangeRate(date);

            std::cout << date << " => " 
              << std::fixed << std::setprecision(value == (int)value ? 0 : 1) << value 
              << " = " 
              << std::fixed << std::setprecision(2) << value * exchangeRate
              << std::endl;
        } else {
            std::cerr << date << " => Error: Invalid line format." << std::endl;
        }
    }

    file.close();
    return 0;
}

bool BitcoinExchange::dateIsBeforeFirstDate(const std::string &date) {
    return date < this->map.begin()->first;
}

float BitcoinExchange::getExchangeRate(const std::string &date) {
    if (this->map.find(date) != this->map.end()) {
        return this->map[date];
    } else {
        return getExchangeRate(decrementDate(date));    
    }
}

