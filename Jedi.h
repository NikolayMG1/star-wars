#pragma once
#include "Ranks.h"
#include <iostream>

class Jedi{
    private:
    char* name;
    Ranks rank;
    unsigned age;
    char* saberColor;
    double strength;
    char* origin;
    void free();
    void copy(const Jedi&);

    public:
    Jedi();
    Jedi(const char*, const char*, Ranks, unsigned, char*, double);
    Jedi(const Jedi&);
    Jedi& operator=(const Jedi&);
    ~Jedi();
    friend std::ostream& operator<<(std::ostream&, const Jedi&);
    friend std::istream& operator >> (std::istream& in,  Jedi& date);
};