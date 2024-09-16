run: main
	./main

main: main.o
	g++ main.o  -o main

main.o:	main.cpp heatNode.h heatNode.cpp heatStack.h heatStack.cpp msgQueue.h msgQueue.cpp msgNode.h msgNode.cpp
	g++ -c main.cpp

clean:
	rm *.o