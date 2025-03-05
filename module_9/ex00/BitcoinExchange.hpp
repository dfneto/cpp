#ifndef BTC_EXCHANGE
#define BTC_EXCHANGE

#include    <map>
#include	<iostream> 	//cout, cerr
#include	<fstream>  	//getline
#include	<sstream>	//istringstream
#include 	<cstdlib>  	//atof()
#include 	<cctype>   	//isdigit()
#include 	<iomanip>	//setprecision

#define	CSV_FILE "data.csv"

class BitcoinExchange {
	private:
        BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange&		operator=(const BitcoinExchange &rhs);
		
        std::map<std::string, float> map;
		void				loadDictionary();
		bool				isValidDate(const std::string &);
		bool				isNumber(const std::string &);
		float				getExchangeRate(const std::string &date);
		std::string			decrementDate(const std::string &date);
		int					getDaysInMonth(int year, int month);
		bool				isLeapYear(int year);
		bool 				dateIsBeforeFirstDate(const std::string &date);



	public:
		BitcoinExchange();
		~BitcoinExchange();
		
        int			calculate(char *);
};

#endif
