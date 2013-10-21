#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include "Monster.h"
#include <string>

class Player
{
public:
	// Constructor
	Player();

	// Methods
	bool isDead();

	std::string getName();
	int			getArmor();

	void takeDamage(int damage);

	void createClass();
	bool attack(Monster& monster);
	void levelUp();
	void rest();
	void viewStat();
	void victory(int xp, int gold);
	void gameover();
	void displayHitPoints();

private:
	// Data members
	std::string mName;
	std::string mClassName;
	int			mAccuracy;
	int			mHitPoints;
	int			mMaxHitPoints;
	int			mExpPoints;
	int			mNextLevelExp;
	int			mLevel;
	int			mGold;
	int			mArmor;
	Weapon		mWeapon;
};

#endif