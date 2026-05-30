#pragma once
#include <vector>
#include "Star.h"
#include <functional>
template<typename T>
class Repository {
	std::vector<T> items_;

public:
	void add(const T& item);
	void remove(std::function<bool(const T&)> predicate);
	void sortBy(std::function<bool(const T&, const T&)> comparator);
};

template<typename T>
inline void Repository<T>::add(const T& item)
{
	this->items_.push_back(item);
}

template<typename T>
inline void Repository<T>::remove(std::function<bool(const T&)> predicate)
{
	std::erase_if(this->items_, predicate);
}

template<typename T>
inline void Repository<T>::sortBy(std::function<bool(const T&, const T&)> comparator)
{
	std::sort(this->items_.begin(), this->items_.end(), comparator);
}