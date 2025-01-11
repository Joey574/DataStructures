#pragma once
#include <iostream>

template <typename T>
class Stack {
public:

	Stack() : m_base((T*)malloc(0)), m_stack(m_base), m_size(0), m_rsize(0) {}
	Stack(size_t size) : m_base((T*)malloc(size * sizeof(T))), m_stack(&m_base[size - 1]), m_size(size), m_rsize(size) {}
	~Stack() { free(m_base); }

	T& peek() const;
	T pop();
	void push(T val);

	inline size_t size() const { return m_size; }

private:
	T* m_base;
	T* m_stack;

	size_t m_size;
	size_t m_rsize;

	void extend();
};
