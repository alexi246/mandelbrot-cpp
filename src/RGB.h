//
// Created by alexi on 3/5/17.
//

#ifndef RGB_H_
#define RGB_H_

namespace fractal {

    struct RGB {

        double r;
        double g;
        double b;

        RGB(double r, double g, double b);
    };

    RGB operator-(const RGB& first, const RGB& second);
}

#endif //FRACTALPROJECT_RGB_H
