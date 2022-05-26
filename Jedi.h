#pragma once
#include "Ranks.h"

class Jedi{
    private:
    char* name;
    Ranks rank;
    unsigned age;
    char* saberColor;
    double strength;
    void free();
    void copy(const Jedi&);

    public:
    Jedi();
    Jedi(const char*, Ranks, unsigned, char*, double);
    Jedi(const Jedi&);
    Jedi& operator=(const Jedi&);
    ~Jedi();
};