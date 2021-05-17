// creating a stack of integer pointers

#include"gstack.h"
#include<stdio.h>
#include<stdlib.h>

void intptrcopy(void* destination, void* source);

int main() {

    gstack s;
    
    init_gstack(&s, 3, sizeof(int*), intptrcopy); // creating a stack of int* (integer pointers)

    int a = 10, b = 20;
    int *ptr1 = &a;

    push_gstack(&s, &ptr1); // we have to push ptr1 in stack. So we pass address of ptr1 as we have to pass pointer to object to be pushed in stack

    ptr1 = &b;
    push_gstack(&s, &ptr1);

    int** ret;
    ret = peek_gstack(&s); // peek returns pointer to peeked object. Our object is int*. Hence we must define 'ret' as int**
    printf("%d\n", **ret);

    ret = pop_gstack(&s);
    printf("%d\n", **ret);

    ret = pop_gstack(&s);
    printf("%d\n", **ret);

    destroy_gstack(&s);

    return 0;
}

void intptrcopy(void* destination, void* source) { // for making integer pointer stack

    // destination and source are pointers to object. Our object is int*. Hence we must typecast both to int**

    int** currDest = (int**) destination;
    int** currSource = (int**) source;

    *currDest = *currSource;
    return;
}
