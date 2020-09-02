#include <iostream>
#include "FractalCreator.h"
#include "Zoom.h"

using namespace std;
using namespace fractal;


int main() {

	FractalCreator fractalCreator(1920, 1080);

	fractalCreator.addRange(0.0, RGB(0, 0, 0));
	fractalCreator.addRange(0.2, RGB(255, 0, 255));
	fractalCreator.addRange(0.4, RGB(128, 255, 128));
	fractalCreator.addRange(0.6, RGB(176, 154, 78));
	fractalCreator.addRange(0.8, RGB(212, 132, 128));
	fractalCreator.addRange(1.0, RGB(196, 128, 255));

	fractalCreator.addZoom(Zoom(403.5, 444, 0.1));
	fractalCreator.addZoom(Zoom(1183.5, 264, 0.1));

	fractalCreator.run("test.bmp"); //creating file test.bmp.

	cout << "Finished." << endl; //console output so we know that we finished.

	return 0;
}