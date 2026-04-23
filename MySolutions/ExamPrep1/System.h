#pragma once
#include "Collection.h"

class System {
private:
	std::vector<Collection> collections_;

	System() = default;

public:

	System(const System& other) = delete;
	System& operator=(const System& other) = delete;

	static System& getInstance();
};