#include<stdio.h>
#include<stdlib.h>
#include "testing.h"
#include "heap.h"

/* Funcion de comparacion auxiliar */
int cmp_int (const void* prim,const void* seg){
    if (*(int*)prim > *(int*)seg) return 1;
    if (*(int*)prim < *(int*)seg) return -1;
    return 0;
}

void prueba_heap_vacio(){
    printf("INICIO PRUEBA HEAP VACIO \n");
    
    /*Creo el heap*/
    heap_t* heap = heap_crear(cmp_int);
    
    /*Pruebas heap vacio*/
    print_test("Se creo el heap", heap != NULL);
    print_test("La cantidad de elementos es 0", heap_cantidad(heap) == 0);
    print_test("Desencolar devuelve NULL", heap_desencolar(heap) == NULL);
    print_test("Ver el maximo devuelve NULL", heap_ver_max(heap) == NULL);
    print_test("El heap esta vacio", heap_esta_vacio(heap));
    
    /*Destruyo el heap*/
    heap_destruir(heap, NULL);
    print_test("Se destruyo el heap vacio", true);
}

void prueba_heap_vacio_alternativa(){
    printf("INICIO PRUEBA HEAP VACIO FORMA ALTERNATIVA \n");
    
    /*Creo el heap con arreglo NULL*/
    heap_t* heap = heap_crear_arr(NULL, 0, cmp_int);
    print_test("Se creo el heap", heap != NULL);
    
    /*Pruebas*/
    print_test("La cantidad de elementos es 0", heap_cantidad(heap) == 0);
    print_test("Desencolar devuelve NULL", heap_desencolar(heap) == NULL);
    print_test("Ver el maximo devuelve NULL", heap_ver_max(heap) == NULL);
    print_test("El heap esta vacio", heap_esta_vacio(heap));
    
    /*Destruyo el heap*/
    heap_destruir(heap, NULL);
    print_test("Se destruyo el segundo heap vacio", true);
}

void prueba_guardar_unitaria (){
    printf("INICIO PRUEBA GUARDAR UNITARIA \n");
    
    /*Creo el heap*/
    heap_t* heap = heap_crear(cmp_int);
    print_test("Se creo el heap", heap != NULL);
    
    /*Declaro variable*/
    int dato1 = 1;

    /*Pruebas unitarias*/
    print_test("Se puedo encolar en el heap",heap_encolar(heap,&dato1));
    print_test("La cantidad de elementos es 1",heap_cantidad(heap) == 1);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el elemento",heap_ver_max(heap) == &dato1);
    print_test("Desencolar devuelve el elemento",heap_desencolar(heap) == &dato1);
    
    /*Destruyo el heap*/
    heap_destruir(heap,NULL);
    print_test("Se destruyo el heap",true);  
}

void prueba_guardar_varios_elementos (){
    printf("INICIO PRUEBA GUARDAR VARIOS \n");
    
    /*Creo el heap*/
    heap_t* heap = heap_crear(cmp_int);
    print_test("Se creo el heap",heap != NULL);
    
    /*Declaro variables*/
    int dato1 = 1;
    int dato2 = 2;
    int dato3 = 3;

    /*Encolo 3 elementos*/
    print_test("Se puedo encolar el primer elemento en el heap",heap_encolar(heap,&dato1));
    print_test("Se puedo encolar el segundo elemento en el heap",heap_encolar(heap,&dato2));
    print_test("Se puedo encolar el tercer elemento el heap",heap_encolar(heap,&dato3));
    
    /*Pruebas con 3 elementos*/
    print_test("La cantidad de elementos es 3",heap_cantidad(heap) == 3);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el tercer elemento",heap_ver_max(heap) == &dato3);
    
    /*Desencolo*/
    print_test("Desencolar devuelve el tercer elemento",heap_desencolar(heap) == &dato3);
    print_test("La cantidad de elementos es 2",heap_cantidad(heap) == 2);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el segundo elemento",heap_ver_max(heap) == &dato2);
    
    /*Desencolo*/
    print_test("Desencolar devuelve el segundo elemento",heap_desencolar(heap) == &dato2);
    print_test("La cantidad de elementos es 1",heap_cantidad(heap) == 1);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el primer elemento",heap_ver_max(heap) == &dato1);
    
    /*Desencolo*/
    print_test("Desencolar devuelve el primer elemento",heap_desencolar(heap) == &dato1);
    print_test("La cantidad de elementos es 0",heap_cantidad(heap) == 0);
    print_test("El heap no esta vacio",heap_esta_vacio(heap));
    
    /*Destruyo el heap*/
    heap_destruir(heap,NULL);
    print_test("Se destruyo el heap vacio",true);  
}

void prueba_guardar_varios_elementos_alternativa (){
    printf("INICIO PRUEBA GUARDAR VARIOS ALTERNATIVA \n");
    
    /*Creo el heap*/
    heap_t* heap = heap_crear_arr(NULL,0,cmp_int);
    print_test("Se creo el heap",heap != NULL);
    
    /*Inicializo variables*/
    int dato1 = 1;
    int dato2 = 2;
    int dato3 = 3;

    /*Encolo 3 elementos*/
    print_test("Se puedo encolar el primer elemento en el heap",heap_encolar(heap,&dato1));
    print_test("Se puedo encolar el segundo elemento en el heap",heap_encolar(heap,&dato2));
    print_test("Se puedo encolar el tercer elemento el heap",heap_encolar(heap,&dato3));
    
    /*Pruebas con 3 elementos*/
    print_test("La cantidad de elementos es 3",heap_cantidad(heap) == 3);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el tercer elemento",heap_ver_max(heap) == &dato3);
    
    /*Desencolo*/
    print_test("Desencolar devuelve el tercer elemento",heap_desencolar(heap) == &dato3);
    print_test("La cantidad de elementos es 2",heap_cantidad(heap) == 2);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el segundo elemento",heap_ver_max(heap) == &dato2);
    
    /*Desencolo*/
    print_test("Desencolar devuelve el segundo elemento",heap_desencolar(heap) == &dato2);
    print_test("La cantidad de elementos es 1",heap_cantidad(heap) == 1);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el primer elemento",heap_ver_max(heap) == &dato1);
    
    /*Desencolo*/
    print_test("Desencolar devuelve el primer elemento",heap_desencolar(heap) == &dato1);
    print_test("La cantidad de elementos es 0",heap_cantidad(heap) == 0);
    print_test("El heap no esta vacio",heap_esta_vacio(heap));
    
    /*Destruyo el heap*/
    heap_destruir(heap,NULL);
    print_test("Se destruyo el heap vacio",true);  
}

void prueba_heap_alternativo (){
    printf("INICIO PRUEBA HEAP ALTERNATIVO \n");
    
    /*Inicializo variables*/
    int v2[5] = {3,4,10,1,6};
    void** v = malloc(sizeof(int*)*5);
    v[0] = v2;
    v[1] = v2+1;
    v[2] = v2+2;
    v[3] = v2+3;
    v[4] = v2+4;

    /*Creo el heap con arreglo*/
    heap_t* heap = heap_crear_arr(v,5,cmp_int);
    
    /*Pruebas de heap con arreglo*/
    print_test("Se creo el heap",heap != NULL);
    print_test("La cantidad de elementos es 5",heap_cantidad(heap) == 5);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el elemento correcto",heap_ver_max(heap) == v[2]);
    
    /*Desencolo*/
    print_test("Desencolar devuelve el elemento correcto",heap_desencolar(heap) == v[2]);
    print_test("La cantidad de elementos es 4",heap_cantidad(heap) == 4);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el elemento correcto",heap_ver_max(heap) == v[4]);
    
    /*Desencolo*/
    print_test("Desencolar devuelve el elemento correcto",heap_desencolar(heap) == v[4]);
    print_test("La cantidad de elementos es 3",heap_cantidad(heap) == 3);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));    
    print_test("Ver el maximo devuelve el elemento correcto",heap_ver_max(heap) == v[1]);
    
    /*Desencolo*/
    print_test("Desencolar devuelve el elemento correcto",heap_desencolar(heap) == v[1]);
    print_test("La cantidad de elementos es 2",heap_cantidad(heap) == 2);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el elemento correcto",heap_ver_max(heap) == v[0]);
    
    /*Desencolo*/
    print_test("Desencolar devuelve el elemento correcto",heap_desencolar(heap) == v[0]);
    print_test("La cantidad de elementos es 1",heap_cantidad(heap) == 1);
    print_test("El heap no esta vacio",!heap_esta_vacio(heap));
    print_test("Ver el maximo devuelve el elemento correcto",heap_ver_max(heap) == v[3]);
    
    /*Desencolo*/
    print_test("Desencolar devuelve el elemento correcto",heap_desencolar(heap) == v[3]);
    print_test("La cantidad de elementos es 0",heap_cantidad(heap) == 0);
    print_test("El heap esta vacio",heap_esta_vacio(heap));
    
    /*Destruyo el heap*/
    heap_destruir(heap,NULL);
    print_test("Se destruyo el heap vacio",true);
    
    /*Libero el arreglo*/
    free(v);  
}

void prueba_encolar_y_desencolar(){
    printf("INICIO PRUEBAS ENCOLAR Y DESENCOLAR MULTIPLE \n");
    /*Creo el heap*/
    heap_t* heap = heap_crear(cmp_int);
    print_test("Se creo el heap",heap != NULL);
    
    /*Declaro variables*/
    int dato1 = 1;
    int dato2 = 2;
    int dato3 = 3;
    int dato4 = 4;
    int dato5 = 5;

    /*Prueba desencolar y encolar multiple*/
    print_test("encolo el elemento 1", heap_encolar(heap, &dato1));
    print_test("encolo el elemento 3", heap_encolar(heap, &dato3));
    print_test("desencolar devuelve dato 3", heap_desencolar(heap) == &dato3);
    print_test("desencolar devuelve dato 1", heap_desencolar(heap) == &dato1);
    print_test("el heap quedo vacio", heap_esta_vacio(heap));
    print_test("encolo el elemento 2", heap_encolar(heap, &dato2));
    print_test("encolo el elemento 5", heap_encolar(heap, &dato5));
    print_test("encolo el elemento 4", heap_encolar(heap, &dato4));
    print_test("la cantidad es 3", heap_cantidad(heap) == 3);
    print_test("desencolar devuelve el dato 5", heap_desencolar(heap) == &dato5);
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("desencolar devuelve el dato 4", heap_desencolar(heap) == &dato4);
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("desencolar devuelve el dato 2", heap_desencolar(heap) == &dato2);
    print_test("la cantidad es 0", heap_cantidad(heap) == 0);

    /*Destruto el heap*/
    heap_destruir(heap, NULL);
}


void prueba_heapsort(){
    printf("INICIO PRUEBA HEAPSORT \n");
    
    /*Inicializo variables*/
    int v2[5] = {3,4,10,1,6};
    void** v = malloc(sizeof(int*)*5);
    v[0] = v2;
    v[1] = v2+1;
    v[2] = v2+2;
    v[3] = v2+3;
    v[4] = v2+4;

    /*Hago heapsort del arreglo*/
    heap_sort(v, 5, cmp_int);
    
    /*Pruebas*/
    int  min = *(int*)v[0];
    bool todo_ok = true;
    for(int x = 0; x < 5; x++){
        if(*(int*)v[x] < min) todo_ok = false;
        min = *(int*)v[x];
    }
    print_test("El arreglo quedo ordenado", todo_ok == true);
    
    /*Libero el arreglo*/
    free(v);
}

void prueba_volumen_sin_arreglo(){
    printf("INICIO PRUEBA VOLUMEN SIN ARREGLO \n");
    
    /*Creo el heap*/
    heap_t* heap = heap_crear(cmp_int);
    
    /*Inicializo variables*/
    bool todo_ok = true;
    int v[5000];
    for(int x = 0; x < 5000; x++){
        v[x] = x;
    }

    /*Pruebas*/
    for(size_t x = 0; x < 5000; x++){
        heap_encolar(heap, v + x);
    }
    for(size_t x = 0; x < 5000; x++){
        if(heap_desencolar(heap) != v + 4999 -x)todo_ok = false;  
    }
    print_test("Se desencolaron todos los elementos en el orden correcto", todo_ok);
    
    /*Destruyo el heap*/
    heap_destruir(heap, NULL);
}

void prueba_volumen_con_arreglo(){
    printf("INICIO PRUEBA VOLUMEN CON ARREGLO \n");
    
    /*Inicializo variables*/
    bool todo_ok = true;
    void** arr = malloc(sizeof(void*)* 10);
    int v[5000];    
    
    for(int x = 0; x < 5000; x++){
        v[x] = x;
    }
    
    for(int x = 0; x < 10; x++){
        arr[x] = v + x;
    }

    /*Creo el heap*/
    heap_t* heap = heap_crear_arr(arr, 10, cmp_int);
    
    /*Pruebas*/
    for(size_t x = 10; x < 5000; x++){
        heap_encolar(heap, v + x);
    }

    for(size_t x = 0; x < 5000; x++){
        if(heap_desencolar(heap) != v + 4999 -x)todo_ok = false;  
    }
    
    print_test("Se desencolaron todos los elementos en el orden correcto", todo_ok);
    
    /*Destruyo el heap*/
    heap_destruir(heap, NULL);
    
    /*Libero el arreglo*/
    free(arr);
}

void prueba_con_funcion_destruir(){
    printf("PRUEBA CON FUNCION DESTRUIR \n");
    /*Creo el heap*/
    heap_t* heap = heap_crear(cmp_int);

    /*Inicializo variables*/
    int* a = malloc(sizeof(int));
    *a = 1; 
    int* b = malloc(sizeof(int));
    *b = 2;
    int* c = malloc(sizeof(int)); 
    *c = 3;

    /*Encolo los elementos*/
    print_test("Se puedo encolar el primer elemento en el heap",heap_encolar(heap, a));
    print_test("Se puedo encolar el segundo elemento en el heap",heap_encolar(heap, b));
    print_test("Se puedo encolar el tercer elemento en el heap",heap_encolar(heap, c));

    /*Destruyo con funcion*/
    heap_destruir(heap, free);
    print_test("Se destruyo correctamente con funcion destruir", true);


}

void pruebas_heap_alumno(void){
    
    prueba_heap_vacio();
    prueba_guardar_unitaria();
    prueba_guardar_varios_elementos();
    prueba_heap_vacio_alternativa();    
    prueba_guardar_varios_elementos_alternativa (); 
    prueba_heap_alternativo ();
    prueba_encolar_y_desencolar();
    prueba_heapsort();
    prueba_volumen_sin_arreglo();
    prueba_volumen_con_arreglo();
    prueba_con_funcion_destruir();
}