#include "Jedi.h"
#include <cstring>

Jedi::Jedi(){
    this->age = 0;
    this->strength = 0;
    this->name = nullptr;
    this->saberColor = nullptr;
    this->origin = nullptr;
    this->rank = UNKNOWN;
}
Jedi::Jedi(const char* origin, const char* name, Ranks rank, unsigned age, char* saberColor, double strength){
    this->origin = new char[strlen(origin)+1];
    strcpy(this->origin, origin);
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->rank = rank;
    this->age = age;
    this->saberColor = new char[strlen(saberColor)+1];
    strcpy(this->saberColor, saberColor);
    this->strength = strength;
}
Jedi::Jedi(const Jedi& other){
    copy(other);
}
Jedi& Jedi::operator=(const Jedi& other){
    if(&other != this){
        free();
        copy(other);
    }
    return *this;
}
Jedi::~Jedi(){
    free();
}

void Jedi::free(){
    delete[] name;
    delete[] saberColor;
    delete[] origin;
}
void Jedi::copy(const Jedi& other){
    this->age = other.age;
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name,other.name);
    this->rank = other.rank;
    this->strength = other.strength;
    this->saberColor = new char[strlen(other.saberColor)+1];
    strcpy(this->saberColor,other.saberColor);
}

std::istream& operator>>(std::istream& in,  Jedi& jedi){
    int i;
    std::cout << "Enter the origin: ";
    in >> jedi.origin; 
    std::cout << "Enter the name: ";
    in >> jedi.name;
    std::cout << "Enter the rank: ";
    in >> i;
    std::cout << "Enter 1 for YOUNGLING" << '\n';
    std::cout << "Enter 2 for INITIATE" << '\n';
    std::cout << "Enter 3 for PADAWAN" << '\n';
    std::cout << "Enter 4 for KNIGHT_ASPIRANT" << '\n';
    std::cout << "Enter 5 for KNIGHT" << '\n';
    std::cout << "Enter 6 for MASTER" << '\n';
    std::cout << "Enter 7 for BATTLE_MASTER" << '\n';
    std::cout << "Enter 8 for GRAND_MASTER" << '\n';
    switch (i){
    case 1:
        jedi.rank = YOUNGLING;
        break;
    case 2:
        jedi.rank = INITIATE;
        break;
    case 3:
        jedi.rank = PADAWAN;
        break;
    case 4:
        jedi.rank = KNIGHT_ASPIRANT;
        break;
    case 5:
        jedi.rank = KNIGHT;
        break;
    case 6:
        jedi.rank = MASTER;
        break;
    case 7:
        jedi.rank = BATTLE_MASTER;
        break;
    case 8:
        jedi.rank = GRAND_MASTER;
        break;
    default:
        break;
    }
    std::cout << "Enter the age: ";
    in >> jedi.age;
    std::cout << "Enter the color of the saber: ";
    in >> jedi.saberColor;  
    std::cout << "Enter the strength: ";
    in >> jedi.strength;    
    return in;
}
std::ostream& operator<<(std::ostream& out, const Jedi& jedi){
    out << '\n';
    out <<"Origin: " << jedi.origin << '\n';
    out <<"Name: " << jedi.name << '\n';
    out <<"Rank: " << jedi.rank << '\n';
    out <<"Age: " << jedi.age << '\n';
    out <<"SaberColor: " << jedi.saberColor << '\n';
    out <<"Strength: " << jedi.strength << '\n';
    return out;
}
