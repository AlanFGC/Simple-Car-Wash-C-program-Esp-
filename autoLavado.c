/** 
 *@file main.c
 *@brief Administrador de Autolavado
 *@details Programa que cuenta con multiples funciones. Entre ellas, mostrar trabajos, gestión de clientes, agendar citas y finalmente ver reportes de ganancias. 
 *@author
 * Alan Garcia, Jaime Mizrahi, Marissa López Gutiérrez
 *@date Fecha de creación
 * 1 de Diciembre.
 *@author Desarrollador que hizo la última modificación
 * Alan Garcia
 *@date Fecha de última modificación
 * 5 de Diciembre.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libFundamentos.h"

/** @brief Prototipos de funcion */
void mostrarMenuP(void);
void menuCatalogo(void);
void menuClientes(void);
void menuReportes(void);

/**
 * @fn Funcion del programa principal.
 */

void main(void)
{
    mostrarInstrucciones("Alan Garcia, Jaime Mizrahi, Marissa López Gutiérrez", "Programa para gestionar clientes de un autolavado.");
    mostrarMenuP();
    return;
}

void mostrarMenuP(void)
{
    short int opcionMenu;
    do
    {
        system("clear");
        do
        {
            printf("Selecciona un opción del menú (1-5):\n");
            printf("\t 1) Catálogos.\n");
            printf("\t 2) Registro de clientes.\n");
            printf("\t 3) Agendar cita.\n");
            printf("\t 4) Reportes.\n");
            printf("\t 5) Salir.\n");
            scanf(" %hd", &opcionMenu);
            limpiarBuffer();
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
            printf("Acción: Agendar cita.\n");
            break;
        case 4:
            printf("Acción: Reportes.\n");
            menuReportes();
            break;
        case 5:
            printf("Salir\n");
            return;
            break;
        default:
            printf("Input Invalido");
            return;
        }
    } while (opcionMenu != 5);
    return;
}

void menuCatalogo(void)
{

    short int opcionMenu;
    do
    {
        system("clear");
        do
        {
            printf("Selecciona un opción del Catálogo (1-3):\n");
            printf("\t I.Paquetes para lavado de autos.\n");
            printf("\t II.Regresar al menú principal.\n");
            scanf(" %hd", &opcionMenu);
            limpiarBuffer();
        } while (opcionMenu < 1 || opcionMenu > 5);

        switch (opcionMenu)
        {
        case 1:
            printf("Paquetes para lavado de autos. \n\n");
            printf(" 1) Espuma activa.\n");
            printf("\t a. Costo $80.00.\n");
            printf("\t b. Descripción:Espuma activa, lavado, aspirado interior y secado.\n\n");
            printf(" 2) Cera líquida.\n\n");
            printf("\t a. Costo $90.00.\n");
            printf("\t b. Descripción: Espuma activa, lavado, aspirado interior, secado y súper encerado.\n\n");
            printf(" 3) Premium.\n\n");
            printf("\t a. Costo $99.00.\n");
            printf("\t b. Descripción: Espuma activa, lavado, aspirado interior, secado, súper encerado y lavado de chasis. \n\n ");
            printf("\n **NOTA**\n Agregue el servicio de aspirado de cajuela por $10.00 extra\n");
            printf(" **NOTA**\n Se incrementarán $10.00 al precio de cualquier paquete cuando los servicios sean para camionetas o pickups grandes.\n\n");

            break;
        case 2:
            printf(" Regresar al menú principal. \n");
            return;
            break;
        default:
            printf("Input Incorrecto\n");
            return;
        }

    } while (opcionMenu != 2);
    return;
}

void menuClientes(void)
{

    short int opcionMenu;
    do
    {
        system("clear");
        do
        {
            printf("Selecciona un opción del menú (1-5):\n");
            printf("\t 1) Mostrar cliente.\n");
            printf("\t 2) agregar Cliente.\n");
            printf("\t 3) editar cliente.\n");
            printf("\t 4) Borrar cliente.\n");
            printf("\t 5) Regresar al menú principal.\n");
            scanf(" %hd", &opcionMenu);
            limpiarBuffer();
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
        case 5:
            printf("Regresar.\n");
            return;
            break;
        default:
            printf("Input Invalido");
            return;
        }
    } while (opcionMenu != 5);
    return;
}

void menuReportes(void)
{

    short int opcionMenu;
    do
    {
        system("clear");
        do
        {
            printf("Selecciona un opción del menú (1-4):\n");
            printf("\t 1) Ganancias.\n");
            printf("\t 2) Citas.\n");
            printf("\t 3) Programa de lealtad.\n");
            printf("\t 4) Regresar al menú principal.\n");
            scanf(" %hd", &opcionMenu);
            limpiarBuffer();
        } while (opcionMenu < 1 || opcionMenu > 5);

        switch (opcionMenu)
        {
        case 1:
            printf("Ganancias.\n");
            break;
        case 2:
            printf("Citas.\n");
            break;
        case 3:
            printf("Programa de lealtad.\n");
            break;
        case 4:
            printf("Regresar al menú principal.\n");
            break;
        default:
            printf("Input Invalido");
            return;
        }
    } while (opcionMenu != 4);
    return;
}