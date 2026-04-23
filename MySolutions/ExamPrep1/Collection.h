#pragma once
#include "Node.h"
#include <vector>

class Collection {
private:
	std::vector<std::shared_ptr<Node>> nodes_;

public:
	void add(const std::shared_ptr<Node>& node);
	void remove(const std::string& id);
	std::shared_ptr<Node> find(const std::string& id) const;
	Collection& operator()(const std::string& id, double value);
};