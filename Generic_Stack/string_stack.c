#include"gstack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stringcopy(void* destination, void* source);

int main() {

    gstack s;

    char string[100];

    int size;
    printf("Enter size of stack: ");
    scanf("%d", &size);
    init_gstack(&s, size, sizeof(string), stringcopy);

    int input;
    char *ptr;

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Is Empty\n");
        printf("5. Is Full\n");
        printf("6. Quit\n");

        scanf("%d", &input);

        switch (input) {
            case 1:
                printf("Enter String: ");
                getchar();
                scanf("%[^\n]%*c", string);
                push_gstack(&s, string);
                break;

            case 2:
                ptr = pop_gstack(&s);
                if (ptr)
                    printf("%s\n", ptr);
                else
                    printf("(null)\n");
                getchar(); // clear buffer memory
                break;

            case 3:
                ptr = peek_gstack(&s);
                if (ptr)
                    printf("%s\n", ptr);
                else
                    printf("(null)\n");
                getchar(); // clear buffer memory
                break;

            case 4:
                printf("%d\n", isEmpty_gstack(&s));
                getchar(); // clear buffer memory
                break;  

            case 5:
                printf("%d\n", isFull_gstack(&s));
                getchar(); // clear buffer memory
                break;

            case 6:
                getchar(); // clear buffer memory
                break;
            
            default:
                getchar(); // clear buffer memory
                printf("Invalid Option\n");
                break;
        }

        printf("Press any key to continue: ");
        getchar();
        
        system("clear");

    } while (input != 6);

    destroy_gstack(&s);

    return 0;
}

void stringcopy(void* destination, void* source) { // for making string stack
    char* currDest = (char*) destination;
    char* currSource = (char*) source;

    strcpy(currDest, currSource);
    return;
}
