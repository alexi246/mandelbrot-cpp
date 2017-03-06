//
// Created by alexi on 3/5/17.
//

#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include <memory>
#include <vector>
#include "zoom.h"
#include "bitmap.h"
#include "zoomList.h"
#include "mandelbrot.h"
#include "RGB.h"

namespace fractal {

    class fractalCreator {

        int m_width;
        int m_height;
        std::unique_ptr<int[]> m_histogram;
        std::unique_ptr<int[]> m_fractal;
        bitmap m_bitmap;
        zoomList m_zoomList;
        int m_total {0};
        std::vector<int> ranges;
        std::vector<RGB> colours;
        std::vector<int> range_totals;
        bool bGotFirstRange {false};

        void calculateIteration();
        void calculateTotalIterations();
        void calculateRangeTotals();
        void drawFractal();
        void writeBitmap(const std::string& name);

    public:
        fractalCreator(int width, int height);
        ~fractalCreator();
        void addRange(double rangeEnd, RGB&& rgb);
        void run(const std::string& name);
        int getRange(int iterations) const;
        void addZoom(const zoom& z);
        void addZoom(zoom&& z);
    };
}

#endif //FRACTALCREATOR_H
