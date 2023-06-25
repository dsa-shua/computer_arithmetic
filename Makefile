#GXX=g++
#EXECUTABLE=multiplication.cc

run:
	g++ -o multiplication multiplication.cc
	./multiplication
	
clean:
	rm -rf multiplication
	
