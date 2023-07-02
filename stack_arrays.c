#include <stdio.h>
#include <stdlib.h>
void print_stack(int *,int,int);
int main()
{
    int *p = (int *) malloc(10 * sizeof(int));
    int index = 0;
    int size=10;
    while (1) {
        int option;
        printf("Select :\n");
        printf("\t1.POP operation\n");
        printf("\t2.PUSH operation:\n");
        printf("\t3.Peek\n");
        printf("\t4.Stack Status\n");
        printf("\t5.EXIT THE PROGRAM\n");
        scanf("%d", &option);

        switch (option) {

        case 1:
            if (size>=10) {
                printf("Stack underflow! Can't perform pop operation.\n");
            } else {
                index--;
                printf("Popped element: %d\n", p[index]);
                p[index] = '\0';
                size++;
            }
            break;

        case 2:
            if (size ==0) {
                printf
                    ("\nStack overflow! Can't push an element into the stack");
                break;
            } else {
                int no;
                printf("\nEnter element to be pushed into the stack: \n");
                scanf("%d", &no);
                p[index] = no;
                --size;
                ++index;
            }
            break;

        case 3:
            if (size>=10) {
                printf
                    ("There are no elements in stack.\n");
                break;
            } else
                printf("Topmost element: %d\n", p[index-1]);
            break;

        case 4:
        print_stack(p,size,index);
        break;

        case 5:
        return 0;

        default:
            printf("Invalid Input!\n");
            break;
        }
    }

        free(p);
}

void print_stack(int *p,int size,int index)
{
    if(size==10)
    {
            printf("There are no elemets in the stack.\n");
           return;
    }
    printf("The elements in the present stack are: \n");
    for (int i = 0; i <index; i++) {
        printf("%d\n", p[i]);
    }
}
