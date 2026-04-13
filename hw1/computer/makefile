.PHONY: main clean
CXX := g++
CXXFLAGS := -std=c++11

main: main.o Computer.o ComputerCollection.o
	$(CXX) $(CXXFLAGS) -o $@ $^

debug: CXXFLAGS = -std=c++11 -g
debug: main.o Computer.o ComputerCollection.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm main *.o
