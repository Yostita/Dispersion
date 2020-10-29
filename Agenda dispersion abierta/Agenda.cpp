/*----------------------------------*/
/*  Practica 8. José Luis Bellosta  */
/*----------------------------------*/
#include "Agenda.h"
#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
#include "impresionListasEnlazadas.h" // Para el m�todo imprimir de la tabla hash

Agenda::Agenda(int capacidad) {
	assertdomjudge(capacidad>0);

	this->capacidad = capacidad;
	n = 0;
	tabla = new ListaEnlazada[capacidad];
}

int Agenda::obtenerPosicion(long telefono) {
	return (telefono%capacidad);
}

bool Agenda::existeContacto(long telefono) {
	Contacto contacto;
	contacto.telefono = telefono;

	int posicion = obtenerPosicion(telefono);

	if (tabla[posicion].buscar(contacto) != -1) {
		return true;
	}
	
	return (false);
}

string Agenda::getContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));

	Contacto contacto;
	contacto.telefono = telefono;

	int posicion = obtenerPosicion(telefono);
	int posicionLista = tabla[posicion].buscar(contacto);

	if (posicionLista != -1) {
		return (tabla[posicion].getValor(posicionLista).nombre);
	}
}

void Agenda::introducirContacto(long telefono, string contacto) {
	assertdomjudge(!existeContacto(telefono));

	Contacto contactos;
	contactos.telefono = telefono;
	contactos.nombre = contacto;

	int i = obtenerPosicion(telefono);

	tabla[i].insertar(0,contactos);
	n++;
}

void Agenda::eliminarContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));

	Contacto contacto;
	contacto.telefono = telefono;

	int posicion = obtenerPosicion(telefono);
	int posicionLista = tabla[posicion].buscar(contacto);

	if (posicionLista != -1) {
		tabla[posicion].eliminar(posicionLista);
		n--;
	}
}

void Agenda::imprimir() {
	for (int i = 0; i<capacidad; i++) {
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&tabla[i]);
	}
}

Agenda::~Agenda() {
	delete[] tabla;
}