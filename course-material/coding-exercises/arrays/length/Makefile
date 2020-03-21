all: compile test

compile:
	ls *.cpp | grep -v solution.cpp | xargs g++ -o run-tests

test:
	./run-tests