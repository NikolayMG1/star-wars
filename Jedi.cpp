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
Jedi::Jedi(const char* origin, const char* name, Ranks rank, unsigned age,const char* saberColor, double strength){
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
    this->origin = new char[strlen(other.origin)+1];
    strcpy(this->origin,other.origin);
    this->age = other.age;
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name,other.name);
    this->rank = other.rank;
    this->strength = other.strength;
    this->saberColor = new char[strlen(other.saberColor)+1];
    strcpy(this->saberColor,other.saberColor);
}
void Jedi::printOnConsole(){
    std::cout << "Enter the origin, name, rank " << '\n';
    // std::cout << "Enter the name, " << '\n';
    // std::cout << "Enter the rank, " << '\n';
    std::cout << "-Enter 0 for YOUNGLING" << '\n';
    std::cout << "-Enter 1 for INITIATE" << '\n';
    std::cout << "-Enter 2 for PADAWAN" << '\n';
    std::cout << "-Enter 3 for KNIGHT_ASPIRANT" << '\n';
    std::cout << "-Enter 4 for KNIGHT" << '\n';
    std::cout << "-Enter 5 for MASTER" << '\n';
    std::cout << "-Enter 6 for BATTLE_MASTER" << '\n';
    std::cout << "-Enter 7 for GRAND_MASTER" << '\n';

    // std::cout << "Enter the color of the saber, " << '\n';
    // std::cout << "Enter the strength " << '\n';
        std::cout << "Enter the age, saber, strength " << '\n';
}

std::istream& operator>>(std::istream& in,Jedi& jedi){
    int i;
    char temp[1024];
    jedi.free();
    in >> temp;
    jedi.origin = new char[strlen(temp)+1];
    strcpy(jedi.origin, temp);
    in >> temp;
    jedi.name = new char[strlen(temp)+1];
    strcpy(jedi.name, temp);
    in >> i;
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
    in >> jedi.age;
    in >> temp;
    jedi.saberColor = new char[strlen(temp)+1];
    strcpy(jedi.saberColor, temp);
    in >> jedi.strength;    
    return in;
}
std::ostream& operator<<(std::ostream& out, const Jedi& jedi){
    out << '\n';
    out <<"Origin: " << jedi.origin << '\n';
    out <<"Name: " << jedi.name << '\n';
    out <<"Rank: ";
    switch (jedi.getRank()){
    case 1:
        out << "YOUNGLING";
        break;
    case 2:
        out << "INITIATE";
        break;
    case 3:
        out << "PADAWAN";
        break;
    case 4:
        out <<  "KNIGHT_ASPIRANT";
        break;
    case 5:
        out <<  "KNIGHT";
        break;
    case 6:
        out << "MASTER";
        break;
    case 7:
        out <<  "BATTLE_MASTER";
        break;
    case 8:
        out <<  "GRAND_MASTER";
        break;
    default:
        break;
    }
    out << '\n';
    out <<"Age: " << jedi.age << '\n';
    out <<"SaberColor: " << jedi.saberColor << '\n';
    out <<"Strength: " << jedi.strength << '\n';
    return out;
}

char* Jedi::getOrigin() const{
    return origin;
}
double Jedi::getPower() const{
    return strength;
}
char* Jedi::getName() const{
    return name;
}

Ranks Jedi::getRank() const{
    return rank;
}

void Jedi::setRank(const Ranks& rank){
    this->rank = rank;
}

void Jedi::setPower(const double strength){
    this->strength = strength;
}