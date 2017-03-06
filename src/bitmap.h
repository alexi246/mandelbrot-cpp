#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>

namespace fractal {

class bitmap {

private:
	int m_width {0};
	int m_height {0};
	std::unique_ptr<std::uint8_t[]> m_pPixels {nullptr};
public:

	bitmap(int width, int height);
	bool write(const std::string& filename);
	void setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue);
	virtual ~bitmap();
  };
}

#endif
