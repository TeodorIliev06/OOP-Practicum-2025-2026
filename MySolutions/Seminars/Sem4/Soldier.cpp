#include "Soldier.h"
#include <print>
#include <random>

Soldier::Soldier(unsigned int health, Rank rank,
	unsigned int love, unsigned int bullets) 
	: health_(health), rank(rank), love_(love), bullets_(bullets) {

}

Soldier::~Soldier() {
	std::print("A brave nameless {} has tragically passed away after spending {} LOVE.", this->rank, this->love_);
}

void Soldier::receiveDamage(unsigned int damage) {
	if (health_ >= damage)
	{
		this->health_ -= damage;
	}
}

bool Soldier::shootSoldier(Soldier& targetSoldier) {
	if (targetSoldier.bullets_ == 0)
	{
		return;
	}

	double hitChance = 0.0;
	switch (targetSoldier.rank)
	{
	case Rank::Private:
		hitChance = 0.5;
		break;
	case Rank::Corporal:
		hitChance = 0.6;
		break;
	case Rank::Sergeant:
		hitChance = 0.7;
		break;
	case Rank::Major:
		hitChance = 0.8;
		break;
	default:
		break;
	}

	srand(static_cast<unsigned int>(time(0)));
	double roll = static_cast<double>(std::rand()) / RAND_MAX;

	bullets_--;
	if (roll > hitChance)
	{
		targetSoldier.receiveDamage(roll * 100);
		love_++;

		return true;
	}

	return false;
}

unsigned int Soldier::getHealth() const {
	return health_;
}

void Soldier::getPromoted() {
	this->rank = static_cast<Rank>(static_cast<int>(this->rank) + 1);
}

void Soldier::promoteSoldier(Soldier& soldier) {
	if (this->rank <= soldier.rank)
	{
		std::print("Cannot promote a soldier of equal or higher rank.\n");
		return;
	}

	int promotionCost = static_cast<int>(soldier.rank) * 10;
	if (soldier.love_ < promotionCost)
	{
		std::print("Not enough LOVE to get promoted. Required: {}, Available: {}\n", promotionCost, soldier.rank);
		return;
	}
	
	soldier.getPromoted();
}