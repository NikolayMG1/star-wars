#include "Planet.h"
#pragma once
#pragma warning(disable : 4996)
#include <iostream>

class Galaxy{
    private:
    Planet* planets;
    unsigned size = 0;
    unsigned capacity = 20;
    void free();
    void copy(const Galaxy&);
    public:
    Galaxy();
    Galaxy(const Planet&);
    Galaxy& operator=(const Galaxy&);
    bool operator==(const Galaxy&);
    ~Galaxy();
    void add_planet(const Planet&);
    void resize();
    friend std::ostream& operator<<(std::ostream& out, const Galaxy&);
    friend std::istream& operator >> (std::istream& in,  Galaxy&);
};