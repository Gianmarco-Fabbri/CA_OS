/* 
Write a function that returns a pointer to the first occurrence 
of byte `needle` in [buf, buf+len), or NULL if not found. 

Use only pointer arithmetic (no [] indexing).
If you are unfamiliar with what uint8_t means, 
please check [https://sourceware.org/glibc/manual/latest/html_mono/libc.html]
// (https://sourceware.org/glibc/manual/latest/html_mono/libc.html). 
// These types of data are often used in embedded OS.
*/

#include <stdint.h>
#include <stddef.h>

const uint8_t* memscan8(const void* buf, size_t len, uint8_t needle);

const uint8_t* memscan8(const void* buf, size_t len, uint8_t needle) {
    const uint8_t *p = (const uint8_t*)buf;
    const uint8_t *end = (const uint8_t*)buf + len;

    while(p < end) {
        if (*p == needle) return p;
        p++;
    }
    
    return NULL;
}