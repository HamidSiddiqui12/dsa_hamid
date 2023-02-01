#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void display(struct node* headptr){
    struct node* p = headptr;
    struct node* q = headptr;
    while(headptr!=NULL)
    {
        printf("%d ", headptr->data);
        headptr = headptr->next;
    }

    printf("\n");
    
    while (p->next != NULL)
    {
        p = p->next;
    }
    
    while (p != q){
        printf("%d ", p->data);
        p = p->prev;       
    }
    printf("%d ", p->data);
    
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = fourth;
    third->prev = second;

    fourth->data = 4;
    fourth->next = NULL;
    fourth->prev = third;

    display(head);

    return 0;
}