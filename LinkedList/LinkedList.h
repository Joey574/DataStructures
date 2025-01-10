#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class LinkedList {
public:

	LinkedList() {
		head = nullptr;
	}

	~LinkedList() {
		node* n = head;

		while (n->next != nullptr) {
			node* t = n;
			n = n->next;
			delete(t);
		}

		delete(n);
	}

	void append(T data);
	void append(LinkedList<T>& llist);

	void insert(int index, T data);
	void insert(int index, LinkedList<T>& llist);

	void remove(int index);

	T at(int index);
	void set(int index, T data);

	size_t size();

	std::vector<T> toVector();

private:
	struct node {
		node() : data(nullptr), next(nullptr) {}
		node(T data) : data(data), next(nullptr) {}

		T data;
		node* next;
	};

protected:
	node* head;
};
