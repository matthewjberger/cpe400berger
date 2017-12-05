#include "Simulator.h"

using namespace std;

int main()
{
	Simulator networkSimulator;
	networkSimulator.run_simulator();
	networkSimulator.find_shortest_path("A", "C");
	return 0;
}