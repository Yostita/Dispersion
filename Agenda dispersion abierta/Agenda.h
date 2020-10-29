/*----------------------------------*/
/*  Practica 8. José Luis Bellosta  */
/*----------------------------------*/

#pragma once
#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"
#include "Contacto.h"
#include <iostream>
#include <string>
using namespace std;

class Agenda
{
	int capacidad;
	int n;
	ListaEnlazada *tabla;

public:
	//Constructor por parametros.
	//Precondicion : cantidad mayor que 0
	//Complejidad Temporal : O(cantidad)
	//Complejidad Espacial : O(cantidad)
	Agenda(int cantidad);

	//Devuelve la posicion del contacto en base a su telefono
	//Precondicion : ninguna
	//Complejidad Temporal : O(1)
	//Complejidad Espacial : O(1)
	int obtenerPosicion(long telefono);

	//Comprueba si ya existe un contacto con ese telefono
	//Precondicion : ninguna
	//Complejidad Temporal : O(1), en el pero caso 0(n)
	//Complejidad Espacial : O(1)
	bool existeContacto(long telefono);

	//Devuelve el nombre asociado a un telefono
	//Precondicion : que exista el contacto
	//Complejidad Temporal : O(1), en el pero caso 0(n)
	//Complejidad Espacial : O(1)
	string getContacto(long telefono);

	//Añade un contacto a la tabla
	//Precondicion : que no exista ya el contacto
	//Complejidad Temporal : O(1)
	//Complejidad Espacial : O(1)
	void introducirContacto(long telefono, string contacto);

	//Elimina un contacto de la tabla
	//Precondicion : que exista el contacto
	//Complejidad Temporal : O(1), en el pero caso 0(n)
	//Complejidad Espacial : O(1)
	void eliminarContacto(long telefono);

	//Imprime la tabla
	//Precondicion : ninguna
	//Complejidad Temporal : O(cantidad), en el peor O(cantidad+n)
	//Complejidad Espacial : O(1)
	void imprimir();

	//Destructor
	//Precondicion : ninguna
	//Complejidad Temporal : O(cantidad), en el peor O(cantidad+n)
	//Complejidad Espacial : O(1)
	~Agenda();
};