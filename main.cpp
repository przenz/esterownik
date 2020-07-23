#include <iostream>
#include <regex>
#include <DataParser.h>
#include <EcoalDataParser.h>
#include <thread>

#include "DataCollector.h"
#include "EcoalDataCollector.h"

int main() {
    for( int i=0; i<100; i++) {
        std::unique_ptr<DataCollector> dataCollector = std::make_unique<EcoalDataCollector>();
        std::string xmlData = dataCollector->collectData();

        std::unique_ptr<DataParser> dataParaser = std::make_unique<EcoalDataParser>();
        auto result = dataParaser->parse(xmlData);

        for(const auto& avp : result) {
            auto [attribute,value] = avp;
            std::cout << "Attribute: " << attribute << ", value: " << value << std::endl;
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(3s);
    }

    std::cout << "\nClean exit" << std::endl;

    return 0;
}