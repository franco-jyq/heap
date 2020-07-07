#include "heap.h"
#include <stdbool.h>
#include <stdlib.h>
#define TAMANIO_INICIAL 50

struct heap{
    void** datos;
    size_t tam;
    size_t cant;
    cmp_func_t cmp;
};

heap_t* heap_crear(cmp_func_t cmp){
    heap_t* heap = malloc(sizeof(heap_t));
    if (!heap) return NULL;
    heap->tam = TAMANIO_INICIAL;
    heap->datos = malloc(sizeof(void*)*heap->tam);
    if (!heap->datos){
        free(heap);
        return NULL;
    }
    heap->cmp = cmp;
    heap->cant = 0;
    return heap;
}

void heapify (void** datos,cmp_func_t cmp,size_t final){
    for (size_t i = final / 2; i >= 0;i--){
        downheap(datos,cmp,i,final);
    }
}

heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp){
    heap_t* heap = malloc(sizeof(heap_t));
    if (!heap) return NULL;
    heap->datos = malloc(sizeof(void*)*n);
    if (!heap->datos){
        free(heap);
        return NULL;
    }
    for (size_t i = 0;i < n;i++){
        heap->datos[i] = arreglo[i];
    }
    heapify(heap->datos,cmp,n-1);
    heap->tam = n;
    heap->cant = n;
    heap->cmp = cmp;
    return heap;
}

void heap_destruir(heap_t *heap, void (*destruir_elemento)(void *e)){
    for (size_t i = 0;i < heap->tam;i++){
        if (destruir_elemento) destruir_elemento(heap->datos[i]);
    }
    free(heap->datos);
    free(heap);
}

size_t heap_cantidad(const heap_t *heap){
    return heap->cant;
}

bool heap_esta_vacio(const heap_t *heap){
    return heap->cant == 0;
}

bool heap_redimensionar(heap_t* heap){
    if (heap->tam == TAMANIO_INICIAL) return true;
    return true;
}

void upheap (void** datos,cmp_func_t cmp,size_t actual){
    if (actual < 0) return;
    size_t padre = (actual - 1) / 2;
    void* aux = NULL;
    if (padre >= 0 && cmp(datos[actual],datos[padre]) > 0){
        aux = datos[actual];
        datos[actual] = datos[padre];
        datos[padre] = aux;
        upheap (datos,cmp,padre);
    }
}

bool heap_encolar(heap_t *heap, void *elem){
    heap->cant++;
    if (!heap_redimensionar(heap)) return false; 
    heap->datos[heap->cant - 1] = elem;
    upheap (heap->datos,heap->cmp,heap->cant - 1);
    return true;
}

void *heap_ver_max(const heap_t *heap){
    if (heap_esta_vacio(heap)) return NULL;
    return heap->datos[0];
}

void downheap(void** datos,cmp_func_t cmp,size_t actual,size_t cant){
    if (actual > cant) return;
    size_t hijo_izq = 2 * actual + 1;
    size_t hijo_der = 2 * actual + 2;
    size_t hijo_mas_grande = hijo_izq;
    if (hijo_der <= cant){
        if (cmp(datos[hijo_izq],datos[hijo_der]) < 0) hijo_mas_grande = hijo_der;
    }                   
    if (hijo_mas_grande <= cant && cmp(datos[actual],datos[hijo_mas_grande] < 0)){
        void* aux = datos[hijo_mas_grande];
        datos[hijo_mas_grande] = datos[actual];
        datos[actual] = aux;
        downheap(datos,cmp,hijo_mas_grande,cant);
    }
}

void *heap_desencolar(heap_t *heap){
    if (heap_esta_vacio(heap)) return NULL;
    void* dato = heap->datos[0];
    heap->cant--;
    heap->datos[0] = heap->datos[heap->cant];
    downheap(heap->datos,heap->cmp,0,heap->cant - 1);    
    heap_redimensionar(heap);
    return dato;
}

void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp){
    heapify(elementos,cmp,cant-1);
}