#pragma once
#include "arco.h"
#include "caja_nodo.h"

template <typename T> class nodo {
private:
  DONDE donde;
  bool encontrado;
  caja_nodo<T> *principio;
  caja_nodo<T> *_lugar_agregado;
  caja_nodo<T> *anterior;
  void buscar(T);
public:
  nodo(): donde(INICIO), encontrado(false), anterior(NULL) , principio(NULL){}
  ~nodo();
  void agregar(T);
  void pintar();
  caja_nodo<T>* lugar_agregado(){return _lugar_agregado;}
};
template <typename T> nodo<T>::~nodo() {
  caja_nodo<T> *p;
  while (principio) {
    p = principio;
    principio = p->siguiente;
    delete p->entrante;
    delete p->saliente;
    delete p;
  }
  encontrado = false;
  anterior = NULL;
  donde = INICIO;
}
template <typename T> void nodo<T>::buscar(T id) {
  if (!principio) {
    donde = INICIO;
    anterior = NULL;
    encontrado = false;
    return;
  }
  caja_nodo<T> *p = principio;
  while (p) {
    if (p->id < id) {
      anterior = p;
      p = p->siguiente;
    } else if (p->id == id) {
      encontrado = true;
      _lugar_agregado = p;
      return;
    } else {
      encontrado = false;
      if (principio == p) donde = INICIO;
      else donde = MITAD;
      return;
    }
  }
  encontrado = false;
  donde = MITAD;
}
template <typename T> void nodo<T>::agregar(T id) {
  buscar(id);
  if (encontrado) return;
  caja_nodo<T> *p = new caja_nodo<T>;
  p->id = id;
  p->saliente = new arco<T>;
  p->entrante = new arco<T>;
  if (donde == MITAD) {
    p->siguiente = anterior->siguiente;
    anterior->siguiente = p;
  } else {
    p->siguiente = principio;
    principio = p;
  }
  _lugar_agregado = p;
}
template <typename T> void nodo<T>::pintar() {
  caja_nodo<T> *p = principio;
  while (p) {
    std::cout << "Nodo: " << p->id << std::endl;
    std::cout << "Entrantes: ";
    p->entrante->pintar();
    std::cout << "Salientes: ";
    p->saliente->pintar();
    std::cout << std::endl;
    p = p->siguiente;
  }
}
