build:
	clang++ -std=c++17 -Wall -Wextra -Werror -Wpedantic -o ./bin/VacationPlanner ./src/VacationPlanner.cpp ./src/Employee.cpp ./src/Date.cpp

execute:
	./bin/VacationPlanner

all: build execute