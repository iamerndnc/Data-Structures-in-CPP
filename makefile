hepsi: derle calistir
derle:
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/StackDugum.o -c ./src/StackDugum.cpp
	g++ -I ./include/ -o ./lib/agacDugum.o -c ./src/agacDugum.cpp
	g++ -I ./include/ -o ./lib/BinarySearchTree.o -c ./src/BinarySearchTree.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Stack.o ./lib/StackDugum.o ./lib/agacDugum.o ./lib/BinarySearchTree.o ./src/main.cpp
	
calistir:
	./bin/Test