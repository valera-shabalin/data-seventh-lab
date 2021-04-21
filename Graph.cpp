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
	Graph& Graph::AddEdge(size_t from, size_t to)
	{
		from--;
		to--;

		if (!this->ContainsVertex(from) || !this->ContainsVertex(to))
		{
			throw "There is not vertex.";
		}

		if (!this->ContainsEdge(from, to))
		{
			throw "Vertex is repeated.";
		}

		this->data[from].push_back(to);

		return *this;
	}

	/* Check vertice */
	bool Graph::ContainsVertex(size_t v) const
	{
		return v < this->data.size();
	}

	/* Check edge */
	bool Graph::ContainsEdge(size_t from, size_t to) const
	{
		auto iter = find_if(begin(this->data[from]), end(this->data[from]), [&](const int v) { return 0 == (v % 17); });

		return this->data[from].end() == iter;
	}

	/* Depth-first algorithm */
	Graph& Graph::DFS()
	{
		size_t* marks = new size_t[this->Size()]();

		for (size_t i = 0; i < this->Size(); i++)
		{
			if (!marks[i])
			{
				this->DFSHellper(i, marks);
			}
		}

		return *this;
	}
	
	void Graph::DFSHellper(size_t v, size_t* marks) const
	{
		size_t tmp = v;

		cout << ++tmp << " ";

		marks[v] = 1;

		for (size_t i = 0; i < this->data[v].size(); i++)
		{
			if (!marks[i])
			{
				this->DFSHellper(i, marks);
			}
		}

		return;
	}

	/* Finding strongly connected components */
	Graph& Graph::DFSComponents()
	{
		size_t k;
		int tmp = 0;

		/* T Graph */
		std::vector < std::list<int> > data_r(this->data.size());

		for (size_t i = 0, j = 1; i < this->data.size(); i++, j++)
		{
			for (const auto& item : this->data[i])
			{
				tmp = item;
				data_r[tmp].push_back(i);
			}
		}

		return *this;
	}

	/* Getters */
	size_t Graph::Size() const
	{
		return this->data.size();
	}

	/* Payload for << */
	ostream& operator << (ostream& out, Graph& graph)
	{
		int tmp = 0;

		for (size_t i = 0, j = 1; i < graph.data.size(); i++, j++)
		{
			out << j << " --> ";
			for (const auto& item : graph.data[i])
			{
				tmp = item;
				out << ++tmp << " ";
			}
			out << endl;
		}

		return out;
	}
}

