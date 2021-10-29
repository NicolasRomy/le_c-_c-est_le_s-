#ifndef Armors_HEADER
#define Armors_HEADER
#include <vector>
#include "include/map.h"
#include "include/Character.h"
#include"include/Armor.h"

#include <string>

Armor::Armor(std::string new_name, int new_type, int new_defence) :
	name(new_name), type(new_type), defence(new_defence) {}

std::string Armor::get_name() {
	return name;
}

int Armor::get_type() {
	return type;
}

int Armor::get_defence() {
	return defence;
}
Armor Armor::alea_Armor()
{
    //          ( nom, type, armure )
    Armor helmet("helmet", 1, 3);
    Armor jogging("jogging de la guille", 3, 3);

    mapfiller fill;
    std::vector<Armor>armor;
    fill.armorlist.push_back(helmet);
    fill.armorlist.push_back(jogging);


    int random = rand() % armor.size();
    return armor[random];
}

#endif