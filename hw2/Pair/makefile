.PHONY: all debug clean

TARGET = main
OBJ = Map.o Pair.o main.o
CXXFLAG = -std=c++11

all: $(OBJ)
	g++ $(CXXFLAG) -o $(TARGET) $(OBJ)

debug: CXXFLAG = -std=c++11 -g 
debug: $(OBJ)
	g++ $(CXXFLAG) -o $(TARGET) $(OBJ)

%.o: %.cpp
	g++ $(CXXFLAG) -o $@ -c $<

clean:
	rm *.o main