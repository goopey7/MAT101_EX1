build:
	g++ -c -ISFML/include *.cpp
	g++ *.o -o exec -lsfml-graphics -lsfml-window -lsfml-system
run: build
	./exec
