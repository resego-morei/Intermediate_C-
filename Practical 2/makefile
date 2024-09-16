ofiles	=	main.o	factory.o	drone.o
gpp_o	=	g++	-c	-std=c++11	-static

main:	$(ofiles)
	g++	-std=c++11	-static	$(ofiles)	-o	main

main.o:	main.cpp	factory.h	drone.h
	$(gpp_o)	main.cpp

drone.o:	drone.cpp	drone.h
	$(gpp_o)	drone.cpp

factory.o:	factory.cpp	factory.h
	$(gpp_o)	factory.cpp

run:	main
	./main

clean:
	rm	*.o	main