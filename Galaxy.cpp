#include "Galaxy.h"
#include <cstring>


Galaxy::Galaxy(){
    this->planet = nullptr;
}
// Galaxy::Galaxy(const Planet& planet){
//     this->planet = planet;
// }
void Galaxy::add_planet(const Planet& planet){
    this->planet = new Planet[capacity];
    if(size >= capacity){
        resize();
    }
    this->planet[size++] = planet; 
}
void Galaxy::resize(){
    Planet* temp = new Planet[capacity*=2];
    for(size_t i = 0;i < size; i++){
        temp[i] = this->planet[i];
    }
    delete[] planet;
    planet = temp;
}