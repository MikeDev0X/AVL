#include <string>
using namespace std;
#pragma once

class Nodo{
  private:
    //atributos
    int dato;
    int FE;
    Nodo *izq, *der;
  public:
    Nodo(int);

    //getters
    Nodo* getIzq();
    Nodo* getDer();
    int getDato();
    int getFE();
    //setters
    void setIzq(Nodo*);
    void setDer(Nodo*);
    void setDato(int);
    void setFE(int);
};

Nodo::Nodo(int _dato){//constructor con dato
  dato = _dato;
  izq = NULL;
  der = NULL;
  FE = 0;
}
//getters
Nodo* Nodo::getIzq(){//Obtener dirección de nodo izquierdo
  return izq;
}
Nodo* Nodo::getDer(){//obtener dirección de nodo derecho
  return der;
}
int Nodo::getDato(){//obtener dato del nodo
  return dato;
}
//setters
void Nodo::setIzq(Nodo* _izq){//cambiar el nodo izquierdo
  izq = _izq;
}
void Nodo::setDer(Nodo* _der){//cambiar el nodo derecho
  der = _der;
}
void Nodo::setDato(int _dato){//cambiar el dato del nodo
  dato = _dato;
}
int Nodo::getFE(){
  return FE;
}
void Nodo::setFE(int _FE){
  FE = _FE;
}