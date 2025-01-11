#include "ArrayList.h"

template <typename T>
void ArrayList<T>::append(T data) {
	if (m_size >= m_rsize) {
		extend();
	}

	m_data[m_size] = data;
	m_size++;
}

template <typename T>
std::string ArrayList<T>::toString() const {
	std::string out;

	out.append("{ ");
	for (size_t i = 0; i < m_size; i++) {
		out.append(std::to_string(m_data[i]));
		if (i < m_size - 1) {
			out.append(", ");
		}
	}
	out.append(" }");

	return out;
}

template <typename T>
inline size_t ArrayList<T>::size() const {
	return m_size;
}

template <typename T>
void ArrayList<T>::extend() {
	m_rsize = (m_rsize * 1.5) + 1;
	m_data = (T*)realloc(m_data, m_rsize * sizeof(T));
}