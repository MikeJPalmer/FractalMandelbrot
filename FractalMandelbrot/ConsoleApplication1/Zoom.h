#pragma once

namespace fractal { 

	struct Zoom { //class for creating Zooming of pixels in the bitmap.
		int x{ 0 };
		int y{ 0 };
		double scale{ 0.0 };

		Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {};

	};

}