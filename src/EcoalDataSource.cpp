#include <iostream>
#include <httplib.h>
#include "EcoalDataSource.h"

void EcoalDataSource::fetchData() {
    // IMPORTANT: 1st parameter must be a hostname or an IP adress string.
    httplib::Client httpClient("192.168.0.173", 80);
    httpClient.set_basic_auth("root", "root");

    auto res = httpClient.Get("/getregister.cgi?device=0&tcwu_value&tpow_value&tzew_value");
    if (res && res->status == 200) {
        data = res-> body;
    } else {
        std::cout << "Failure getting data from source";
    }
}

std::string EcoalDataSource::getData() {
    return data;
}