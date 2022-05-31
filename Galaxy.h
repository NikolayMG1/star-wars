#include "Planet.h"

class Galaxy{
    private:
    Planet* planet;
    unsigned size = 0;
    unsigned capacity = 20;
    public:
    Galaxy();
    Galaxy(const Planet&);
    void add_planet(const Planet&);
    void resize();
};