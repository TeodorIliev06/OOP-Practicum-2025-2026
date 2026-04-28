#pragma once
#include "Entry.h"

class Container {
private:
	Entry* entries_;
	size_t size_;
	size_t cap_;
	double tax_;

	void free();
	void copyFrom(const Container& other);
	void moveFrom(Container&& other) noexcept;
public:
	Container() = default;
	Container(const Container& other);
	Container(Container&& other) noexcept;

	Container& operator=(const Container& other);
	Container& operator=(Container&& other) noexcept;

	~Container();

	double getScore() const;

	Container& operator+=(const Entry& entry);
	Container& operator-=(double value);

	friend std::ostream& operator<<(std::ostream& os, const Container& c);
	friend std::istream& operator>>(std::istream& is, Container& c);

	auto operator<=>(const Container& other) const {
		return getScore() <=> other.getScore();
	}

	bool operator==(const Container& other) const = default;

	explicit operator bool() const;
};
