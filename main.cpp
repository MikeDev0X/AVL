#include <iostream>
#include "Arbol.h"
#include "Nodo.h"

using namespace std;

int main() {
  Arbol a1;
  //a1.setRaiz(a1.insertaAVL(a1.getRaiz(),false,5));
  a1.insertaAVL(a1.getRaiz(),false,5);
  //a1.insertaAVL(a1.getRaiz(),false,7);
  //a1.insertaAVL(a1.getRaiz(),false,4);
  a1.preorder(a1.getRaiz());

}