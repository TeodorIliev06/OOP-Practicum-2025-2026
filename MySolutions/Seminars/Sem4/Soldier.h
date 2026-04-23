#pragma once
#include <fstream>

class Soldier {
private:
	enum class Rank {
		Private,
		Corporal,
		Sergeant,
		Major
	};

	unsigned int health_ = 100;
	Rank rank;
	unsigned int love_ = 0;
	unsigned int bullets_ = 100;

public:
	Soldier() = default;
	Soldier(unsigned int health, Rank rank, unsigned int love, unsigned int bullets);
	~Soldier();

	bool shootSoldier(Soldier& targetSoldier);
	void receiveDamage(unsigned int damage);
	unsigned int getHealth() const;
	void promoteSoldier(Soldier& soldier);
	void getPromoted();
};