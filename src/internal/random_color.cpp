#include <random>
#include <SFML/Graphics/Color.hpp>
#include <time.h>

namespace xsf
{

	sf::Color random_color(
		unsigned int r_min, unsigned int r_max,
		unsigned int g_min, unsigned int g_max,
		unsigned int b_min, unsigned int b_max,
		unsigned int a_min, unsigned int a_max)
	{
		static std::mt19937 en(static_cast<unsigned int>(time(0)));

		static std::uniform_int_distribution<unsigned int> r(r_min, r_max);
		static std::uniform_int_distribution<unsigned int> g(g_min, g_max);
		static std::uniform_int_distribution<unsigned int> b(b_min, b_max);
		static std::uniform_int_distribution<unsigned int> a(a_min, a_max);

		return sf::Color(r(en), g(en), b(en), a(en));
	}

}