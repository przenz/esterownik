#pragma once

#include "DataParser.h"

class EcoalDataParser : public DataParser {
public:
    ParsedData parse(std::string data);
};