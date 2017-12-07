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

void Router::transmit() const
{
	Logger::instance()->log("Transmitting packets for router #" + to_string(id_));
	this_thread::sleep_for(chrono::milliseconds(rand() % 300 + 200));
	if(rand() % 10 != 4)
	{
		Logger::instance()->log("Packet transfer successful!");
	}
	else
	{
		Logger::instance()->log("Packet loss detected! Connection failure. Retransmitting... #" + to_string(id_), LogLevel::ERROR);
		transmit();
	}
}
