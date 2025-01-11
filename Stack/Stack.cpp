#include "Stack.h"

template <typename T>
T& Stack<T>::peek() const {
	return m_stack[0];
}

template <typename T>
T Stack<T>::pop() {
	m_size--;
	m_stack = &m_base[m_size - 1];
	return m_stack[1];
}

template <typename T>
void Stack<T>::push(T val) {
	if (m_size >= m_rsize) {
		extend();
	}

	m_size++;
	m_stack = &m_base[m_size - 1];
	m_stack[0] = val;
}

template <typename T>
void Stack<T>::extend() {
	m_rsize = (m_rsize * 1.5) + 1;

	m_base = (T*)realloc(m_base, m_rsize * sizeof(T));
	m_stack = &m_base[m_size - 1];
}