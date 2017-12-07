#include "Simulator.h"
using namespace std;

int main()
{
	const auto NUM_ROUTERS = 100;
	Simulator simulator(NUM_ROUTERS);
	simulator.run_simulator();
	return 0;
}