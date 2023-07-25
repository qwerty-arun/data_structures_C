#include <stdio.h>
#include <stdlib.h>
        struct node{
        int data;
        struct node* next;
        };
void display(struct node** root,const int*);
void peek(struct node**);
void pop(struct node**,int*);
void push(int ,struct node**,int*);
void delete(struct node** head,int *,int n);
void insert(struct node**,int *,int,int);
int search(struct node**,int);
void middle(struct node**,const int);
struct node* create_node(int data)
{

        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Failed to allocate memory!\n");
                return NULL;
        }
        temp->data=data;
        return temp;
}

void insert(struct node** head,int* no_elements,int data,int n)
{
        (*no_elements)++;
        struct node* temp=create_node(data);
                //temp->data=data;
                temp->next=NULL;
        if(n==1)
        {
                temp->next=*head;
                *head=temp;
                display(head,no_elements);
                return;
        }
        else
        {
                struct node* temp1=*head;
                for(int i=0;i<n-2;i++)
                        {
                        temp1=temp1->next;
                        }
                temp->next=temp1->next;
                temp1->next=temp;
        }
        display(head,no_elements);
}

void delete(struct node** head,int* no_elements,int n)
{
        struct node* temp=*head;
        if(n==1)//if we are trying to delete the first element
        {
                (*no_elements)--;
                struct node* temp1=*head;
                (*head)=(*head)->next;
                free(temp1);
                temp1=NULL;
                display(head,no_elements);
        }
        else
        {
                (*no_elements)--;
        for(int i=0;i<n-2;i++)//going to (n-1)th node
        {
                temp=temp->next;
        }
        struct node* temp1=temp->next;
        temp->next=(temp->next)->next;
        free(temp1);
        temp1=NULL;
        display(head,no_elements);
        }
}
int search(struct node** root,int n)
{
        struct node* temp=*root;
        int f=0;
        while(temp->next!=NULL)
        {
                if(temp->data==n)
                {
                        f=1;
                }
                temp=temp->next;
        }
        return f;
}
void push(int data,struct node** root,int* no)
{
        (*no)++;
        struct node* new=create_node(data);
        new->data=data;
        new->next=*root;
        *root=new;
        display(root,no);
        /*root->next=new;
        root=new;
        new->data=data;
        new->next=NULL;*/
        //display(root);
}
void display(struct node** head,const int* no)
{
        if((*head)->next==NULL && *no==0)
        {
                printf("There are no elements present in the stack!\n");
        return;
        }
        printf("The no. of elements in the stack: %d\n\n",*no);
        struct node* temp=*head;
        printf("The Stack: \n\n");
        printf("|%4d| <-- TOP\n",temp->data);
        printf("+----+\n");
        temp=temp->next;
        while(temp->next!=NULL)
        {
                printf("|%4d|\n",temp->data);
                printf("+----+\n");
                temp=temp->next;
        }
}

void pop(struct node** root,int* no)
{

        (*no)--;
        int val;
        struct node* temp=*root;
        val=temp->data;
        printf("The popped element: %d\n",val);

        (*root)=(*root)->next;
        free(temp);
        display(root,no);
}

void peek(struct node** root)
{
        printf("The topmost element: %d\n",(*root)->data);
}

void middle(struct node** head,const int no)
{
                struct node* temp=*head;
                if(no%2!=0)
                {
                        int c=0;
                        while(c<no/2)
                        {
                                temp=temp->next;
                                c++;
                        }
                                printf("The middle element in the linked list is: %d\n",temp->data);
                }
                else
                {
                        int i=0;
                        while(i<((no/2)-1))
                        {
                                temp=temp->next;
                                i++;
                        }
                                printf("The middle elements in the linked list is: %d and %d\n",temp->data,(temp->next)->data);
                }
}
int main()
        {
        int no_elements=0;int choice, value;
        struct node* head=(struct node*)malloc(sizeof(struct node));
        if(head==NULL)
        {
                printf("Failed to allocate memory to head node!\n");
                exit(EXIT_FAILURE);
        }
        printf("--------STACK IMPLEMENTATION USING LINKED LIST--------");
        while (1) {
        printf("\n1. Push\n2. Pop\n3. Stack Status\n4. Peek\n5. Search for an element\n6. Insert at nth position\n7. Delete an element at nth position\n8. Display Middle element\n9. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {

                case 1:
                        if(no_elements<10){
                        printf("\nEnter the value to insert: ");
                        scanf("%d", &value);
                        push(value,&head,&no_elements);}
                        else
                        {
                                printf("STACK OVERFLOW! Maximum size of stack is 10\n");
                        }
                        break;

                case 2:
                        if(no_elements==0)
                        {
                                printf("STACK UNDERFLOW!\n");
                        }
                        else
                        pop(&head,&no_elements);
                        break;

                case 3:
                        if(no_elements==0)
                        {
                                printf("STACK UNDERFLOW!\n");
                        }
                        else
                        display(&head,&no_elements);
                        break;

                case 4:
                        if(no_elements==0)
                        {
                                printf("STACK UNDERFLOW!\n");
                        }
                        else
                        peek(&head);
                        break;

                case 5:
                        int n;
                if(no_elements==0)
                {
                printf("There are no elements in the stack!\n");
                }
                else{
                        printf("Enter a no. to be searched:\n");
                        scanf("%d",&n);
                        int f=search(&head,n);
                        if(f==1)
                        {
                                printf("Element %d is present in the stack!\n",n);
                        }
                        else
                                printf("Element %d is NOT present in the stack.\n",n);}
                        break;

                case 6:
                        if(no_elements==10)
                        {
                                printf("STACK OVERFLOW!\n");
                        }
                        else
                        {
                        int value;
                        int pos;
                        printf("Enter the position: \n");
                        scanf("%d",&pos);
                        if(pos>no_elements+1 || pos<=0)
                        {
                                printf("Enter a valid position! (1 to %d)\n",no_elements+1);
                        }
                        else
                        {
                                        printf("Enter the element to be inserted: \n");
                        scanf("%d",&value);
                        insert(&head,&no_elements,value,pos);
                        }
                        }
                        break;

                case 7:
                        if(no_elements==0)
                        {
                                printf("STACK UNDERFLOW!\n");
                        }
                        else
                        {
                        int position;
                        printf("Enter the postion at which an element is to be deleted (1 to %d)\n",no_elements);
                        scanf("%d",&position);
                        if(position<=0 || position>no_elements)
                        {
                                printf("Enter a valid position!\n");
                        }
                        else
                        delete(&head,&no_elements,position);
                        }
                        break;
                case 8:
                        if(no_elements==0)
                        {
                                printf("There are NO elements in the stack!\n");
                        }
                        else
                        {
                                middle(&head,no_elements);
                        }
                        break;
                case 9:
                        exit(0);
                        break;

                default:
                printf("\nWrong Choice\n");
                break;
        }

    }
free(head);
return 0;
}
