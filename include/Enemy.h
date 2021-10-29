#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <vector>

using namespace std;

class Enemy
{
    std::string name;
    int pv;
    int mana;
    int attack;
    int gold;
    std::string ascii;

public:

    Enemy(std::string new_name, int new_pv, int new_mana, int new_attack, int new_gold, std::string new_ascii);


    std::string get_name();
    int get_pv();
    int get_mana();
    int get_attack();
    void get_ascii()
    {
        ifstream f("ascii/monstres/" + ascii + ".txt"); //taking file as inputstream
        string str;
        if (f) {
            ostringstream ss;
            ss << f.rdbuf(); // reading data
            str = ss.str();
        }
        cout << str;
        cout << "\n";
    }    
    int get_gold();
    Enemy alea_Enemy();
    Enemy boss();





protected:
};

