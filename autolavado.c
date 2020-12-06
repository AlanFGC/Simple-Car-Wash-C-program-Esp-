/** 
 *@file main.c
 *@brief Administrador de Autolavado
 *@details Programa que cuenta con multiples funciones. Entre ellas, mostrar trabajos, gestión de clientes, agendar citas y finalmente ver reportes de ganancias. 
 *@author
 * Alan Garcia, Jaime Mizrahi, Marissa López Gutiérrez
 *@date Fecha de creación
 * 18 de noviembre
 *@author Desarrollador que hizo la última modificación
 * Alan Garcia
 *@date Fecha de última modificación
 * 18 de noviembre
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/** @brief Prototipos de funcion */
void mostrarInstrucciones(char nombre[], char inst[]);
void limpiarBufer(void);
void mostrarMenuP(void);
void menuCatalogo(void);
void menuClientes(void);
void menuReportes(void);

/** 
 *@fn procedimiento que limpia el bufer de entrada.
 */
void limpiarBufer(void)
{
    int limpiar;
    while ((limpiar = getchar()) != '\n' && limpiar != EOF)
    {
    }

    return;
}

/**
 * @fn Funcion del programa principal.
 */
void main(void)
{
    mostrarInstrucciones("Alan Garcia", "escribe aqui tus instrucciones");
    mostrarMenuP();
    return;
}

/**
 * @fn Muestra instrucciones del programa.
 */

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

void mostrarMenuP(void)
{
    short int opcionMenu;
    do
    {
        printf("Selecciona un opción del menú (1-5):\n");
        printf("\t 1) Catálogos.\n");
        printf("\t 2) Registro de clientes.\n");
        printf("\t 3) Agendar cita.\n");
        printf("\t 4) Reportes.\n");
        printf("\t 5) Salir.\n");
        scanf(" %hd", &opcionMenu);
        limpiarBufer();
    } while (opcionMenu < 1 || opcionMenu > 5);

    switch (opcionMenu)
    {
    case 1:
        printf("Acción Catalogos\n");
        menuCatalogo();
        break;
    case 2:
        printf("Acción 2.\n");
        menuClientes();
        break;
    case 3:
        printf("Acción 3.\n");
        break;
    case 4:
        printf("Acción 4.\n");
        break;
    case 5:
        printf("Salir\n");
        return;
        break;
    default:
        printf("Input Invalido");
        return mostrarMenuP();
    }
}

void menuCatalogo(void)
{
    short int opcionMenu;
    do
    {
        printf("Selecciona un opción del Catálogo (1-3):\n");
        printf("\t I.Paquetes para lavado de autos.\n");
        printf("\t II.Regresar al menú principal.\n");
        scanf(" %hd", &opcionMenu);
        limpiarBufer();
    } while (opcionMenu < 1 || opcionMenu > 5);

    switch (opcionMenu)
    {
    case 1:
        printf("Paquetes para lavado de autos. \n");
        break;
    case 2:
        printf(" Regresar al menú principal. \n");
        return;
        break;
    default:
        printf("Input Incorrecto\n");
        return;
    }
}

void menuClientes(void)
{
    short int opcionMenu;
    do
    {
        printf("Selecciona un opción del menú (1-5):\n");
        printf("\t 1) Mostrar cliente.\n");
        printf("\t 2) agregar Cliente.\n");
        printf("\t 3) editar cliente.\n");
        printf("\t 4) Borrar cliente.\n");
        scanf(" %hd", &opcionMenu);
        limpiarBufer();
    } while (opcionMenu < 1 || opcionMenu > 5);

    switch (opcionMenu)
    {
    case 1:
        printf("Mostrar.\n");
        break;
    case 2:
        printf("Crear.\n");
        break;
    case 3:
        printf("Editar.\n");
        break;
    case 4:
        printf("Borrar.\n");
        break;
    default:
        printf("Input Invalido");
        return;
    }
}