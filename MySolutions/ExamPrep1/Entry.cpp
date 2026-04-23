#include "Entry.h"

Entry::Entry(std::string name, std::string id, double accumulatedValue, double rate)
	: name_(std::move(name)), id_(std::move(id)), accumulatedValue_(accumulatedValue), rate_(rate) {
}

double Entry::getAccumulatedValue() const {
	return accumulatedValue_;
}

std::ostream& operator<<(std::ostream& os, const Entry& e)
{
	os << e.name_ << " " << e.id_ << " " << e.accumulatedValue_ << " " << e.rate_ << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Entry& e)
{
	is >> e.name_ >> e.id_ >> e.accumulatedValue_ >> e.rate_;
	return is;
}

Entry& Entry::operator++() {
	accumulatedValue_ += rate_;
	return *this;
}

Entry Entry::operator++(int dummy) {
	Entry temp = *this;
	++(*this);
	return temp;
}