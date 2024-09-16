main: main.o trolley.o 
	g++ -static main.o  -o main

main.o:	main.cpp trolley.h trolley.cpp manager.h
	g++ -c main.cpp -Wall -std=c++98 

trolley.o:	trolley.cpp trolley.h
	g++ -c trolley.cpp -Wall -std=c++98 

run: main
	./main

clean:
	rm -f *.o main