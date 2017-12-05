#include "Simulator.h"
#include <queue>

using namespace std;

void Simulator::generate_routers()
{
	// Create the router
	auto routerA = make_shared<Router>("A");
	auto routerB = make_shared<Router>("B");
	auto routerC = make_shared<Router>("C");

	routers_.emplace(routerA->mac_address(), routerA);
	routers_.emplace(routerB->mac_address(), routerB);
	routers_.emplace(routerC->mac_address(), routerC);

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

std::map<string,int> Simulator::find_shortest_path(string sourceRouter, string destinationRouter)
{

	map<string, int> minimumDistance;

	//// Set the comparator for routers
	//auto comparator = [&minimumDistance](string left, string right)
	//{
	//	return minimumDistance[left] > minimumDistance[right];
	//};

	//priority_queue< string, vector<string>, function<bool(string, string)>> unoptimizedNodes(comparator);

	//// Set the minimum distance from the starting node to zero
	//minimumDistance.emplace(make_pair(sourceRouter, 0));;
	//unoptimizedNodes.push(sourceRouter);

	//// Set all initial distances to infinite
	//for (const auto& router : routers_)
	//{
	//	auto address = router.second->mac_address();
	//	if (address == sourceRouter) continue;
	//	minimumDistance.emplace(make_pair(address, INT_MAX));
	//	unoptimizedNodes.push(address);
	//}


	//while(!unoptimizedNodes.empty())
	//{
	//	const auto unoptimizedNodeAddress = unoptimizedNodes.top();
	//	unoptimizedNodes.pop();
	//	auto neighbors = network_[unoptimizedNodeAddress];
	//	for(const auto& neighbor : neighbors)
	//	{
	//		const auto neighborAddress = neighbor.first->mac_address();
	//		const auto neighborDistance = neighbor.second;
	//		const auto alternatePath = minimumDistance[unoptimizedNodeAddress] + neighborDistance;
	//		if(alternatePath < minimumDistance[neighborAddress])
	//		{
	//			minimumDistance[neighborAddress] = alternatePath;
	//		}
	//	}
	//}

	return minimumDistance;
}
