/*----------------------------------*/
/*  Practica 8. José Luis Bellosta  */
/*----------------------------------*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Agenda
{
	int capacidad;
	string *nombres;
	long * telefonos;
	bool *ocupados;

public:
	//Constructor por parametros.
	//Precondicion : cantidad mayor que 0
	//Complejidad Temporal : O(cantidad)
	//Complejidad Espacial : O(cantidad)
	Agenda(int cantidad);

	//Obtiene la posicion del telefono en la tabla.
	//Precondicion : ninguna.
	//Complejidad Temporal : O(1)
	//Complejidad Espacial : O(1)
	int obtenerPosicion(long telefono);

	//Nos dice si existe el contacto en la tabla
	//Precondicion :  ninguna.
	//Complejidad Temporal : O(1)
	//Complejidad Espacial : O(1)
	bool existeContacto(long telefono);

	//Devuelve el nombre asociado al telefono en la tabla.
	//Precondicion : que exista el contacto
	//Complejidad Temporal : O(1)
	//Complejidad Espacial : O(1)
	string getContacto(long telefono);
	
	//Añade un contacto a la tabla
	//Precondicion : que la lista no este llena y que no exista ya el contacto
	//Complejidad Temporal : O(1)
	//Complejidad Espacial : O(1)
	void introducirContacto(long telefono, string contacto);

	//Elimina un contacto de la tabla
	//Precondicion : que exista el contacto
	//Complejidad Temporal : O(1)
	//Complejidad Espacial : O(1)
	void eliminarContacto(long telefono);

	//Imprimie la tabla.
	//Precondicion :  ninguna.
	//Complejidad Espacial : O(cantidad)
	//Complejidad Espacial : O(1)
	void imprimir();

	//Destructor.
	//Precondicion : ninguna.
	//Complejidad Temporal : O(1)
	//Complejidad Espacial : O(1)
	~Agenda();
};