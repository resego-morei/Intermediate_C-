main: tome.o main.cpp
	g++ -g -static tome.o main.cpp -o main 


tome.o:tome.cpp
	g++ -static -c tome.cpp
	
run:
	./main
	
clean:
	rm -f *.o main
