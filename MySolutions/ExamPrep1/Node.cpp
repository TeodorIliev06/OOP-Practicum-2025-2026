#include "Node.h"

Node::Node(std::string name, std::string id, double value)
	: name_(std::move(name)), id_(std::move(id)), value_(value)
{
}

const std::string& Node::getId() const
{
	return id_;
}

void Node::setValue(double value)
{
	value_ = value;
}

std::ostream& operator<<(std::ostream& os, const Node& n)
{
	os << n.name_ << " " << n.id_ << " " << n.value_;
	return os;
}