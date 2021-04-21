#ifndef GRAPH_H
#define GRAPH_h

#include <iostream>
#include <vector>
#include <list>

namespace graph
{
	class Graph
	{
	private:
		std::vector < std::list<int> > data;

		void DFSHellper(size_t v, size_t* marks) const;
	public:
		/* Constructor & destructor */
		Graph(size_t verticesCount = 0);
		~Graph();

		bool ContainsVertex(size_t v) const;
		bool ContainsEdge(size_t from, size_t to) const;

		Graph& AddEdge(size_t from, size_t to);

		/* Depth-first algorithm */
		Graph& DFS();

		/* Finding strongly connected components */
		Graph& DFSComponents();

		/* Getters */
		size_t Size() const;

		/* Friend functions */
		friend std::ostream& operator << (std::ostream& os, Graph& graph);
	};
}

#endif

