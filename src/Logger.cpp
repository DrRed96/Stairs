#include "Logger.h"

#include <fstream>

void Logger::log(std::string p_log)
{
    std::string log = priv::getTimeString() + " [INFO] "; 
    log += p_log;
    priv::logs.push_back(log);
    printf("%s\n", log.c_str());
}

void Logger::debug(std::string p_log, std::string p_file, int p_line)
{
    if (debugMode)
    {
        std::string log = priv::getTimeString() + " [DEBUG: " + p_file + ":" + std::to_string(p_line) + "] "; 
        log += p_log;
        priv::logs.push_back(log);
        printf("%s\n", log.c_str());
    }
}

void Logger::warning(std::string p_log, std::string p_file, int p_line)
{
    std::string log = priv::getTimeString() + " [WARNING: " + p_file + ":" + std::to_string(p_line) + "] "; 
    log += p_log;
    priv::logs.push_back(log);
    printf("%s\n", log.c_str());
}

void Logger::error(std::string p_log, std::string p_file, int p_line)
{
    std::string log = priv::getTimeString() + " [ERROR: " + p_file + ":" + std::to_string(p_line) + "] "; 
    log += p_log;
    priv::logs.push_back(log);
    printf("%s\n", log.c_str());
    Logger::log("Exiting with code 1");
    saveLogs();
    exit(1);
}

std::string Logger::priv::getTimeString()
{
    std::string log;
    time_t cur_time = time(0);
    tm *local = localtime(&cur_time);
    log = "[";
    log += std::to_string(local->tm_hour);
    log += ":";
    log += std::to_string(local->tm_min);
    log += ":";
    log += std::to_string(local->tm_sec);
    log += "]";
    return log;
}

void Logger::saveLogs()
{
    time_t cur_time = time(0);
    tm *local = localtime(&cur_time);
    std::string fileName = std::to_string(local->tm_mday) + "_" + std::to_string(local->tm_mon) + "_" + std::to_string(local->tm_year) + "__" + std::to_string(local->tm_hour) + "_" + std::to_string(local->tm_min) + "_" + std::to_string(local->tm_sec);
    std::string logConcat = "Stairs Logs - " + fileName + "\n";
    for (std::string str : priv::logs)
    {
        logConcat += str;
        logConcat += "\n";
    }
    std::string filePath = "logs/" + fileName + ".log";
    std::ofstream file(filePath, std::ofstream::binary);
    file << logConcat;
    file.close();
    std::ofstream latest("logs/latest.log", std::ofstream::binary);
    latest << logConcat;
    latest.close();
}
