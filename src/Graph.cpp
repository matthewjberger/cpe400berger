#include "Graph.h"
#include <queue>
#include <functional>
#include "Logger.h"

using namespace std;

Graph::Graph(const int numberOfNodes) : numberOfNodes_(numberOfNodes)
{
	nodeAdjacencyLists_ = new list<Node>[numberOfNodes];
}

void Graph::add_edge(const int source, int destination, int weight) const
{
	nodeAdjacencyLists_[source].push_back(make_pair(destination, weight));
}

vector<int> Graph::find_shortest_paths(int source) const
{
	Logger::instance()->log("Reconstructing routing table...");
	priority_queue< Node, vector <Node>, greater<Node> > minHeap;
	// Initial distances are all infinite
	vector<int> distances(numberOfNodes_, INT_MAX);

	// Distance from source to itself is zero
	minHeap.push(make_pair(0, source));
	distances[source] = 0;

	// While there are distances that haven't been finalized
	while (!minHeap.empty())
	{
		// Get the next node
		const auto sourceNode = minHeap.top().second;
		minHeap.pop();

		// Investigate the neighboring nodes
		for (const auto& neighborInfo : nodeAdjacencyLists_[sourceNode])
		{
			auto neighboringNode = neighborInfo.first;
			const auto weight = neighborInfo.second;

			// If the distance to the neighbor can be updated
			if (distances[neighboringNode] > distances[sourceNode] + weight)
			{
				// Update it and add the node back to the heap
				distances[neighboringNode] = distances[sourceNode] + weight;
				minHeap.push(make_pair(distances[neighboringNode], neighboringNode));
			}
		}
	}
	Logger::instance()->log("Routing table successfully updated!");
	return distances;
}

int Graph::number_of_nodes() const
{
	return numberOfNodes_;
}
