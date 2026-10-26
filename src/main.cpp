#include <iostream>
#include <vector>
#include "LogParser.hpp"

int main() {
    std::cout << "--- LogPulse Production Analyzer v3.---3-3-3-3-33.0 ---" << std::endl;
    
    std::vector<std::string> sampleLogs = {
    "[INFO] Database connection established",
    "[ERROR] Timeout connecting to server",
    "[ERROR] Out of memory exception",
    "[DEBUG] Cache hit ratio at 98.5%" // <-- Add this line
    };

    auto summary = LogParser::countByLevel(sampleLogs);

    for (const auto& [level, count] : summary) {
        std::cout << level << ": " << count << std::endl;
    }

    return 0;
}