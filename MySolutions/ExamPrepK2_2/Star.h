#pragma once
#include <iostream>

enum class Rarity {
	Rare,
	SuperRare,
	Epic,
	Mythic,
	Legendary
};

class Star {
	std::string name_;
	int trophies_;
	int level_;
	Rarity rarity_;

public:
	Star(std::string name, int trophies, int level, Rarity rarity);

	const std::string& getName() const;
	const int getTrophies() const;
	const int getLevel() const;
	const Rarity getRarity() const;

	void addTrophies(int trophies);
};