#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

//Traversing in the linked list.
void display(struct node* headptr) {
    while (headptr!= NULL)
    {
        printf("%d\n", headptr->data);
        headptr = headptr->next;
    }
    
}

//Insertion before first node
struct node* insertion_At_first(struct node* headptr, int data) {

    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = headptr;
    headptr = ptr;

    return headptr;
}

//Insertion after end node
struct node* insertion_At_end(struct node* headptr, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = headptr;
    ptr->data = data;
    
    while (p->next != NULL)
    {
        p= p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    
    return headptr;
}

struct node * insertion_in_between_two_nodes(struct node* headptr, int index, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = headptr;
    ptr->data = data;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    
    ptr->next = p->next;
    p->next = ptr;

    return headptr;

}

struct node* insertion_At_given_node(struct node* headptr, struct node* thirdptr, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = headptr;
    ptr->data = data;

    while (p->next != thirdptr)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = thirdptr;

    return headptr;
}

int main(){
    struct node* head;

    //Dynamical allocating the space
    head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    struct node* fifth = (struct node*)malloc(sizeof(struct node));

    //Setting the data and address to the next ptr
    head->data = 25;
    head->next = second;

    second->data = 24;
    second->next = third;

    third->data = 23;
    third->next = fourth;

    fourth->data = 22;
    fourth->next = fifth;

    fifth->data = 21;
    fifth->next = NULL;

    //Traversal of a node
    display(head);

    /*
        Insertion type in linked list are:
        1. before first node. 
        2. after end node.
        3. in between the two nodes.
        4. at the given node. 
    */
   
    printf("\nAll operations of Insertion in linked list: \n");
   
    //Insertion before first node
    head = insertion_At_first(head, 26);
    display(head);

    //Insertion after end node
    head = insertion_At_end(head, 20);
    display(head);

    //Insertion in between the two nodes
    printf("Before insertion operation\n");
    display(head);
    head = insertion_in_between_two_nodes(head, 3, 20);
    printf("After insertion operation\n");
    display(head);

    //Insertion at the given node
    head = insertion_At_given_node(head, third, 1);
    printf("After insertion operation\n");
    display(head);

   return 0;
}