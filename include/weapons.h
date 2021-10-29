#pragma once
#include <string>

class weapon
{
public:
    

    weapon(std::string new_name, int new_attack );

    std::string get_name();
    int get_attack();
    weapon alea_weapon();

protected:
    std::string name;
    int attack;
};

