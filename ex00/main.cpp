# include "includes/BitcoinExchange.hpp"

time_t convertDate(std::string& Stime) {
    struct tm   tm = {};
   
    if (strptime(Stime.c_str(),"%Y-%m-%d", &tm) == NULL) {
        std::cerr << "Error: invalid date format\n";
        return -1;
    }
    if (tm.tm_year + 1900 < 2009 || tm.tm_year + 1900 >= 2025) {
        std::cerr << "Error: year not vaid\n";
        return -1;
    }
    return mktime(&tm);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: wrong number of argument\n";
        return 1;
    }

    std::ifstream myFile;
    myFile.open(argv[1]);
    if (!myFile.is_open()) {
        std::cout << "Error: file corrupted or inexistent\n";
        return 1;
    }
    try {
        std::string line;
        BitcoinExchange bit;
        while(std::getline(myFile, line)) {
            std::string Stime = line.substr(0, line.find('|') - 1);
            if (Stime.length() <= 0) {
                std::cout << "Error: date format not valid\n";
            }
            time_t date = convertDate(Stime);
            if (date == -1)
                continue ;
            std::string Svalue = line.substr(line.find('|') + 1);
            if (Svalue.length() <= 0) {
                std::cout << "Error: value not found\n";
                continue ;
            }
            float value = std::atof(Svalue.c_str());
            if (value < 0 || value > 1000) {
                std::cout << "Error: value out of range\n";
                continue ;
            }
            bit.makeExchange(date, value, Stime);
        }
    }
    catch (BitcoinExchange::DateFailure& e) {
        std::cerr << e.what();
    }
    catch (BitcoinExchange::FileFailure& e) {
        std::cerr << e.what();
    }
    myFile.close();

    return 0;
}
