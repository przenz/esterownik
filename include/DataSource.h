#pragma once

class DataSource {
public:
    virtual void fetchData() = 0;
    virtual std::string getData() = 0;
};