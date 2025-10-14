#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

int main(void) {
    int a[6] = {2, 4, 6, 8, 10, 12};
    int *start = a;             // punta al primo elemento
    int *end_exclusive = a + 6; // one-past-last

    // 1) Stampare in avanti (usa pointer arithmetic)
    printf("Stampo in avanti:\n");
    for (int *p = start; p < end_exclusive; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // 2) Stampare in retrospettiva (partendo dall'ultimo valido)
    printf("Stampo in retrospettiva:\n");
    int *last = end_exclusive - 1; // punta all'ultimo elemento valido
    for (int *p = last; p >= start; p--) {
        printf("%d ", *p);
    }
    printf("\n");

    // 3) Distanza (offset) e confronto
    ptrdiff_t dist = end_exclusive - start; // quanti elementi totali
    printf("Distanza tra end_exclusive e start: %td elementi\n", dist);

    // 4) Esempio di confronto puntatori
    if (start < last) {
        printf("start è prima di last\n");
    }

    return 0;
}

/*
    1.	Scambia il primo e l’ultimo elemento usando solo puntatori (nessun a[0] o a[5]).
*/
void swap_elements(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

/* 
    2.	Trova il massimo in un array scorrendo con puntatori (ritorna il puntatore al massimo).
*/
int *find_max(int *start, int *end_exclusive) {
    if (start == end_exclusive) return NULL;

    int *max = start;
    while (++start < end_exclusive) {
        if (*start > *max) max = start;
    }
    return max;
}

/* 
    3.	Calcola la somma dei primi N elementi usando un puntatore che si muove.
*/
long sum_n(int *start, size_t n) {
    long sum = 0;
    int *end = start + n;
    while (start < end) {
        sum += *start;
        start++;
    }
    return sum;
}