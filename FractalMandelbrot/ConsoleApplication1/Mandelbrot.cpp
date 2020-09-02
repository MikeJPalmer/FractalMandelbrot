#include "Mandelbrot.h"
#include <complex> //complex number class.

using namespace std;

namespace fractal {

	Mandelbrot::Mandelbrot()
	{
	}


	Mandelbrot::~Mandelbrot()
	{
	}

	int Mandelbrot::getIterations(double x, double y) {

		complex<double> z = 0; //initializing to 0.
		complex<double> c(x, y); //passing in x, y as a function/method.

		int iterations = 0; //initially set to 0, this will count our iterations from 0.

		while (iterations < MAX_ITERATIONS) { //while less than 1000 iterations that we set in header.
			z = z * z + c; //initially it'd be 0 + c which sets the new z, and then we cycle back through again.

			if (abs(z) > 2) { //abs(absolute value) gets the magnitude of a comlex number, if this remains below 2 then it stays within the Mandelbrot set and does not go to infinite.
				break; //break the loop.
			}

			iterations++; //incrementing iteration through each loop.

		}

		return iterations;
	}

}