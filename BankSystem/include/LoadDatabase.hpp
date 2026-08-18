#ifndef LOADDATABASE_HPP
#define LOADDATABASE_HPP

#include <unordered_map>
#include <string>
#include "Details.hpp"

using Database = std::unordered_map<std::string, Details>;

Database LoadDatabase();

#endif
