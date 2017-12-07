#pragma once
#include <vector>

class Router
{
public:
	explicit Router(int id);
	~Router() = default;

	void transmit() const;
	void id();

private:
	std::vector<int> routingTable_;
	bool down_;
	int id_; // Equivalent to a MAC address

};
