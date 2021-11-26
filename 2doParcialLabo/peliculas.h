
#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED
typedef struct
{
    int id_peli;
    char titulo[50];
    char genero[50];
    float rating;
} ePelicula;


#endif // PAISES_H_INCLUDED
/** \brief Crea una estructura pelicula vacia
 *
 * \return ePelicula*
 *
 */
ePelicula* nuevo_pelicula();
/** \brief Crea una estructura de pelicula con los datos que le pasa
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param generoStr char*
 * \param duracionStr char*
 * \return ePelicula*
 *
 */
ePelicula* pelicula_nuevoParametro(char* idStr, char* nombreStr, char* generoStr, char* duracionStr);
/** \brief elimina una estructura pelicula
 *
 * \param pPelicula ePelicula*
 * \return void
 *
 */
void eliminarPelicula(ePelicula* pPelicula);
/** \brief setea el id de la estructura pelicula
 *
 * \param this ePelicula*
 * \param id int
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int pelicula_setId(ePelicula* this,int id);
/** \brief te da el id de la estructura pelicula que le envias
 *
 * \param this ePelicula*
 * \param id int*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int pelicula_getId(ePelicula* this,int* id);
/** \brief setea el Titulo de la estructura pelicula
 *
 * \param this ePelicula*
 * \param titulo char*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int pelicula_setTitulo(ePelicula* this,char* titulo);
/** \brief te da el titulo de la estructura pelicula que le envias
 *
 * \param this ePelicula*
 * \param titulo char*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int pelicula_getTitulo(ePelicula* this,char* titulo);
/** \brief setter de genero de la estructura pelicula
 *
 * \param this ePelicula*
 * \param genero char*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int pelicula_setGenero(ePelicula* this,char* genero);
/** \brief getter de genero de la estructura pelicula
 *
 * \param this ePelicula*
 * \param genero char*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int pelicula_getGenero(ePelicula* this,char* genero);
/** \brief setter del rating de la estructura pelicula
 *
 * \param this ePelicula*
 * \param rating float
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien;
 *
 */
int pelicula_setRating(ePelicula* this,float rating);
/** \brief getter de rating de la estructura pelicula
 *
 * \param this ePelicula*
 * \param rating float*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int pelicula_getRating(ePelicula* this,float* rating);
/** \brief funcion que asigna el rating de manera aleatoria entre 1 y 10 de una estructura pelicula
 *
 * \param pelicula void*
 * \return int devuelve 0 si hubo un error, o 1 si salio todo bien
 *
 */
int asignarRating(void* pelicula);
/** \brief funcion que asigna el genero de manera aleatoria entre 4 generos de una estructura pelicula
 *
 * \param pelicula void*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int asignarGenero(void* pelicula);
/** \brief funcion que sirve para filtrar por genero comedia
 *
 * \param pelicula void*
 * \return int devuelve 0 si hubo un errror, 1 si salio todo bien
 *
 */
int filterComedia(void* pelicula);
/** \brief funcion que sirve para filtrar por genero accion
 *
 * \param pelicula void*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int filterAccion(void* pelicula);
/** \brief funcion que sirve para filtrar por genero terror
 *
 * \param pelicula void*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int filterTerror(void* pelicula);
/** \brief funcion que sirve para filtrar por genero drama
 *
 * \param pelicula void*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int filterDrama(void* pelicula);
/** \brief menu para decidir que genero queres filtrar
 *
 * \return int
 *
 */
int menuGenero();
/** \brief funcion que ordena por genero y rating ascendente
 *
 * \param peliA void*
 * \param peliB void*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int compararGeneroRating( void* peliA, void* peliB );
