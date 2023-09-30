FLAGS = -Wall -Wextra -Werror

all: solver

solver: solver.o
	@g++ $(FLAGS) solver.o -o solver

solver.o: solver.cpp
	@g++ $(FLAGS) -c solver.cpp
