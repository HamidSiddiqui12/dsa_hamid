#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void display(struct node* headptr) {
    struct node* ptr = headptr;

    do{

        printf("%d ", ptr->data);
        ptr = ptr->next;

    } while (ptr != headptr);
    
    printf("\n");
}

//Insertion in circular linked list
struct node* insert_At_first(struct node* headptr, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = headptr->next;
    ptr->data = data;

    while (p->next!=headptr)
    {
        p = p->next;
    } //At this point "p" is pointing towards last node

    p->next = ptr;
    ptr->next = headptr;
    headptr = ptr;
 
    return headptr;
}

struct node* insert_at_end(struct node* headptr, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = headptr->next;
    ptr->data = data;

    while (p->next != headptr)
    {
        p = p->next;
    }
    
    p->next = ptr;
    ptr->next = headptr;

    return headptr;
}

struct node* insert_in_between(struct node* headptr, int data, int index) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* q = headptr;
    struct node* p = headptr->next;
    ptr->data = data;
    int i = 0;

    while (i!=index-1)
    {
        q = q->next;
        p  = p->next;
        i++;
    }
    
    q->next = ptr;
    ptr->next = p; 

    return headptr;
}

struct node* insert_at_given(struct node* headptr, int data, int valueptr){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    struct node* p = headptr;
    struct node* q = headptr->next;

    while (q->data != valueptr)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = ptr;
    ptr->next = q;

    return headptr;
}

//Insertion in circular linked list
struct node* deletion_at_first(struct node* headptr) {
    struct node* p = headptr;
    struct node* q = headptr->next;

    while (q->next!= headptr)
    {
        q = q->next;
    }

    q->next = p->next;
    headptr = p->next;
    free(p);

    return headptr;
}

struct node* deletion_at_end(struct node* headptr) {
    struct node* p = headptr;
    struct node* q = headptr->next;

    while (q->next != headptr)
    {
        q = q->next;
        p = p->next;
    }
    
    p->next = headptr;
    free(q);

    return headptr;
}

struct node* deletion_in_between(struct node* headptr, int index) {
    struct node* p = headptr;
    struct node* q = headptr->next;
    int i = 0;

    while (i != index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    
    p->next = q->next;
    free(q);

    return headptr;
}

struct node* deletion_at_given(struct node* headptr, int value) {
    struct node* p = headptr;
    struct node* q = headptr->next;

    while (q->data != value && q->next != headptr)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return headptr;
}

int main(){

    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    head->data = 12;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 12;
    third->next = fourth;

    fourth->data = 12;
    fourth->next = head;

    display(head);

    //Insertion in circular linked list
    head = insert_At_first(head, 99);
    display(head);

    head = insert_at_end(head, 88);
    display(head);

    head = insert_in_between(head, 77, 3); //"3 here is the index number"
    display(head);

    head = insert_at_given(head, 66, 12); //It will remove the first instance of the "12" in the linked list, and here "12" is a value.
    display(head);


    //Deletion in circular linked list
    head = deletion_at_first(head);
    display(head);

    head = deletion_at_end(head);
    display(head);

    head = deletion_in_between(head, 2);
    display(head);

    head = deletion_at_given(head, 12);
    display(head);

    return 0;
}