#pragma once

#include <string>
#include <cstdint>
using namespace std;

namespace fractal {
	class Bitmap {
	private:
		int _width{0}; //initializing them to 0 for now, but will set later on.
		int _height{0}; //initializing them to 0 for now, but will set later on.
		unique_ptr<uint8_t[]> _pPixels{ nullptr }; //equivalent to an unsigned chart type, initialized as nullptr, this is our memory allocation, unique_ptr so we don't need to define destroy memory.

	public:
		Bitmap(int width, int height); //constructor where we'll past int width and int height.
		void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue); //out setPixel method to set the pixels in the bitmap via x/y axis, uint8_t is for unsigned 8 bit int for each color.
		bool write(string fileName); //create bitmap, set pixels, and then we write it with this method, specifying the filename to write to, bool so it can be 0 if it fails.
		~Bitmap();
	};

}