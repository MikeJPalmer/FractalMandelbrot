#pragma once

#include <cstdint> //header to guarantee 32-bit int. (int32_t)
using namespace std;

#pragma pack(2) //packing so we can ensure that these values and sizes are exact on 2 byte boundaries (instead of using padding).

namespace fractal {

	struct BitmapFileHeader {
		char header[2]{ 'B', 'M' }; //creating 2 bytes for the letter B and M, set in an array of 2.
		int32_t fileSize; //size of the final file that we'll fill in later, must be 32-bit so we're using int32_t from cstdint.
		int32_t reserved{ 0 }; //initialized to 0 and we're not going to use.
		int32_t dataOffset; //setting later, how long into the file does the data actually begin.

	};
}