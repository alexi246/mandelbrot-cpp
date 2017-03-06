//
// Created by alexi on 3/5/17.
//

#include <cmath>
#include <iostream>
#include <cassert>
#include "fractalCreator.h"

namespace fractal {

    fractalCreator::fractalCreator(int width, int height) :
            m_width(width), m_height(height), m_histogram(new int[mandelbrot::MAX_ITERATIONS] {0}), m_fractal(new int[m_width * m_height] {0}),
            m_bitmap(m_width, m_height), m_zoomList(m_width, m_height) {


        m_zoomList.add(zoom(m_width / 2, m_height / 2, 4.0 / m_width));

    }

    void fractalCreator::run(const std::string &name) {

        calculateIteration();
        calculateTotalIterations();
        calculateRangeTotals();
        drawFractal();
        writeBitmap("test.bmp");
    }

    void fractalCreator::calculateIteration() {

        for(int y = 0; y < m_height; ++y) {
            for(int x = 0; x < m_width; ++x) {
                std::pair<double, double> coords = m_zoomList.doZoom(x, y);

                int iterations = mandelbrot::getIterations(coords.first, coords.second);

                m_fractal[y * m_width + x] = iterations;

                if (iterations != mandelbrot::MAX_ITERATIONS) {
                    ++m_histogram[iterations];
                }
            }

        }
    }

    void fractalCreator::drawFractal() {

        for (int y = 0; y < m_height; ++y) {
            for (int x = 0; x < m_width; ++x) {

                int iterations {m_fractal[y * m_width + x]};

                int range {getRange(iterations)};
                int rangeTotal {range_totals[range]};
                int rangeStart {ranges[range]};

                RGB& startColour = colours[range];
                RGB& endColour = colours[range + 1];
                RGB colourDiff = endColour - startColour;

                std::uint8_t red {0};
                std::uint8_t green {0};
                std::uint8_t blue {0};

                if(iterations != fractal::mandelbrot::MAX_ITERATIONS) {

                    int totalPixels {0};

                    for (int i = rangeStart; i <= iterations; ++i) {
                        totalPixels += m_histogram[i];
                    }

                    red = startColour.r + colourDiff.r * static_cast<double>(totalPixels) / rangeTotal;
                    green = startColour.g + colourDiff.g * static_cast<double>(totalPixels) / rangeTotal;
                    blue = startColour.b + colourDiff.b * static_cast<double>(totalPixels) / rangeTotal;

                }

                m_bitmap.setPixel(x, y, red, green, blue);

            }
        }
    }

    void fractalCreator::addRange(double rangeEnd, RGB &&rgb) {
        ranges.push_back(rangeEnd * mandelbrot::MAX_ITERATIONS);
        colours.push_back(rgb);

        if(bGotFirstRange) {
            range_totals.push_back(0);
        }

        bGotFirstRange = true;

    }

    void fractalCreator::addZoom(const zoom &z) {

        m_zoomList.add(z);
    }

    void fractalCreator::addZoom(zoom &&z) {

        m_zoomList.add(z);
    }

    void fractalCreator::writeBitmap(const std::string &name) {

        m_bitmap.write(name);
    }

    void fractalCreator::calculateTotalIterations() {

        for (int i = 0; i < mandelbrot::MAX_ITERATIONS; ++i) {

            m_total += m_histogram[i];
        }
    }

    void fractalCreator::calculateRangeTotals() {

        int rangeIndex {0};

        for(int i = 0; i < mandelbrot::MAX_ITERATIONS; ++i) {
            int pixels = m_histogram[i];

            if(i >= ranges[rangeIndex + 1]) {
                ++rangeIndex;
            }
            range_totals[rangeIndex] += pixels;
        }
    }

    int fractalCreator::getRange(int iterations) const {

        int range {0};

        for (int i = 1; i < ranges.size(); ++i) {
            range = i;

            if(ranges[i] > iterations) break;
        }

        --range;

        assert(range > -1);
        assert(range < ranges.size());

        return range;
    }

    fractalCreator::~fractalCreator() {}
}
