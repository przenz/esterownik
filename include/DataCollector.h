#pragma once

#include <string>

class DataCollector {
public:
    virtual std::string collectData() = 0;
};