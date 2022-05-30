#pragma once
#include "Jedi.h"

class Planet{
    private:
    char* namePlanet;
    Jedi* jedi;
    unsigned size = 0;
    unsigned capacity = 20;
    void free();
    void copy(const Planet&);
    void resize();

    public:
    Planet();
    Planet(const char* namePlanet);
    Planet(const Planet&);
    Planet& operator=(const Planet&);
    ~Planet();
    void create_jedi(const char* namePlanet, const Jedi& jedi);//adds a jedi

};