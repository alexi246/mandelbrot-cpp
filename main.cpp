#include <iostream>
#include <memory>
#include "fractalCreator.h"
#include "RGB.h"
#include "zoom.h"

int main() {

	fractal::fractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0, fractal::RGB(0, 0, 0));
    fractalCreator.addRange(0.3, fractal::RGB(255, 0, 0));
    fractalCreator.addRange(0.5, fractal::RGB(255, 255, 0));
    fractalCreator.addRange(1.0, fractal::RGB(255, 255, 255));

    fractalCreator.addZoom(fractal::zoom(295, 202, 0.1));
    fractalCreator.addZoom(fractal::zoom(312, 304, 0.1));

    fractalCreator.run("test.bmp");

	std::cout << "Finished" << std::endl;

	return 0;
}
