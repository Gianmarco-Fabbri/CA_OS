/* 
Implement the following functions:

    - Insert a new element in the list: 
    - Removes the first occurrence of `value`. Returns true if removed.
    - Free the entire list; sets *head to NULL.

## Constraints
* Absolutely no memory leaks.
* Functions must be total: accept head == NULL gracefully where sensible.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>

typedef struct node {
    int value;
    struct node* next;
} node;

void list_push_front(node** head, int value) {
    if (head == NULL) {
        return;
    }

    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        return;
    }

    new_node->value = value;
    new_node->next = *head;

    *head = new_node;
}

bool list_remove_first(node** head, int value) {
    if (head == NULL || *head == NULL) {
        return false;
    }

    if ((*head)->value == value) {
        node* to_free = *head;
        *head = (*head)->next;
        free(to_free);
        return true;
    }

    node* current = *head;
    
    while (current->next != NULL && current->next->value != value) {
        current = current->next;
    }

    if (current->next == NULL) {
        return false;
    }

    node* to_free = current->next;
    
    current->next = to_free->next;
    
    free(to_free);
    return true;
}

void list_free(node** head) {
    if (head == NULL) return;
    
    node* current = *head;
    node* next_node = NULL;
    
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    
    *head = NULL;
}

