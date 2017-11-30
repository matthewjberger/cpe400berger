#pragma once
#include <map>
#include "Vertex.h"

class Graph
{
public:
	typedef std::map<std::string, Vertex *> VertexMap;
	VertexMap work;
	void add_vertex(const std::string&);
	void add_edge(const std::string& from, const std::string& to, int cost);
};
