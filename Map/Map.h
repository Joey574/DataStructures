#pragma once
#include <iostream>

template <typename K, typename V>
class Map {
public:
	Map() : m_keys((K*)malloc(0)), m_values((V*)malloc(0)), m_size(0), m_rsize(0) {}

	bool append(K key, V val);
	bool contains(K key);

	int indexOf(K key);
	V valueOf(K key);


private:
	K* m_keys;
	V* m_values;

	size_t m_size;
	size_t m_rsize;

	void extend();
};

