#ifndef LOGGER_H
#define LOGGER_H

#include <ctime>
#include <cstdio>
#include <string>
#include <vector>

/**
 * Game Logger
 */
namespace Logger
{
    /**
     * Normal/Info logging
     * @param p_log String you want to log
     */
    void log(std::string p_log);
    /**
     * Debug Logging
     * @param p_log String you want to log
     * @param p_file __FILE__
     * @param p_line __LINE__
     */
    void debug(std::string p_log, std::string p_file, int p_line);
    /**
     * Wanring Logging, should be used for exceptions
     * @param p_log String you want to log
     * @param p_file __FILE__
     * @param p_line __LINE__
     */
    void warning(std::string p_log, std::string p_file, int p_line);
    /**
     * Error Logging, will automatically exit the program with code 1
     * @param p_log String you want to log
     * @param p_file __FILE__
     * @param p_line __LINE__
     */
    void error(std::string p_log, std::string p_file, int p_line);

    /**
     * Saves the logs
     * Two files will be saved, one will be the time and date the logs were save, the other will be called latest.log, these files will be saved in a folder called logs
     */
    void saveLogs();

    /**
     * Change to toggle debug mode
     */
    inline bool debugMode = false;

    /**
     * Do not change this stuff
     */
    namespace priv {
        std::string getTimeString();
        inline std::vector<std::string> logs;
    }
}

#endif // LOGGER_H
