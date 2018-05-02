#include "../include/dni_t.hpp"

dni_t::dni_t(void):
    dni(0) {}

dni_t::~dni_t() {}

int dni_t::cont = 0; // Inicializamos la variable estática a 0.
int dni_t::colision = 0;

dni_t* dni_t::secuencia_demo(int sz) {
    dni_t* dni_ = new dni_t[sz];
    int valor[sz];
    
    srand(time(NULL));
    for (int i = 0; i < sz; i++) {
        valor[i] = (rand() %(8000 - 3000) + 3000);
        dni_[i].set_dni(valor[i]);
    }
    return dni_;
}

int dni_t::get_dni(void) const {
    return dni;
}

void dni_t::set_dni(int n) {
    dni = n;    
}

// SOBRECARGA DE OPERADORES //

bool dni_t::operator==(const dni_t& n) {
    cont++;
    return(dni == n.get_dni());
}

bool dni_t::operator!=(const dni_t& n) {
    cont++;
    return(dni != n.get_dni());
}

bool dni_t::operator>(const dni_t& n) {
    cont++;
    return(dni > n.get_dni());
}

bool dni_t::operator<(const dni_t& n) {
    cont++;
    return(dni < n.get_dni());
}

bool dni_t::operator<=(const dni_t& n) {
    cont++;
    return(dni <= n.get_dni());
}

bool dni_t::operator>=(const dni_t& n) {
    cont++;
    return(dni >= n.get_dni());
}

int dni_t::get_cont() {
    return cont;   
}

void dni_t::iniciar_contador(void) {
    cont = 0;  
}

int dni_t::get_colision() {
    return colision;   
}

void dni_t::suma_colision(void) {
    colision++;
    cout << "COLISIONES -> " << colision << endl;
}
ostream& operator<<(ostream& os, dni_t dni_) {
    os << dni_.get_dni();
    return os;
}