#pragma once
#include "Graph.h"
#include "Router.h"


class Simulator
{
public:
	Simulator() = default;
	~Simulator() = default;

	void run_simulator(int numberOfNodes);

private:
	Graph<Router> network_;

};
