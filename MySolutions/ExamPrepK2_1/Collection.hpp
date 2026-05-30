#include <vector>
#include <functional>
#include <optional>

template <typename T>
class Collection {
protected:
	std::vector<T> items_;

public:
	void enlist(const T& item);
	void discharge(std::function<bool(const T&)>);
	std::vector<T> where(std::function<bool(const T&)> predicate) const;
	std::optional<T> locateFirst(std::function<bool(const T&)> predicate) const;
	void foreach(std::function<void(const T&)> action) const;
	void sortBy(std::function<bool(const T&, const T&)> comparator);
	size_t count() const;
	bool isEmpty() const;
};

template <typename T>
inline void Collection<T>::enlist(const T& item)
{
	this->items_.push_back(item);
}

template <typename T>
inline void Collection<T>::discharge(std::function<bool(const T&)> predicate)
{
	std::erase_if(this->items_, predicate);
}

template <typename T>
inline std::vector<T> Collection<T>::where(std::function<bool(const T&)> predicate) const
{
	std::vector<T> result;
	for (const auto& item : this->items_)
	{
		if (predicate(item))
		{
			result.push_back(item);
		}
	}

	return result;
}

template <typename T>
inline std::optional<T> Collection<T>::locateFirst(std::function<bool(const T&)> predicate) const
{
	for (const auto& item : this->items_)
	{
		if (predicate(item))
		{
			return item;
		}
	}

	return std::nullopt;
}

template <typename T>
inline void Collection<T>::foreach(std::function<void(const T&)> action) const
{
	for (const auto& item : this->items_)
	{
		action(item);
	}
}

template <typename T>
inline void Collection<T>::sortBy(std::function<bool(const T&, const T&)> comparator)
{
	std::sort(this->items_.begin(), this->items_.end(), comparator);
}

template <typename T>
inline size_t Collection<T>::count() const
{
	return this->items_.size();
}

template <typename T>
inline bool Collection<T>::isEmpty() const
{
	return this->items_.empty();
}