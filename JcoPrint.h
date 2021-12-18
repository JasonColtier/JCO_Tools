#ifndef JCOPRINT_H
#define JCOPRINT_H

#include <iostream>

enum class LogType
{
    LOG,
    WARN,
    ERROR,
    SUCCESS,
    INFO,
};

static std::string _EnumToString(LogType logType)
{
    switch (logType)
    {
    case LogType::LOG: return "LOG    ";
    case LogType::WARN: return "\x1B[33mWARN   ";
    case LogType::ERROR: return "\x1B[31mERROR  ";
    case LogType::SUCCESS: return "\x1B[32mSUCCESS";
    case LogType::INFO: return "\x1B[34mINFO   ";
    }
    return "LOG";
}

#define LOG(...) \
    std::cout<<"LOG     - "<<__FUNCTION__<<"():"<<__LINE__<<" - "<<__VA_ARGS__<<std::endl


#define LOG_COLOR(Logtype,...) \
    std::cout<<_EnumToString(Logtype)<<" - "<<__FUNCTION__<<"():"<<__LINE__<<" - "<<__VA_ARGS__<<"\033[0m\t\t"<<std::endl

#endif //JCOPRINT_H