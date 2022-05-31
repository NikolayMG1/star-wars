#pragma once
#include "Jedi.h"

class Planet{
    private:
    char* namePlanet;
    Jedi* jedies;
    unsigned size = 0;
    unsigned capacity = 20;
    void free();
    void copy(const Planet&);
    void resize();

    public:
    Planet();
    Planet(const char* namePlanet, const Jedi&);
    Planet(const Planet&);
    Planet& operator=(const Planet&);
    ~Planet();
    void create_jedi(const char* namePlanet, const Jedi& jedi);//adds a jedi
    void add_planet(const Planet& planet);
    friend std::ostream& operator<<(std::ostream&, const Planet&);
    friend std::istream& operator >> (std::istream& in,  Planet&);

};