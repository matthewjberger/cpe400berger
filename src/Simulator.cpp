#include "Simulator.h"

using namespace std;

void Simulator::generate_routers()
{
	// Create the router
	auto routerA = make_shared<Router>("A");
	auto routerB = make_shared<Router>("B");
	auto routerC = make_shared<Router>("C");

	routers_.emplace(routerA->mac_address(), routerA);
	routers_.emplace(routerB->mac_address(), routerB);
	routers_.emplace(routerB->mac_address(), routerC);

	// Create some neighbors
	AdjacencyList<SharedRouter> routerANeighbors;
	AdjacencyList<SharedRouter> routerBNeighbors;
	AdjacencyList<SharedRouter> routerCNeighbors;

	routerANeighbors.push_back(make_pair(routerB, 10));
	routerANeighbors.push_back(make_pair(routerC, 4));

	routerBNeighbors.push_back(make_pair(routerA, 2));
	routerBNeighbors.push_back(make_pair(routerC, 6));

	routerCNeighbors.push_back(make_pair(routerA, 1));
	routerCNeighbors.push_back(make_pair(routerB, 7));

	// Add the routers to the network graph
	network_.emplace(routerA->mac_address(), routerANeighbors);
	network_.emplace(routerB->mac_address(), routerBNeighbors);
	network_.emplace(routerC->mac_address(), routerCNeighbors);

}


void Simulator::run_simulator()
{
	generate_routers();
}

void Simulator::find_shortest_path(string sourceRouter, string destinationRouter)
{
	// TODO: Implement this
}
