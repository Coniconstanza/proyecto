#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "proyecto.h"

int main(){
	
	int menu,n;
	char fin;
    do {
        printf("\n\t Empresa Constructura'La Choza de Concreto'\n");
        printf("\n1. Ingresar datos del trabajador:\n");
        printf("\n2. Modificar datos del trabajador:\n");
        printf("\n3. Eliminar datos del trabajador:\n");
        printf("\n4. Consultar datos del trabajador:\n");
        printf("\n5. Generar sueldo:\n");
        printf("\n6. Ingrese un departamento:\n");
        printf("\n7. Elimine un departamento:\n");
        printf("\n8. Numero total de trabajadores de la empresa:\n");
        printf("\n9. Numero total de trabajadores por departamento:\n");
        printf("\n Pulsa 0 para salir del programa.\n");
        printf("\n\n Selecciona una opcion: ");
        scanf("%d",&menu);
        
        }while (getchar() != '\n');
 
        switch (menu) {
            case 1:
              //  agregar_datos();
 
                break;
            case 2:
              //  modificar_datos();
                break;
 
            case 3:
              //  remove_datos();
                break;
 
            case 4:
              //  mostrar_datos();
                break;
 
            case 5:
                printf("Ingrese horas trabajadas:");
                scanf("%d",&n);
              //  salarioHora(n);
                break;
 
            case 6:
               // createDpto();
                break;
 
            case 7:
              //  remove_Dpto();
                break;
 
            case 8:
              //  size_tabla();
                break;
 
            case 9:
               // size_Dpto();
                break;
            case 0:
                printf("\nQuieres salir del programa.");
                printf("\n¿Estas seguro? s/n...");
                scanf("%c", &fin);
                if (fin == 's')
				return;
                break;
 
            default:
                printf("\n\nNo ha introducido un numero valido.");
                break;
        }
        while (getchar() != '\n');
        printf("\nPulse una tecla para continuar: ");
        getchar();

     system("pause");
     return 0;

}
