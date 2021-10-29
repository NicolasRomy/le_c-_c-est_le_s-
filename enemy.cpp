#ifndef Enemy_HEADER
#define Enemy_HEADER
#include <iostream>
#include <vector>
#include"include/Enemy.h"

Enemy::Enemy(std::string new_name, int new_pv, int new_mana, int new_attack, int new_gold, std::string new_ascii) :
	name(new_name), pv(new_pv), mana(new_mana), attack(new_attack), gold(new_gold), ascii(new_ascii) {}

std::string Enemy::get_name() {

	return name;

}

int Enemy::get_pv() {

	return pv;

}
int Enemy::get_mana() {

	return mana;

}

int Enemy::get_attack() {

	return attack;

}
int  Enemy::get_gold() {

	return gold;
}



Enemy Enemy::alea_Enemy()
{
    Enemy ghost("trolling ghosst", 30, 6, 10, 10, "ghost");
    Enemy rat("a rat", 20, 2, 5, 3, "rat");

    std::vector<Enemy>enemybase;
    enemybase.push_back(rat);
    enemybase.push_back(ghost);
    int random = rand() % enemybase.size();
    return enemybase[random];
}

Enemy Enemy::boss()
{
    Enemy dragon("The Dragon", 150, 6, 25, 100, "dragon");

    return dragon;
}

#endif