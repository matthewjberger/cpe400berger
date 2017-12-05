#pragma once
#include <map>
#include <string>

class Router
{
public:
	explicit Router(std::string mediaAccessControlAddress);
	~Router() = default;

	// TODO: Init routing table

	std::string mac_address() const;
	void transmit();

private:
	std::string mediaAccessControlAddress_;
	std::map<std::string, int> routingTable_;
	bool down_;

};
