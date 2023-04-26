FLAGS = -pedantic-errors -std=c++11

achievement.o: achievement.cpp achievement.h
	g++ $(FLAGS) -c $<
	
main.o: main.cpp achievement.h
	g++ $(FLAGS) -c $<
	
main: main.o achievement.o
	g++ $(FLAGS) $^ -o $@
	
clean:
	rm -f achievement.o main.o main

.PHONY: clean 
