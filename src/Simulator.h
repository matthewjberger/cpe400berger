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

	void run_simulator();
	void generate_routers();
	void find_shortest_path(std::string sourceNode, std::string destinationNode);

private:
	Graph<SharedRouter> network_;
	std::map<std::string, SharedRouter> routers_;

};
