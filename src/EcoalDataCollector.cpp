#include <iostream>

#include "httplib.h"

#include "EcoalDataCollector.h"

std::string EcoalDataCollector::collectData() {
    dataSource->fetchData();
    return dataSource->getData();
}