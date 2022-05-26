#pragma once
#include "Jedi.h"

class Moon: public Jedi{
    private:
    char* nameMoon;
    Jedi* jedi;
    public:
    Moon();
    Moon(const char* nameMoon,const Jedi* jedi,const char* name, Ranks rank, unsigned age, char* saberColor, double strength);
    Moon(const Moon&);
    Moon& operator=(const Moon&);
    ~Moon();
};