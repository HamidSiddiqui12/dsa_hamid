#include <iostream>
using namespace std;

class node {
    public:

    int data;
    node *next;

    void display(node* headptr){

        while (headptr!= NULL)
        {
            cout<<headptr->data<<endl;
            headptr = headptr->next;
        }
        
    }

    node* insert_At_first(node* headptr, int data_inp) {
        node* ptr = new node();
        ptr->data = data_inp;
        ptr->next = headptr;
        headptr = ptr;

        return headptr;
    }

    node* insert_At_end(node* headptr, int data_inp) {
        node* ptr = new node();
        node* ptr2 = new node();
        ptr2->data = data_inp;
        ptr = headptr;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = ptr2;
        ptr2->next = NULL; 

        return headptr;
    }

    node* insert_in_between(node* headptr, int index, int data_inp) {
        node* ptr = new node();
        node* ptr2 = new node();
        ptr2->data = data_inp;
        ptr = headptr;
        int i = 0;

        while (i!= index-1)
        {
            ptr = ptr->next;
            i++;
        }

        ptr2->next = ptr->next;
        ptr->next = ptr2;

        return headptr;
    }

    node* insert_at_given_node(node* headptr, node* ptr2, int data_inp) {
        node* pt_r = new node;
        pt_r->data = data_inp;
        node* ptr = new node();
        ptr = headptr;

        while (ptr->next != ptr2)
        {
            ptr = ptr->next;
        }

        ptr->next = pt_r;
        pt_r->next = ptr2;

        return headptr;
    }

};

int main() {

    class node* head;
    class node* first;
    class node* second;
    class node* third;
    class node* fourth;

    head = new node();
    first = new node();
    second = new node();
    third = new node();
    fourth = new node();

    head->data = 0;
    head->next = first;

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    head->display(head);

    cout<<"After insertion at head\n";
    head = head->insert_At_first(head, -1);
    head->display(head);

    cout<<"After insertion at end\n";
    head = head->insert_At_end(head, 5);
    head->display(head);

    cout<<"After insertion in between\n";
    head = head->insert_in_between(head, 2, 6);
    head->display(head);

    cout<<"After insertion at given node\n";
    head = head->insert_at_given_node(head, third, 10);
    head->display(head);

    return 0;
}