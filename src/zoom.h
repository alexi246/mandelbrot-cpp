//
// Created by alexi on 3/5/17.
//

#ifndef ZOOM_H_
#define ZOOM_H_

namespace fractal {

    struct zoom {
        int x{0};
        int y{0};
        double scale{0.0};

        zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {};

    };
}

#endif //FRACTALPROJECT_ZOOM_H
