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
		bool *marks = new bool[this->Size()]();

		for (size_t i = 0; i < this->Size(); i++)
		{
			if (!marks[i])
			{
				this->DFSHellper(i, marks);
			}
		}

		return *this;
	}
	
	void Graph::DFSHellper(size_t v, bool* marks) const
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
		/* Initialization vectors */
		vector<bool>marks;
		vector<size_t>component, order;

		/* Create T Graph */
		vector < list<int> > data_r(this->Size());
		size_t tmp = 0;
		for (size_t i = 0, j = 1; i < this->Size(); i++, j++)
		{
			for (const auto& item : this->data[i])
			{
				tmp = item;
				data_r[tmp].push_back(i);
			}
		}

		marks.assign(this->Size(), false);
		for (size_t i = 0; i < this->Size(); i++)
		{
			if (!marks[i])
			{
				this->DFSComponentsHellperOne(i, marks, order);
			}
		}

		marks.assign(this->Size(), false);
		for (size_t i = 0, j = 1; i < this->Size(); ++i, j++) {
			size_t v = order[this->Size() - 1 - i];
			if (!marks[v]) 
			{
				this->DFSComponentsHellperTwo(v, marks, data_r, component);
				cout << j << " --> ";
				for (size_t j = 0; j < component.size(); j++)
				{
					cout << ++component[j] << " ";
				}
				cout << endl;
				component.clear();
			}
		}

		return *this;
	}

	void Graph::DFSComponentsHellperOne(size_t v, vector<bool> &marks, vector<size_t> &order) const
	{
		size_t tmp = 0;
		marks[v] = true;

		for (const auto& item : this->data[v])
		{
			if (!marks[item])
			{
				tmp = item;
				this->DFSComponentsHellperOne(tmp, marks, order);
			}
		}

		order.push_back(v);

		return;
	}

	void Graph::DFSComponentsHellperTwo(size_t v, vector<bool>& marks, vector < list<int> > & data_r, vector<size_t> &component) const
	{
		size_t tmp = 0;
		marks[v] = true;

		component.push_back(v);

		for (const auto& item : data_r[v])
		{
			if (!marks[item])
			{
				tmp = item;
				this->DFSComponentsHellperTwo(tmp, marks, data_r, component);
			}
		}

		return;
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

