


CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17


snake: main.cpp map.cpp
	$(CXX) $(CXXFLAGS) -o snake main.cpp map.cpp