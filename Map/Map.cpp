#include "Map.h"

template <typename K, typename V>
bool Map<K, V>::append(K key, V val) {
	if (!contains(key)) {
		if (m_size >= m_rsize) {
			extend();
		}

		m_keys[m_size] = key;
		m_values[m_size] = val;
		m_size++;

		return true;
	}

	return false;	
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
int Map<K, V>::indexOf(K key) {
	for (size_t i = 0; i < m_size; i++) {
		if (m_keys[i] == K) {
			return i;
		}
	}

	return -1;
}

template <typename K, typename V>
V Map<K, V>::valueOf(K key) {
	for (size_t i = 0; i < m_size; i++) {
		if (m_keys[i] == key) {
			return m_values[i];
		}
	}

	return NULL;
}

template <typename K, typename V>
void Map<K, V>::extend() {
	m_rsize = (m_rsize * 1.5) + 1;

	m_keys = (K*)realloc(m_keys, m_rsize * sizeof(K));
	m_values = (V*)realloc(m_values, m_rsize * sizeof(V));
}