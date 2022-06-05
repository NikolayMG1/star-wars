#include "Galaxy.h"
#include <cstring>


Galaxy::Galaxy(){
    this->planets = nullptr;
}
// Galaxy::Galaxy(const Planet& planet){
//     this->planet = planet;
// }
void Galaxy::add_planet(const Planet& planet){
    this->planets = new Planet[capacity];
    if(size >= capacity){
        resize();
    }
    this->planets[size++] = planet; 
}
void Galaxy::resize(){
    Planet* temp = new Planet[capacity*=2];
    for(size_t i = 0;i < size; i++){
        temp[i] = this->planets[i];
    }
    delete[] planets;
    planets = temp;
}

// std::ostream& operator<<(std::ostream& out, const Galaxy& other){
//     for(int i  = 0; i < other.size; i++){
//         out << other.planets[i];
//     }
// }
// std::istream& operator >> (std::istream& in,  Galaxy& other){
//     other.free();
    
// }

void Galaxy::free(){
    delete[] planets;
}
void Galaxy::copy(const Galaxy& other){
    this->planets = new Planet[other.size + 1];
    for(int i = 0; i < size; i++){
        this->planets[i] = other.planets[i];
    }
}