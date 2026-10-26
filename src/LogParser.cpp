#include "LogParser.hpp"
#include <sstream>

LogEntry LogParser::parseLine(const std::string& line) {
    std::stringstream ss(line);
    std::string level, msg;
    
    if (ss >> level) {
        std::getline(ss, msg);
        if (!msg.empty() && msg[0] == ' ') {
            msg = msg.substr(1);
        }
        return {level, msg};
    }
    return {"UNKNOWN", line};
}

std::map<std::string, int> LogParser::countByLevel(const std::vector<std::string>& lines) {
    std::map<std::string, int> counts;
    for (const auto& line : lines) {
        LogEntry entry = parseLine(line);
        counts[entry.level]++;
    }
    return counts;
}