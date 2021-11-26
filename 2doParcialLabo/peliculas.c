#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "peliculas.h"
#include "LinkedList.h"
#include "BibliotecaPersonal.h"

ePelicula* nuevo_pelicula()
{
    ePelicula* nuevaPeli = (ePelicula*) malloc(sizeof(ePelicula));
    if (nuevaPeli != NULL)
    {
        nuevaPeli->id_peli = 0;
        strcpy(nuevaPeli->titulo, "");
        strcpy(nuevaPeli->genero, "");
        nuevaPeli->rating = 0;

    }
    return nuevaPeli;
}

ePelicula* pelicula_nuevoParametro(char* idStr, char* nombreStr, char* generoStr, char* ratingStr)
{
    ePelicula* nuevaPeli= nuevo_pelicula();
    if (nuevaPeli != NULL)
    {
        nuevaPeli->id_peli = atoi(idStr);
        strcpy(nuevaPeli->titulo, nombreStr);
        strcpy(nuevaPeli->genero, generoStr);
        nuevaPeli->rating = atof(ratingStr);
    }
    return nuevaPeli;
}

void eliminarPelicula(ePelicula* pPelicula)
{
    if (pPelicula != NULL)
    {
        free(pPelicula);
    }
}

int pelicula_setId(ePelicula* this,int id)
{
    int todoOk = 0;
    if (this != NULL && id > 0)
    {
        this->id_peli = id;
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_getId(ePelicula* this,int* id)
{
    int todoOk = 0;
    if (this != NULL && id != NULL)
    {
        *id = this->id_peli;
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_setTitulo(ePelicula* this,char* titulo)
{
    int todoOk = 0;
    if (this != NULL && titulo != NULL && strlen(titulo) > 0 && strlen(titulo) < 128)
    {
        strcpy(this->titulo, titulo);
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_getTitulo(ePelicula* this,char* titulo)
{
    int todoOk = 0;
    if (this != NULL && titulo != NULL )
    {
        strcpy(titulo, this->titulo);
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_setGenero(ePelicula* this,char* genero)
{
    int todoOk = 0;
    if (this != NULL && genero != NULL && strlen(genero) > 0 && strlen(genero) < 128)
    {
        strcpy(this->genero, genero);
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_getGenero(ePelicula* this,char* genero)
{
    int todoOk = 0;
    if (this != NULL && genero != NULL )
    {
        strcpy(genero, this->genero);
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_setRating(ePelicula* this,float rating)
{
    int todoOk = 0;
    if (this != NULL && rating > 0)
    {
        this->rating = rating;
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_getRating(ePelicula* this,float* rating)
{
    int todoOk = 0;
    if (this != NULL && rating != NULL)
    {
        *rating = this->rating;
        todoOk = 1;
    }
    return todoOk;
}

int asignarRating(void* pelicula){
    int todoOk =0;
    ePelicula* auxPelicula = NULL;
    float auxRating;
    if(pelicula != NULL){
        auxPelicula= (ePelicula*) pelicula;
        auxRating = (float) (rand() % (100 - 10 + 1) + 10)/10;

        pelicula_setRating(auxPelicula, auxRating);

        todoOk =1;
    }


    return todoOk;
}
int asignarGenero(void* pelicula){
    int todoOk =0;
    ePelicula* auxPelicula = NULL;
    int aux;
    char auxGenero[20];
    if(pelicula != NULL){
        auxPelicula= (ePelicula*) pelicula;
        aux = rand() % (4 - 1 + 1) + 1;
        printf("%d", aux);
        switch(aux){
    case 1:
        strcpy(auxGenero, "drama");
        pelicula_setGenero(auxPelicula,auxGenero);
        break;
    case 2:
        strcpy(auxGenero, "comedia");
        pelicula_setGenero(auxPelicula,auxGenero);
        break;
    case 3:
        strcpy(auxGenero, "accion");
        pelicula_setGenero(auxPelicula,auxGenero);
        break;
    case 4:
        strcpy(auxGenero, "terror");
        pelicula_setGenero(auxPelicula,auxGenero);
        break;
        }

       todoOk =1;
    }
    return todoOk;
}


int filterComedia(void* pelicula)
{
    int todoOk = 0;
    ePelicula* auxPelicula = NULL;

    if ( pelicula!= NULL)
    {
        auxPelicula = (ePelicula*) pelicula;
        if ( strcmp( auxPelicula->genero, "comedia"  ) == 0  )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filterAccion(void* pelicula){

int todoOk =0;
ePelicula* auxPelicula = NULL;

if(pelicula !=NULL){

    auxPelicula = (ePelicula*) pelicula;
    if(strcmp(auxPelicula->genero, "comedia") == 0){
        todoOk =1;
    }
}

return todoOk;
}
int filterTerror(void* pelicula){

int todoOk =0;
ePelicula* auxPelicula = NULL;

if(pelicula !=NULL){

    auxPelicula = (ePelicula*) pelicula;
    if(strcmp(auxPelicula->genero, "terror") == 0){
        todoOk =1;
    }
}

return todoOk;
}

int filterDrama(void* pelicula){

int todoOk =0;
ePelicula* auxPelicula = NULL;

if(pelicula !=NULL){

    auxPelicula = (ePelicula*) pelicula;
    if(strcmp(auxPelicula->genero, "drama") == 0){
        todoOk =1;
    }
}

return todoOk;
}

int menuGenero(){
 int opcion = 0;
    system("cls");
    printf("   -Elija por que genero que desea filtrar- \n");
    printf("1- Comedia \n");
    printf("2- Accion\n");
    printf("3- Drama\n");
    printf("4- Terror\n");
    validarEntero(&opcion, "Ingrese el genero; (1-2-3-4): ", "Error al ingresar numero incorrecto", 1,4,25);

    return opcion;
}
int compararGeneroRating( void* peliA, void* peliB )
{
    int todoOk = 0;

    if(  (strcmp( ((ePelicula*)peliA)->genero,  ((ePelicula*)peliB)->genero )  > 0 ) ||
       ( (strcmp( ((ePelicula*)peliA)->genero,  ((ePelicula*)peliB)->genero )  == 0 ) &&
                   ((ePelicula*)peliA)->rating > ((ePelicula*)peliB)->rating )
           )
    {
        todoOk = 1;
    }
    if(  (strcmp( ((ePelicula*)peliA)->genero,  ((ePelicula*)peliB)->genero )  < 0 ) ||
       ( (strcmp( ((ePelicula*)peliA)->genero,  ((ePelicula*)peliB)->genero )  == 0 ) &&
                   ((ePelicula*)peliA)->rating < ((ePelicula*)peliB)->rating )
          )
    {
        todoOk = -1;
    }
    return todoOk;
}
