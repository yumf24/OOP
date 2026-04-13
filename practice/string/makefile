.PHONY: all clean

all: main.o string.o
	g++ -o main $^

%.o: %.c
	g++ $@ -c $< 

clean:
	rm %.o main