#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace fractal;
using namespace std;

namespace fractal {

	Bitmap::Bitmap(int width, int height) : 
		_width(width), _height(height), _pPixels(
				new uint8_t[width * height * 3] { }) { //initializing that _width and _height will be set as the parameters passed here, _pPixels will pass in width*height*3 (RGB).

	}

	bool Bitmap::write(string fileName) { //stub so we can fill more in later.
		
		BitmapFileHeader fileHeader; //setting header objects.
		BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) 
			+ (_width * _height * 3); //filesize is size of both headers + the size of the data.
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader); //tells you where the header's stop so we can write data.

		infoHeader.width = _width; //setting these so the values match.
		infoHeader.height = _height; //setting these so the values match.

		ofstream file; //creating a file to output to.
		
		file.open(fileName, ios::out | ios::binary); //opening fileName, outputting as binary file name.

		if (!file) { //if we get an error with the file creation then we'll return false.
			return false;
		}

		file.write((char *)&fileHeader, sizeof(fileHeader)); //casting the reference to a char pointer for fileHeader.
		file.write((char *)&infoHeader, sizeof(infoHeader)); //casting the reference to a char pointer for infoHeader.
		file.write((char *)_pPixels.get(), _width*_height*3); //need to use .get so we can get the raw pointer to the underlyine bytes, so now we can cast to char *.

		file.close();

		if (!file) { //same but for closing file, if that files we'll return false.
			return false;
		}

		return true; //return true if succeeds.
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) { //sets the pixel colors and location.
		uint8_t *pPixel = _pPixels.get(); //setting a pointer to the memory for _pPixel, represents the whole screen.

		pPixel += (y * 3) * _width + (x * 3); //y * _width is number of pixels/bytes in all the rows before the one we're interested specified by y, then we move it forward to the next x, * 3 is for RGB.

		pPixel[0] = blue; //reverse order for these: bitmap is indian file format so we store the least significant byte in the area of memory that has the smallest memory address (towards the right of the hex).
		pPixel[1] = green;
		pPixel[2] = red;
	}

	Bitmap::~Bitmap() //may not use destructor.
	{
	}
}