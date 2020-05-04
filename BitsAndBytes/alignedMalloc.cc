#include<stdio.h>
#include<stdlib.h>

void *aligned_malloc(size_t size, size_t align)
{
    void *orig = NULL;
    void **aligned = NULL;

    int total = size + align-1 + sizeof(void *);
    
    orig = (void *) malloc(total);

    printf("Orig = 0x%u, align missed by: %d", orig, orig%align);

    if (orig == NULL)
    {
        return NULL;
    } 
 
    aligned = ((uintptr_t)(orig)+total) & ~(align-1)
    
    (uintptr_t)aligned - 1 = orig;

    return aligned;
}

void aligned_free(void *p)
{
    if (p == NULL) return;

    free((void*) *((size_t *)p-1));
}

int main()
{
    int *p = aligned_malloc(20,32);
    aligned_free(p);
}