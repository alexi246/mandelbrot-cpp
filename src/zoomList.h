//
// Created by alexi on 3/5/17.
//

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>
#include "zoom.h"

namespace fractal {

    class zoomList {
        double m_xCentre {0};
        double m_yCentre {0};
        double m_scale {1.0};
        int m_width {0};
        int m_height {0};
        std::vector<zoom> zooms;
    public:
        zoomList(int width, int height);
        std::pair<double, double> doZoom(int x, int y);
        void add(const zoom& z);
        void add(zoom&& z);
    };

}

#endif //ZOOMLIST_H_
