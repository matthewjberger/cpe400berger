#pragma once
#include <iomanip>

enum class LogLevel
{
	INFO, 
	ERROR,
	WARNING
};

class Logger
{
public:
	/* Static access method. */
	static Logger* instance();

	static void log(std::string message, LogLevel level = LogLevel::INFO);

	static std::string current_time();

private:
	static Logger* instance_;
	Logger(){}

};
