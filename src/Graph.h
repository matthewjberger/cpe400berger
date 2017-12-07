#pragma once
#include <list>
#include <vector>

using Node = std::pair<int, int>;

class Graph
{
public:
	explicit Graph(int numberOfNodes);
	void add_edge(int source, int destination, int weight) const;
	std::vector<int> find_shortest_paths(int source) const;
	int number_of_nodes() const;

private:
	int numberOfNodes_;
	std::list<std::pair<int, int>> *nodeAdjacencyLists_;
};
