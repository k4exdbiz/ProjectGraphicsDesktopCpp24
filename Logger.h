#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>



class Logger
{
public:

	static enum LogLevel
	{
		LOG_INFO = 0,
		LOG_WARNING,
		LOG_ERROR,
		LOG_EXIT
	};

	Logger() = delete;

	template <typename T>
	static void log(LogLevel logLvl, T val)
	{
		switch (logLvl)
		{
		case LOG_INFO:
			std::cout << "[INFO]: " << val << std::endl;
			break;
		case LOG_WARNING:
			std::cout << "[WARNING]: " << val << std::endl;
			break;
		case LOG_ERROR:
			std::cout << "[ERROR]: " << val << std::endl;
			break;
		case LOG_EXIT:
			std::cout << "[EXIT]: " << val << std::endl;
			break;
		default:
			break;
		}
	}
};

#define logInfo(message) Logger::log(Logger::LogLevel::LOG_INFO, message)
#define logWarning(message) Logger::log(Logger::LogLevel::LOG_WARNING, message)
#define logError(message) Logger::log(Logger::LogLevel::LOG_ERROR, message)
#define logExit(message) Logger::log(Logger::LogLevel::LOG_EXIT, message)


#endif