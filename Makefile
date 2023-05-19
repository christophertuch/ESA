build:
	mkdir -p ./bin
	clang++ -std=c++20 -Wall -Wextra -Werror -Wpedantic -o ./bin/VacationPlanner ./src/VacationPlanner.cpp ./src/Employee.cpp ./src/Date.cpp

execute:
	./bin/VacationPlanner

all: build execute

windows:
	mkdir -p bin
	g++ -o ./bin/VacationPlanner ./src/VacationPlanner.cpp ./src/Employee.cpp ./src/Date.cpp