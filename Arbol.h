#pragma once
#include <iostream>
#include "Nodo.h"
#include <string>
using namespace std;

class Arbol{
  public:
  //constructor y destructor
  Arbol();
  ~Arbol();
  //getters
  Nodo* getRaiz();
  //setters
  void setRaiz(Nodo*);
  Nodo* insertaAVL(Nodo*, bool, int);//insertar Nodo
  //printers
  void preorder( Nodo*);
  void inorder(Nodo *);
  bool empty();


  private:
  Nodo* raiz;//atributo raíz
};

Arbol::Arbol(){//constructor por omisión
  raiz=NULL;
}

Arbol::~Arbol(){}//destructor

Nodo * Arbol::getRaiz(){//obtener la raíz
  return raiz;
}

void  Arbol::setRaiz(Nodo* _raiz){//obtener la raíz
  raiz = _raiz;
}

Nodo* Arbol::insertaAVL(Nodo* nodo, bool BO ,int num){
  if(nodo!=NULL){
    if( num < nodo->getDato()){//1.1
      nodo->setIzq(insertaAVL(nodo->getIzq(),BO,num));
      if(BO){//1.1.1
        if(nodo->getFE() == 1){//1.1.1.A
          nodo->setFE(0);        
          BO=false;
        }
        else if(nodo->getFE() == 0){
          nodo->setFE(-1);
        }
        else if(nodo->getFE() == -1){
          Nodo *nodo1=nodo->getIzq();
          if(nodo1->getFE()<=0){//1.1.1.B
            //rotacion II
            nodo->setIzq(nodo1->getDer());
            nodo1->setDer(nodo);
            nodo->setFE(0);
            nodo=nodo1;
            //fin rotacion II
          }
          else{
            //rotacion ID
            Nodo *nodo2=nodo1->getDer();
            nodo->setIzq(nodo2->getDer());
            nodo2->setDer(nodo);
            nodo1->setDer(nodo2->getIzq());//////////////////////////////////
            nodo2->setIzq(nodo1);
            if(nodo2->getFE() == -1){//1.1.1.C
              nodo->setFE(1);
            }
            else{
              nodo->setFE(0);//1.1.1.C
            }
            //fin 1.1.1.C
            
            //1.1.2.C
            //1.1.1.D
            if(nodo2->getFE() == 1){
              nodo1->setFE(-1);
            }
            else{
              nodo1->setFE(0);//1.1.1.D
            }
            //fin 1.1.1.D 
            //1.1.2.D 
            nodo=nodo2;
            //fin rotacion ID 
          }
          nodo->setFE(0);
          BO = false;
        }
      }
    }
    else{
      if( num > nodo->getDato() ){
        nodo->setDer(insertaAVL(nodo->getDer(),BO,num));
        if(BO){
          if(nodo->getFE() == -1){
            nodo->setFE(0);
            BO = false;
          }
          else if(nodo->getFE() == 0){
            nodo->setFE(1);
          }
          else if(nodo->getFE() == 1){
            Nodo * nodo1=nodo->getDer();
            if(nodo1->getFE() >= 0){//rotacion DD
              nodo->setDer(nodo1->getIzq());
              nodo1->setIzq(nodo);
              nodo->setFE(0);
              nodo = nodo1;//fin rotacion dd
            }
            else{//rotacion DI
              Nodo *nodo2 = nodo1->getIzq();
              nodo->setDer(nodo2->getIzq());
              nodo2->setIzq(nodo);
              nodo1->setIzq(nodo2->getDer());
              nodo2->setDer(nodo1);
              if(nodo2->getFE() == 1){
                nodo->setFE(-1);
              }
              else{
                nodo->setFE(0);
              }
              if(nodo2->getFE() == -1){
                nodo1->setFE(1);
              }
              else{
                nodo1->setFE(0);
              }
              nodo = nodo2;
            }
            nodo->setFE(0);
            BO = false;
          }
        }
      }
      else{
        cout<<"El nodo ya se encuentra en el árbol"<<endl;
      }
    }
    return nodo;
  } 
  else{
    Nodo *cat = new Nodo(num);
    BO = true;
    return cat;
  }
}

void Arbol::preorder(Nodo* aux){//imprimir datos de los nodos
  if(aux != NULL){
    cout<<aux->getDato()<<endl;
    preorder(aux->getIzq());
    preorder(aux->getDer());
  }
}
void Arbol::inorder(Nodo*aux){//imprimir datos de los nodos en orden
  if(aux != NULL){
    
    preorder(aux->getIzq());
    cout<<aux->getDato()<<endl;
    preorder(aux->getDer());
  }
}
bool Arbol::empty(){
  if(raiz == NULL){
    return true;
  }
  else{
    return false;
  }
}





