#include "Collection.h"

void Collection::add(const std::shared_ptr<Node>& node)
{
	if (find(node->getId()) != nullptr)
	{
		return;
	}

	nodes_.push_back(node);
}

// I would use the last alternative for remove below.
// The uncommented implementation has O(n^2) complexity in the worst case.
// The second alternative is both shorter and has better performance.

void Collection::remove(const std::string& id)
{
	for (size_t i = 0; i < nodes_.size(); i++)
	{
		if (nodes_[i]->getId() == id)
		{
			nodes_.erase(nodes_.begin() + i);
			i--;
		}
	}
}

// Alternative version - erase can delete a range of elements -> from the beginning of the iterator
// passed as the first argument up to the second iterator.
// remove_if rearranges the elements so that those matching the condition are moved to the end of
// the vector, and returns an iterator to the beginning of that shift.
// That is, we pass the result of remove_if as the first argument to erase, and the end of the vector as the second.

//void Collection::remove(const std::string& id)
//{
//	nodes_.erase(
//		std::remove_if(nodes_.begin(), nodes_.end(), [&id](const std::shared_ptr<Node>& node) {
//			return node->getId() == id;
//		}),
//		nodes_.end()
//	);
//}


// Yet another alternative, available since C++20.
// erase_if combines the work of erase and remove_if. This time it takes the vector itself
// as the first argument, and our lambda function as the second.

//void Collection::remove(const std::string& id)
//{
//	std::erase_if(nodes_, [&id](const std::shared_ptr<Node>& node) {
//		return node->getId() == id;
//	});
//}

std::shared_ptr<Node> Collection::find(const std::string& id) const
{
	for (const auto& node : nodes_)
	{
		if (node->getId() == id)
		{
			return node;
		}
	}

	return nullptr;
}


// Alternative version of the find function. find_if takes an iterator to the beginning and end of the vector.
// The third argument is a lambda function, to which we must capture the id (i.e. inside the square brackets).
// The function returns an iterator to the end if nothing is found.
// If found, we dereference the iterator to get the object it points to.

//std::shared_ptr<Node> Collection::find(const std::string& id) const
//{
//	auto it = std::find_if(nodes_.begin(), nodes_.end(), [&id](const std::shared_ptr<Node>& node) {
//		return node->getId() == id;
//	});
//
//	if (it == nodes_.end())
//	{
//		return nullptr;
//	}
//
//	return *it;
//}

Collection& Collection::operator()(const std::string& id, double value)
{
	std::shared_ptr<Node> node = find(id);

	if (node)
	{
		node->setValue(value);
	}

	return *this;
}