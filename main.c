#include <stdio.h>
#include <stdlib.h>
#include "proyecto.h"


int main(){
	int i;
	Lista* list = createLista();
	char nd[100];
	printf("Escriba nombre del primer departamento: ");
	scanf("%s", nd);
	addDpto(list, nd);
	
	system("pause");
	return 0;
}
