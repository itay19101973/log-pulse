#include <gtest/gtest.h>
#include "LogParser.hpp"

TEST(LogParserTest, ParsesLogLevelCorrectly) {
    std::string sample = "[ERROR] Database Failed";
    LogEntry entry = LogParser::parseLine(sample);
    
    EXPECT_EQ(entry.level, "[ERROR]");
    EXPECT_EQ(entry.message, "Database Failed");
}

TEST(LogParserTest, CountsLogsAccurately) {
    std::vector<std::string> logs = {
        "[INFO] OK",
        "[ERROR] Fail 1",
        "[ERROR] Fail 2"
    };
    auto summary = LogParser::countByLevel(logs);
    
    EXPECT_EQ(summary["[ERROR]"], 2);
    EXPECT_EQ(summary["[INFO]"], 1);
}