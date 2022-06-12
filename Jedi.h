#pragma once
#include "Ranks.h"
#include <iostream>
#pragma warning(disable : 4996)
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
    Jedi(const char*, const char*, Ranks, unsigned,const char*, double);
    Jedi(const Jedi&);
    Jedi& operator=(const Jedi&);
    ~Jedi();
    friend std::ostream& operator<<(std::ostream&, const Jedi&);
    friend std::istream& operator >> (std::istream& in,  Jedi&);
    char* getOrigin() const;
    char* getName() const;
};