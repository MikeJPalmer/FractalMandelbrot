#pragma once

#include <cstdint> //header to guarantee both 32-bit and 16-bit ints. (int32_t and int16_t)

using namespace std;

#pragma pack(2) //packing so we can ensure that these values and sizes are exact on 2 byte boundaries (instead of using padding).

namespace fractal {

	struct BitmapInfoHeader {
		int32_t headerSize{ 40 }; //size of the struct, if you count this up in bytes then they add to 40 bytes. 4 bytes
		int32_t width; //setting later, width of the actual bitmap. + 4 bytes = 8
		int32_t height; //setting later, height of the actual bitmap. +4 bytes = 12
		int16_t planes{ 1 }; //maybe a layer feature of bitmap. +2 bytes = 14
		int16_t bitsPerPixel{ 24 }; //3 x 8 bytes is 24 bits, 1 byte for each color in RGB. +2 bytes = 16
		int32_t compression{ 0 }; //no compression is being used so set to 0. +4 bytes = 20
		int32_t dataSize{ 0 }; //set to initialization of 0, set this later to the size of data that we write to the bitmap file. +4 bytes = 24
		int32_t horizontalResolution{ 2400 }; //2400 bits per pixel for horizontal resolution, +4 bytes = 28
		int32_t verticalResolution{ 2400 }; //2400 bits per pixel for vertical resolution, +4 bytes = 32
		int32_t colors{ 0 }; //may not be used, but initialized as 0. +4 bytes = 36
		int32_t importantColors{ 0 }; //may not be used, but initialized as 0, +4bytes = 40 (same as the header size value we set at the top).
	};
}