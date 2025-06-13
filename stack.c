#include "stack.h"

#define MAX_SIZE 100  //Tamano estatico 

static unsigned int stack[MAX_SIZE];  //Arreglo que guarda los datos
static int top = -1;  // indice del último elemento (

//Inicializa el stack, lo deja vacío
void stack_init() {
    top = -1;
}

//Se anade un elemento al stack (devuelve 0 si se puede o -1 si etsa lleno)
int stack_push(unsigned int data) {
    if (stack_is_full()) {  // Si está lleno, no se puede añadir
        return -1;
    }
    stack[++top] = data;  // Añade el dato y aumenta `top`
    return 0;
}

// SE saca un elemento del stack
int stack_pop() {
    if (stack_is_empty()) {  //Si esta vacio, devuelve -1 y no se puede sacar nada
        return -1;
    }
    return stack[top--];  //Devuelve el dato y disminuye la variable top
}

// Devuelve cuantos elementos hay en el stack
unsigned int stack_size() {
    return top + 1;  // top empieza en -1, así que +1
}

//Verifica si el stack está lleno (1: lleno, 0: no lleno)
int stack_is_full() {
    return top == MAX_SIZE - 1;  // Si `top` llega al máximo
}

//Verifica si el stack está vacío (1: vacío, 0: no vacío)
int stack_is_empty() {
    return top == -1;  // Si `top` es -1, está vacío
}