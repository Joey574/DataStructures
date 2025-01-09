#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

void run_tests();
void llistString(LinkedList<int>& llist);


int main() {
	run_tests();
}

void llistString(LinkedList<int>& llist) {
	for (size_t i = 0; i < llist.size(); i++) {
		std::cout << llist.at(i) << " ";
	} std::cout << "\n";
}



void run_tests() {
	LinkedList<int> llistA;
	LinkedList<int> llistB;

	int valuesA[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int valuesB[] = { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };

	for (int i = 0; i < 10; i++) {
		llistA.append(valuesA[i]);
		llistB.append(valuesB[i]);
	}

	llistString(llistA);
	llistString(llistB);

	llistA.remove(0);
	llistB.remove(1);

	llistString(llistA);
	llistString(llistB);

	llistA.append(llistB);

	llistString(llistA);
}