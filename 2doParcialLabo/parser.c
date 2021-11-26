#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "parser.h"
int parser_peliculaFromText(FILE* pFile, LinkedList* pArrayListaPelicula)
{
    int todoOk = 0;
    int cant;
    char id[50];
    char titulo[50];
    char genero[50];
    char rating[50];
    ePelicula* auxPeli;

    if (pFile != NULL && pArrayListaPelicula != NULL  )
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, genero, rating);
        do
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,titulo,genero,rating);
            if (cant < 4)
            {
                break;
            }

            auxPeli = pelicula_nuevoParametro( id, titulo, genero, rating);
            if (auxPeli != NULL)
            {
                ll_add( pArrayListaPelicula, auxPeli);
                todoOk = 1;
                auxPeli = NULL;
            }
        }
        while (!feof(pFile));
    }
    return todoOk;

}
