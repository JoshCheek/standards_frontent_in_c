#include <stdlib.h>

typedef struct node {
  struct node* successor;
  void*        data;
} Node;

typedef struct {
  Node* head;
  int   size;
} LinkedList;

LinkedList* ll_new();
void  ll_free(LinkedList*);

int   ll_size(LinkedList* ll);
int   ll_is_empty(LinkedList* ll);

void  ll_push(LinkedList* ll, void*);
void* ll_pop(LinkedList* ll);
void* ll_peek(LinkedList* ll);

// eventually might be nice to provide iterators
// apparently fibers can do this: https://en.wikipedia.org/wiki/Setcontext
// there's also libs like:        https://github.com/stevedekorte/coroutine/blob/master/samples/twoCoroTest.c

LinkedList* ll_new() {
  LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));
  ll->head       = NULL;
  ll->size       = 0;
  return ll;
}

void ll_free(LinkedList* ll) {
  while(!ll_is_empty(ll))
    ll_pop(ll);
  free(ll);
}

int ll_size(LinkedList* ll) {
  return ll->size;
}

int ll_is_empty(LinkedList* ll) {
  return ll_size(ll) == 0;
}

Node* new_node(Node* successor, void* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  if(node) {
    node->successor = successor;
    node->data      = data;
  }
  return node;
}

void ll_push(LinkedList* ll, void* to_add) {
  ll->size++;
  ll->head = new_node(ll->head, to_add);
}

void* ll_peek(LinkedList* ll) {
  if(ll_is_empty(ll))
    return NULL;
  else
    return ll->head->data;
}

void* ll_pop(LinkedList* ll) {
  // TODO: this is wrong when empty
  Node* n         = ll->head;
  ll->head        = n->successor;
  void* to_return = n->data;
  free(n);
  ll->size--;
  return to_return;
}
