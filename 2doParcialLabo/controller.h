#include "LinkedList.h"
#include "peliculas.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListaPelicula);
/** \brief funcion menu principal
 *
 * \return int devuelve la opcion marcada
 *
 */
int menu();
/** \brief funcion que lista todas las peliculas de la Linked list
 *
 * \param pArrayListaPelicula LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_listarPeliculas(LinkedList* pArrayListaPelicula);
/** \brief funcion que muestra solo una pelicula de la linked list
 *
 * \param pelicula ePelicula*
 * \return int devuelve 0 si hubo un errror, 1 si salio todo bien
 *
 */
int mostrarPelicula(ePelicula* pelicula);
/** \brief funcion que guarda en un archivo de texto
 *
 * \param path char*
 * \param pArrayListaPelicula LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListaPelicula);
/** \brief funcion que utiliza map para asignar el rating
 *
 * \param pArrayListaPeliculas LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_mapPeliculas(LinkedList* pArrayListaPeliculas);
/** \brief funcion que utiliza la funcion ll_map para asignar el genero
 *
 * \param pArrayListaPeliculas LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_mapPeliculasGenero(LinkedList* pArrayListaPeliculas);
/** \brief funcion que utilizo para filtrar por genero
 *
 * \param pArrayPelicula LinkedList*
 * \return int
 *
 */
int controller_filtrarGenero(LinkedList* pArrayPelicula);
/** \brief funcion que ordena la lista por genero y luego por rating
 *
 * \param pArrayListaPeliculas LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_ordenarPeliculaGeneroRating(LinkedList* pArrayListaPeliculas);
/** \brief funcion que guarda la informacion en un archivo con el nombre que decide el usuario
 *
 * \param pArrayListaPeliculas LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_guardarArchivo(LinkedList* pArrayListaPeliculas);


