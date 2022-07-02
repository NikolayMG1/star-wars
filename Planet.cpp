#include "Planet.h"
#include <cstring>
#include <math.h>

Planet::Planet()
{
    this->namePlanet = nullptr;
    this->jedies = new Jedi[capacity];
}
Planet::Planet(const char *namePlanet)
{
    this->namePlanet = new char[strlen(namePlanet) + 1];
    strcpy(this->namePlanet, namePlanet);
    this->jedies = new Jedi[capacity];
}
Planet::Planet(const Planet &other)
{
    copy(other);
}
Planet &Planet::operator=(const Planet &other)
{
    if (&other != this)
    {
        free();
        copy(other);
    }
    return *this;
}
Planet::~Planet()
{
    free();
}
void Planet::free()
{
    delete[] jedies;
    delete[] namePlanet;
}
void Planet::copy(const Planet &other)
{
    this->namePlanet = new char[strlen(other.namePlanet) + 1];
    strcpy(this->namePlanet, other.namePlanet);
    this->jedies = new Jedi[other.capacity];
    this->size = other.size;
    for (size_t i = 0; i < size; i++)
    {
        this->jedies[i] = other.jedies[i];
    }
    this->capacity = other.capacity;
}
void Planet::resize()
{
    Jedi *temp = new Jedi[capacity *= 2];
    for (size_t i = 0; i < size; i++)
    {
        temp[i] = this->jedies[i];
    }
    delete[] jedies;
    jedies = temp;
}
void Planet::create_jedi(const char *namePlanet, const Jedi &Newjedi)
{
    if (!strcmp(namePlanet, Newjedi.getOrigin()))
    {
        bool exists = false;
        for (int i = 0; i < size; i++)
        {
            if (!strcmp(jedies[i].getName(), Newjedi.getName()))
            {
                exists = true;
            }
        }
        if (!exists)
        {
            // delete[] this->namePlanet;
            // this->namePlanet = new char[strlen(namePlanet) + 1];
            // strcpy(this->namePlanet, namePlanet);
            if (size >= capacity)
            {
                resize();
            }
            this->jedies[size++] = Newjedi;
            std::cout << this->jedies[size - 1];
            std::cout << Newjedi.getName() << " was added successfully" << '\n';
        }
        else
        {
            std::cout << Newjedi.getName() << " already exists" << '\n';
        }
    }
}
void Planet::removeJedi(const char *namePlanet, const Jedi &Newjedi)
{

    if (!strcmp(namePlanet, Newjedi.getOrigin()))
    {
        bool exists = false;
        for (int i = 0; i < size; i++)
        {
            if (!strcmp(jedies[i].getName(), Newjedi.getName()))
            {
                exists = true;
                std::cout << Newjedi.getName() << " was removed successfully" << '\n';
                this->jedies[i] = jedies[size-1];
                size--;

            }
        }
        if (!exists)
        {
            std::cout << Newjedi.getName() << " doesn't exists on this planet" << '\n';
            // delete[] this->namePlanet;
            // this->namePlanet = new char[strlen(namePlanet) + 1];
        }
    }
}
void Planet::demote_jedi(const char *jediName, const double multiplier)
{
    if (multiplier < 0)
    {
        throw "multiplier must be a positive number";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (!strcmp(jedies[i].getName(), jediName))
            {
                // std::cout << jedies[i].getRank();
                if (jedies[i].getRank() == 1)
                {
                    jedies[i].setRank(YOUNGLING);
                }
                if (jedies[i].getRank() == 2)
                {
                    jedies[i].setRank(INITIATE);
                }
                else if (jedies[i].getRank() == 3)
                {
                    jedies[i].setRank(PADAWAN);
                }
                else if (jedies[i].getRank() == 4)
                {
                    jedies[i].setRank(KNIGHT_ASPIRANT);
                }
                else if (jedies[i].getRank() == 5)
                {
                    jedies[i].setRank(KNIGHT);
                }
                else if (jedies[i].getRank() == 6)
                {
                    jedies[i].setRank(MASTER);
                }
                else if (jedies[i].getRank() == 7)
                {
                    jedies[i].setRank(BATTLE_MASTER);
                }
                else
                {
                    std::cout << "Lowest rank is YOUNGLING";
                }
                jedies[i].setPower(jedies[i].getPower() * (1 - multiplier));
            }
        }
    }
}
void Planet::promote_jedi(const char *jediName, const double multiplier)
{
    if (multiplier < 0)
    {
        throw "multiplier must be a positive number";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (!strcmp(jedies[i].getName(), jediName))
            {
                // std::cout << jedies[i].getRank();
                if (jedies[i].getRank() == 0)
                {
                    jedies[i].setRank(INITIATE);
                }
                else if (jedies[i].getRank() == 1)
                {
                    jedies[i].setRank(PADAWAN);
                }
                else if (jedies[i].getRank() == 2)
                {
                    jedies[i].setRank(KNIGHT_ASPIRANT);
                }
                else if (jedies[i].getRank() == 3)
                {
                    jedies[i].setRank(KNIGHT);
                }
                else if (jedies[i].getRank() == 4)
                {
                    std::cout << "basda";
                    jedies[i].setRank(MASTER);
                }
                else if (jedies[i].getRank() == 5)
                {
                    jedies[i].setRank(BATTLE_MASTER);
                }
                else if (jedies[i].getRank() == 6)
                {
                    jedies[i].setRank(GRAND_MASTER);
                }
                else
                {
                    std::cout << "Highest rank is GRAND_MASTER";
                }
                jedies[i].setPower(jedies[i].getPower() * (1 + multiplier));
            }
        }
    }
}
std::ostream &operator<<(std::ostream &out, const Planet &planet)
{
    out << '\n';
    out << "The planet " << planet.namePlanet << " has the jedies: " << '\n';
    for (int i = 0; i < planet.size; i++)
    {
        out << "Jedi " << i + 1 << ": " << planet.jedies[i] << '\n';
    }
    return out;
}
void Planet::printOnConsole(){
    std::cout << "Enter the planet name: " << '\n';
    std::cout << "Enter a jedi: ";
}
std::istream &operator>>(std::istream &in, Planet &planet)
{
    planet.free();
    char temp[1024];
    in >> temp;
    planet.namePlanet = new char[strlen(temp) + 1];
    strcpy(planet.namePlanet, temp);
    
    for (int i = 0; i < planet.size; i++)
    {
        in >> planet.jedies[i];
    }
    return in;
}

char *Planet::getName() const
{
    return this->namePlanet;
}

void Planet::getStrongestJedi() const
{
    double biggestPower = 0;
    char buffer[100];
    for (int i = 0; i < size; i++)
    {
        double diff;
        if (jedies[i].getPower() > 0)
        {
            diff = biggestPower - jedies[i].getPower();
        }
        else
        {
            diff = biggestPower + jedies[i].getPower();
        }
        if (diff < __DBL_EPSILON__)
        {
            biggestPower = jedies[i].getPower();
            strcpy(buffer, jedies[i].getName());
        }
    }
    std::cout << '\n'
              << buffer << " is the strongest Jedi" << '\n';
}

void Planet::printCommand(Planet& planet){
    int x;
    std::cout << '\n';
    std::cout <<"to create a jedi type 1" <<'\n';
    std::cout <<"to remove jedi type 2" <<'\n'; 
    std::cout <<"to promote jedi type 3" <<'\n'; 
    std::cout <<"to demote jedi type 4" <<'\n'; 
    std::cout <<"to find the stongest jedi type 5" <<'\n'; 
    std::cout <<"to end the program and print all jedies type 6" <<'\n';
    std::cin >> x;


    if(x == 1){
        Jedi jedi;
        jedi.printOnConsole();
        std::cin >> jedi;
        bool exists = false;
        for(int i = 0; i < size; i++){
            if(!strcmp(jedi.getName(),jedies[i].getName())){
                exists = true;
            }
        }
        std::cout << '\n';
        if(!exists){
            planet.create_jedi(jedi.getOrigin(), jedi);
        }
        else{
            std::cout << jedi.getName() << "already exists";
        }
    }
    else if(x == 2){
        Jedi jedi;
        jedi.printOnConsole();
        std::cin >> jedi;
        
        bool exists = false;
        for(int i = 0; i < size; i++){
            if(!strcmp(jedi.getName(),jedies[i].getName())){
                //std::cout << jedi.getName() << " removed";
                planet.removeJedi(jedi.getName(), jedi);
                exists = true;
            }
        }
        std::cout << '\n';
        if(!exists){
            std::cout << jedi.getName() << " doesnt exist";
        }
    }
    else if(x == 3){
        Jedi jedi;
        jedi.printOnConsole();
        std::cin >> jedi;
        
        //bool exists = false;
        for(int i = 0; i < size; i++){
            if(!strcmp(jedi.getName(),jedies[i].getName())){
                //std::cout << jedi.getName() << " removed";
                planet.promote_jedi(jedies[i].getName(),1);
                std::cout << jedi << "promoted successfully";
                //std::cout << jedi;
                //exists = true;
            }
        }
        // std::cout << '\n';
        // if(!exists){
        //     std::cout << jedi.getName() << " max rank";
        // }
    }
    else if(x == 4){
        Jedi jedi;
        jedi.printOnConsole();
        std::cin >> jedi;
        
        //bool exists = false;
        for(int i = 0; i < size; i++){
            if(!strcmp(jedi.getName(),jedies[i].getName())){
                //std::cout << jedi.getName() << " removed";
                std::cout << jedi << "demoted successfully" << '\n';
                planet.demote_jedi(jedi.getName(),1);
                //std::cout << jedi;
                //exists = true;
            }
        }
        // std::cout << '\n';
        // if(!exists){
        //     std::cout << jedi.getName() << " max rank";
        // }
    }
    else if(x == 5){
        planet.getStrongestJedi();
    }
    else if(x == 6){
        for(int i = 0; i < size; i++){
            std::cout << planet.jedies[i];
        }
        std::cout << "Program completed";
        return;
    }
    printCommand(planet);
}