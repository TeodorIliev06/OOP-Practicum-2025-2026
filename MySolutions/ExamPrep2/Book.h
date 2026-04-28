#pragma once
#include <fstream>
#include <compare>

class Book {
	char* title_;
	char* author_;
	int readersCount_;
	int pagesCount_;

	void free();
	void copyFrom(const Book& other);
	void moveFrom(Book&& other) noexcept;

public:
	Book(const char* title, const char* author, int pagesCount);
	Book(const Book& other);
	Book(Book&& other) noexcept;

	Book& operator=(const Book& other);
	Book& operator=(Book&& other) noexcept;
	~Book();

	friend std::ostream& operator <<(std::ostream& os, const Book& book);
	Book& operator++();
	Book operator++(int dummy);

	/*auto operator<=>(const Node& other) const {
		return id_ <=> other.id_;
	}*/

	//bool operator==(const Book& other) const = default;
};