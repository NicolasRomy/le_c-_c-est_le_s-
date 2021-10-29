#pragma once
#include <string>
class Enemy;
class Armor;
class weapon;

class Character
{
public:
    bool combat(Enemy& enemy , bool GAMEOVER);
    void EquipeArmor(Armor* Armor);
    void Equipeweapon(weapon* weapon);
    void set_weapon(weapon* weapon) { p_weapon = weapon; }
    int get_defence();
    bool Openchest();
    int get_gold() { return gold; }
    void addgold(int);
    int player_positionx = 1;
    int player_positiony = 1;
    char Confirmation();
    Character init();
    Character(std::string new_name, int new_pv, int new_mana);

private:
    std::string name;
    int pv;
    int mana;

    weapon* p_weapon = nullptr;
    Armor* p_helmet = nullptr;
    Armor* p_plastron = nullptr;
    Armor* p_leggings = nullptr;
    Armor* p_botte = nullptr;
    int gold = 0;


protected:
};