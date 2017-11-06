#include <Graphy/Graphy.hpp>

int main()
{
  using namespace graphy;
  Graph g;
  Axes ax;
  Equation eq([] (double x) {return x*x;});
  g.add(ax.x);
  g.add(ax.y);
  g.add(eq);
  g.mainloop();
  return 0;
}
