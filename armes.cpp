#ifndef weapons_HEADER
#define weapons_HEADER

#include "include/weapons.h"
#include "include/Character.h"
#include "include/map.h"
#include <string>
#include <vector>

weapon::weapon(std::string new_name, int new_attack) :
	name(new_name), attack(new_attack){}

std::string weapon::get_name() {
	return name;
}

int weapon::get_attack() {
	return attack;
}
weapon weapon::alea_weapon()
{

    weapon sword("sword", 10);
    weapon mass("mass", 15);

    mapfiller fill;
    fill.weaponlist.push_back(sword);
    fill.weaponlist.push_back(mass);
    int random = rand() % fill.weaponlist.size();
    return fill.weaponlist[random];
}


#endif