#include <iostream>
#include <string>

#include "include/map.h"
#include "include/Enemy.h"
#include "include/Character.h"
#include "include/Armor.h"
#include "include/weapons.h"

Character::Character(std::string new_name, int new_pv, int new_mana) :
    name(new_name), pv(new_pv), mana(new_mana)
{
}

int Character::get_defence()
{
    int def = p_helmet->defence + p_plastron->defence + p_leggings->defence + p_botte->defence;
    return def;
}
void  Character::addgold(int add)
{
    gold += add;
}


char Character::Confirmation() {

    char confirmation;
    std::cin >> confirmation;
    confirmation = toupper(confirmation);

    while ((confirmation != 'Y') && (confirmation != 'N'))
    {
        std::cout << "invalid input please retry \n";
        std::cin >> confirmation;
        confirmation = toupper(confirmation);
    }
    return confirmation;
}

char attaquechoice() {

    char confirmation;
    std::cin >> confirmation;
    confirmation = toupper(confirmation);

    while ((confirmation != 'A') && (confirmation != 'F') && (confirmation != 'H') && (confirmation != 'I'))
    {
        std::cout << "invalid input please retry \n";
        std::cin >> confirmation;
        confirmation = toupper(confirmation);
    }
    return confirmation;
}


bool Character::combat(Enemy& enemy, bool GAMEOVER)
{
    bool turn = true;
    int pv_ennemie = enemy.get_pv();
    while (pv >= 1 && pv_ennemie >= 1)
    {

        while (turn == true)
        {
            std::cout << "You face the enemy, what you wanna do ?\n" << std::endl;
            std::cout << "Attack for " << p_weapon->get_attack() << " dammages.  (0 mana) -> press A"<< std::endl;
            std::cout << "Fireball for 15 dammages.  (5 mana) -> press F" << std::endl;
            std::cout << "Heal yourself for 10 pv (10 mana) -> press H" << std::endl;
            std::cout << "Info of the battle -> press I \n" << std::endl;


            char attackchoice = attaquechoice();
            if (attackchoice == 'A')
            {
                pv_ennemie -= p_weapon->get_attack();
                std::cout <<"You attack and inflict " << p_weapon->get_attack() << " dammage , there's  " << pv_ennemie << " pv left to " << enemy.get_name() << std::endl;
                turn = false;
            }
            else if (attackchoice == 'F')
            {
                if (mana < 5) 
                {
                    std::cout << "You have " << mana <<" mana, you need 5 mana to throw a fireball" << std::endl;
                }
                else 
                {
                    mana -= 5;
                    pv_ennemie -= 15;
                    std::cout << "You throw a fireball, there's  " << pv_ennemie << " pv left to " << enemy.get_name() << std::endl;
                    turn = false;
                }
            }
            else if (attackchoice == 'H')
            {
                if (mana < 10)
                {
                    std::cout << "You have only " << mana << " mana, you need 10 mana to throw a fireball"<< std::endl;
                }
                else 
                {
                    mana -= 10;
                    pv += 10;
                    std::cout << "You heal yourself for 10 PV" << std::endl;
                    if (pv > 20)
                    {
                        std::cout << "You cant have more than 20 PV." << std::endl;
                        std::cout << "The potion healed you for only " << 10 - (pv - 20) << " PV" << std::endl;
                        pv = 20;
                    }
                    std::cout << "You have now " << pv << " pv" << std::endl;

                    turn = false;
                }
            }
            else if (attackchoice == 'I')
            {
                std::cout << "---------------------" << std::endl;
                std::cout << "  Your PV : "<< pv << std::endl;
                std::cout << "  Your Mana : " << mana <<  std::endl;
                std::cout << "  Your armor : " << get_defence() <<  std::endl;
                std::cout << "---------------------" << std::endl;
                std::cout << "  Ennemi's PV: " << pv_ennemie <<  std::endl;
                std::cout << "----------------------" << std::endl;

            }

            if (pv_ennemie <= 0)
            {
                std::cout << enemy.get_name() << " is dead" << std::endl;
                int gold = rand() % enemy.get_gold() + 1;
                addgold(gold);
                std::cout << " Wow ! you found " << gold << " golds " << std::endl;
                mana = 20;
                pv = 20;

                GAMEOVER = false;
                return(GAMEOVER);
            }
        }
        if (pv_ennemie > 0) 
        {     
            if (enemy.get_attack() - get_defence() < 1)
            {
                std::cout << enemy.get_name() << " attack and inflict " << enemy.get_attack() << " dammage ; but your armor overpowerd it and took 0 dammage " << std::endl;
                turn = true;
                cout << "\n";
            }
            else
            {
                pv -= enemy.get_attack() - get_defence();
                std::cout << enemy.get_name() << " attack and inflict " << enemy.get_attack() << " dammage , your armor absorb " << get_defence() << " dammage;  you have " << pv << " pv left " << std::endl;
                turn = true;
                cout << "\n";
                if (pv <= 0)
                {
                    std::cout << name << " is dead" << std::endl;
                    GAMEOVER = true;
                    return(GAMEOVER);

                }
            }    
        }
    }


};

void Character::EquipeArmor(Armor* Armor)
{
    char confirmation;

    switch (Armor->type) {
    case 1:

        if (p_helmet == nullptr)
        {
            p_helmet = Armor;
            std::cout << "you find the helmet : " << Armor->name << " who have "<< Armor->get_defence() <<" armor \n";

        }
        else {
            std::cout << "you find the helmet : " << Armor->name << " who have " << Armor->get_defence() << " armor \n";
            std::cout << "you are already wearing a helmet : " << p_helmet->name << "\n";
            std::cout << "do you want to change it ? (Y / N)\n";
            confirmation = Confirmation();

            if (confirmation == 'Y')
            {
                p_helmet = Armor;
                int defence = get_defence();
                std::cout << "you equip helmet : " << Armor->name << " ; you now have " << get_defence() << " defense points \n";

            }
            else if (confirmation == 'N')
            {
                std::cout << "you leave the helmet on the ground \n";
            }
        }
        break;

    case 2:
        if (p_plastron == nullptr)
        {
            p_plastron = Armor;
            std::cout << "you find the chestplate : " << Armor->name << " who have " << Armor->get_defence() << " armor \n";

        }
        else {
            std::cout << "you find the chestplate : " << Armor->name << " who have " << Armor->get_defence() << " armor \n";
            std::cout << "you are already wearing a chestplate : " << p_plastron->name << "\n";
            std::cout << "do you want to change it ? (Y / N)\n";
            confirmation = Confirmation();

            if (confirmation == 'Y')
            {
                p_plastron = Armor;
                int defence = get_defence();
                std::cout << "you equip chestplate : " << Armor->name << " ; you now have " << get_defence() << " defense points \n";

            }
            else if (confirmation == 'N')
            {
                std::cout << "you leave the chestplate on the ground \n";
            }
        }
        break;

    case 3:
        if (p_leggings == nullptr)
        {
            p_leggings = Armor;
            std::cout << "you find the pants : " << Armor->name << " who have " << Armor->get_defence() << " armor \n";

        }
        else {


            std::cout << "you find the pants : " << Armor->name << " who have " << Armor->get_defence() << " armor \n";
            std::cout << "you are already wearing pants : " << p_leggings->name << "\n";
            std::cout << "do you want to change it ? (Y / N)\n";
            confirmation = Confirmation();

            if (confirmation == 'Y')
            {
                p_leggings = Armor;
                int defence = get_defence();
                std::cout << "you equip the pants : " << Armor->name << " ; you now have " << get_defence() << " defense points \n";

            }
            else if (confirmation == 'N')
            {
                std::cout << "you leave the pants on the ground \n";
            }
        }
        break;

    case 4:
        if (p_botte == nullptr)
        {
            p_botte = Armor;
            int defence = get_defence();
            std::cout << "you find the boots : " << Armor->name << " who have " << Armor->get_defence() << " armor \n";

        }
        else {

            std::cout << "you find the boots : " << Armor->name << " who have " << Armor->get_defence() << " armor \n";
            std::cout << "you are already wearing boots : " << p_botte->name << "\n";
            std::cout << "do you want to change it ? (Y / N)\n";
            confirmation = Confirmation();
            
            if (confirmation == 'Y')
            {
                p_botte = Armor;
                int defence = get_defence();
                std::cout << "you equip boots : " << Armor->name << " ; you now have " << get_defence() << " defense points \n";

            }
            else if (confirmation == 'N')
            {
                std::cout << "you leave the boots on the ground \n";
            }
        }
        break;
    }

}


void Character::Equipeweapon(weapon* weapon) {



    char confirmation;
    std::cout << "you you found the weapon : " << weapon->get_name() <<" that deal "<< weapon->get_attack() << " dammage\n";
    std::cout << "you are already wearing a weapon : " << p_weapon->get_name() << " that deal " << p_weapon->get_attack() <<" dammage \n";
    std::cout << "do you want to change it ? (Y / N)\n";
    confirmation = Confirmation();
    confirmation = toupper(confirmation);

    if (confirmation == 'Y')
    {
        p_weapon = weapon;
        std::cout << "you equip the weapon \n";

    }
    else if (confirmation == 'N')
    {
        std::cout << "you let the weapon on the ground \n";
    }
}

bool Character::Openchest()
{
    std::cout << "You found a Chest ! it contain a random ammount of gold. Do you want to open it ? (Y / N) \n";
    char confirmation;

    confirmation = Confirmation();
    confirmation = toupper(confirmation);
    if (confirmation == 'Y')
    {
        int gold = rand() % 10 + 1;
        addgold(gold);
        std::cout << " Wow ! you found " << gold << " golds\n";
        return true;

    }
    else if (confirmation == 'N')
    {
        std::cout << "you dont open the chest. Who knows, it could be a mimic \n";
        return false;
    }
}