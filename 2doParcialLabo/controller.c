#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "parser.h"
#include "BibliotecaPersonal.h"
#include "controller.h"
#include "LinkedList.h"
int controller_loadFromText(char* path, LinkedList* pArrayListaPelicula)
{
int todoOk = 0;
    FILE* pFile;
    if (path != NULL && pArrayListaPelicula != NULL)
    {
        system("cls");
        printf("Cargar los datos de las peliculas desde el archivo movies.csv (modo texto).\n");

        pFile = fopen( path, "r");
        if (pFile == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if (parser_peliculaFromText( pFile, pArrayListaPelicula ) )
            {
                printf( "Carga de archivo de texto exitosa\n" );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

int menu()
{
    int opcion = 0;
    system("cls");
    printf("    ***PELICULAS***\n");
    printf("1- Cargar los datos de las peliculas desde el archivo en modo csv \n");
    printf("2- Listar Peliculas \n");
    printf("3- Asignar Rating usando Map\n");
    printf("4- Asignar Genero usando Map\n");
    printf("5- Filtrar por Genero\n");
    printf("6- Ordenar por Genero y rating \n");
    printf("7- Guardar pelicula en archivo\n");
    printf("8- Salir\n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
int controller_listarPeliculas(LinkedList* pArrayListaPelicula)
{
    int todoOk = 0;
    ePelicula* auxPelicula;
    int controlador;
    controlador = ll_isEmpty(pArrayListaPelicula);
    if (pArrayListaPelicula != NULL)
    {
        if(controlador == 0){
        system("cls");
        printf("Listar peliculas\n");

        printf("Id  Nombre          Genero       Rating\n");
        for (int i = 0; i < ll_len(pArrayListaPelicula); i++)
        {
            auxPelicula = (ePelicula*) ll_get( pArrayListaPelicula, i );
            mostrarPelicula(auxPelicula);
        }

        todoOk = 1;
        }else{
            printf("Hubo un error al cargar la lista\n");
        }
    }
    return todoOk;
}

int mostrarPelicula(ePelicula* pelicula)
{
    int todoOk = 0;
    int id;
    char titulo[50];
    char genero[50];
    float rating;


    if (pelicula != NULL)
    {
        todoOk = 1;
        if ( pelicula_getId( pelicula, &id ) &&
                pelicula_getTitulo( pelicula, titulo ) &&
                pelicula_getGenero( pelicula, genero) &&
                pelicula_getRating( pelicula, &rating)
           )
        {
            printf ("%-7d %-28s %-15s      %-6.1f\n", id, titulo, genero, rating);
            todoOk = 1;
        }
    }
    return todoOk;
}
int controller_saveAsText(char* path, LinkedList* pArrayListaPelicula)
{
    int todoOk = 0;
    FILE* pFile;
    int id;
    char titulo[50];
    char genero[50];
    float rating;
    ePelicula* auxPelicula;

    if (path != NULL && pArrayListaPelicula != NULL){
        system("cls");
        printf("Guardar los datos de las peliculas en el archivo movie.csv (modo texto).\n");

        pFile = fopen(path, "w");
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");
        }
        fprintf( pFile, "id,titulo,genero,rating\n" );

        for (int i = 0; i < ll_len(pArrayListaPelicula); i++)
        {
            auxPelicula = ll_get(pArrayListaPelicula, i);
            if (pelicula_getId( auxPelicula, &id ) &&
                pelicula_getTitulo( auxPelicula, titulo ) &&
                pelicula_getGenero( auxPelicula, genero) &&
                pelicula_getRating(auxPelicula, &rating)
               )
            {
                fprintf(pFile, "%d,%s,%s,%.1f\n", id, titulo, genero, rating);
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}


int controller_mapPeliculas(LinkedList* pArrayListaPeliculas){
int todoOk = 0;

if(pArrayListaPeliculas != NULL){
    pArrayListaPeliculas = ll_map(pArrayListaPeliculas, (void*) asignarRating);
    if(pArrayListaPeliculas != NULL){
    printf("Se han cargado los datos de manera correcta\n");

    controller_listarPeliculas(pArrayListaPeliculas);
    todoOk = 1;
    }
}

return todoOk;
}
int controller_mapPeliculasGenero(LinkedList* pArrayListaPeliculas){
int todoOk = 0;

if(pArrayListaPeliculas != NULL){
    pArrayListaPeliculas = ll_map(pArrayListaPeliculas,(void*) asignarGenero);
    if(pArrayListaPeliculas != NULL){
    printf("Se han cargado los datos de manera correcta\n");

    controller_listarPeliculas(pArrayListaPeliculas);
    todoOk = 1;
    }
}

return todoOk;
}
int controller_filtrarGenero(LinkedList* pArrayPelicula)
{
    int todoOk = 0;
    int opcion;
    char archivoGuardado[50];

    opcion = menuGenero();
    switch (opcion)
    {
    case 1:
        pArrayPelicula = ll_filter(pArrayPelicula, filterComedia);
        strcpy(archivoGuardado, "peliculaComedia.csv");
        break;
    case 2:
        pArrayPelicula = ll_filter(pArrayPelicula, filterAccion);
        strcpy(archivoGuardado, "peliculaAccion.csv");
        break;
    case 3:
        pArrayPelicula = ll_filter(pArrayPelicula, filterDrama);
        strcpy(archivoGuardado, "peliculaDrama.csv");
        break;
    case 4:
        pArrayPelicula = ll_filter(pArrayPelicula, filterTerror);
        strcpy(archivoGuardado, "peliculaTerror.csv");
        break;
    }

    if ( pArrayPelicula != NULL  )
    {
        controller_listarPeliculas(pArrayPelicula);
        system("pause");
        controller_saveAsText(archivoGuardado, pArrayPelicula);
        todoOk = 1;
    }
    return todoOk;
}
int controller_ordenarPeliculaGeneroRating(LinkedList* pArrayListaPeliculas)
{
    int todoOk =0;
    if (pArrayListaPeliculas != NULL)
    {
        ll_sort(pArrayListaPeliculas, compararGeneroRating, 1);
        controller_listarPeliculas(pArrayListaPeliculas);
        todoOk = 1;
    }

    return todoOk;
}
int controller_guardarArchivo(LinkedList* pArrayListaPeliculas){
int todoOk =0;
char auxChar[20];
if (pArrayListaPeliculas != NULL){
   printf("Ingrese el nombre del archivo a guardar: ");
        scanf("%s", auxChar);

        strcat(auxChar, ".csv");
        controller_saveAsText(auxChar,pArrayListaPeliculas);
        todoOk =1;
}

return todoOk;
}
