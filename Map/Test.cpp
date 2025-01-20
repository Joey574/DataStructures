#include <iostream>
#include <string>

#include "Map.h"
#include "Map.cpp"


int main() {
	Map<char, int> map;
	map.append('a', 12);
	map.append('b', 15);

	std::cout << map.valueOf('a') << "\n" << map.valueOf('b') << "\n";
}