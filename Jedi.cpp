#include "Jedi.h"
#include <cstring>

Jedi::Jedi(){
    this->age = 0;
    this->strength = 0;
}
Jedi::Jedi(const char* name, Ranks rank, unsigned age, char* saberColor, double strength){
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