#pragma once
#include <string>

class Armor
{
public:
    std::string name;
    int type;
    int defence;

    Armor(std::string new_name, int new_type, int defence);


    std::string get_name();
    int get_type();
    int get_defence();
    Armor alea_Armor();
protected:
};

