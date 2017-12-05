#include "Simulator.h"

using namespace std;

void Simulator::add_router_to_graph(Router* router, AdjacencyList<SharedRouter> routerAdjacencyList)
{
	network_.emplace(router->mac_address(), routerAdjacencyList);
}


void Simulator::run_simulator(int numberOfNodes)
{
	// Create the router
	auto routerA = std::make_shared<Router>("A");
	auto routerB = std::make_shared<Router>("B");
	auto routerC = std::make_shared<Router>("C");

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
	add_router_to_graph(routerA.get(), routerANeighbors);
	add_router_to_graph(routerB.get(), routerBNeighbors);
	add_router_to_graph(routerC.get(), routerCNeighbors);
}
