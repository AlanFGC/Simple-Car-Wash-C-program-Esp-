#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void mostrarInstrucciones(char nombre[], char inst[]);
void limpiarBuffer(void);
int numRandom(int, int);

void mostrarInstrucciones(char autores[], char instrucciones[])
{
    printf("Aplicacion desarrollada por:\n");
    printf("\t %s \n\n", autores);
    printf("Descripcion del programa:\n");
    printf("\t %s \n\n", instrucciones);
    printf("Presiona ENTER  para continuar");
    getchar();
    system("clear");
    return;
}

void limpiarBuffer(void)
{
    int limpiar;
    while ((limpiar = getchar()) != '\n' && limpiar != EOF)
    {
    }
    return;
}

int numRandom(int inicio, int final)
{
    int aleatorio;
    srand(time(NULL));
    aleatorio = inicio + rand() % final;
    return aleatorio;
}