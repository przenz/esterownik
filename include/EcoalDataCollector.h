#pragma once

#include <string>
#include "EcoalDataSource.h"
#include "DataCollector.h"

class EcoalDataCollector : public DataCollector {
public:
    EcoalDataCollector() : dataSource{std::make_unique<EcoalDataSource>()} {};
    std::string collectData();

private:
    std::unique_ptr<DataSource> dataSource;
};