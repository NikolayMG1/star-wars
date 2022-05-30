#include "Planet.h"

class Galaxy{
    private:
    Planet* planet;
    unsigned size = 0;
    unsigned capacity = 20;
    public:
    Galaxy(const Planet&,unsigned);
    void add_planet(const Planet&);
};