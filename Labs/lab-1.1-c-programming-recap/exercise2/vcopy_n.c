/* 
    Implement a function that copies `count` elements 
    from `src` to `dst`, each of size `elem_size`.
    The two regions may overlap. 
*/
#include <stddef.h>
#include <stdint.h>

void vcopy_n(void* dst, const void* src, size_t count, size_t elem_size);

void vcopy_n(void* dst, const void* src, size_t count, size_t elem_size) {
    size_t total = count * elem_size;

    const unsigned char *s = (const unsigned char*)src;
    unsigned char *d = (unsigned char*)dst;

    if (d == s || total == 0) return;

    if (d < s) {
        // Copy forward
        while (total--) {
            *d++ = *s++;
        }
    } else {
        // Copy backward to manage overlap
        d += total - 1;
        s += total - 1;
        while (total--) {
            *d-- = *s--;
        }
    }
}