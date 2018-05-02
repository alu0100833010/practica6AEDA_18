#pragma once
#include <iostream>
#include <cmath>
#include <queue>
#include "../include/dni_t.hpp"
#include "../include/nodo_t.hpp"
#include "../include/colision_t.hpp"

template <class clave>
class ABB_t {
    private:
        nodoBB_t<clave>* raiz_;
    
    public:
        // PARTE ESTADISTICA //
        int cont_max;
        int cont_min;
        int suma;
        float media;
  
        // OPERACIONES INICIALES
        ABB_t();
        ~ABB_t();
    
        void podar(nodoBB_t<clave>*& nodo);
        
        bool EsVacio(nodoBB_t<clave>* nodo) { 
            return nodo == NULL;
        }
        
        bool EsHoja(nodoBB_t<clave>* nodo) { 
            return !nodo->get_nodo_dch() && !nodo->get_nodo_izq();
        }
        
        void mostrar();
    
        // OPERACIONES //
        
        void insertar(clave x) { 
            insertar_rama(raiz_, x);
        }
        
        void insertar_rama(nodoBB_t<clave>*& nodo, clave x);
        
        void eliminar(clave x){ 
            eliminar_rama(raiz_,x);
        }
        
        void eliminar_rama(nodoBB_t<clave>*& nodo, clave x);
        
        void sustituye(nodoBB_t<clave>*& eliminado, nodoBB_t<clave>*& sust);
        
        nodoBB_t<clave>* buscar(clave x) { 
            return buscar_rama(raiz_, x);
        }
        nodoBB_t<clave>* buscar_rama(nodoBB_t<clave>* nodo, clave x);
      
        // PARTE ESTADISTICA //
        void inicializar_contadores();
        
        float resultado(int num_prueba);
        
        void podar_arbol() { 
            podar(raiz_);
        }
    
    
};

template<class clave>
ABB_t<clave>::ABB_t():
    raiz_(NULL)
    {}

template<class clave>
ABB_t<clave>::~ABB_t() {
    podar(raiz_);
}

template<class clave>
void ABB_t<clave>::podar(nodoBB_t<clave>* &nodo) {
    if(nodo == NULL) return;
    podar(nodo->get_nodo_izq());
    podar(nodo->get_nodo_dch());
    delete nodo;
    nodo = NULL;
}

template <class clave>
void ABB_t<clave>::inicializar_contadores() {
    cont_max = 0;
    cont_min = 9999;
    suma = 0;
    media = 0;
}

template <class clave>
float ABB_t<clave>::resultado(int num_prueba) {
    media = suma/num_prueba;
    return media;
}

template<class clave>
void ABB_t<clave>::insertar_rama(nodoBB_t<clave>*& nodo, clave x) {
    if(nodo == NULL){
        nodo = new nodoBB_t<clave>(x, NULL, NULL);
        
    } else if(x < nodo->get_nodo_valor()) {
        insertar_rama(nodo->get_nodo_izq(), x);
        
    } else if (x > nodo->get_nodo_valor()) {
        insertar_rama(nodo->get_nodo_dch(), x);
        
    } else if (x == nodo->get_nodo_valor()) {
        nodo->suma_colision();
    }
}

template<class clave>
void ABB_t<clave>::eliminar_rama(nodoBB_t<clave>*& nodo, clave x) {
    if(nodo == NULL)  return;
    if(x < nodo->get_nodo_valor()){
        eliminar_rama(nodo->get_nodo_izq(), x);
        
    } else if(x > nodo->get_nodo_valor()) {
        eliminar_rama(nodo->get_nodo_dch(), x);
        
    } else {
        nodoBB_t<clave>* eliminado = nodo;
        
        if (nodo->get_nodo_dch() == NULL){
            nodo = nodo->get_nodo_izq();
            
        } else if(nodo->get_nodo_izq() == NULL){
           nodo = nodo->get_nodo_dch();
            
        } else{
            sustituye(eliminado, nodo->get_nodo_izq());
        }
        delete eliminado;
    }
}

template<class clave>
void ABB_t<clave>::sustituye(nodoBB_t<clave>*& eliminado, nodoBB_t<clave>*& sust) {
    if (sust->get_nodo_dch() != NULL) {
       // cout << "SUSTITUIR 1 --> " << sust -> get_nodo_valor() << endl;
       sustituye(eliminado, sust->get_nodo_dch());

    } else {
        //cout << "SUSTITUIR 2 --> " << sust -> get_nodo_valor() << endl;
       eliminado-> get_nodo_valor() = sust -> get_nodo_valor();
       eliminado = sust;
       sust = sust-> get_nodo_izq();
   } 
}

template<class clave>
nodoBB_t<clave>* ABB_t<clave>::buscar_rama(nodoBB_t<clave>* nodo, clave x) {
    // Si x es menor o igual que la raiz, la búsqueda prosigue de manera
    // recursiva por el subárbol izquierdo.
    // Si x es mayor que la raiz, la búsqueda prosigue de manera
    // recursiva por el subárbol derecho.
    // La búsqueda se termina cuando se encuentra el elemento o
    // cuando ya no quedan más nodos por visitar.
    if(nodo == NULL) return NULL;
    if(x == nodo->get_nodo_valor()) return nodo;
    if(x < nodo-> get_nodo_valor()) return buscar_rama(nodo->get_nodo_izq(), x);
    return buscar_rama(nodo-> get_nodo_dch(),x);
}

template<class clave>
void ABB_t<clave>::mostrar() {
    queue<nodoBB_t<clave>*> cola;
    nodoBB_t<clave>* nodo_cola;
    nodoBB_t<clave>* aux = new nodoBB_t<clave>();

    int i=0;
    int cont=0;
    int meter_cola=0;
    
    nodo_cola = raiz_;
    cola.push(nodo_cola);
    clave aux2;
    
    cout << "Nivel 0:" << endl;
    while(!cola.empty()){
        
        // Va mostrando los niveles
        if(cont == pow(2,i)){ // 2 elevado a i
            cout << endl;
            i++;
            cont=0;
            cout << "Nivel" << i << ":" << endl;
        }
        
        nodo_cola = cola.front();
        cola.pop();
        cont ++;
        if (nodo_cola != NULL) {
            aux -> set_nodo_valor(nodo_cola-> get_nodo_valor());
            aux2 = aux -> get_nodo_valor();
            cout << "[" << aux2.get_dni() << "]";
        
        cola.push(nodo_cola->get_nodo_izq());
        cola.push(nodo_cola->get_nodo_dch());
        
        } else{
            cout << "[.]";
        }
        
    }
  cout << endl;
}