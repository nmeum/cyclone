#ifndef CYCLONE_CK_POLYFILL_H
#define CYCLONE_CK_POLYFILL_H

#include "cyclone/types.h"
#include "cyclone/hashset.h"
#include <stdbool.h>
#include <stdint.h>

void ck_polyfill_init();

// CK Array section
struct ck_array {
  pthread_mutex_t lock;
  hashset_t hs;
}
typedef struct ck_array ck_array_t;

struct ck_array_iterator {
  int unused;
};
typedef struct ck_array_iterator ck_array_iterator_t;

struct ck_malloc {                                                               
  void *(*malloc)(size_t);                                                       
  void *(*realloc)(void *, size_t, size_t, bool);                                
  void (*free)(void *, size_t, bool);                                            
};                                                                               

#define CK_ARRAY_MODE_SPMC 0

// DESCRIPTION
//      The ck_array_init(3) function initializes the array pointed to by the
//      argument array.  The mode value must be CK_ARRAY_MODE_SPMC.  The
//      allocator argument must point to a ck_malloc data structure with valid
//      non-NULL function pointers initialized for malloc, free and realloc. The
//      initial_length specifies the initial length of the array. The value of
//      initial_length must be greater than or equal to 2. An array allows for
//      one concurrent put or remove operations in the presence of any number of
//      concurrent CK_ARRAY_FOREACH operations.
// 
// RETURN VALUES
//      This function returns true if the array was successfully created. It
//      returns false if the creation failed. Failure may occur due to internal
//      memory allocation failures or invalid arguments.
bool
ck_array_init(ck_array_t *array, unsigned int mode,
         struct ck_malloc *allocator, unsigned int initial_length);

// DESCRIPTION
//      The ck_array_put_unique(3) function will attempt to insert the value of
//      pointer into the array pointed to by array.  This function may incur
//      additional memory allocations if not enough memory has been allocated in
//      the array for a new entry. The operation is also free to apply the opera-
//      tion immediately if there is an opportunity for elimination with a pend-
//      ing (uncommitted) remove operation. The function will not make any modi-
//      fications if the pointer already exists in the array.
// 
// RETURN VALUES
//      This function returns 1 if the pointer already exists in the array.  It
//      returns 0 if the put operation succeeded. It returns -1 on error due to
//      internal memory allocation failures.
int
ck_array_put_unique(ck_array_t *array, void *pointer);

// DESCRIPTION
//      The ck_array_remove(3) function will attempt to remove the value of
//      pointer into the array pointed to by array. The operation is also free to
//      apply the operation immediately if there is an opportunity for elimina-
//      tion with a pending (uncommitted) put operation. If no elimination was
//      possible, the function may require to allocate more memory.
// 
// RETURN VALUES
//      This function returns true if the remove operation succeeded. It will
//      return false otherwise due to internal allocation failures or because the
//      value did not exist.
bool
ck_array_remove(ck_array_t *array, void *pointer);


// DESCRIPTION
//      The ck_array_commit(3) function will commit any pending put or remove
//      operations associated with the array. The function may end up requesting
//      the safe reclamation of memory actively being iterated upon by other
//      threads.
// 
// RETURN VALUES
//      This function returns true if the commit operation succeeded. It will
//      return false otherwise, and pending operations will not be applied.
bool
ck_array_commit(ck_array_t *array);


  // TODO:

// Can we safely lock the array, make a copy, and interate over that????
#define CK_ARRAY_FOREACH(a, i, b)       \                                        
  pthread_mutex_lock(&(a->lock));
  size_t *tmp = calloc(a->hs->nitems, sizeof(struct hashset_st));
  int tmpc = a->hs->nitems;
  // TODO: just do this in the loop below, this is unnecessary
  for (unsigned int tmpi = 0, tmpii = 0; tmpi < tmpc; tmpi++) {
    if (a->hs->items != 0 && a->hs->items != 1) {
      tmp[tmpii] = a->hs->items[tmpi];
      tmpii++;
    }
  }
  pthread_mutex_unlock(&(a->lock));
  for (unsigned int _ck_i = 0;
      _ck_i < (a)->active->n_committed &&
      ((*b) = (a)->active->values[_ck_i], 1);
      _ck_i++)                                                                   
                  
// CAS section
bool
ck_pr_cas_ptr(void *target, void *old_value, void *new_value);

bool
ck_pr_cas_int(int *target, int old_value, int new_value);

bool
ck_pr_cas_8(uint8_t *target, uint8_t old_value, uint8_t new_value);

#endif                          /* CYCLONE_CK_POLYFILL_H */
