// gstack.h - generic stack

typedef struct gstack {
    void* arr;
    int nmemb;
    int size;
    int top;
    void (*copy)(void* destination, void* source);
}gstack;

/*
    init_stack:
    'nmemb' is the number of elements user wants in the stack
    'size' is the size of each element in bytes. eg sizeof(int), sizeof(char)
    'copy' is a function pointer. It points to a function which accepts 2 arguments which are pointers to 2 objects(int, char, struct, etc)
        User should write an appropriate function which copies whatever there is at the 'source' in the 'destination'
        For this user should first typecast void* into the appropriate 'data_type*' whose stack user is making
*/
void init_gstack(gstack *s, int nmemb, int size, void (*copy)(void* destination, void* source));

/*
    push_stack:
    'data' is pointer to object which user wants to push in stack
*/
void push_gstack(gstack *s, void* data);

/*
    pop_stack:
    Function returns pointer to object which is popped from stack
    Returns NULL if stack is empty
    User should dereference pointer appropriately and store the popped value in another variable
    This is because the content at returned pointer might change afterwards
*/
void* pop_gstack(gstack *s);

/*
    peek_stack:
    Function returns pointer to object which is at top of the stack
    Returns NULL if stack is empty
    User should dereference pointer appropriately and store the peeked value in another variable
    This is because the content at returned pointer might change afterwards
*/
void* peek_gstack(gstack *s);

int isEmpty_gstack(gstack *s);
int isFull_gstack(gstack *s);
void destroy_gstack(gstack *s);
