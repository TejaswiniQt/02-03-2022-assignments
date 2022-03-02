/*******Find whether the  loop is present in the given linked list or not?
 A->B->C->D->E->F->B  ******/

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#define NODES 6

typedef struct node
{
    char data;
    struct node *link;
}sll;

void insert(char data,sll **head)
{
    sll *new=(sll *)malloc(sizeof(sll));
    if(new==NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        new->data=data;
        new->link=NULL;
        
        if(*head==NULL)
        {
            *head = new;
        }
        else
        {
        sll *temp = *head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
        }
    }
}


void display(sll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head;
        printf("List contains:\n");
        while(temp != NULL)
        {
            printf("%c ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void create_loop(sll **head)
{
    sll *temp = *head;
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp->link != NULL)
        {
            temp=temp->link;
        }
        temp->link = (*head)->link;
    }
}



int detect_loop(sll **head)
{
    sll *prev,*next;
    prev = *head;
    next = *head;
    while(prev!=NULL && next!=NULL && next->link!=NULL )
    {
        prev = prev->link;
        next = next->link->link;
        if(prev==next)
        {
            return 1;
        }
    }
    return 0;
    
}


int main()
{
    sll *head=NULL;
    int i=0,result;
    char data;
    while(i++ < NODES)
    {
        printf("Enter a character:");
        __fpurge(stdin);
        scanf("%c",&data);
        insert(data,&head);
    }
    display(&head);
    create_loop(&head);
    result=detect_loop(&head);
    if(result==1)
    printf("Loop is created\n");
    else
    printf("Loop is not created\n");
    
    return 0;
}



