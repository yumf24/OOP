.PHONY: all clean debug

CXXFLAG = -std=c++11

all: main.o product.o sum.o
	g++ $(CXXFLAG) -o main $^

debug: CXXFLAG=-std=c++11 -g -DDEBUG
debug: main.o product.o sum.o
	g++ $(CXXFLAG) -o main $^

%.o: %.cpp
	g++ $(CXXFLAG) -c $<

clean:
	-rm main *.o
