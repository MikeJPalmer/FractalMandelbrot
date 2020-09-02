#pragma once

#include <vector>
#include <utility> //allows for pair which stores a pair of values so we can return it as that pair of values.
#include "Zoom.h"

using namespace std;

namespace fractal {
	class ZoomList {
	private:
		double _xCenter{ 0.0 };
		double _yCenter{ 0.0 };
		double _scale{ 1.0 };
		int _width{ 0 };
		int _height{ 0 };
		vector<Zoom> zooms;

	public:
		ZoomList(int width, int height);
		void add(const Zoom& zoom);
		pair<double, double> doZoom(int x, int y);

	};

}