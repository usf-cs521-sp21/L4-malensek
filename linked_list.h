#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <sys/types.h>

struct list_node; 

/** Insert at the beginning (head) of the list. */
int insert(struct list_node **head, int data);

/** Prints the list contents */
void print(struct list_node *head);

int insert_at(struct list_node **head, int index, int data);

int insert(struct list_node **head, int data);

int append(struct list_node **head, int data);

int search(struct list_node *head, int data);

int delete_at(struct list_node **head, int index);

int delete_data(struct list_node **head, int data);

/**
 * Free the linked list.  
 */
void free_list(struct list_node *head);

#endif
