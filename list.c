#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * TODO: Returns the tail of the linked list.
 */
struct ll_node *ll_tail(struct ll_node *head) {
        if (head == NULL) {
        return NULL;
}
struct ll_node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    return curr;
}
/**
 * TODO: Returns the number od nodes in the Linked List. 
 */
int ll_size(struct ll_node *head) {
  int count = 0;
    struct ll_node *curr = head;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    return count;
}

/**
 * TODO: Searches the linked list for the first node whose data equals value
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    struct ll_node *curr = head;

    while (curr != NULL) {
        if (curr->data == value) {
            return curr;
        }
        curr = curr->next;
    }

    return NULL;
}

/**
 * TODO: Converts the linked list into a dynamically allocated array of integers
 */
int *ll_toarray(struct ll_node *head) {
    int size = ll_size(head);
    if (size == 0) {
        return NULL;
    }

    int *arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        // Allocation failed
        return NULL;
    }

    struct ll_node *curr = head;
    for (int i = 0; i < size; i++) {
        arr[i] = curr->data;
        curr = curr->next;
    }

    return arr;
}

/**
 * TODO: Creates a new linked list node with the given data
 */
struct ll_node *ll_create(int data) {
     struct ll_node *node = malloc(sizeof(struct ll_node));
    if (node == NULL) {
        return NULL;
    }

    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * TODO: Frees up all nodes in the linked list 
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *curr = head;

    while (curr != NULL) {
        struct ll_node *next = curr->next;
        free(curr);
        curr = next;
    }
}

/**
 * TODO: Appends a new node with the given data to the tail of an existing lisy 
 */
void ll_append(struct ll_node *head, int data) {
  if (head == NULL) {
        return;
    }

    struct ll_node *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    struct ll_node *new_node = ll_create(data);
    if (new_node == NULL) {
        // Allocation failed; do nothing.
        return;
    }

    tail->next = new_node;
}

/**
 * TODO: Creates a linked list from a given array 
 */
struct ll_node *ll_fromarray(int* data, int len) {
 if (data == NULL || len <= 0) {
        return NULL;
    }

    struct ll_node *head = NULL;
    struct ll_node *tail = NULL;

    for (int i = 0; i < len; i++) {
        struct ll_node *node = ll_create(data[i]);
        if (node == NULL) {
            // Clean up already created nodes
            ll_destroy(head);
            return NULL;
        }

        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

/**
 * TODO: Removes the first node in the list whose data equals value 
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
 if (head == NULL) {
        return NULL;
    }

    // Case 1: head needs to be removed
    if (head->data == value) {
        struct ll_node *new_head = head->next;
        free(head);
        return new_head;
    }

    // Case 2: remove from middle/end
    struct ll_node *prev = head;
    struct ll_node *curr = head->next;

    while (curr != NULL) {
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            break;  // only remove the first matching node
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

