#include <memory>
#include "DataSource.h"

class EcoalDataSource : public DataSource {
public:
    void fetchData() override;
    std::string getData() override;

private:
    std::string data;
};