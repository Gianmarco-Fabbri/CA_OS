#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * @brief Libera la memoria allocata da strsplit.
 * Libera ogni token individuale e poi l'array di token.
 * * @param tokens L'array di token da liberare.
 * @param count Il numero di token nell'array.
 */
void free_split_tokens(char** tokens, size_t count) {
    if (tokens == NULL) {
        return;
    }
    
    for (size_t i = 0; i < count; ++i) {
        free(tokens[i]);
    }
    free(tokens);
}

/**
 * @brief Splits a string 's' in token based on 'delim'.
 *
 * @param s La stringa di input da dividere (const).
 * @param delim Il carattere delimitatore.
 * @param out_tokens Puntatore di output (triplo puntatore) per memorizzare
 *  l'indirizzo del nuovo array di token (char**).
 * @param out_count Puntatore di output per memorizzare il numero di token trovati.
 * 
 * @return 0 in caso di successo, non zero in caso di fallimento 
 */
int strsplit(const char* s, char delim, char*** out_tokens, size_t* out_count) {
    if (s == NULL || out_tokens == NULL || out_count == NULL) {
        return -1;
    }

    *out_tokens = NULL;
    *out_count = 0;
    // The number of tokens is count of delims + 1
    size_t num_tokens = 0;
    const char* p = s;
    while (*p != '\0') {
        if (*p == delim) {
            num_tokens++;
        }
        p++;
    }
    num_tokens++;

    // Allocates the array that it will counts the pointers to tokens
    char** tokens = (char**)malloc(num_tokens * sizeof(char*));
    if (tokens == NULL) {
        return -2;
    }
    for (size_t i = 0; i < num_tokens; ++i) {
        tokens[i] = NULL;
    }

    const char* token_start = s;
    size_t token_index = 0;

    for (p = s; ; p++) {
        if (*p == delim || *p == '\0') {
            size_t token_len = p - token_start;

            char* token_str = (char*)malloc(token_len + 1);
            if (token_str == NULL) {
                // FALLIMENTO! Dobbiamo liberare tutta la memoria allocata finora.
                free_split_tokens(tokens, token_index); // Libera i token già creati
                return -2; // Errore: fallimento malloc
            }

            memcpy(token_str, token_start, token_len);
            token_str[token_len] = '\0';

            tokens[token_index] = token_str;
            token_index++;

            if (*p == '\0') {
                break;
            }
            token_start = p + 1;
        }
    }
    
    *out_count = num_tokens; 
    *out_tokens = tokens;
    return 0;
}