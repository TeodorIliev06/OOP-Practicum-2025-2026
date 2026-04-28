#pragma once
#include "Book.h"

class Reader {
	int id_;
	char* name_;
	Book** books_;

	void free();
	void copyFrom(const Reader& other);
	void movefrom(Reader&& other) noexcept;

public:
	Reader(int id, const char* name);
	Reader(const Reader& other);
	Reader(Reader&& other) noexcept;

	Reader& operator=(const Reader& other);
	Reader& operator=(Reader&& other) noexcept;

	~Reader();

	friend std::ostream& operator<<(std::ostream& os, const Reader& reader);
	bool operator!() const;
	Reader& operator+=(Book* book);
	bool operator()(const char* bookTitle) const;
	Book* operator[](size_t index) const;

};