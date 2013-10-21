#ifndef MONSTER_H
#define MONSTER_H

#include "Range.h"
#include "Weapon.h"

#include <string>

class Player;

class Monster
{
public:
	Monster(const std::string& name, int hp, int acc, int xpReward, 
		Range goldRewards, int armor, const std::string& weaponName, 
		int lowDamage, int highDamage);

	bool isDead();

	int			getXPReward();
	int			getGoldReward();
	std::string	getName();
	int			getArmor();

	void attack(Player& player);
	void takeDamage(int damage);
	void displayHitPoints();
private:
	std::string mName;
	int			mHitPoints;
	int			mAccuracy;
	int			mExpRewards;
	Range		mGoldRewards;
	int			mArmor;
	Weapon		mWeapon;
};

#endif