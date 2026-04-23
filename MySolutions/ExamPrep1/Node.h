#pragma once
#include <iostream>

class Node {
private:
	std::string name_ = "";
	std::string id_ = "";
	double value_ = 0;

public:
	Node() = default;
	Node(std::string name, std::string id, double value);

	const std::string& getId() const;
	void setValue(double value);

	friend std::ostream& operator<<(std::ostream& os, const Node& n);

	auto operator<=>(const Node& other) const {
		return id_ <=> other.id_;
	}

	bool operator==(const Node& other) const = default;
};