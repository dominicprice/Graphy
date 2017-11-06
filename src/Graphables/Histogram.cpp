#include <Graphy/Graphables/Histogram.hpp>
#include <SFDraw.h>

namespace graphy
{

	//Bin

	Bin::Bin(double x, double width, double height) :
		x(x), width(width), height(height)
	{

	}

	//Histogram

	Histogram::Histogram()
	{

	}

	Histogram::Histogram(std::initializer_list<std::pair<std::string, double>> bins)
	{
		double cur_index = 0;
		for (const auto& elem : bins) {
			//add_bin(elem.first, cur_index, 1, elem.second);
			Bin bin(cur_index, 1, elem.second);
			bin.style.label.text = elem.first;
			bin.style.label.enabled = true;
			this->bins.push_back(bin);
			cur_index++;
		}
	}

	void Histogram::draw()
	{
		//Calculate normalisation if necessary
		double norm = 0;
		if (normalise) {
			for (const auto& bin : bins)
				norm += bin.height * bin.width;
		}
		if (norm == 0) {
			norm = 1;
		}

		for (const Bin& bin : bins) {
			//Draw bin
			canvas.draw(Canvas::Background, sfd::rectangle(
				sf::FloatRect{ map_x(bin.x), map_y(bin.height / norm), rmap_x(bin.width), rmap_y(bin.height / norm) },
				bin.style.color));
			//Draw label
			if (bin.style.label.enabled) {
				canvas.draw(Canvas::Labels, sfd::text(
					bin.style.label.text, canvas.font(), bin.style.label.size,
					map(bin.x + (bin.width / 2), 0),
					true, bin.style.label.color));
			}
		}
	}

	Bin& Histogram::get_bin(const std::string& label)
	{
		std::vector<Bin>::iterator it = std::find_if(bins.begin(), bins.end(), [&label](const Bin& bin) {return bin.style.label.text == label;});
		if (it == bins.end())
			throw "Bin not found!";
		else
			return *it;
	}

	Histogram::iterator Histogram::begin()
	{
		return bins.begin();
	}

	Histogram::iterator Histogram::end()
	{
		return bins.end();
	}
}
