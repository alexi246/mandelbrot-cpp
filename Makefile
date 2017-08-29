begin: main.o bitmap.o mandelbrot.o fractalCreator.o RGB.o zoomList.o
		g++ main.o bitmap.o mandelbrot.o fractalCreator.o RGB.o zoomList.o -o fractal

main.o: src/main.cpp
		g++ -c src/main.cpp

bitmap.o: src/bitmap.cpp src/bitmap.h
		g++ -c src/bitmap.cpp

mandelbrot.o: src/mandelbrot.cpp src/mandelbrot.h
		g++ -c src/mandelbrot.cpp

fractalCreator.o: src/fractalCreator.cpp src/fractalCreator.h
	g++ -c src/fractalCreator.cpp

RGB.o: src/RGB.cpp src/RGB.h
	g++ -c src/RGB.cpp

zoomList.o: src/zoomList.cpp src/zoomList.h
	g++ -c src/zoomList.cpp

clean:
	rm *.o
