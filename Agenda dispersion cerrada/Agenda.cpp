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
	telefonos = (long*)malloc(capacidad * sizeof(long));
	vacias = (bool*)malloc(capacidad * sizeof(bool));
	borradas = (bool*)malloc(capacidad * sizeof(bool));

	for (int i = 0; i < capacidad; i++) {
		borradas[i] = false;
		vacias[i] = true;
	}
}

int Agenda::obtenerPosicion(long telefono) {
	return (telefono%capacidad);
}

int Agenda::buscarContacto(long telefono) {
	int i = obtenerPosicion(telefono);
	int restantes = capacidad;
	bool encontrado = false; 

	while ((!vacias[i] || borradas[i]) && !encontrado && restantes > 0) {
		if (!vacias[i] && telefonos[i] == telefono) {
			encontrado = true;
		}else {
			i = (i + 1) % capacidad; 
			restantes--;
		}
	}

	if (encontrado) {
		return (i);
	}else
		return (-1);
}

int Agenda::buscarHueco(long telefono) {
	assertdomjudge(!isLlena());

	int i = obtenerPosicion(telefono);

	while (!vacias[i]) {
		i = (i + 1) % capacidad;
	}

	return (i);
}

bool Agenda::isLlena() {
	for (int i = 0; i < capacidad; i++) {
		if (vacias[i]) {
			return false;
		}
	}
	return true;
}


bool Agenda::existeContacto(long telefono) {
	int i = buscarContacto(telefono);

	if (telefonos[i] == telefono && !vacias[i]) {
		return (true);
	}
	else
		return (false);
}

string Agenda::getContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));

	int i = buscarContacto(telefono);

	return (nombres[i]);
}

void Agenda::introducirContacto(long telefono, string contacto) {
	assertdomjudge(!isLlena());
	assertdomjudge(!existeContacto(telefono));

	int i = buscarHueco(telefono);
	nombres[i] = contacto;
	telefonos[i] = telefono;
	borradas[i] = false;
	vacias[i] = false;
}

void Agenda::eliminarContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));

	int i = buscarContacto(telefono);
	vacias[i] = true;
	borradas[i] = true;
}

void Agenda::imprimir() {
	for (int i = 0; i<capacidad; i++)
		cout << "Posicion " << i << " | Vacia: " << vacias[i] << " | Borrada: " << borradas[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

Agenda::~Agenda() {
	free(telefonos);
	free(vacias);
	free(borradas);
	delete[] nombres;
}