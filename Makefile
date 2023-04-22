FLAGS = -pedantic-errors -std=c++11

achievement.o: achievement.cpp achievement.h
	g++ $(FLAGS) -c $<
	
testingfile.o: testingfile.cpp
	g++ $(FLAGS) -c $<
	
main: testingfile.o achievement.o
	g++ $(FLAGS) $^ -o $@
	
clean:
	rm -f achievement.o testingfile.o main

.PHONY: clean 