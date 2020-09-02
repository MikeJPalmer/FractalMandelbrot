#pragma once

namespace fractal {
	class Mandelbrot {
	public:
		static const int MAX_ITERATIONS{ 50000 }; //the more iterations you're willing to do for each pixel, the better quality of the image.


	public:
		Mandelbrot();
		~Mandelbrot();

		static int getIterations(double x, double y);
	};

}