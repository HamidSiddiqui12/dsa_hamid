#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void display(struct node* headptr) {
    while (headptr != NULL)
    {
        printf("%d\n", headptr->data);
        headptr = headptr->next;
    }
}

// Deletion of first node
struct node * deletion_At_first(struct node* headptr) {

    struct node* ptr = headptr;
    headptr = headptr->next;
    free(ptr);

    return headptr;
}

// Deletion of end node
struct node * deletion_At_end(struct node* headptr) {
    struct node* ptr1 = headptr;
    struct node* ptr2 = headptr->next;

    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ptr1->next = NULL;
    free(ptr2);

    return headptr;
}

// Deletion between two nodes
struct node* deletion_between_two_nodes(struct node* headptr, int index) {
    struct node * ptr1 = headptr;
    struct node * ptr2 = headptr->next;
    int i = 0;
    while (i != index - 1)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        i++;
    }

    ptr1->next = ptr2->next;
    free(ptr2);
    
    return headptr;
}

int main(){
    struct node* head, *second, *third, *fourth, *fifth;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    fifth = (struct node*)malloc(sizeof(struct node));

    //Allocating the value to the data and address to the nexr pointer
    head->data = 1;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 111;
    third->next = fourth;

    fourth->data = 1111;
    fourth->next = fifth;

    fifth->data = 11111;
    fifth->next = NULL;

    //Traversing through the linked list
    display(head);

    /*
        Deletion method in linked list are:
            1. first node
            2. end node
            3. between two nodes
            4. given node
    */

    // Deletion of first node
    printf("\nDeletion part 1: \n");
    head = deletion_At_first(head);
    display(head);

    // Deletion of end node
    printf("\nDeletion part 2: \n");
    head = deletion_At_end(head);
    display(head);

    // Deletion between two nodes
    printf("\nDeletion part 3: \n");
    head = deletion_between_two_nodes(head, 1);
    display(head);

    return 0;
}