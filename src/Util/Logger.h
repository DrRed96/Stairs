#ifndef LOGGER_H
#define LOGGER_H

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

class Logger
{
    public:
    static void log(std::string message)
    {
        printf("%s\n", message.c_str());
        messages.push_back(message);
    }

    static void save()
    {
        std::string message = "Stars Log File\n";
        for (std::string msg : messages)
        {
            message += msg + "\n";
        }
        std::string date = __DATE__, time = __TIME__;
        std::string fileName = "log\\" + date + " " + time + ".txt";
        std::ofstream file(fileName, std::ofstream::binary);
        file << message;
    }

    private:
    static std::vector<std::string> messages;
};

#endif // LOGGER_H
