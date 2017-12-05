#pragma once
#include <map>

class Router
{
public:
	Router();
	~Router() = default;

	// TODO: Init routing table

	void transmit();

private:
	std::string mediaAccessControlAddress_;
	std::map<std::string, int> routingTable_;
	bool down_;

};
