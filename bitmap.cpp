#include <fstream>
#include "bitmap.h"
#include "bitmapinfoheader.h"
#include "bitmapfileheader.h"

namespace fractal {

bitmap::bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3] { }) {}

bool bitmap::write(const std::string& filename) {

	Bitmapfileheader fileHeader;
	Bitmapinfoheader infoHeader;

	fileHeader.fileSize = sizeof(Bitmapfileheader) + sizeof(Bitmapinfoheader) + m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(Bitmapfileheader) + sizeof(Bitmapinfoheader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	std::ofstream file;

	file.open(filename, std::ios::out | std::ios::binary);

	if(!file) {
	  return false;
	}

	file.write(reinterpret_cast<char*> (&fileHeader), sizeof(fileHeader));
	file.write(reinterpret_cast<char*> (&infoHeader), sizeof(infoHeader));
	file.write(reinterpret_cast<char*> (m_pPixels.get()), m_width * m_height * 3);

	file.close();

	if(!file) {
	  return false;
	}

	return true;
}

void bitmap::setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue) {

	uint8_t *pPixel = m_pPixels.get();

	pPixel += (y * 3) * m_width + (x * 3);

	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}

bitmap::~bitmap() {}

}
