#pragma once
#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

class dni_t {
    private:
        
    public:
        static int cont;
        static int colision;
        int dni;
        
        dni_t();
        ~dni_t();
        
        dni_t* secuencia_demo(int sz);
        
        int get_dni(void) const;
        void set_dni(int n);
        
        bool operator==(const dni_t& n);
        bool operator!=(const dni_t& n);
        bool operator>(const dni_t& n);
        bool operator<(const dni_t& n);
        bool operator<=(const dni_t& n);
        bool operator>=(const dni_t& n);
        
        int get_cont(void);
        void iniciar_contador(void);
        int get_colision(void);
        void suma_colision(void);
        
        friend ostream& operator<<(ostream& os, dni_t dni_);
        
};