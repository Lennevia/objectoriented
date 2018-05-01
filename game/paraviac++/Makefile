output: main.o player.o actions.o upkeep.o
	g++ main.o player.o actions.o upkeep.o -o output

main.o: main.cpp
	g++ -c main.cpp

player.o: player.cpp player.h
	g++ -c player.cpp

actions.o: actions.cpp actions.h
	g++ -c actions.cpp

upkeep.o: upkeep.cpp upkeep.h
	g++ -c upkeep.cpp

clean:
	rm *.o output




