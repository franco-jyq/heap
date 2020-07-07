#include "heap.h"
#include <stdbool.h>
#include <stdlib.h>

struct heap{
    void** datos;
    size_t tam;
    size_t cant;
    cmp_fun_t cmp;
};

heap_t* heap_crear(cmp_fun_t cmp){

    heap_t* heap = malloc(sizeof(heap_t));
    if(!heap) return NULL;
    heap->cmp = cmp;                

}

