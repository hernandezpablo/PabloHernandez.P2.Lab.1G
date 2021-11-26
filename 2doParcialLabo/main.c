#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "peliculas.h"
#include "controller.h"
#include "BibliotecaPersonal.h"
#include <time.h>
int main()
{
     srand(time(NULL));
    char salir;
    char seguir = 's';
    LinkedList* listaPeliculas = ll_newLinkedList();

    if (listaPeliculas == NULL)
    {
        printf("No se pudo crear el linkedList\n");
        exit(1);

    }
    do
    {
        switch(menu())
        {
        case 1:
            if(!controller_loadFromText("movies.csv",listaPeliculas))
            {
                printf("Error durante la llamada\n");
            }
            break;
        case 2:
            if(!controller_listarPeliculas(listaPeliculas))
            {
                printf("Error al listar las peliculas\n");
            }
            break;
        case 3:
            if(!controller_mapPeliculas(listaPeliculas)){
               printf("Error a asignar rating a las peliculas\n");
               }
            break;
        case 4:
            if(!controller_mapPeliculasGenero(listaPeliculas)){
               printf("Error a asignar genero de pelicula\n");
               }
            break;
        case 5:
            if(!controller_filtrarGenero(listaPeliculas)){
               printf("Error a filtrar por genero\n");
               }
            break;
        case 6:
            if(!controller_ordenarPeliculaGeneroRating(listaPeliculas)){
               printf("Error a ordenar las peliculas\n");
               }
            break;
         case 7:
             if ( !controller_guardarArchivo(listaPeliculas) )
            {
                printf("Error al guardar en modo texto\n");
            }
            break;

        case 8:
             printf("Esta seguro que quiere salir? (S/N)\n");
            fflush(stdin);
            scanf("%c", &salir);
            salir = toupper(salir);
            if (salir == 'S')
            {
                seguir = 'n';
            }
            else
            {
                break;
            }
            break;
        default:
            printf("Opcion invalida\n");
            printf("Ingrese otra opcion:\n");
        }
        system("pause");
    }
    while(seguir == 's');


    free(listaPeliculas);
    return 0;
}
