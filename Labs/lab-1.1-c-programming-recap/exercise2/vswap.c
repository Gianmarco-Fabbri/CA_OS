/* 
    Implement a generic swap function that swaps 
    the content of two objects of `size` bytes may overlap.
*/
#include <stddef.h>

void vswap(void* a, void* b, size_t size);

void vswap(void* a, void* b, size_t size) {
    // Unsigned char = 1 byte like uint_8 but is 
    // better for arbitrary memory access
    unsigned char* p = a;
    unsigned char* q = b;

    while (size--) {
        unsigned char temp = *p;
        *p++ = *q;
        *q++ = temp;
    }
}