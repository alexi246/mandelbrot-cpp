#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace fractal {

  class mandelbrot {

  public:

    static const int MAX_ITERATIONS = 1000;
    mandelbrot();
    static int getIterations(double x, double y);
    virtual ~mandelbrot();

  };

}

#endif
