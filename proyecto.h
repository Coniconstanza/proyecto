#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fechaNacimiento{  //fecha de nacimiento hecha struct
	int dia;
	int mes;
	int anio;
}FechaNacimiento;

typedef struct datosTrabajador{		//datos de un trabajador
	int rut[8];
	char codigoVerificador[1];
	char nombre[50];
	char aPaterno[25];
	char aMaterno[25];
	FechaNacimiento* fecha;
	char contrato[10];
	int salarioHora;
	int cargas;
}DatosTrabajador;

typedef struct trabajador{		//struct del trabajador
	int key;
	DatosTrabajador* trabajador;
	struct trabajador* next;
	struct trabajador* prev;
}Trabajador;

typedef struct dpto{ 	//struct del departamento
	int size;
	int tableSize;
	Trabajador** table;
	int N_Dpto;
	char nombreDpto[100];
	struct dpto* next;
	struct dpto* prev;
}Dpto;

typedef struct lista{  	//lista de departamentos
	int size;
	Dpto* head;
	Dpto* tail;
}Lista;

Lista* createLista();
Dpto* createDpto(char element[], Dpto* next, Dpto* prev, int listSize);
DatosTrabajador* createDT();
void addDpto(Lista* list, char element[]);
void addDptoAt(Lista* list, char element[], unsigned int pos);
Dpto* getDptoAt(Lista* list, unsigned int pos);
void ht_put(Dpto* ht, int key, DatosTrabajador* value);
int hashDiv(int key, int tableSize);
void addTrabajador(Dpto* ht)
