F = -std=c++20 -Wall -Wextra -Wpedantic -Wfatal-errors
Z = ICS46_hw8.zip
P = main

def: $P

main: src/dijkstras.cpp src/dijkstras_main.cpp
	g++ $F src/dijkstras.cpp src/dijkstras_main.cpp -o main

clean:
	/bin/rm -f $P