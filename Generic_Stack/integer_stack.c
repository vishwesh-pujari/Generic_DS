#include"gstack.h"
#include<stdio.h>
#include<stdlib.h>

int main() {

    gstack s;
    int size;
    printf("Enter size of stack: ");
    scanf("%d", &size);
    init_gstack(&s, size, sizeof(int));

    int input, data, *ptr;

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
                printf("Enter Data: ");
                scanf("%d", &data);
                push_gstack(&s, &data);
                break;

            case 2:
                ptr = pop_gstack(&s);
                if (ptr)
                    printf("%d\n", *ptr);
                else
                    printf("(null)\n");
                break;

            case 3:
                ptr = peek_gstack(&s);
                if (ptr)
                    printf("%d\n", *ptr);
                else
                    printf("(null)\n");
                break;

            case 4:
                printf("%d\n", isEmpty_gstack(&s));
                break;  

            case 5:
                printf("%d\n", isFull_gstack(&s));
                break;

            case 6:
                break;
            
            default:
                printf("Invalid Option\n");
                break;
        }

        getchar(); // clear buffer memory
        printf("Press any key to continue: ");
        getchar();
        
        system("clear");

    } while (input != 6);

    destroy_gstack(&s);

    return 0;
}
