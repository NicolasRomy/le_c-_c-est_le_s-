#include "include/map.h"
#include "include/Character.h"
#include <string>       
#include <iostream>     
#include <sstream>  
#include <Windows.h>

bool GAMEOVER = false;
void carte::Deplacement(Character& character) {
        bool changedir = false;
        while (changedir == false){
            std::cout << "please choose a direction N E S W  \n";
            char direction = Direction();
            if (direction == 'N')
            {
                if (character.player_positiony == 1){
                    std::cout << "you cannot go there \n";
                }
                else {
                    character.player_positiony -= 1;
                    changedir = true;
                }
            }
            if (direction == 'S')
            {
                if (character.player_positiony == SIZEY - 2)
                    std::cout << "you cannot go there \n";
                else {
                    character.player_positiony += 1;
                    changedir = true;
                }
            }
            if (direction == 'W')
            {
                if (character.player_positionx == 1)
                    std::cout << "you cannot go there \n";
                else{
                    character.player_positionx -= 1;
                changedir = true;
            }

            }
            if (direction == 'E')
            {
                if (character.player_positionx == SIZEY - 2)
                    std::cout << "you cannot go there \n";
                else {
                    character.player_positionx += 1;
                    changedir = true;
                }

            }
        }
        std::string lire = Stringinit(character);
        std::cout << lire;
    }
void carte::roomalloc() {
    for (int y = 0; y < SIZEY; y++)
    {
        map.push_back(std::vector<Salle>());
        for (int x = 0; x < SIZEX; x++)
        {
            map[y].push_back(Salle((x) == SIZEX - 1 || (y) == SIZEY - 1 || (x) == 0 || (y) == 0 ? salledef::wall : salledef::center));
        }
    }
}
char carte::Direction() {

    char direction;
    std::cin >> direction;
    direction = toupper(direction);

    while ((direction != 'N') && (direction != 'S')&& (direction != 'E') && (direction != 'W'))
    {
        std::cout << "invalid input please retry \n";
        std::cin >> direction;
        direction = toupper(direction);


    }
    return direction;
}
std::string carte::Stringinit(Character& character) {
    {
        std::stringstream string_stream;
        for (int y = 0; y < SIZEY; y++)
        {
            for (int x = 0; x < SIZEX; x++)
            {
                map[y][x].push_back(Salle::Armor_fill);
                if (character.player_positionx == x && character.player_positiony == y)

                    string_stream << "\u001b[31mp\u001b[0m"  << " ";

                else
                    string_stream << map[y][x].roomtype() << " ";
                    

            }
            string_stream << "\n";
        }
        return string_stream.str();
    }
}
std::string carte::Stringinit(Character& character) {
    {
        std::stringstream string_stream;
        for (int y = 0; y < SIZEY; y++)
        {
            for (int x = 0; x < SIZEX; x++)
            {
                if (character.player_positionx == x && character.player_positiony == y)

                    string_stream << "\u001b[31mp\u001b[0m" << " ";

                else
                    string_stream << map[y][x].roomtype() << " ";

            }
            string_stream << "\n";
        }
        return string_stream.str();
    }
}