
#ifndef BITCOINEXCHANGED_HPP
# define BITCOINEXCHANGED_HPP

#include <ctime>
#include <exception>
#include <map>
#include <string>
# include<bits/stdc++.h>
#include <cstdlib>
#include <fstream>

typedef std::map<time_t, float>::iterator iterator;

class BitcoinExchange {

    private:
        std::map<time_t, float> _dataBaseBtc;
        time_t                  _date;
        float                   _value;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);

        class DateFailure : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class FileFailure : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        BitcoinExchange& operator=(const BitcoinExchange& copy);

        time_t StringToDate(std::string& Stime);
        time_t closestDate(time_t targetDate);
        void makeExchange(time_t date, float value, std::string& Sdate);

        ~BitcoinExchange();

};



#endif