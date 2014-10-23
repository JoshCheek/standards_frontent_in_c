#include <stdio.h>
#include "linked_list.c"

void pass(char* msg) {
  printf("\033[32m%s\033[39m\n", msg);
}

void fail(char* msg) {
  printf("\033[31m%s\033[39m\n", msg);
}

#define assert(name, boo) \
  if(boo) { pass(name); } \
  else     { fail(name); };

void run_linked_list_tests() {
  char* inputs[] = {
    "item1",
    "item2",
    "item3",
  };
  int   num_inputs = sizeof(inputs) / sizeof(char*);
  char* data;

  // after init
  LinkedList *ll = ll_new();
  assert("Starts empty",      ll_is_empty(ll));
  assert("Initial size is 0", ll_size(ll)==0);
  assert("Peek returns null", ll_peek(ll)==NULL);

  // after pushing one item
  ll_push(ll, inputs[0]);
  assert("Is not empty after pushing an item",  !ll_is_empty(ll));
  assert("Has size of 1 after pushing an item", ll_size(ll)==1);
  assert("Peeking returns the item we pushed",  ll_peek(ll)==inputs[0]);

  // after two items
  ll_push(ll, inputs[1]);
  assert("Is not empty after pushing a second item",  !ll_is_empty(ll));
  assert("Has size of 2 after pushing a second item", ll_size(ll)==2);
  assert("Peeking returns the second item",           ll_peek(ll)==inputs[1]);

  // after three items
  ll_push(ll, inputs[2]);
  assert("Is not empty after pushing a third item",  !ll_is_empty(ll));
  assert("Has size of 3 after pushing a third item", ll_size(ll)==3);
  assert("Peeking returns the third item",           ll_peek(ll)==inputs[2]);

  // iterating through the items
  LinkedList_Iterator *iterator;
  int index = num_inputs;
  for(iterator = ll_i_new(ll); !ll_i_is_empty(iterator); ll_i_iterate(iterator)) {
    char test_message[50];
    sprintf(test_message, "It iterates through the list %d", index);
    assert(test_message, inputs[--index] == ll_i_get(iterator));
  }
  assert("It iterated the correct number of times", index==0);
  ll_i_free(iterator);



  // popping an item
  data = ll_pop(ll);
  assert("It is not empty after popping the third item", !ll_is_empty(ll));
  assert("Has size of 2 after popping the third item",   ll_size(ll)==2);
  assert("Peeking returns the second item",              ll_peek(ll)==inputs[1]);

  // cleanup
  ll_free(ll);
}
