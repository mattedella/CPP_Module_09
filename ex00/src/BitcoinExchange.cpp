
#include "../includes/BitcoinExchange.hpp"

time_t BitcoinExchange::StringToDate(std::string& Stime) {
    struct tm   tm = {};
    time_t      time = 0;
   
    if (strptime(Stime.c_str(),"%Y-%m-%d", &tm) != NULL)
        time = mktime(&tm);
    else
        throw BitcoinExchange::DateFailure();
    return time;
}

BitcoinExchange::BitcoinExchange() {
    std::ifstream data("data.csv");
    std::string line;

    if (!data.is_open())
        throw BitcoinExchange::FileFailure();

    while (std::getline(data, line)) {
        std::string sTime = line.substr(0, line.find(','));
        std::string sValue = line.substr(line.find(',') + 1);
        _date = StringToDate(sTime);            
        _value = std::atof(sValue.c_str());
        _dataBaseBtc[_date] = _value;
    }
    data.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _dataBaseBtc(copy._dataBaseBtc) {}

const char* BitcoinExchange::DateFailure::what() const throw() {
    return "Error: date parsing failed\n";
}
const char* BitcoinExchange::FileFailure::what() const throw() {
    return "Error: data file corrupted or inexistent\n";
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
    if (this != &copy) {
        _dataBaseBtc = copy._dataBaseBtc;
    }

    return *this;
}

time_t BitcoinExchange::closestDate(time_t targetDate) {
    iterator It = _dataBaseBtc.lower_bound(targetDate);
    if (It == _dataBaseBtc.begin() || It == _dataBaseBtc.end()) {
        std::cerr << "Error: data not found\n";
        return -1;
    }
    if (It->first != targetDate)
        It--;
    return It->first;
}

void BitcoinExchange::makeExchange(time_t date, float value, std::string& Sdate) {
    time_t exchangeDate = closestDate(date);
    if (exchangeDate == -1)
        return ;
    iterator It = _dataBaseBtc.find(exchangeDate);
    if (It == _dataBaseBtc.end()) {
        std::cerr << "Error: data in database not found\n";
        return ;
    }
    float exchangeValue =  value * It->second;
    std::cout << Sdate << " => " << value << " = " << exchangeValue << std::endl;
}

BitcoinExchange::~BitcoinExchange() {};
