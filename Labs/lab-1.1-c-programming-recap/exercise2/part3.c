/* 
    Write a function that computes min and max of an array 
    using a comparator function:`comparator(a, b)` that returns 
    <0 if `*a < *b`, 0 if equal, >0 if `*a > *b`. The comparator 
    funcion is passed as a parameter to the min

    On success, provide pointers to the first min and first max elements.

    Provide two comparators for tests:

    ```
    int cmp_int32(const void* a, const void* b);
    int cmp_double(const void* a, const void* b);
    ```
    ## Constraints
    * No type punning; treat memory as unsigned char* when moving bytes.
    * Handle `count == 0` robustly.
*/
bool vminmax(const void* base, size_t count, size_t elem_size,
             int (*comparator)(const void*, const void*),
             const void** out_min, const void** out_max);

bool vminmax(const void* base, size_t count, size_t elem_size,
             int (*comparator)(const void*, const void*),
             const void** out_min, const void** out_max) {
    int;


}