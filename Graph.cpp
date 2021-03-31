#include "Graph.h"

using namespace std;

namespace graph
{
	/* Constructor */
	Graph::Graph(size_t verticesCount)
	{
		this->data.resize(verticesCount);
	}

	/* Destructor */
	Graph::~Graph()
	{
		
	}

	/* Insert edge */
	bool Graph::AddEdge(size_t from, size_t to)
	{
		if (from > this->data.size())
		{
			throw "There is not vertex.";
		}

		this->data[from].push_back(to);

		return true;
	}

	/* Getters */
	size_t Graph::GetVerticesCount() const
	{
		return this->data.size();
	}

	/* Payload for << */
	ostream& operator << (ostream& out, Graph& graph)
	{
		for (size_t i = 0, j = 1; i < graph.data.size(); i++, j++)
		{
			out << j << ") ";

			for (const auto& item : graph.data[i])
			{
				int value = item;
				out << ++value << " ";
			}

			out << endl;
		}

		return out;
	}
}

