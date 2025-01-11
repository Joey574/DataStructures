#pragma once
#include <iostream>
#include <string>

template <typename T>
class ArrayList {
public:

	ArrayList() : m_data((T*)malloc(0)), m_size(0), m_rsize(0) {}
	ArrayList(size_t size) : m_data((T*)malloc(size * sizeof(T))), m_size(size), m_rsize(size) {}
	ArrayList(size_t size, T val) : m_data((T*)malloc(size * sizeof(T))), m_size(size), m_rsize(size) {
		for (size_t i = 0; i < size; i++) {
			m_data[i] = val;
		}
	}
	~ArrayList() {
		free(m_data);
	}

	void append(T data);

	std::string toString() const;

	inline size_t size() const;

	inline const T& operator [] (size_t idx) const {
		return m_data[idx];
	}
	inline T& operator [] (size_t idx) {
		return m_data[idx];
	}

private:
	T* m_data;
	size_t m_size;
	size_t m_rsize;

	void extend();
};