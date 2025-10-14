/* 
Write a function that reverses a buffer in-place. Operate via two moving pointers; no indexing.
```
void memrev(void* buf, size_t len);
```
*/
#include <stdint.h>
#include <stddef.h>

void memrev(void* buf, size_t len) {
    for (uint8_t *p = buf, *q = (uint8_t*)buf + len - 1; p < q; p++, q--) {
        uint8_t tmp = *p;
        *p = *q;
        *q = tmp;
    }
}