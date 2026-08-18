#ifndef DETAILS_HPP
#define DETAILS_HPP

#include <unordered_map>
#include <string>

struct Details {
    std::string accountNum;
    std::string lName, fName, mName;
    std::string pin;
    double bal;
};

using Database = std::unordered_map<std::string, Details>;

#endif
