ALL: main Practica2

main: main.cpp
	g++ -c main.cpp src/GenNodeSet.cpp src/NodeSet.cpp src/NearestTrioProblem.cpp  -std=c++11 

Practica2: 
	g++ *.o -o Practica2
clean:
	rm -f *.o Practica2