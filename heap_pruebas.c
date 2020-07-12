#include<stdio.h>
#include<stdlib.h>
#include "testing.h"
#include "heap.h"

// Funcion auxiliar
int cmp_int (const void* prim,const void* seg){
    if (*(int*)prim > *(int*)seg) return 1;
    if (*(int*)prim < *(int*)seg) return -1;
    return 0;
}

void prueba_heap_vacio(){
    printf("INICIO PRUEBA HEAP VACIO \n");
    heap_t* heap = heap_crear(cmp_int);
    print_test("Se creo el heap",heap != NULL);
    print_test("La cantidad de elementos es 0",heap_cantidad(heap) == 0);
    print_test("Desencolar devuelve NULL",heap_desencolar(heap) == NULL);
    print_test("Ver el maximo devuelve NULL",heap_ver_max(heap) == NULL);
    print_test("El heap esta vacio",heap_esta_vacio(heap));
    heap_destruir(heap,NULL);
    print_test("Se destruyo el heap vacio",true);
}

void prueba_heap_vacio_alternativa(){
    printf("INICIO PRUEBA HEAP VACIO FORMA ALTERNATIVA \n");
    heap_t* heap = heap_crear_arr(NULL,0,cmp_int);
    print_test("Se creo el heap",heap != NULL);
    print_test("La cantidad de elementos es 0",heap_cantidad(heap) == 0);
    print_test("Desencolar devuelve NULL",heap_desencolar(heap) == NULL);
    print_test("Ver el maximo devuelve NULL",heap_ver_max(heap) == NULL);
    print_test("El heap esta vacio",heap_esta_vacio(heap));
    heap_destruir(heap,NULL);
    print_test("Se destruyo el segundo heap vacio",true);
}

void prueba_guardar_unitaria (){
    printf("INICIO PRUEBA GUARDAR UNITARIA \n");
    heap_t* heap = heap_crear(cmp_int);
    print_test("Se creo el heap",heap != NULL);
    int dato1 = 1;
    print_test("Se puedo encolar en el heap",heap_encolar(heap,&dato1));
    print_test("La cantidad de elementos es 1",heap_cantidad(heap) == 1);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el elemento",heap_ver_max(heap) == &dato1);
    print_test("Desencolar devuelve el elemento",heap_desencolar(heap) == &dato1);
    heap_destruir(heap,NULL);
    print_test("Se destruyo el heap",true);  
}

void prueba_guardar_varios_elementos (){
    printf("INICIO PRUEBA GUARDAR VARIOS \n");
    heap_t* heap = heap_crear(cmp_int);
    print_test("Se creo el heap",heap != NULL);
    int dato1 = 1;
    int dato2 = 2;
    int dato3 = 3;
    print_test("Se puedo encolar el primer elemento en el heap",heap_encolar(heap,&dato1));
    print_test("Se puedo encolar el segundo elemento en el heap",heap_encolar(heap,&dato2));
    print_test("Se puedo encolar el tercer elemento el heap",heap_encolar(heap,&dato3));
    print_test("La cantidad de elementos es 3",heap_cantidad(heap) == 3);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el tercer elemento",heap_ver_max(heap) == &dato3);
    print_test("Desencolar devuelve el tercer elemento",heap_desencolar(heap) == &dato3);
    print_test("La cantidad de elementos es 2",heap_cantidad(heap) == 2);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el segundo elemento",heap_ver_max(heap) == &dato2);
    print_test("Desencolar devuelve el segundo elemento",heap_desencolar(heap) == &dato2);
    print_test("La cantidad de elementos es 1",heap_cantidad(heap) == 1);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el primer elemento",heap_ver_max(heap) == &dato1);
    print_test("Desencolar devuelve el primer elemento",heap_desencolar(heap) == &dato1);
    print_test("La cantidad de elementos es 0",heap_cantidad(heap) == 0);
    print_test("El heap no esta vacio",heap_esta_vacio(heap));
    heap_destruir(heap,NULL);
    print_test("Se destruyo el heap vacio",true);  
}

void prueba_guardar_varios_elementos_alternativa (){
    printf("INICIO PRUEBA GUARDAR VARIOS ALTERNATIVA \n");
    heap_t* heap = heap_crear_arr(NULL,0,cmp_int);
    print_test("Se creo el heap",heap != NULL);
    int dato1 = 1;
    int dato2 = 2;
    int dato3 = 3;
    print_test("Se puedo encolar el primer elemento en el heap",heap_encolar(heap,&dato1));
    print_test("Se puedo encolar el segundo elemento en el heap",heap_encolar(heap,&dato2));
    print_test("Se puedo encolar el tercer elemento el heap",heap_encolar(heap,&dato3));
    print_test("La cantidad de elementos es 3",heap_cantidad(heap) == 3);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el tercer elemento",heap_ver_max(heap) == &dato3);
    print_test("Desencolar devuelve el tercer elemento",heap_desencolar(heap) == &dato3);
    print_test("La cantidad de elementos es 2",heap_cantidad(heap) == 2);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el segundo elemento",heap_ver_max(heap) == &dato2);
    print_test("Desencolar devuelve el segundo elemento",heap_desencolar(heap) == &dato2);
    print_test("La cantidad de elementos es 1",heap_cantidad(heap) == 1);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el primer elemento",heap_ver_max(heap) == &dato1);
    print_test("Desencolar devuelve el primer elemento",heap_desencolar(heap) == &dato1);
    print_test("La cantidad de elementos es 0",heap_cantidad(heap) == 0);
    print_test("El heap no esta vacio",heap_esta_vacio(heap));
    heap_destruir(heap,NULL);
    print_test("Se destruyo el heap vacio",true);  
}

void prueba_heap_alternativo (){
    printf("INICIO PRUEBA HEAP ALTERNATIVO \n");
    int v2[5] = {3,4,10,1,6};
    void** v = malloc(sizeof(int*)*5);
    v[0] = v2;
    v[1] = v2+1;
    v[2] = v2+2;
    v[3] = v2+3;
    v[4] = v2+4;
    heap_t* heap = heap_crear_arr(v,5,cmp_int);
    print_test("Se creo el heap",heap != NULL);
    print_test("La cantidad de elementos es 5",heap_cantidad(heap) == 5);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el elemento correcto",heap_ver_max(heap) == v+2);
    print_test("Desencolar devuelve el elemento correcto",heap_desencolar(heap) == v+2);
    print_test("La cantidad de elementos es 4",heap_cantidad(heap) == 4);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el elemento correcto",heap_ver_max(heap) == v+4);
    print_test("Desencolar devuelve el elemento correcto",heap_desencolar(heap) == v+4);
    print_test("La cantidad de elementos es 3",heap_cantidad(heap) == 3);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));    
    print_test("Ver el maximo devuelve el elemento correcto",heap_ver_max(heap) == v+1);
    print_test("Desencolar devuelve el elemento correcto",heap_desencolar(heap) == v+1);
    print_test("La cantidad de elementos es 2",heap_cantidad(heap) == 2);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el elemento correcto",heap_ver_max(heap) == v);
    print_test("Desencolar devuelve el elemento correcto",heap_desencolar(heap) == v);
    print_test("La cantidad de elementos es 1",heap_cantidad(heap) == 1);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el elemento correcto",heap_ver_max(heap) == v+3);
    print_test("Desencolar devuelve el elemento correcto",heap_desencolar(heap) == v+3);
    print_test("La cantidad de elementos es 0",heap_cantidad(heap) == 0);
    print_test("El heap esta vacio",heap_esta_vacio(heap));
    heap_destruir(heap,NULL);
    print_test("Se destruyo el heap vacio",true);
    free(v);  
}

void prueba_heapsort (){
    
}

void pruebas_heap_alumno(void){
    /*
    prueba_heap_vacio();
    prueba_guardar_unitaria();
    prueba_guardar_varios_elementos();
    prueba_heap_vacio_alternativa();    
    prueba_guardar_varios_elementos_alternativa (); */
    prueba_heap_alternativo ();
}