#include <Graphy/Graphables/Point.hpp>
#include <SFMath.h>

namespace graphy
{
	std::string Point::resolve_label() const
	{
		std::string out = style.label.text;
		for (int i = 0; i < static_cast<int>(out.size()) - 3; ++i) {
			if (
				out[i] == '{' && //Starts with left curly brace
				out[i + 1] - '0' < 10 && //Then has a number between 0 and 9
				out[i + 3] == '}' //Ends with a right curly brace
				) {
				if (out[i + 2] == 'x') {
					out.replace(i, 4, sfm::dtos(x, out[i + 1] - '0'));
				}
				else if (out[i + 2] == 'y') {
					out.replace(i, 4, sfm::dtos(y, out[i + 1] - '0'));
				}
			}
		}
		return out;
	}
}
