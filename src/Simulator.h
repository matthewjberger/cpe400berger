#pragma once
#include "Graph.h"
#include "Router.h"
#include <memory>


using SharedRouter = std::shared_ptr<Router>;

class Simulator
{
public:
	Simulator() = default;
	~Simulator() = default;

	void run_simulator(int numberOfNodes);

private:
	Graph<SharedRouter> network_;

	void add_router_to_graph(Router* router, AdjacencyList<SharedRouter> routerAdjacencyList);

};
