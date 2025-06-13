#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;          //Dato almacenado
    struct Node* next; //Puntero al siguiente nodo
} Node;

static Node* head = NULL;  //Puntero al primer nodo
static unsigned int size = 0;  //Tamaño  de la lista, 0 porque esta vacia

//Inicializa la lista osea, la deja vacía
void linked_list_init() {
    head = NULL;
    size = 0;
}

// Anade un elemento al final; 0: exito, -1: error
int linked_list_append(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));  //Crea un nodo nuevo
    if (new_node == NULL) {  //Si no hay memoria, marca error
        return -1;
    }
    new_node->data = data;
    new_node->next = NULL; //sera el ultimo nodo

    if (head == NULL) {  //Si la lista está vacía, el nuevo nodo es el primero
        head = new_node;
    } else {  // Si no, recorre hasta el final y añade el nodp
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    size++;  // Aumenta el tamaño
    return 0;
}

// Añade un elemento al inicio (0: éxito, -1: error)
int linked_list_prepend(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return -1;
    }
    new_node->data = data;
    new_node->next = head;  //El nuevo nodo apunta al head pasado
    head = new_node;        // head es el nuevo nodo
    size++;
    return 0;
}

// Elimina un elemento (0: exito, -1: no encontrado)
int linked_list_remove(int data) {
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == data) {  // Si encuentra el dato
            if (prev == NULL) {  // Si es el primer nodo
                head = current->next;
            } else {  // Si esta en medio o al final
                prev->next = current->next;
            }
            free(current);  //Libera memoria
            size--;
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return -1;  // No se encontró el dato
}

// Busca un elemento (1: encontrado, 0: no encontrado)
int linked_list_contains(int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Devuelve el tamaño de la lista
unsigned int linked_list_size() {
    return size;
}

// Imprime todos los elementos
void linked_list_print() {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}