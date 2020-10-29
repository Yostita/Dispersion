/*----------------------------------*/
/*  Practica 8. José Luis Bellosta  */
/*----------------------------------*/

#pragma once
#include "Agenda.h"
#include "assertdomjudge.h"

Agenda::Agenda(int capacidad) {
	assertdomjudge(capacidad>0);

	this->capacidad = capacidad;
	nombres = new string[capacidad];
	ocupados = (bool*)malloc(capacidad * sizeof(bool));
	telefonos = (long*)malloc(capacidad * sizeof(long));

	for (int i = 0; i < capacidad; i++) {
		ocupados[i] = false;
	}
}

int Agenda::obtenerPosicion(long telefono) {
	return (telefono%capacidad);
}

bool Agenda::existeContacto(long telefono) {
	int i = obtenerPosicion(telefono);

	if (telefonos[i] == telefono && ocupados[i]) {
		return (true);
	}
	else
		return (false);
}

string Agenda::getContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));

	int i = obtenerPosicion(telefono);

	return (nombres[i]);
}

void Agenda::introducirContacto(long telefono, string contacto) {
	int i = obtenerPosicion(telefono);

	assertdomjudge(!ocupados[i]);

	nombres[i] = contacto;
	ocupados[i] = true;
	telefonos[i] = telefono;
}

void Agenda::eliminarContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));

	int i = obtenerPosicion(telefono);
	ocupados[i] = false;
}

void Agenda::imprimir() {
	for (int i = 0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

Agenda::~Agenda() {
	delete[] nombres;
	free(ocupados);
	free(telefonos);
}