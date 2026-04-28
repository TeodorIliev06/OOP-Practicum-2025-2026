#include "Book.h"
#include <iostream>

void Book::free()
{
    delete[] title_;
    delete[] author_;
    title_ = author_ = nullptr;
    readersCount_ = pagesCount_ = 0;
}

void Book::copyFrom(const Book& other)
{
    title_ = new char[strlen(other.title_) + 1];
    strcpy(title_, other.title_);

    author_ = new char[strlen(other.author_) + 1];
    strcpy(author_, other.author_);

    readersCount_ = other.readersCount_;
    pagesCount_ = other.pagesCount_;
}

void Book::moveFrom(Book&& other) noexcept
{
    title_ = other.title_;
    author_ = other.author_;
    readersCount_ = other.readersCount_;
    pagesCount_ = other.pagesCount_;

    other.title_ = nullptr;
    other.author_ = nullptr;
    other.readersCount_ = 0;
    other.pagesCount_ = 0;
}

Book::Book(const char* title, const char* author, int pagesCount)
{
    title_ = new char[strlen(title) + 1];
    strcpy(title_, title);

    author_ = new char[strlen(author) + 1];
    strcpy(author_, author);

    readersCount_ = 0;
    pagesCount_ = pagesCount;
}

Book::Book(const Book& other)
{
    copyFrom(other);
}

Book::Book(Book&& other) noexcept
{
    moveFrom(std::move(other));
}

Book& Book::operator=(const Book& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Book& Book::operator=(Book&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Book::~Book()
{
    free();
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	std::cout << "Title: " << book.title_ << std::endl;
	std::cout << "Author: " << book.author_ << std::endl;
	std::cout << "Pages: " << book.pagesCount_ << std::endl;
}

Book& Book::operator++()
{
    ++readersCount_;
    return *this;
}

Book Book::operator++(int dummy)
{
    Book temp(*this);
    ++readersCount_;
    return temp;
}
