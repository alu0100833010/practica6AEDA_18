#pragma once
#include <iostream>
#include "../include/dni_t.hpp"
#include "../include/colision_t.hpp"
using namespace std;

template <class clave>
class nodoBB_t {
    private:
    
    public:
    
        nodoBB_t<clave>* dch; 
        nodoBB_t<clave>* izq; 
        colision_t colision;
        clave valor;
        int nivel;
    
        nodoBB_t(void);
        nodoBB_t(clave dat, nodoBB_t<clave>* izq_=NULL, nodoBB_t<clave>* dch_=NULL):
            valor(dat),
            dch(dch_),
            izq(izq_),
            nivel(0)
            {}
            
        ~nodoBB_t();

        void set_nodo_dch(nodoBB_t<clave>*& dch_) { 
            dch = dch_; 
        }
        nodoBB_t<clave>*& get_nodo_dch(void) { 
            return dch; 
        }
        void set_nodo_izq(nodoBB_t<clave>*& izq_) { 
            izq = izq_; 
        }
        nodoBB_t<clave>*& get_nodo_izq(void) { 
            return izq; 
        }
        void set_colision(nodoBB_t<clave>* colision_) {
            colision = colision_;
        }
        nodoBB_t<clave>*& get_colision(void) {
            return colision;
        }
        colision_t suma_colision(void) {
            colision.numero_colision();
        }
        clave& get_nodo_valor(void) { 
            return valor;
        } 
        void set_nodo_valor(clave valor_) { 
            valor = valor_; 
        }
        int get_nivel(void) { 
            return nivel;
        }
        void set_nivel(int nivel_) { 
            nivel = nivel_;
        }
};

template <class clave>
nodoBB_t<clave>::nodoBB_t():
    dch(NULL),
    izq(NULL),
    valor() {}

template <class clave>
nodoBB_t<clave>::~nodoBB_t() {
    delete dch;
    delete izq;
    dch = NULL;
    izq = NULL;
}

