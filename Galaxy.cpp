#include "Galaxy.h"
#include <cstring>

Galaxy::Galaxy(){
    this->planets = new Planet[capacity];
}
// Galaxy::Galaxy(const Planet& planet){
//     this->planets = new Planet[capacity];
//     this->planets[size++] = planet;
// }
void Galaxy::add_planet(const Planet& planet){
    bool isThere = false;
    for(int i = 0; i < size; i++){
        if(!strcmp(this->planets[i].getName(), planet.getName())){
            isThere = true;         
        }
    }
    if(size >= capacity){
        resize();
    }
    if(!isThere){
        this->planets[size++] = planet; 
    }
    else{
        //std::cout << planet.getName() << " already exists" << '\n';
    }
}
void Galaxy::resize(){
    Planet* temp = new Planet[capacity*=2];
    for(size_t i = 0;i < size; i++){
        temp[i] = this->planets[i];
    }
    delete[] planets;
    planets = temp;
}
std::ostream& operator<<(std::ostream& out, const Galaxy& other){
    for(int i  = 0; i < other.size; i++){
        out <<"Planet " << i+1 << ": " << other.planets[i];
    }
    return out;
}
Galaxy& Galaxy::operator=(const Galaxy& other){
    if(this != &other){
        copy(other);
    }
    return *this;
}
Galaxy::~Galaxy(){
    free();
}
void Galaxy::free(){
    delete[] planets;
}
void Galaxy::copy(const Galaxy& other){
    this->planets = new Planet[other.size];
    for(int i = 0; i < size; i++){
        this->planets[i] = other.planets[i];
    }
}