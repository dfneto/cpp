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
		const std::string 	decreaseDate(std::string date); //todo: make it static

	public:
		BitcoinExchange();
		~BitcoinExchange();
		
        int			calculate(char *);
};

#endif
