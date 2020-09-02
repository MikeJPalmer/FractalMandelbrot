#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <memory>
#include <math.h> //needed for power function: pow(NULL,NULL)
#include <vector>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "Zoom.h"
#include "RGB.h"

using namespace std;

namespace fractal {
	class FractalCreator {
	private:
		int _width;
		int _height;
		unique_ptr<int[]> _histogram; //array of integers to store the pixels that corresponds with each assortment of iterations in memory, can't go beyond the 1000 iterations though, initializing the entire array at 0.
		unique_ptr<int[]> _fractal; //array of memory to store the total number of iterations per pixel.
		Bitmap _bitmap; //creating bitmap size 1920x1080 (might set this as my desktop wallpaper after done).
		ZoomList _zoomList;
		int _total{ 0 };

		vector<int> _ranges;
		vector<RGB> _colors;
		vector<int> _rangeTotals;

		bool _bGotFirstRange{ false };

	private:
		void calculateIteration();
		void calculateTotalIterations();
		void calculateRangeTotals();
		void drawFractal();
		void writeBitmap(string fileName);
		int getRange(int iterations) const;

	public:
		void run(string fileName);
		FractalCreator(int width, int height);
		void addRange(double rangeEnd, const RGB& rgb);
		virtual ~FractalCreator();
		void addZoom(const Zoom& zoom);

	};

}