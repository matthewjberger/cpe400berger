#include "Router.h"
#include <time.h>
#include "Logger.h"
#include <chrono>
#include <thread>
#include <string>

using namespace std;

Router::Router(const int id)
{
	down_ = false;
	id_ = id;
	srand(static_cast<unsigned>(time(nullptr)));
}

void Router::transmit(const int retransmitNumber) const
{
	if(retransmitNumber >= 3)
	{
		Logger::instance()->log("Exceeded max number of retransmits! Connection failure, could not utilize damaged link!", LogLevel::ERROR);
	}

	Logger::instance()->log("Transmitting packets for router #" + to_string(id_));
	this_thread::sleep_for(chrono::milliseconds(rand() % 300 + 200));
	const auto successRoll = rand() % 10;
	if(successRoll > 8)
	{
		Logger::instance()->log("No ack received, resending...", LogLevel::WARNING);
		this_thread::sleep_for(chrono::milliseconds(rand() % 100 + 100));
	}
	if(successRoll != 4)
	{
		Logger::instance()->log("Packet transfer successful!");
	}
	else
	{
		Logger::instance()->log("Packet loss detected! Connection failure. Retransmitting... #" + to_string(id_), LogLevel::WARNING);
		transmit(retransmitNumber + 1);
	}
}
