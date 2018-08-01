#include "proyecto.h"

Lista* createLista() {										//crea una lista por defecto siempre debera estar creada o sino no habra nada :l
	Lista* list = (Lista*)malloc(sizeof(Lista));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

Dpto* createDpto(char element[100], Dpto* next, Dpto* prev, int listSize) {		//crea un departamento
	Dpto* nn = (Dpto*)malloc(sizeof(Dpto));
	nn->size = 0;
	nn->tableSize = 13;
	
	nn->table = (Trabajador**) malloc(sizeof(Trabajador*) * nn->tableSize);
	
	int i;
	for (i = 0; i < nn->tableSize; i++) {
		nn->table[i] = NULL;
	}
	
	nn->N_Dpto = listSize+1;
	strncpy(nn->nombreDpto, element, sizeof(nn->nombreDpto));
	nn->next = next;
	nn->prev = prev;

	return nn;
}

DatosTrabajador* createDT(){				//Crea los datos de un trabajador
	DatosTrabajador* datos = (DatosTrabajador*)malloc(sizeof(DatosTrabajador));
	//mi idea es poner algunos gets o cosas asi pero que todos los datos se rellenen aqui y lo devuelva como el value de la tabla de hash.
	return datos;
}

void addTrabajador(Dpto* ht){		//Dado un departamento, preguntara los datos del trabajador y los agregara a tal departamento.
	DatosTrabajador* datos = createDT();
	ht_put(ht, datos->rut, datos)
}

void addDpto(Lista* list, char element[100]) {				//añade un departamento al final de la lista
	addDptoAt(list, element, list->size);
}

void addDptoAt(Lista* list, char element[100], unsigned int pos) {		//añade un departamento en algún lugar de la lista
	Dpto* nn;
	Dpto* cn;
	Dpto* tmpl;

	if (pos >= 0 && pos <= list->size) {
		nn = createDpto(element, NULL, NULL, list->size);

		if (list->size == 0) {					/* The list is empty*/
			list->head = nn;
			list->tail = nn;
		}
		else {									/* The list is not empty */
			if (pos == list->size) { 			/* If pos points to the list tail */
				tmpl = list->tail;
				tmpl->next = nn;
				nn->prev = tmpl;
				list->tail = nn;
			}
			else {
				cn = getDptoAt(list, pos);	/* At this point, pos is a valid position */

				if (pos == 0) { 				/* If pos points to the list head */
					cn->prev = nn;
					nn->next = cn;
					list->head = cn;
				}
				else { 							/* Adds to intermediate position */
					(cn->prev)->next = nn;
					nn->prev = cn->prev;
					cn->prev = nn;
					nn->next = cn;
				}
			}
		}
		list->size++;
	}
	else {
		fprintf(stderr, "Invalid list index %d\n", pos);
		exit(EXIT_FAILURE);
	}

}

Dpto* getDptoAt(Lista* list, unsigned int pos){   	//obtiene un departamento en una posición dada de la lista
	Dpto* tmp;
	int i;
	if (pos >= 0 && pos < list->size) {
		tmp = list->head;

		for (i = 1; i <= pos; i++) {
			tmp = tmp->next;
		}
		return tmp;
	}
	else {
		fprintf(stderr, "Invalid list index %d\n", pos);
		exit(EXIT_FAILURE);
	}
}

void ht_put(Dpto* ht, int key, DatosTrabajador* value) {    	//añade los datos a un trabajador
	int index = hashDiv(key, ht->tableSize);
	Trabajador* entry = ht->table[index];
	DatosTrabajador* oldValue;
	bool found = false;

	while (entry!= NULL && !found) {
		/* Checks if the key is already in the hashtable*/
		if (entry->key == key){
			oldValue = value;
			entry->trabajador = value;
			found = true;
		}
		entry = entry->next;
	}


	if (!found) {
		Trabajador* en = (Trabajador*)malloc(sizeof(Trabajador));
		en->key = key;
		en->trabajador = value;

		/* Updating pointers to put the new <key, value> as first entry in the bucket...*/
		en->prev = NULL;
		en->next = ht->table[index];

		if (ht->table[index] == NULL) { /*First element in the bucket...*/
			ht->table[index] = en;
		}
		else {
			ht->table[index]->prev = en;
			ht->table[index] = en;
		}
		
		ht->size++;
	}
}

int hashDiv(int key, int tableSize) {		//index de la tabla de hash
	return key % tableSize;
}

int salarioHora(int i){                                         // i= al valor pagado por hora trabajada
	int sueldo=160*i, liqui=0;                           // 8 horas diarias del lunes a viernes
	liqui=((sueldo)-(sueldo*0,07)-(sueldo*0,1)+(sueldo*0,25)+30000);	
	return liqui;
	
}
