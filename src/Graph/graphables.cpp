#include <Graphy/Graph.hpp>
#include <Graphy/Graphable.hpp>

namespace graphy
{

	void Graph::add(Graphable& g)
	{
		graphables.push_back(&g);
		g.graph = this;
	}

	void Graph::remove(Graphable& g)
	{
		auto it = graphables.begin(), end = graphables.end();
		while (it != end) {
			if (*it == &g) {
				graphables.erase(it);
				g.graph = nullptr;
				break;
			}
			++it;
		}
	}

	void Graph::clear()
	{
		for (Graphable* g : graphables)
			g->graph = nullptr;
		graphables.clear();
	}

}
