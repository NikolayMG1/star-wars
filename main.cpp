#include <iostream>
#include "Galaxy.h"

int main(){
    Jedi jedi("asd", "pesho",GRAND_MASTER, 5, "cherven", 15);
    Jedi jedi1("asd", "bonk",MASTER, 10, "cherven", 10);
    //Jedi jedi2("asd", "bonk",MASTER, 1, "cherven", 1);
    ///Jedi jedi2("dfsf", "zxc",KNIGHT, 5, "cherven", 1);
    // Jedi jedi;
    // std::cin >> jedi;
    // std::cout << jedi;
    Planet planet("asd");
    //Planet planet1("dfsf");
    //Galaxy galaxy;
    //galaxy.add_planet(planet);
    //galaxy.add_planet(planet1);
    planet.create_jedi("asd", jedi);
    planet.create_jedi("asd", jedi1);
    //planet.demote_jedi("bonk", 10);
    //planet.create_jedi("asd", jedi2);
    //planet1.create_jedi("asd", jedi1);
    //planet.create_jedi("dfsf", jedi2);
    //planet.removeJedi("asd", jedi1);
    //planet.promote_jedi("bonk", 10);
    //std::cin >> planet;
    // std::cout << planet;
    //std::cout << planet;
    planet.getStrongestJedi();
    std::cout << planet;
}