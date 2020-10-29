/*----------------------------------*/
/*  Practica 8. José Luis Bellosta  */
/*----------------------------------*/
#pragma once
#include "ListaEnlazada.h"
#include "assertdomjudge.h"

Nodo * ListaEnlazada::getNodo(int posicion) {
	assertdomjudge(n > 0);
	assertdomjudge(posicion >= 0 && posicion <= n - 1);

	Nodo *resultado = NULL;

	if (posicion == posicionUltimoNodoAccedido && posicionUltimoNodoAccedido != -1) {
		resultado = punteroUltimoNodoAccedido;
	}
	else if (posicion == posicionUltimoNodoAccedido + 1 && posicionUltimoNodoAccedido != -1) {
		resultado = punteroUltimoNodoAccedido->siguienteNodo;
	}
		else if (posicion == posicionUltimoNodoAccedido - 1 && posicionUltimoNodoAccedido != -1) {
			resultado = punteroUltimoNodoAccedido->anteriorNodo;
		}
			else if (posicion <= n / 2) {
				resultado = lista;
				for (int i = 0; i < posicion; i++) {
					resultado = resultado->siguienteNodo;
				}
			}
				else {
					resultado = lista->anteriorNodo; 
					for (int i = n - 1; i > posicion; i--) {
						resultado = resultado->anteriorNodo;
					}
				}

	posicionUltimoNodoAccedido = posicion;
	punteroUltimoNodoAccedido = resultado;

	return (resultado);
}

ListaEnlazada::ListaEnlazada() {
	lista = NULL;
	n = 0;
	posicionUltimoNodoAccedido = -1;
	punteroUltimoNodoAccedido = NULL;
}

Contacto ListaEnlazada::getValor(int posicion) {
	assertdomjudge(n > 0);
	assertdomjudge(posicion >= 0 && posicion <= n - 1);

	Nodo *nodo = getNodo(posicion);
	return (nodo->elemento);
}

void ListaEnlazada::setValor(int posicion, Contacto nuevoValor) {
	assertdomjudge(n > 0);
	assertdomjudge(posicion >= 0 && posicion <= n - 1);

	getNodo(posicion)->elemento = nuevoValor;
}

int ListaEnlazada::getN() {
	return (n);
}

void ListaEnlazada::insertar(int posicion, Contacto nuevoValor) {
	assertdomjudge(posicion <= n && posicion >= 0);

	Nodo *nodo = new Nodo;
	nodo->elemento = nuevoValor;

	if (n == 0) {
		nodo->siguienteNodo = nodo;
		nodo->anteriorNodo = nodo;
	}

	else {
		Nodo *nodoSiguiente; 

		if (posicion == n) {
			nodoSiguiente = lista;
		}
		else {
			nodoSiguiente = getNodo(posicion);
		}
		Nodo *nodoAnterior = nodoSiguiente->anteriorNodo;

		nodo->anteriorNodo = nodoAnterior;
		nodo->siguienteNodo = nodoSiguiente;
		nodoSiguiente->anteriorNodo = nodo;
		nodoAnterior->siguienteNodo = nodo;
	}


	if (posicion == 0) {
		lista = nodo;
	}

	posicionUltimoNodoAccedido = -1; 
	punteroUltimoNodoAccedido = NULL; 
	n++;
}

void ListaEnlazada::eliminar(int posicion) {
	assertdomjudge(n > 0);
	assertdomjudge(posicion >= 0 && posicion <= n - 1);

	Nodo *nodoParaEliminar = getNodo(posicion);

	if (n == 1) {
		lista = NULL;
	}else {
		Nodo *nodoAnterior = nodoParaEliminar->anteriorNodo;
		Nodo *nodoSiguiente = nodoParaEliminar->siguienteNodo;

		nodoAnterior->siguienteNodo = nodoSiguiente;
		nodoSiguiente->anteriorNodo = nodoAnterior;

		if (posicion == 0) {
			lista = nodoSiguiente;
		}
	}

	posicionUltimoNodoAccedido = -1;
	punteroUltimoNodoAccedido = NULL; 

	delete(nodoParaEliminar);

	n--;
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar) {
	assertdomjudge(listaAConcatenar != NULL);

	int capacidad = listaAConcatenar->getN();

	for (int i = 0; i < capacidad; i++) {
		Contacto contacto = listaAConcatenar->getValor(i);
		insertar(n, contacto);
	}
}

int ListaEnlazada::buscar(Contacto elementoABuscar) {
	int posicion = 0;
	bool encontrado = false;

	while (!encontrado && posicion < n) {
		if (getValor(posicion).telefono == elementoABuscar.telefono) {
			encontrado = true;
		}
		posicion++;
	}

	if (encontrado) {
		return (posicion - 1);
	}
	else {
		return (-1);
	}
}

ListaEnlazada::~ListaEnlazada() {
	while (n > 0) {
		eliminar(0);
	}
}