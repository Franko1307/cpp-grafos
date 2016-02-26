#pragma once
#include "caja_nodo.h"
#include "nodo.h"
#include "arco.h"

template <typename T> class grafo {
private:
  nodo<T> *A;
public:
  grafo();
  ~grafo();
  void agregar(T,T);
  void pintar(){A->pintar();}
};
template <typename T> grafo<T>::grafo() {
  A = new nodo<T>;
}
template <typename T> grafo<T>::~grafo() {
  delete A;
}
template <typename T> void grafo<T>::agregar(T var, T var_2) {
  caja_nodo<T> *p;
  A->agregar(var);
  p = A->lugar_agregado();
  p->saliente->agregar(var_2);
  A->agregar(var_2);
  p = A->lugar_agregado();
  p->entrante->agregar(var);
}
