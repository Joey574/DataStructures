#include "Map.h"

template <typename K, typename V>
void Map<K, V>::append(K key, V val) {
	if (m_size >= m_rsize) {
		extend();
	}

	m_keys[m_size] = K;
	m_values[m_size] = V;
	m_size++;
}

template <typename K, typename V>
bool Map<K, V>::contains(K key) {
	for (size_t i = 0; i < m_size; i++) {
		if (m_keys[i] == key) {
			return true;
		}
	}

	return false;
}

template <typename K, typename V>
void Map<K, V>::extend() {
	m_rsize *= 1.5f + 1;

	m_keys = (K*)realloc(m_rsize * sizeof(K));
	m_values = (V*)realloc(m_rsize * sizeof(V));
}