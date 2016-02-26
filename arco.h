#pragma once
#include <iostream>
#include "caja.h"

enum DONDE { INICIO,MITAD };

template <typename T> class arco {
private:
  DONDE donde;
  caja<T> *principio;
  caja<T> *anterior;
  bool encontrado;
  void buscar(T);
public:
  arco(): donde(INICIO), principio(NULL), anterior(NULL), encontrado(false){}
  ~arco();
  void agregar(T);
  void pintar();
  caja<T>* lugar_agregado() {return principio;}
};
template <typename T> arco<T>::~arco() {
  caja<T> *p;
  while (principio) {
    p = principio;
    principio = p->siguiente;
    delete p;
  }
  anterior = NULL;
  encontrado = false;
  donde = INICIO;
}
template <typename T> void arco<T>::buscar(T var) {
  if (!principio) {
    donde = INICIO;
    principio = NULL;
    anterior = NULL;
    encontrado = false;
    return;
  }
  caja<T> *p = principio;
  while (p) {
    if (p->var < var) {
      anterior = p;
      p = p->siguiente;
    } else if (p->var == var){
      encontrado = true;
      return;
    } else {
      encontrado = false;
      if (principio == p) donde = INICIO;
      else donde = MITAD;
      return;
    }
  }
  donde = MITAD;
  encontrado = false;
}
template <typename T> void arco<T>::agregar(T var) {
  buscar(var);
  if (encontrado) return;
  caja<T> *p = new caja<T>;
  p->var = var;
  if (donde == MITAD) {
    p->siguiente = anterior->siguiente;
    anterior->siguiente = p;
  } else {
    p->siguiente = principio;
    principio = p;
  }
}
template <typename T> void arco<T>::pintar() {
  std::cout << "[ ";
  caja<T> *p = principio;
  while (p) {
    std::cout << p->var << ",";
    p = p->siguiente;
  }
  std::cout << "\b ]" << std::endl;
}
