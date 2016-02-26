/*
 * Estructura caja que sirve para contener una variable de tipo dado por plantilla y dos punteros de tipo
 * caja siguiente y anterior para ser utilizados en una lista doblemente ligada.
 * Autor: Francisco Enrique Córdova González
 * Última actualización: 19/Feb/2016
 */
#pragma once //Directiva al compilador para que sea anexada una vez
#include "arco.h"

template <typename T> struct caja_nodo {
  T id;
  arco<T> *saliente;
  arco<T> *entrante;
  caja_nodo<T> *siguiente;
};
