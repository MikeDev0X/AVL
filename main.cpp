#include <iostream>
#include "Arbol.h"
#include "Nodo.h"

using namespace std;

int main() {
  Arbol a1;
  //a1.setRaiz(new Nodo(5));
  a1.setRaiz(a1.insertaAVL(a1.getRaiz(),false,14));
  a1.setRaiz(a1.insertaAVL(a1.getRaiz(),false,5));
  a1.setRaiz(a1.insertaAVL(a1.getRaiz(),false,34));
  a1.setRaiz(a1.insertaAVL(a1.getRaiz(),false,3));
  a1.setRaiz(a1.insertaAVL(a1.getRaiz(),false,7));
  a1.setRaiz(a1.insertaAVL(a1.getRaiz(),false,9));
  a1.preorder(a1.getRaiz());
  //cout<<a1.getRaiz()->getDato();
  //a1.inorder(a1.getRaiz());

}