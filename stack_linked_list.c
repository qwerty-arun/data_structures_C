#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *nextNode;
} *top=NULL;

int count = 0;

void push(int data)
{
	struct node* newNode;
	newNode=malloc(sizeof(newNode));
	if(newNode==NULL)
	{
		printf("Stack overflow!\n");
		return;
	}
	newNode->data=data;
	newNode->nextNode=NULL;
	newNode->nextNode=top;
	top=newNode;
        count++;//counts the no. of nodes present in linked list
        printf("Node is Inserted!\n\n");
    }


void pop()
{
	struct node* temp;
    	temp=top;
	if(top==NULL)
	{
		printf("STACK UNDERFLOW! CAN'T PERFORM POP OPERATION");
		return ;
	}
	int val;//some variable to store topmost element
	val=temp->data;
	printf("The popped element: %d",val);
	printf("\n");	
	top=top->nextNode;
	free(temp);
	temp=NULL;
}

void display()
{
	struct node* temp;
	temp=top;
	if(top==NULL)
	{
		printf("STACK UNDERFLOW!");
		return ;
	}
	printf("\nStack elements are: \n");
	while(temp)
	{
		printf("%d--->",temp->data);
		temp=temp->nextNode;
	}
	printf("NULL\n");
	free(temp);
	temp=NULL;

}

void peek()
{
	if(top==NULL)
	{
		printf("THERE ARE NO ELEMENTS IN THE STACK!\n");
		return ;
	}
	else
		printf("%d",top->data);
}

int main()
{
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) {
	printf("\n\n1. Push\n2. Pop\n3. Stack Status\n4. Peek\n5. Exit\n");
	printf("\nEnter your choice : ");
	scanf("%d", &choice);
	switch (choice) {
	
		case 1:
	    		printf("\nEnter the value to insert: ");
	    		scanf("%d", &value);
	    		push(value);
	    		break;
	
		case 2:
	    		printf("Popped element is :\n");
			 pop();
	    		break;
	
		case 3:
	    		display();
	   		break;
	
		case 4:
			peek();
			break;
		
		case 5:
		    	exit(0);
	                break;
	
		default:
	    	printf("\nWrong Choice\n");
	    	break;
	}
    
    }
}
