#include <iostream>
#include "Galaxy.h"

int main(){

    Jedi jedi("fmi", "pesho",KNIGHT, 5, "cherven", 1);
    // Jedi jedi;
    // std::cin >> jedi;
    // std::cout << jedi;

    Planet planet;
    planet.create_jedi("Hui", jedi);
    // std::cin >> planet;
    std::cout << planet;
}