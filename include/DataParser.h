#pragma once

#include <string>

using ParsedData = std::vector<std::pair<std::string, float>>;

class DataParser {
public:
    virtual ParsedData parse(std::string) = 0;
};