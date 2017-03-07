CFLAGS = -std=c++11 -fopenmp
INCPATH = -I/usr/local/include
LIBPATH = -L/usr/local/lib

all:    main_
main_:    ./src/main_.cpp ./src/cosSimilar.h
	g++ $(CFLAGS) $(INCPATH) $(LIBPATH) -o ./bin/index ./src/main_.cpp $(LIBS)
clean:
	rm -f index
