#include "Router.h"

Router::Router(std::string mediaAccessControlAddress)
{
	mediaAccessControlAddress_ = mediaAccessControlAddress;
	down_ = false;

	// TODO: Initialize routing table
}

std::string Router::mac_address() const
{
	return mediaAccessControlAddress_;
}

void Router::transmit()
{
	// TODO: Implement this, add chance of failing
}
