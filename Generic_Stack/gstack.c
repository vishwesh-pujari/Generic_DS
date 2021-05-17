// gstack.c - generic stack

#include<stdlib.h>
#include"gstack.h"

/*
    init_stack:
    'nmemb' is the number of elements user wants in the stack
    'size' is the size of each element in bytes. eg sizeof(int), sizeof(char)
    'copy' is a function pointer. It points to a function which accepts 2 arguments which are pointers to 2 objects(int, char, struct, etc)
        User should write an appropriate function which copies whatever there is at the 'source' in the 'destination'
        For this user should first typecast void* into the appropriate 'data_type*' whose stack user is making
*/

void init_gstack(gstack *s, int nmemb, int size, void (*copy)(void* destination, void* source)) {
    
    s->nmemb = nmemb;
    if (s->nmemb <= 0)
        s->nmemb = 0;
    s->top = -size; // MOST IMP: set s->top to -size and not -1 because here we increment s->top according to s->size
    s->size = size;
    if (s->size <= 0)
        s->size = 0;
    s->arr = malloc(s->nmemb * s->size);
    s->copy = copy;
    return;
}

int isEmpty_gstack(gstack *s) {
    if (!s->size || !s->nmemb || !s->arr || s->top / s->size == -1) // number of elements currently in the stack is given by s.top / s.size. This is because we are incrementing and decrementing s.top according to s.size
        return 1;
    return 0;
}

int isFull_gstack(gstack *s) {
    if (!s->size || !s->nmemb || !s->arr || (s->top / s->size) == s->nmemb - 1)
        return 1;
    return 0;
}

/*
    push_stack:
    'data' is pointer to object which user wants to push in stack
*/
void push_gstack(gstack *s, void* data) {
    if (isFull_gstack(s))
        return;
    s->top += s->size; // MOST IMP : Increment s->top according to s->size
    s->copy(s->arr + s->top, data);
    return;
}

/*
    pop_stack:
    Function returns pointer to object which is popped from stack
    Returns NULL if stack is empty
    User should dereference pointer appropriately and store the popped value in another variable
    This is because the content at returned pointer might change afterwards
*/

void* pop_gstack(gstack *s) {
    if (isEmpty_gstack(s))
        return NULL;

    void* ret = s->arr + s->top;
    
    s->top -= s->size;
    return ret;
}

/*
    peek_stack:
    Function returns pointer to object which is at top of the stack
    Returns NULL if stack is empty
    User should dereference pointer appropriately and store the peeked value in another variable
    This is because the content at returned pointer might change afterwards
*/

void* peek_gstack(gstack *s) {
    if (isEmpty_gstack(s))
        return NULL;

    return s->arr + s->top;
}

void destroy_gstack(gstack *s) {
    free(s->arr);
    s->arr = NULL;
    s->size = 0;
    s->top = -1;
    return;
}
