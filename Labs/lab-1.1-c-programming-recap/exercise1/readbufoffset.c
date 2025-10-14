/* 
Write a function that reads an aligned 32-bit little-endian unsigned integer 
from memory at location `buf + offset`.
Little-endian is a byte-ordering scheme in computer architecture where 
the least significant byte (LSB) of a multi-byte data value, such as an 
integer, is stored at the lowest memory address. 

Return true and write to `*out` if success; false if out-of-bounds or misaligned.

What “alignment” means:
	* Every type in C/C++ has an alignment requirement, which is the number of bytes 
        at which objects of that type must be stored in memory.
	* On most architectures, this means the address of an object of that type 
        must be a multiple of its alignment.
	*	`alignof(T)` (or `_Alignof(T)` in pure C11) gives you this alignment 
        requirement at compile time as a constant expression.

You can therefore check the alignment of an address 
by checking if: `(uintptr_t)(buf+offset) % alignof(uint32_t) == 0`.

## Constraints

* Use only pointer increments/decrements when traversing the buffer; no [].
* Avoid strict-aliasing violations. In C, the compiler is allowed to 
    assume that two pointers of different types don’t point to the 
    same memory (they don’t “alias”). This assumption helps the compiler optimize 
    aggressively. Treat buf as const uint8_t* for traversal.
* Don’t read past len, i.e., check the buffer size.
*/
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

bool read_u32_le_aligned(const void* buf, size_t len, size_t offset, uint32_t* out);

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

bool read_u32_le_aligned(const void* buf, size_t len, size_t offset, uint32_t* out) {
    const uint8_t *base = (const uint8_t*)buf;

    if (offset + 4 > len) {
        return false;
    }

    // Check the alignment
    const void *addr = base + offset;
    if ((uintptr_t)addr % alignof(uint32_t) != 0) {
        return false;
    }

    // Read 4 byte in little-endian format
    const uint8_t *p = addr;
    uint32_t value = 0;
    value |= (uint32_t)(*p++);
    value |= (uint32_t)(*p++) << 8;
    value |= (uint32_t)(*p++) << 16;
    value |= (uint32_t)(*p++) << 24;

    *out = value;
    return true;
}