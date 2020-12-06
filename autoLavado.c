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
//clientes
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
//Citas
typedef struct citas
{
    // los días del mes para hacer la cita.
    int dia;
    // hora de la cita en 24 horas. Es un arreglo porque maximo habrá 5 citas por día.
    int hora[5];
    //id del cliente que hara cita.  Es un arreglo porque maximo habrá 5 clientes por día.
    int idCliente[5];
    //cuantas citas hay registradas en todo el día.
    int numCitas;
    //cantidad final que será cobrada por cita. Cuando cobremos el total de dinero será sumado aca. Es un arreglo porque maximo habrá 5 citas por día.
    int monto[5];
} typeCitas;

/** @brief Se declaran las variables globales */
//Clientes
typeCliente regClientes[TAM_Lista];
//Citas
typeCitas regCitas[5];

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
void menuCitas(void);
void hacerCita(void);
void mostrarCitas(void);
//extras
int verificarId(int);
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
            printf("Catalogos:\n");
            menuCatalogo();
            break;
        case 2:
            printf("Clientes:\n");
            menuClientes();
            break;
        case 3:
            printf("Agendar cita:\n");
            menuCitas();
            break;
        case 4:
            printf("Reportes:\n");
            menuReportes();
            break;
        case 5:
            printf("Salir.\n");
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
    system("clear");
    short int opcionMenu;
    do
    {
        do
        {
            printf("Selecciona un opción del Catálogo (1-3):\n");
            printf("\t I.Paquetes para lavado de autos.\n");
            printf("\t II.Regresar al menú principal.\n");
            scanf(" %hd", &opcionMenu);
            limpiarBuffer();
        } while (opcionMenu < 1 || opcionMenu > 2);

        switch (opcionMenu)
        {
        case 1:
            system("clear");
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

void menuCitas(void)
{
    short int opcionMenu;
    system("clear");
    do
    {
        do
        {
            printf("\n\n Selecciona una opcion\n");
            printf("1: Agendar una cita\n");
            printf("2: Mostrar citas\n");
            printf("3: Salir\n");
            scanf("%hd", &opcionMenu);
            limpiarBuffer();
        } while (opcionMenu < 1 || opcionMenu > 3);

        switch (opcionMenu)
        {
        case 1:
            printf("Agendar Cita.\n");
            hacerCita();
            break;
        case 2:
            printf("Mostrar citas.\n");
            mostrarCitas();
            break;
        case 3:
            printf("Regresar menú principal.\n");
            return;
            break;
        default:
            printf("Input Invalido");
            return;
        }
    } while (opcionMenu != 3);
    return;
}
/*
*
*
*
*
*
*
*
*
*/
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
            printf("Ingresa el tipo vehículo\n\t1 = automóvil\n\t2 = Camioneta\n\t3 = Camión\n");
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
/*
*
*
*
*
*
*
*
*
*/
/** 
 * @brief Procedimiento para agendar un cita.
 * @Param void
 */
void hacerCita(void)
{
    system("clear");
    int diaCita = 0, horario = 0, idCliente = 0, monto = 0, camioneta = 0, opcion = 0, paquete = 0;
    //vamos a seleccionar el dia de la cita usando el struct. Si es miercoles, jueves, viernes, etc.
    do
    {
        system("clear");
        printf("¿Que día será su cita?\n");
        printf("\nSelecciona un dia:\n\n");
        printf("\t\t1:Miercoles\n");
        printf("\t\t2:Jueves\n");
        printf("\t\t3:Viernes\n");
        printf("\t\t4:Sabado\n");
        printf("\t\t5:Domingo\n");
        scanf("%d", &diaCita);
    } while (diaCita < 1 || diaCita > 5);
    //checar si ese día hay citas disponibles. (no puede haber más de 5 citas por día.)
    if (regCitas[diaCita].numCitas >= 5)
    {
        printf("Lo siento no hay espacio disponible ese día (%d/5)", regCitas[diaCita].numCitas);
        return;
    }
    else
    {
        printf("\nTu cita será el día: %d. Hay %d disponibles ese día.\n", diaCita, 5 - regCitas[diaCita].numCitas);
    }
    //checar disponibilidad en horarios.
    do
    {
        printf("Introduce el horario  de la cita de 10 de la mañana a 15 de la tarde. (en 24 horas)\n");
        scanf("%d", &horario);
        if (horario < 10 || horario > 15)
        {
            printf("El horario es invalido. Intenta con otro horario.\n");
        }
        else
        {
            // probar citas regCitas[diaCita].hora[1] = 10;
            //con este for checamos horarios disponibles. i llega hasta el 5 porque solo tenemos 5 citas por día. checa la hora de cada registro durante el día.
            for (int i = 0; i < 5; i++)
            {
                if (horario == regCitas[diaCita].hora[i])
                {
                    printf("Lo siento este espacio ya está reservado. Intenta con otro horario.\n");
                    //le damos un horario invalido para evitar que se brinque el while.
                    horario = 25;
                }
            }
        }

    } while (horario < 10 || horario > 15);
    //meter lo del cliente.   mejor esto lo dejamos hasta el final porque hay que conectarlo con clientes.c

    //Cobrar Monto. Hay que poner los precios y los paquetes y que el usuario eliga uno paquete.
    do
    {
        printf("Estos son los paquetes disponibles:\n\n");
        printf("Favor de elgir una opcion\n");
        printf("1.espuma activa 80$\n");
        printf("2.cera liquida 90$\n");
        printf("3.premium 99$\n");
        scanf("%d", &paquete);
    } while (paquete < 1 || paquete > 3);

    if (paquete == 1)
    {
        monto += 80;
    }
    else if (paquete == 2)
    {
        monto += 90;
    }
    else if (paquete == 3)
    {
        monto += 99;
    }

    do
    {
        system("clear");
        mostrarClientes();
        printf("Porfavor ingresa el número identificador (Id) del usuario que deseas agendar.\n");
        printf("Si no tiene un usuario creado ingrese 0 para salir.\n");
        scanf("%d", &idCliente);

        if (idCliente == 0)
        {
            return;
        }
        //verificador de ID
        if (verificarId(idCliente) > 0)
        {
            printf("\n¡Usuario encontrado!");
            if (regClientes[idCliente].tipo > 1)
            {
                printf("\n Tu vehículo es una camioneta.\n");
                camioneta = 1;
                monto += 10;
            }
            else
            {
                printf("\nTu vehículo NO es una camioneta.\n");
                camioneta = 0;
            }
        }
        else
        {
            printf("\nUsuario no encontrado intente de nuevo.\n");
            camioneta = -1;
        }
    } while (camioneta < 0 || camioneta > 1);

    do
    {
        printf("\nextras:\n");
        printf("Te aspiramos la cajuela por 10$\n");
        printf("Si quieres este servicio elige 1, de lo contrario elige 0\n\n");
        scanf("%d", &opcion);
    } while (opcion < 0 || opcion > 1);

    if (opcion == 1)
    {
        monto += 10;
    }
    system("clear");
    printf("El monto total es igual a $ %d\n", monto);
    printf("La cita ha sido agendada.\n");
    //Salvar toda la info en al struct.
    regClientes[idCliente].servicios++;
    regCitas[diaCita].numCitas += 1;
    regCitas[diaCita].idCliente[regCitas[diaCita].numCitas] = idCliente;
    regCitas[diaCita].hora[regCitas[diaCita].numCitas] = horario;
    regCitas[diaCita].monto[regCitas[diaCita].numCitas] = monto;
    return;
}
/** 
 * @brief Procedimiento para mostrar las.
 * @Param void
 */
void mostrarCitas(void)
{
    int diaCita, i;
    char dias[5][10] = {"Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    do
    {
        system("clear");
        printf("Elige el día que quieras ver las citas\n");
        printf("\t\t1:Miercoles\n");
        printf("\t\t2:Jueves\n");
        printf("\t\t3:Viernes\n");
        printf("\t\t4:Sabado\n");
        printf("\t\t5:Domingo\n");
        scanf("%d", &diaCita);
    } while (diaCita < 1 || diaCita > 5);

    //usar un for para imprimir las citas por día.
    printf("Estas son las citas del dia %s\n", dias[diaCita - 1]);

    for (i = 0; i < 5; i++)
    {
        if (regCitas[diaCita].idCliente[i] > 0)
        {
            printf("ID: %d\t", regCitas[diaCita].idCliente[i]);
            printf("horario: %d\t", regCitas[diaCita].hora[i]);
            printf("El monto a pagar es: %d\n\n", regCitas[diaCita].monto[i]);
        }
    }
}

/** 
 * @brief Función que comprueba si el id ingresado es existente.
 * @Param el id que desea verificar. 
 * si el usuario existe regresará el mismo id, de lo contrario regresará cero. 
 */
int verificarId(int idIngresado)
{
    for (int i = 0; i < TAM_Lista; i++)
    {
        if (regClientes[i].numId == idIngresado)
        {
            return idIngresado;
        }
    }
    printf("Id no encontrado, intente de nuevo.");
    return 0;
}