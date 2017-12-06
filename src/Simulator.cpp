#include "Simulator.h"

using namespace std;

Simulator::Simulator(const int numberOfNodes)
{
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
		routers_.push_back(new Router(i));
	}

	network_->add_edge(0, 1, 4);
	network_->add_edge(0, 7, 8);
	network_->add_edge(1, 2, 8);
	network_->add_edge(1, 7, 11);
	network_->add_edge(2, 3, 7);
	network_->add_edge(6, 8, 6);
	network_->add_edge(7, 8, 7);
}


void Simulator::run_simulator()
{
	generate_routers();
	network_->find_shortest_paths(0);
}
