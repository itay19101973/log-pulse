#include <iostream>
#include <vector>
#include "LogParser.hpp"

int main() {
    std::cout << "--- LogPulse Engine v1.8-patch ---" << std::endl;
    
    std::vector<std::string> sampleLogs = {
    "[INFO] Database connection established",
    "[ERROR] Timeout connecting to server",
    "[WARN] High memory usage detected",
    "[ERROR] Out of memory exception",
    "[DEBUG] Cache hit ratio at 98.5%" // <-- Add this line
    };

    auto summary = LogParser::countByLevel(sampleLogs);

    for (const auto& [level, count] : summary) {
        std::cout << level << ": " << count << std::endl;
    }

    return 0;
}