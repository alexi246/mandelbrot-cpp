//
// Created by alexi on 3/5/17.
//

#include "zoomList.h"

namespace fractal {

    zoomList::zoomList(int width, int height) : m_width(width), m_height(height) {}

    void zoomList::add(const zoom& z) {
        zooms.push_back(z);

        m_xCentre += (z.x - m_width / 2) * m_scale;
        m_yCentre += -(z.y - m_height / 2) * m_scale;

        m_scale *= z.scale;

    }

    void zoomList::add(zoom &&z) {
        zooms.push_back(z);

        m_xCentre += (z.x - m_width / 2) * m_scale;
        m_yCentre += (z.y - m_height / 2) * m_scale;

        m_scale *= z.scale;
    }

    std::pair<double, double> zoomList::doZoom(int x, int y) {

        return std::make_pair<double, double>((x - m_width / 2) * m_scale + m_xCentre, (y - m_height / 2) * m_scale + m_yCentre);
    }

}
