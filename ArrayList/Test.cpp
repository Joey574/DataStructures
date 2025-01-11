#include <iostream>
#include <string>


#include "ArrayList.h"
#include "ArrayList.cpp"

int main() {
	ArrayList<int> alistA = ArrayList<int>();
	ArrayList<float> alistB = ArrayList<float>();


	std::cout << alistA.toString() << "\n";

	for (int i = 0; i < 20; i++) {
		alistA.append(i);
		alistB.append((float)i * 0.5f);
	}

	std::cout << alistA.toString() << "\n";
	std::cout << alistB.toString() << "\n";

	alistA[0] = 1;

	std::cout << alistA.toString() << "\n";
}