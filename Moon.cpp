#include "Moon.h"

Moon::Moon(){
    
}
    Moon(const char* nameMoon,const Jedi* jedi,const char* name, Ranks rank, unsigned age, char* saberColor, double strength);
    Moon(const Moon&);
    Moon& operator=(const Moon&);
    ~Moon();