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
#define TAM_Lista 100

/** @brief se declaran las estructuras de datos */
typedef struct Cliente
{
    int numId;
    char nombreCliente[255];
    char marca[10];
    char modelo[25];
    char color[25];
    char placas[10];
    short int tipo;
    short int servicios;
} typeCliente;

/** @brief Se declaran las variables globales */
typeCliente regClientes[TAM_Lista];

/** @brief Prototipos de funcion */
void mostrarMenuP(void);
void menuCatalogo(void);
void menuClientes(void);
void menuReportes(void);
//clientes
void agregarCliente(void);
void mostrarClientes(void);
int asignarId(void);
void eliminarCliente(void);
void editarCliente(void);
//citas

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
    system("clear");
    short int opcionMenu;
    do
    {
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
            mostrarClientes();
            break;
        case 2:
            printf("Crear.\n");
            agregarCliente();
            break;
        case 3:
            printf("Editar.\n");
            editarCliente();
            break;
        case 4:
            printf("Borrar.\n");
            eliminarCliente();
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

void mostrarClientes(void)
{
    int numId = asignarId();
    system("clear");
    for (int i = 0; i < numId; i++)
    {
        if (regClientes[i].numId > 0)
        {
            printf("ID:%d\t%s\t%s\t%s\t%s\t%s\t\t\tServicios(%hd/3)\t", regClientes[i].numId, regClientes[i].nombreCliente, regClientes[i].marca, regClientes[i].modelo, regClientes[i].color, regClientes[i].placas, regClientes[i].servicios);
            if (regClientes[i].tipo == 1)
            {
                printf("Tipo: automóvil\n");
            }
            else if (regClientes[i].tipo == 2)
            {
                printf("Tipo: camioneta\n");
            }
            else if (regClientes[i].tipo == 3)
            {
                printf("Tipo: Camión\n");
            }
        }
    }
    printf("\n\n");
    return;
}
/** 
 * @brief Procedimiento que agrega un cliente
 * @Param voids
 */
void agregarCliente(void)
{
    char opcion;
    int id = 0;
    system("clear");
    id = asignarId();
    printf(" Id nuevo cliente = %d\n", id);
    do
    {
        regClientes[id] = (typeCliente){.numId = id};
        printf("Ingresa el nombre del cliente.\n");
        scanf("%s", regClientes[id].nombreCliente);
        printf("Ingresa la marca de su vehículo.\n");
        scanf("%s", regClientes[id].marca);
        printf("Ingresa el modelo de su vehículo\n");
        scanf("%s", regClientes[id].modelo);
        printf("Ingresa el color de su vehículo\n");
        scanf("%s", regClientes[id].color);
        printf("Ingresa las placas de su vehículo\n");
        scanf("%s", regClientes[id].placas);
        system("clear");
        do
        {
            printf("Ingresa el tipo vehículo\n\t1 = automóvil\n\t2 = Camioneta\n\t3= Camión\n");
            scanf("%hd", &regClientes[id].tipo);
            limpiarBuffer();
        } while (regClientes[id].tipo < 1 || regClientes[id].tipo > 3);

        system("clear");
        printf("%s\t%s\t%s\t%s\t%s\n", regClientes[id].nombreCliente, regClientes[id].marca, regClientes[id].modelo, regClientes[id].color, regClientes[id].placas);
        if (regClientes[id].tipo == 1)
        {
            printf("Tipo = automóvil\n");
        }
        else if (regClientes[id].tipo == 2)
        {
            printf("Tipo = camioneta\n");
        }
        else if (regClientes[id].tipo == 3)
        {
            printf("Tipo = Camión\n");
        }
        printf("¿La información es correcta? ( s / n )\n");
        scanf(" %c", &opcion);
        limpiarBuffer();
    } while (opcion != 's');
    return;
}
/** 
 * @brief Procedimiento que asigna un nuevo id
 * @Param void
 */
int asignarId(void)
{
    int newId = 0;
    for (int i = 0; i < TAM_Lista; i++)
    {
        if (newId < regClientes[i].numId)
        {
            newId = regClientes[i].numId;
        }
    }
    newId++;
    return newId;
}
/** 
 * @brief Procedimiento elimina un cliente existente
 * @Param void
 */
void eliminarCliente(void)
{
    mostrarClientes();
    int idCliente = 0;
    do
    {
        printf("Ingresa el número ID del cliente que deseas eliminar\n\n");
        scanf("%d", &idCliente);
    } while (idCliente <= 0);
    if (regClientes[idCliente].numId > 0)
    {
        regClientes[idCliente] = (typeCliente){.numId = 0, .marca = "\0", .modelo = "\0", .color = "\0", .placas = "\0", .tipo = 0, .servicios = 0};
        printf("Se ha eliminado al cliente %d existosamente.\n", idCliente);
    }
    else
    {
        printf("No se ha podiddo encotnrar al cliente %d , intente de nuevo.\n", idCliente);
    }
    return;
}
/** 
 * @brief Procedimiento edita un cliente existente.
 * @Param void
 */
void editarCliente(void)
{
    int id = 0;
    mostrarClientes();
    printf("Ingresa el cliente que desees editar:");
    scanf("%d", &id);
    if (regClientes[id].numId == 0)
    {
        system("clear");
        printf("\nLo siento, cliente no encontrado.\n");
        return;
    }
    else
    {
        printf("Ingresa el nombre del cliente. Nombre anterior es: %s\n", regClientes[id].nombreCliente);
        scanf("%s", regClientes[id].nombreCliente);
        printf("Ingresa la marca de su vehículo. La marca anterior es: %s\n", regClientes[id].marca);
        scanf("%s", regClientes[id].marca);
        printf("Ingresa el modelo de su vehículo. El modelo anterior es: %s\n", regClientes[id].modelo);
        scanf("%s", regClientes[id].modelo);
        printf("Ingresa el color de su vehículo. El color anterior es: %s\n", regClientes[id].color);
        scanf("%s", regClientes[id].color);
        printf("Ingresa las placas de su vehículo. Las placas anteriores son: %s\n", regClientes[id].placas);
        scanf("%s", regClientes[id].placas);
        do
        {
            printf("Ingresa el tipo vehículo\n\t1 = automóvil\n\t2 = Camioneta\n\t3= Camión\n");
            scanf("%hd", &regClientes[id].tipo);
            limpiarBuffer();
        } while (regClientes[id].tipo < 1 || regClientes[id].tipo > 3);
    }
    system("clear");
    printf("En hora buena, el perfil del usuario %s ha sido modificado.\n", regClientes[id].nombreCliente);
    return;
}