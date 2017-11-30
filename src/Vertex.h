#pragma once
#include <vector>

struct Vertex {
	typedef std::pair<int, Vertex*> ve;
	std::vector<ve> adj; //cost of edge, destination vertex
	std::string name;
	explicit Vertex(const std::string s) : name(s) {}
};