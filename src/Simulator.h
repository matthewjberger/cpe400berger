#pragma once
#include "Graph.h"
#include "Router.h"

class Simulator
{
public:
	explicit Simulator(int numberOfNodes);
	~Simulator();

	void run_simulator();

private:
	void generate_routers();
	Graph* network_;
	std::vector<Router*> routers_;
};
