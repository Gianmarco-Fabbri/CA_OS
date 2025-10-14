#include <stdint.h>
#include <stddef.h>

void write16(uint8_t *buf, uint16_t value) {
    *buf = (uint8_t)(value & 0xFF);
    *(buf + 1) = (uint8_t)(value >> 8);
}

const uint16_t read16(const uint8_t *buf) {
    return (*(buf + 1) << 8) | *buf;
}

void *my_memcpy(void *dest, const void *src, size_t n) {
    if(n <= 0) return;
    *dest = *src;
    uint8_t *end_exclusive = (uint8_t)src + n;
    
    while(++src < end_exclusive) {
        *dest = *src;
        dest++;
    }
}

size_t count_byte(const void *buf, size_t len, uint8_t value) {
    size_t count = 0;
    const uint8_t *p = (const uint8_t *)buf;
    const uint8_t *end = p + len;

    while (p < end) {
        if (*p == value) count++;
        p++;
    }
    return count;
}