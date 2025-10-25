/* 
    Write a function that computes min and max of an array 
    using a comparator function:`comparator(a, b)` that returns 
    <0 if `*a < *b`, 0 if equal, >0 if `*a > *b`. The comparator 
    funcion is passed as a parameter to the min

    On success, provide pointers to the first min and first max elements.

    Provide two comparators for tests:

    ```
    int cmp_int32(const void* a, const void* b);
    int cmp_double(const void* a, const void* b);
    ```
    ## Constraints
    * No type punning; treat memory as unsigned char* when moving bytes.
    * Handle `count == 0` robustly.
*/
bool vminmax(const void* base, size_t count, size_t elem_size,
             int (*comparator)(const void*, const void*),
             const void** out_min, const void** out_max);

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Trova il primo elemento minimo e massimo in un array generico.
 *
 * @param base Puntatore all'inizio dell'array.
 * @param count Numero di elementi nell'array.
 * @param elem_size Dimensione in byte di un singolo elemento.
 * @param comparator Puntatore a una funzione di comparazione.
 * Deve ritornare <0 se *a < *b, 0 se *a == *b, >0 se *a > *b.
 * @param out_min Puntatore a un puntatore in cui verrà memorizzato 
 * l'indirizzo del primo elemento minimo.
 * @param out_max Puntatore a un puntatore in cui verrà memorizzato
 * l'indirizzo del primo elemento massimo.
 * @return true se min e max sono stati trovati (count > 0), false altrimenti.
 */
bool vminmax(const void* base, size_t count, size_t elem_size,
             int (*comparator)(const void*, const void*),
             const void** out_min, const void** out_max) 
{
    if (base == NULL || count == 0 || elem_size == 0 || 
        comparator == NULL || out_min == NULL || out_max == NULL) 
    {
        return false;
    }

    // Cast a `unsigned char` --> dimensione 1 byte.
    const unsigned char* array_start = (const unsigned char*)base;

    // Inizializziamo sia i puntatori al primo elemento dell'array.
    const void* min_ptr = (const void*)array_start;
    const void* max_ptr = (const void*)array_start;

    for (size_t i = 1; i < count; ++i) {
        // Calcoliamo l'indirizzo dell'elemento corrente (i-esimo)
        // Indirizzo = Inizio_Array + (indice * Dimensione_Elemento)
        const void* current_element_ptr = (const void*)(array_start + (i * elem_size));

        // Confronta l'elemento corrente con il minimo.
        if (comparator(current_element_ptr, min_ptr) < 0) {
            min_ptr = current_element_ptr;
        }
        
        // Confronta l'elemento corrente con il massimo.
        if (comparator(current_element_ptr, max_ptr) > 0) {
            max_ptr = current_element_ptr;
        }
    }
    *out_min = min_ptr;
    *out_max = max_ptr;

    return true;
}