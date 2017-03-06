begin: main.o bitmap.o mandelbrot.o fractalCreator.o RGB.o zoomList.o
		g++ main.o bitmap.o mandelbrot.o fractalCreator.o RGB.o zoomList.o -o fractal

main.o: main.cpp
		g++ -c main.cpp

bitmap.o: bitmap.cpp bitmap.h
		g++ -c bitmap.cpp

mandelbrot.o: mandelbrot.cpp mandelbrot.h
		g++ -c mandelbrot.cpp

fractalCreator.o: fractalCreator.cpp fractalCreator.h
	g++ -c fractalCreator.cpp

RGB.o: RGB.cpp RGB.h
	g++ -c RGB.cpp

zoomList.o: zoomList.cpp zoomList.h
	g++ -c zoomList.cpp

clean:
	rm *.o
