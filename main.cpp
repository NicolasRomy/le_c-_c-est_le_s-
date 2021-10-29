
#include <vector>
#include <iostream>
#include <string>
#include <Windows.h>
#include <sstream>
#include <cstdlib>
#include "include/Enemy.h"
#include "include/Character.h"
#include "include/map.h"
#include <locale>

int main()
{

    std::locale::global(std::locale{ "" });
    srand(time(NULL));
    std::cout << "you wake up in a dark room with a sore head and no idea how you got there \nWhat's your name again?\n-";
    std::string name;
    std::cout << "enter your name: ";
    std::cin >> name;
    //             ( nom, pv, mana )
    Character david(name, 20, 20);
    std::cout << "votre name est : " << name << "\n";
    weapon fist("fist", 5);
    david.set_weapon(&fist);
    Armor bonnet("bonnet", 1, 0);
    Armor veste("veste", 2, 0);
    Armor pentalon("pentalon", 3, 0);
    Armor botte("botte", 4, 0);
    david.EquipeArmor(&bonnet);
    david.EquipeArmor(&veste);
    david.EquipeArmor(&pentalon);
    david.EquipeArmor(&botte);
    bool GAMEOVER = false;
    char confirmation;
    carte map;
    map.roomalloc();
    while (GAMEOVER == false)
    {
        std::string lire = map.Stringinit(david);
        std::cout << lire;
        map.Deplacement(david);
        std::cout << "you enter the room  \n";

        if (david.player_positionx == 5 && david.player_positiony == 5) 
        {
            Enemy enemy = enemy.boss();
            enemy.get_ascii();
            david.combat(enemy, GAMEOVER);
            GAMEOVER = true;
        }       
        bool enemy_dead = true;
        Enemy enemy = enemy.alea_Enemy();

        bool is_enemy = (rand() % 100) < 75;
        bool is_chest = (rand() % 100) < 50;
        bool is_weapon = (rand() % 100) < 40;
        bool is_armor = (rand() % 100) < 40;


        if (is_enemy == true)
        {  
            std::cout << "You see a monster : " << enemy.get_name() << "\n";
        }        
        if (is_chest == true)
        {  
            std::cout << "You see a chest \n";
        }       
        if (is_weapon == true)
        {  
            std::cout << "You see Weapons \n";
        }        
        if (is_armor == true)
        {  
            std::cout << "You see armors \n \n \n";
        }

        if ( is_enemy == true)
        {
            enemy_dead = false;
            enemy.get_ascii();
            std::cout << "Do you wish to fight "<< enemy.get_name() <<"(Y / N) \n";
            confirmation = david.Confirmation();
            confirmation = toupper(confirmation);
            if (confirmation == 'Y' && GAMEOVER == false)
            {
                david.combat(enemy, GAMEOVER);
                enemy_dead = true;
            }
            else 
            {

            }
        }
        if (enemy_dead == true) 
        {
            if (is_chest == true)
            {
                std::cout << "You pick a chest \n";
                david.Openchest();
            }
            if (is_weapon == true)
            {
                std::cout << "You pick Weapons \n";
                weapon new_weapon = new_weapon.alea_weapon();
                david.Equipeweapon(&new_weapon);
            }
            if (is_armor == true)
            {
                Armor new_armor = new_armor.alea_Armor();
                david.EquipeArmor(&new_armor);
            }
        }

      
      
    }
    

};
