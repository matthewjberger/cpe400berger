#include "Graph.h"

using namespace std;

void Graph::add_vertex(const string &name)
{
	const auto itr = work.find(name);
	if (itr == work.end())
	{
		const auto vertex = new Vertex(name);
		work[name] = vertex;
	}
}

void Graph::add_edge(const string & from, const string & to, int cost)
{
	auto f = work.find(from)->second;
	auto t = work.find(to)->second;
	const auto edge = make_pair(cost, t);
	f->adj.push_back(edge);
}