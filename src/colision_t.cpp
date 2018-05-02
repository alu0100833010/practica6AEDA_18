#include "../include/colision_t.hpp"
colision_t::colision_t(void): 
    colision_(0) {}

colision_t::~colision_t(void) {}

void colision_t::numero_colision (void) { 
    colision_++;
    cout << "COLISIONES: " << colision_ << endl;
}

void colision_t::menos_colision (void) { 
    colision_--;
    cout << "COLISIONES: " << colision_ << endl;
}