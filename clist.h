#ifndef _CLIST_H_
#define _CLIST_H_

#include <sys/types.h>

struct clist;
struct clist_iterator {
    unsigned int initialized : 1;
    size_t idx;
};

/**
 * Creates a new circular list with the given capacity and item size.
 */
struct clist *clist_create(size_t capacity, size_t item_sz);

/**
 * Creates a new clist iterator.
 */
struct clist_iterator clist_create_iter(void);

/**
 * Cleans up data structures and any memory associated with the provided clist
 */
void clist_destroy(struct clist *list);

/**
 * Adds a new element to the list by copying the contents pointed to by 'item'
 * into the next available space in the list.
 */
ssize_t clist_add(struct clist *list, void *item);

/**
 * 'Adds' a new element by returning a pointer to the next available space in
 * the list. The element is not cleared, so it may point to
 * previously-initialized data.
 */
void *clist_add_new(struct clist *list);

/**
 * Retrieves element at the provided index, or NULL if not found. Note that this
 * is *NOT* the array index, but rather the circular index (for example, one
 * might retrieve index 682 from a circular list that only stores 5 elements).
 */
void *clist_get(struct clist *list, size_t idx);

/**
 * Starts with the most recently added value to the list and gets the next value.
 * cliet_next and clist_prev are meant to work together. 
 * If clist_next is called and then clist_prev is called the next 
 * and previous values will always be returned. They can be called back and forth indefinitely.
 *
 * clist_next will return NULL once it gets to the last value inserted is reached.
 * The iterator will not be modified at that point 
 * which allows clist_prev to be called to get the prvious element. 
 * clist_prev can be then called get values in the the other direction.
 */ 
void *clist_next(struct clist *list, struct clist_iterator *iter);

/**
 * Gets the previous value from the list working from the first added value to the most recent.
 * cliet_next and clist_prev are meant to work together. 
 * If clist_prev is called imediatly after elements are added to the list
 * clist_prev will return NULL.
 */ 
void *clist_prev(struct clist *list, struct clist_iterator *iter);

/**
 * Iterates through the provided list, starting with the most recent insertion
 * and working backward until the end of the list is reached. Each invocation of
 * the function retrieves the next element, with NULL indicating the end of the
 * list has been reached. 'iter' is used to track state through the iteration.
 */
void *clist_iterate(struct clist *list, struct clist_iterator *iter);

/**
 * Iterates through the provided list, starting with the least-recently inserted
 * element and proceeding forward to the beginning (most recent) element of the
 * list.  NULL indicates the start of the list has been reached. 'iter' is used
 * to track state through the iteration.
 */
void *clist_iterate_rev(struct clist *list, struct clist_iterator *iter);

#endif

/*
 *
Group 0: (Matthew)
struct clist_iterator clist_create_iter(void);

Group 1:
struct clist *clist_create(size_t capacity, size_t item_sz);
void clist_destroy(struct clist *list);

Group 2:
ssize_t clist_add(struct clist *list, void *item);

Group 3:
void *clist_add_new(struct clist *list);

Group 4:
void *clist_get(struct clist *list, size_t idx);

Group 5:
void *clist_iterate(struct clist *list, struct clist_iterator *iter);

Group 6:
void *clist_iterate_rev(struct clist *list, struct clist_iterator *iter);

 */
