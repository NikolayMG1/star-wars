#include "Planet.h"
#include <cstring>

Planet::Planet(){
    this->namePlanet = nullptr;
    this->jedies = new Jedi[capacity];
}
Planet::Planet(const char* namePlanet){
    this->namePlanet = new char[strlen(namePlanet)+1];
    strcpy(this->namePlanet, namePlanet);
    this->jedies = new Jedi[capacity];
}
Planet::Planet(const Planet& other){
    copy(other);
}
Planet& Planet::operator=(const Planet& other){
    if(&other != this){
        free();
        copy(other);
    }
    return *this;
}
Planet::~Planet(){
    free();
}
void Planet::free(){
    delete[] jedies;
    delete[] namePlanet;
}
void Planet::copy(const Planet& other){
    this->namePlanet = new char[strlen(other.namePlanet) + 1];
    strcpy(this->namePlanet, other.namePlanet);
    this->jedies = new Jedi[other.capacity];
    this->size = other.size;
    for(size_t i = 0; i < size; i++){
        this->jedies[i] = other.jedies[i];
    }
    this->capacity = other.capacity;
}
void Planet::resize(){
    Jedi* temp = new Jedi[capacity*=2];
    for(size_t i = 0;i < size; i++){
        temp[i] = this->jedies[i];
    }
    delete[] jedies;
    jedies = temp;
}
void Planet::create_jedi(const char* namePlanet, const Jedi& Newjedi){
    if(!strcmp(namePlanet,Newjedi.getOrigin())){
        delete[] this->namePlanet;
        this->namePlanet = new char[strlen(namePlanet)+1];
        strcpy(this->namePlanet, namePlanet);
        if(size >= capacity){
            resize();
        }
        this->jedies[size++] = Newjedi;
        std::cout << Newjedi.getName() << " was added successfully" << '\n';
    }
    else{
        std::cout << "Jedi already exists";
    }
}
void Planet::removeJedi(const char* namePlanet, const Jedi& Newjedi){

    if(!strcmp(namePlanet,Newjedi.getOrigin())){
        delete[] this->namePlanet;
        this->namePlanet = new char[strlen(namePlanet)+1];
        
        std::cout << Newjedi.getName() << " was removed successfully" << '\n';
        size--;
    }
    else{
        std::cout << "Jedi doesn't exists on this planet";
    }
}
std::ostream& operator<<(std::ostream& out, const Planet& planet){
    out << planet.namePlanet << '\n';
    for(int i = 0; i < planet.size; i++){
        out << "Jedi " << i+1 << ": " << planet.jedies[i] << '\n';
    }
    return out;
}

std::istream& operator>>(std::istream& in, Planet& planet){
    planet.free();
    char temp[1024];
    std::cout << "Enter the planet name: ";
    in >> temp;
    planet.namePlanet = new char[strlen(temp)+1];
    strcpy(planet.namePlanet, temp);
    std::cout << "Enter a jedi: ";
    for(int i = 0; i < planet.size; i++){
        in >> planet.jedies[i];
    }
    return in;
}

char* Planet::getName() const{
    return this->namePlanet;
}