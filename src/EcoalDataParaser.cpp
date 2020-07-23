#include <regex>
#include <iostream>
#include "EcoalDataParser.h"

ParsedData EcoalDataParser::parse(std::string data) {
    std::regex word_regex("<reg[^/>]+(\\/>){1}");
    auto words_begin = std::sregex_iterator(data.begin(), data.end(), word_regex);

    ParsedData parsed;
    std::for_each(words_begin, std::sregex_iterator(), [&parsed](auto s){
        auto line = s.str();
        std::regex id_rgx{"tid=\"([a-z_]*)\""};
        std::smatch id_match;
        std::regex_search(line, id_match, id_rgx);

        std::regex value_rgx{"v=\"([0-9]*.[0-9]*)\""};
        std::smatch value_match;
        std::regex_search(line, value_match, value_rgx);

        if( id_match.size() >= 2 && value_match.size() >= 2 ) {
            parsed.push_back({id_match[1].str(), std::stof(value_match[1].str())});
        }
    });

    return parsed;
}
