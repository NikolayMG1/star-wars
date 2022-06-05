#include <iostream>
#include "Galaxy.h"

int main(){
    Jedi jedi("asd", "pesho",KNIGHT, 5, "cherven", 1);
    Jedi jedi1("asd", "bonk",KNIGHT, 5, "cherven", 1);
    // Jedi jedi;
    // std::cin >> jedi;
    // std::cout << jedi;
    Planet planet;
    planet.create_jedi("asd", jedi);
    planet.create_jedi("asd", jedi1);
    // std::cin >> planet;
    std::cout << planet;
}