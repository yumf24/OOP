.PHONY: all clean debug

all: main.o Move.o
	g++ $^ -o main

debug: main.cpp Move.cpp
	g++ -o main_debug -g main.cpp Move.cpp

%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm *.o main