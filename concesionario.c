#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

int main() {

    int numVehiculos=0;
    bool vehiculos=false;

    printf("*********** CONCESIONARIO ***********");
    
    // Bucle while para conseguir el número de vehiculos entre 1 y 100(incluidos)
    while (vehiculos==false)
    {
        printf("\n\n Ingrese el número de vehiculos que quiere dar de alta: ");
        scanf("%d", &numVehiculos);
        if (numVehiculos < 1)
            printf("\n El número no puede ser menor de 1.");
        else if (numVehiculos > 100)
            printf("\n El número no puede ser mayor de 100.");
        else
            vehiculos=true;
    }

    int aVehiculos[numVehiculos];
    char aMatricula[numVehiculos][25];
    char aMarca[numVehiculos][25];
    int aPrecio[numVehiculos];

    // Asignamos los valores al array de aVehiculos con los valores de numVehiculos
    for (int i = 0; i < numVehiculos; i++) {
        aVehiculos[i]=i+1;
    }
    /* 
        Asignamos el resto de informacion mediante un bucle que sigue funcionando 
        para la cantidad de vehiculos que el usuario escoja 
        Si usamos %s para recibir el valor de la matricula, si ponemos algun espacio 
        inmediatamente salta al siguiente scanf y le asigna lo que estuviese despues del espacio.
        Para arreglarlo usamos %25 que indicaría la cantidad máxima de caracteres
    */
    for (int i = 0; i < numVehiculos; i++)
    {
        printf("\n Ingrese la matrícula del vehículo %d: ", aVehiculos[i]);
        scanf(" %25[^\n]", aMatricula[i]);
        printf("\n La matrícula del vehículo %d es: %s", aVehiculos[i]  , aMatricula[i]);
        printf("\n\n Ingrese la marca del vehículo %d: ", aVehiculos[i]);
        scanf(" %25[^\n]", aMarca[i]);
        printf(" La marca del vehículo %d es: %s", aVehiculos[i] , aMarca[i]);
        printf("\n\n Ingrese el precio del vehículo %d: ", aVehiculos[i]);
        scanf("%d", &aPrecio[i]);
        printf(" El precio del vehículo %d es: %d€", aVehiculos[i] , aPrecio[i]);
    }
    
    char matricula[25];
    printf("\n\n Porfavor introduzca la matrícula del vehiculo que quiera ver: ");
    scanf(" %25[^\n]", matricula);
    int numArray=0;
    bool matriculaEnArray=false;
    // Bucle para buscar si la matrícula que introduce el usuario se encuentra dentro del array
    for (int i = 0; i < numVehiculos; i++)
    {
        numArray=i;
        if (strcmp(aMatricula[i], matricula) == 0)
        {
            matriculaEnArray=true;
            break;
        }
    }
    
    // Imprimimos por pantalla la marca y el precio si la matricula se encuentra dentor del array aMatricula
    if(matriculaEnArray==true)
    {
        printf("\n La marca del vehículo con matrícula %s es: %s", matricula, aMarca[numArray]);
        printf("\n El precio del vehículo con matrícula %s es: %d€\n", matricula, aPrecio[numArray]);
    }
    else
    {
        printf("\n El vehículo no se encuentra en el concesionario.");
    }

    return 0;
}