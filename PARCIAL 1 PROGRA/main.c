/*
1. Crear una función llamada aplicarAumento que reciba como parámetro el precio de un producto
y devuelva el valor del producto con un aumento del 5%. Realizar la llamada desde el main.

2. Crear una función que se llame reemplazarCaracteres que reciba una cadena de caracteres como primer parámetro,
un carácter como segundo y otro carácter  como tercero,
la misma deberá reemplazar cada ocurrencia del segundo parámetro por el tercero y devolver
la cantidad de veces que se reemplazo ese carácter  en la cadena

3. Dada la siguiente estructura generar una función que permita
ordenar un array de dicha estructura por tipo.
Ante igualdad de tipo deberá ordenarse por efectividad creciente.
Hardcodear datos y mostrarlos desde el main
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
} eVacuna;



float aplicarAumento(float precio);
int reemplazarCaracteres(char vec[], char caracterA, char caracterB);
void ordenarTipoEfectividad(eVacuna vec[], int tam);


int main()
{
    float precioF;
    char cad[]="casa";
    int reemplazos;

    eVacuna vacunas[5]=
    {
        {1, "Moderna", 'b', 90},
        {2, "Pfyzer", 'a', 94},
        {3, "Astrazeneca", 'a', 80},
        {4, "Sputnik V", 'a', 92},
        {5, "Synopharm", 'b', 60}
    };

    printf("TEST Ej. 1:\n");
    precioF = aplicarAumento(250);
    printf("%.2f", precioF);
    printf("\n\n-----------------------\n\n");


    printf("TEST Ej. 2:\n");
    reemplazos = reemplazarCaracteres(cad, 'a', 'x');
    printf("%s", cad);
    printf("\nreemplazos realizados: %d\n", reemplazos);
    printf("\n\n-----------------------\n\n");


    printf("TEST Ej. 3:\n");
    ordenarTipoEfectividad(vacunas, 5);
    printf("id     Vacuna    Tipo     Efectividad");
    printf("\n-----------------------------------------\n");
    for(int i=0; i<5; i++)
    {
        printf("%d     %10s     %c        %.2f\n",vacunas[i].id
               , vacunas[i].nombre
               , vacunas[i].tipo
               , vacunas[i].efectividad);
    }


    return 0;
}


float aplicarAumento(float precio)
{

    float precioFinal;
    precioFinal = precio*1.05;

    return precioFinal;
}


int reemplazarCaracteres(char vec[], char caracterA, char caracterB)
{
    int cont=0;
    int largo;
    largo = strlen(vec);

    for(int i=0; i<largo; i++)
    {
        if(vec[i]==caracterA)
        {
            vec[i]=caracterB;
            cont++;
        }
    }
    return cont;
}


void ordenarTipoEfectividad(eVacuna vec[], int tam)
{
    eVacuna auxVacuna;

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if(vec[i].tipo > vec[j].tipo ||
              (vec[i].tipo == vec[j].tipo && vec[i].efectividad > vec[j].efectividad))
            {
                auxVacuna = vec[i];
                vec[i] = vec[j];
                vec[j] = auxVacuna;
            }
        }
    }
}
