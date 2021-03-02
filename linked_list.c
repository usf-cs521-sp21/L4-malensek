/**
 * linked_list.c
 *
 * Implements an unsorted linked list with ops insert, append, print, delete.
 * To keep track of list, you'll pass in its head and then update it (if
 * necessary) using double pointers.
 *
 * Compile:  gcc -g -Wall -o linked_list linked_list.c
 * Run:      ./linked_list
 */

#include <stdio.h>
#include <stdlib.h>

struct list_node {
   int data;
   struct list_node *next;
};

/** Insert at the beginning (head) of the list. */
int insert(/* TODO */);

/** Inserts at a particular position in the list. */
int insert_at(/* TODO */);

/** Appends to the end of the list */
int append(/* TODO */);

/** Prints the list contents */
void print(/* TODO */);

/**
 * Deletes a particular value from the list (if there are duplicate values, the
 * first is deleted. */
int delete(/* TODO */);

/** Delete the node at a particular position in the list */
int delete_at(/* TODO */);

/**
 * Locate a particular node. Returns the node index if found, or -1 on failure.
 */
int search(/* TODO */);

// TODO each function should return 0 to indicate success, -1 on failure.

int main(void)
{
    /* start with empty list */
    struct list_node* head = NULL;

    return 0;
}
