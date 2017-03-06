#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

#pragma pack(2)

namespace fractal {

struct Bitmapfileheader {
	char header[2]{'B', 'M'};
	int32_t fileSize;
	int32_t reserved {0};
	int32_t dataOffset;
  };
}

#endif
