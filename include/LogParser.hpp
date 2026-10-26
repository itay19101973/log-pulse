#ifndef LOG_PARSER_HPP
#define LOG_PARSER_HPP

#include <string>
#include <vector>
#include <map>

struct LogEntry {
    std::string level; // INFO, WARN, ERROR
    std::string message;
};

class LogParser {
public:
    static LogEntry parseLine(const std::string& line);
    static std::map<std::string, int> countByLevel(const std::vector<std::string>& lines);
};

#endif