#pragma once
#include <vector>
#include <map>

// Graph Example:
// NodeType for this example is 'string'
// 'A' -> { ("b",3), ("d",10) }
// 'B' -> { ("d",3), ("f",4) }
// 
// Graph Created:
//
// A -- 3 --> B -- 4 --> F
// |          |
// 10         |
// |          |
// V          |
// D <--- 3 ---

// Each adjacency list entry stores a pair of (neighbor, weight)
// where neighbor is of type 'NodeType'
template<typename NodeType>
using AdjacencyListEntry = std::pair<NodeType, int>;

template<typename NodeType>
using AdjacencyList = std::vector<AdjacencyListEntry<NodeType>>;

template<typename NodeType>
using Graph = std::map<std::string, AdjacencyList<NodeType>>;
