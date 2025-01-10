#include "LinkedList.h"

template <typename T>
void LinkedList<T>::append(T data) {
	if (!head) {
		head = new node(data);
	} else {
		node* n = head;

		while (n->next != nullptr) { n = n->next; }

		node* tmp = new node(data);
		n->next = tmp;
	}
}

template <typename T>
void LinkedList<T>::append(LinkedList<T>& llist) {
	node* othern = llist.head;
	node* thisn = head;

	while (thisn->next != nullptr) { thisn = thisn->next; }

	while (othern != nullptr) {
		node* t = new node(othern->data);

		thisn->next = t;
		thisn = t;
		othern = othern->next;
	}
}

template <typename T>
void LinkedList<T>::insert(int index, T data) {
	node* tmp = new node(data);

	if (index == 0) {
		tmp->next = head;
		head = tmp;
	} else {
		node* n = head;

		for (int i = 0; i < index - 1; i++) {
			n = n->next;
		}

		node* displaced = n->next;
		n->next = tmp;
		tmp->next = displaced;
	}
}

template <typename T>
void LinkedList<T>::insert(int index, LinkedList<T>& llist) {
	node* n = head;
	node* othern = llist.head;

	for (int i = 0; i < index; i++) {
		n = n->next;
	}

	node* displaced = n->next;

	while (othern != nullptr) {

		node* t = new node(othern->data);
		n->next = t;
		n = t;
		othern = othern->next;
	}

	n->next = displaced;
}

template <typename T>
void LinkedList<T>::remove(int index) {
	if (index == 0) {
		node* t = head->next;
		delete(head);
		head = t;
	} else {
		node* n = head;

		for (int i = 0; i < index - 1; i++) {
			n = n->next;
		}

		node* displaced = n->next;
		n->next = displaced->next;
		delete(displaced);
	}
}

template <typename T>
T LinkedList<T>::at(int index) {
	node* n = head;
	for (int i = 0; i < index; i++) {
		n = n->next;
	}
	return n->data;
}

template <typename T>
void LinkedList<T>::set(int index, T data) {
	node* n = head;
	for (int i = 0; i < index; i++) {
		n = n->next;
	}
	n->data = data;
}

template <typename T>
size_t LinkedList<T>::size() {
	size_t len = 1;
	node* n = head;

	while (n->next != nullptr) {
		n = n->next;
		len++;
	}

	return len;
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() {
	std::vector<T> vector;
	vector.reserve(this->size());

	node* n = head;
	while (n != nullptr) {
		vector.push_back(n->data);
		n = n->next;
	}

	return vector;
}