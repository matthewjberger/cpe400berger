#include "Logger.h"
#include <iostream>
#include <chrono>
#include <sstream>

using namespace std;

Logger* Logger::instance_ = nullptr;

Logger* Logger::instance()
{
	if (instance_ == nullptr)
	{
		instance_ = new Logger();
	}

	return instance_;
}

string Logger::current_time()
{
	const auto now = chrono::system_clock::now();
	auto in_time_t = chrono::system_clock::to_time_t(now);

	stringstream ss;
	ss << put_time(localtime(&in_time_t), "%X");
	return ss.str();
}

void Logger::log(const string message, const LogLevel level)
{
	string type;
	switch(level)
	{
		case LogLevel::INFO:
			type = "INFO"; 
		break;
		case LogLevel::ERROR: 
			type = "ERROR"; 
		break;
		case LogLevel::WARNING: 
			type = "WARNING"; 
		break;
		default: type = "INFO"; 
		break;
	}
	cout << current_time() << "(" << type << "): " << message << endl;
}
