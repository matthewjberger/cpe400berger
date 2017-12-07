#include "Simulator.h"
#include <iostream>
#include "Logger.h"
#include <string>

using namespace std;

Simulator::Simulator(const int numberOfNodes)
{
	Logger::instance()->log("Initializing Simulation with: " + to_string(numberOfNodes) + "nodes");
	network_ = new Graph(numberOfNodes);
}

Simulator::~Simulator()
{
	delete network_;
}

void Simulator::generate_routers()
{
	for(auto i = 0; i < network_->number_of_nodes(); i++)
	{
		Logger::instance()->log("Initializing Router Number #" + to_string(i));
		routers_.push_back(new Router(i));
	}

	Logger::instance()->log("Generating network links...");
	// eventually this should have actually random links
	const auto totalNodes = network_->number_of_nodes();
	for(auto i = 0; i < network_->number_of_nodes(); i++)
	{
		const auto sourceNode = rand() % (totalNodes - 1);
		const auto cost = (rand() % 10) + 1;
		network_->add_edge(i, sourceNode, cost);
	}
	Logger::instance()->log("Network links successfully generated!");
}


void Simulator::run_simulator()
{
	Logger::instance()->log("Simulation running...");
	generate_routers();
	network_->find_shortest_paths(0);
	for(auto router : routers_)
	{
		router->transmit();
	}
	Logger::instance()->log("Simulation Complete!");
}
