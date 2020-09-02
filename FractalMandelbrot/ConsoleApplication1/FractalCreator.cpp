
#include "FractalCreator.h"
#include <assert.h>
#include <iostream>

namespace fractal {

	void FractalCreator::run(string fileName) {

		calculateIteration();
		std::cout << "Completed Iteration Calculation, calculating total iterations..." << std::endl;
		calculateTotalIterations();
		std::cout << "Completed Total Iteration Calculation, calculating range totals..." << std::endl;
		calculateRangeTotals();
		std::cout << "Completed Range Totals Calculation, starting drawing..." << std::endl;
		drawFractal();
		std::cout << "Fractal drawn, writing file..." << std::endl;
		writeBitmap("test.bmp"); //creating file test.bmp.
	}

	void FractalCreator::addRange(double rangeEnd, const RGB& rgb) {
		_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
		_colors.push_back(rgb);

		if (_bGotFirstRange) {
			_rangeTotals.push_back(0);
		}

		_bGotFirstRange = true;

	}

	int FractalCreator::getRange(int iterations) const {
		int range{ 0 };

		for (int i = 1; i < _ranges.size(); i++) {
			range = i;

			if (_ranges[i] > iterations) {
				break;
			}

		}

		range--;

		assert(range > -1);
		assert(range < _ranges.size());

		return range;
	}

	void FractalCreator::addZoom(const Zoom& zoom) {
		_zoomList.add(zoom);
	}

	FractalCreator::FractalCreator(int width, int height): _width(width), _height(height), _histogram(new int[Mandelbrot::MAX_ITERATIONS]{ }),
		_fractal(new int[_width*_height]{ }), _bitmap(_width, _height), _zoomList(_width, _height) {

		_zoomList.add(Zoom(_width / 2, _height / 2, 4.0 / _width));
	}
	FractalCreator::~FractalCreator() {

	}

	void FractalCreator::calculateIteration() {
		for (int y = 0; y < _height; y++) { //this creates a pixel at every y point.
			for (int x = 0; x < _width; x++) { //sets pixel at every x point.

				pair<double, double> coords = _zoomList.doZoom(x, y);

				int iterations = Mandelbrot::getIterations(coords.first, coords.second); //passing our Fractal values into the Mandelbroth iteration loop, referencing the two in the coords pair.

				_fractal[y * _width + x] = iterations; //should give us each point on the x/y pixel and what the number of iterations were used.

				if (iterations != Mandelbrot::MAX_ITERATIONS) {
					_histogram[iterations]++; //incrementing the number of iterations which starts at 0 to build out the histogram.
				}
			}
		}
	}

	void FractalCreator::calculateRangeTotals() {

		int rangeIndex = 0;

		for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
			int pixels = _histogram[i];

			if (i >= _ranges[rangeIndex + 1]) {
				rangeIndex++;
			}

			_rangeTotals[rangeIndex] += pixels;
		}

	}

	void FractalCreator::calculateTotalIterations() {
		for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
			_total += _histogram[i];
		}
	}

	void FractalCreator::drawFractal() {

		for (int y = 0; y < _height; y++) { //this creates a pixel at every y point.
			for (int x = 0; x < _width; x++) { //sets pixel at every x point.

				int iterations = _fractal[y * _width + x];

				int range = getRange(iterations);
				int rangeTotal = _rangeTotals[range];
				int rangeStart = _ranges[range];

				RGB& startColor = _colors[range];
				RGB& endColor = _colors[range+1];
				RGB colorDiff = endColor - startColor;

				uint8_t red = 0; //all initialized as 0 for black.
				uint8_t green = 0;
				uint8_t blue = 0;

				if (iterations != Mandelbrot::MAX_ITERATIONS) { //if it's not the max iterations then we keep the max iterations as black and color everything else.

					int totalPixels = 0;

					for (int i = rangeStart; i <= iterations; i++) { //as we move through pixels with a low number of iterations to higher, we calculate a color for each group of pixels with a particular number of iterations.
						totalPixels += _histogram[i];
					}

					//green = pow(255, hue); //power of 255 because hue varies from 0 to 1.
					
					red = startColor.r + colorDiff.r * (double)totalPixels / rangeTotal;
					green = startColor.g + colorDiff.g * (double)totalPixels / rangeTotal;
					blue = startColor.b + colorDiff.b * (double)totalPixels / rangeTotal;

				}

				_bitmap.setPixel(x, y, red, green, blue); //setting color for the pixels.
			}
		}
	}

	void FractalCreator::writeBitmap(string fileName) {
		_bitmap.write(fileName);
	}

}