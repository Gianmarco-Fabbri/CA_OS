#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Firma di una funzione di uno stadio della pipeline.
 * * @param x Puntatore al valore che viene processato.
 * @param user Puntatore a dati "utente" generici per configurare lo stadio.
 * 
 * @return true per continuare la pipeline, false per fermarla immediatamente.
 */
typedef bool (*stage_fn)(int32_t* x, void* user);

/**
 * @brief Esegue una pipeline di 'n_stages' stadi su un valore *x.
 * 
 * * @param x Puntatore al valore da processare.
 * @param stages Array (costante) di puntatori a funzioni di stadio.
 * @param users Array (costante) di puntatori a dati utente. users[i]
 * sarà passato a stages[i].
 * @param n_stages Numero di stadi nella pipeline.
 * 
 * @return true se l'intera pipeline è stata eseguita, false se
 * uno stadio ha richiesto un arresto anticipato.
 */
bool run_pipeline(int32_t* x, stage_fn const* stages, void* const* users, size_t n_stages) 
{
    if (x == NULL || stages == NULL) {
        return false;
    }

    for (size_t i = 0; i < n_stages; ++i) 
    {
        // Prendi la funzione dello stadio corrente dall'array
        stage_fn current_stage_func = stages[i];
        
        // Prendi i dati utente corrispondenti per questo stadio
        // (Gestisce il caso in cui l'array 'users' sia NULL o
        // l'entry specifica 'users[i]' sia NULL)
        void* current_user_data = (users != NULL) ? users[i] : NULL;
        
        if (current_stage_func == NULL) {
            fprintf(stderr, "Errore: Stadio %zu della pipeline e' NULL.\n", i);
            return false;
        }

        // Chiama la funzione, con il puntatore a x e i dati utente.
        bool keep_going = current_stage_func(x, current_user_data);
        
        // Se lo stadio ritorna 'false', fermiamo l'intera pipeline.
        if (!keep_going) {
            printf("Pipeline interrotta (early stop) allo stadio %zu.\n", i);
            return false;
        }
    }
    return true;
}

bool stage_add_k(int32_t* x, void* user) {
    // Questo stadio RICHIEDE dati di configurazione.
    if (user == NULL) {
        fprintf(stderr, "Errore (stage_add_k): dati utente (k) non forniti.\n");
        return false;
    }
    
    // 1. Cast: da void* al tipo che *sappiamo* dovrebbe essere (int32_t*)
    int32_t* k_ptr = (int32_t*)user;
    
    int32_t k = *k_ptr;
    
    *x += k;
    
    return true;
}