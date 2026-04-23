#pragma once
#include <iostream>

class Entry {
	std::string name_ = " ";
	std::string id_ = " ";
	double accumulatedValue_ = 0.0;
	double rate_ = 0.0;

public:
	Entry() = default;
	Entry(std::string name, std::string id, double accumulatedValue, double rate);

	double getAccumulatedValue() const;

	friend std::ostream& operator<<(std::ostream& os, const Entry& entry);
	friend std::istream& operator>>(std::istream& is, Entry& entry);

	std::partial_ordering operator<=>(const Entry& other) const {
		if (auto cmp = accumulatedValue_ <=> other.accumulatedValue_; cmp != 0)
		{
			return cmp;
		}

		return id_ <=> other.id_;
	}

	Entry& operator++();
	Entry operator++(int dummy);

	bool operator==(const Entry& other) const = default;
};