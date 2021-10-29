#include <iostream>
#include <vector>
#include "include/Enemy.h"
#include "include/weapons.h"
#include "include/Armor.h"
#include <list>

class Character;
enum class salledef
{
    wall,
    center
};

class Salle
{
public:
    Salle(salledef c = salledef::wall) : salledef(c) {}
    int roomtype()
    {
        if (salledef == salledef::wall)
        {
            return 1;
        }
        else
        {
            return 2 ;
        };
        }
    Armor Armor_fill() {
        Armor helmet("helmet", 1, 3);
        Armor jogging("jogging de la guille", 3, 3);

        mapfiller fill;
        std::vector<Armor>armor;
        fill.armorlist.push_back(helmet);
        fill.armorlist.push_back(jogging);


        int random = rand() % armor.size();
        return ()
    }
protected:
    salledef salledef;
};
class  carte
{
public:
      char Direction();
      void Deplacement(Character& character);
      void roomalloc();
       std::string Stringinit(Character& character);
       std::vector<std::vector<Salle>> map;
       const int SIZEX = 7;
       const int SIZEY = 7;
protected:
};
class mapfiller {
public:

    std::vector<weapon> weaponlist;
    std::vector<Armor> armorlist;
    std::vector<Enemy> Enemylist;
};