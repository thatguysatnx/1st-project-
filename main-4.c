#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct node
{
    int d;
    struct node* next;
};

struct node* top = NULL;

int isfull(struct node* top)
{
    struct node* p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL){
        return 1;
    }
    free (p);
    return 0 ;
}

int isempty (struct node* top)
{
    if (top == NULL){
        return 1;
    }
    return 0 ;
}


struct node* push (struct node* top,int d)
{
    if (isfull(top)){
        printf ("Stack Overflow!");
        
    }
    struct node* newnode  = (struct node* )malloc(sizeof(struct node));
    newnode->d = d;
    newnode->next = top;
    top = newnode;
    return top;
}


int pop(struct node** top)
{
    int d;
    if (isempty(*top)){
        printf("Stack Underflow!");
    }
    
    struct node* ptr = *top;
    *top = (*top)->next;
    int x = (ptr)->d;
    free (ptr);
    return x;
}


int peek (struct node* top)
{
    if (isempty(top)){
        printf ("Stack empty ! ");
        return -1;
    }
    return top->d;
}

void print (struct node* top)
{
    if (isempty(top)){
        printf ("Stack is empty !");
        return ;
    }
    
    while (top!=NULL){
        printf ("%d\t",top->d);
        top = top->next;
    }
}


int main ()
{
    int choice , data;
    printf ("\n");
    printf ("1: push\n");
    printf ("2: pop \n");
    printf ("3: peek \n");
    printf ("4: print \n");
    printf ("5: Quit\n");
    printf ("Enter the choice:");
    scanf ("%d",&choice);
    
    switch(choice){
        case 1: printf ("Enter the element : ");
        scanf ("%d",&data);
        top = push(top,data);
        break;
        
        case 2: printf ("Popped element is %d",pop(&top));
        break;
        
        case 3: printf ("The topmost element is %d",peek(top));
        break;
        
        case 4: print(top);
        break;
        
        case 5: exit (1);
        break;
        
        default: printf ("Enter the correct option:");
                break;
    }
    main ();
    return 0 ;
}