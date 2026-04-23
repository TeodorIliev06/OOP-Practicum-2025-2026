#include "Container.h"

void Container::free()
{
	delete[] entries_;
	entries_ = nullptr;
	size_ = cap_ = tax_ = 0;
}

void Container::copyFrom(const Container& other)
{
	size_ = other.size_;
	cap_ = other.cap_;
	tax_ = other.tax_;
	entries_ = new Entry[cap_];

	for (size_t i = 0; i < size_; i++)
	{
		entries_[i] = other.entries_[i];
	}
}

void Container::moveFrom(Container&& other) noexcept
{
	entries_ = other.entries_;
	size_ = other.size_;
	cap_ = other.cap_;
	tax_ = other.tax_;

	other.entries_ = nullptr;
	other.size_ = 0;
	other.cap_ = 0;
	other.tax_ = 0;
}

Container::Container(const Container& other)
{
	copyFrom(other);
}

Container::Container(Container&& other) noexcept
{
	moveFrom(std::move(other));
}

Container& Container::operator=(const Container& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Container& Container::operator=(Container&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Container::~Container()
{
	free();
}

double Container::getScore() const
{
	double sum = 0;

	for (size_t i = 0; i < size_; i++)
	{
		sum += entries_[i].getAccumulatedValue();
	}

	return sum - (tax_ * size_);
}

Container& Container::operator+=(const Entry& entry)
{
	if (size_ >= cap_)
	{
		entries_[size_ - 1] = entry;
	}
	else
	{
		entries_[size_++] = entry;
	}
}

Container& Container::operator-=(double value)
{
	size_t newSize = 0;

	for (size_t i = 0; i < size_; i++)
	{
		if (entries_[i].getAccumulatedValue() >= value)
		{
			entries_[newSize++] = entries_[i];
		}
	}

	size_ = newSize;
}

std::ostream& operator<<(std::ostream& os, const Container& c)
{
	os << c.size_ << " " << c.cap_ << " " << c.tax_ << std::endl;

	for (size_t i = 0; i < c.size_; i++)
	{
		os << c.entries_[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, Container& c)
{
	is >> c.cap_ >> c.tax_;

	delete[] c.entries_;
	c.entries_ = new Entry[c.cap_];
	c.size_ = 0;

	return is;
}

explicit Container::operator bool() const {
	double occupied = (double)size_ / cap_;
	return occupied >= 0.6;
}