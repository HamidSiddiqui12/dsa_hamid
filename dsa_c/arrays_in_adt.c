// ADT - Abstract Data Type

#include<stdio.h>
#include<stdlib.h>

struct array_in_adt
{
    int total_space;
    int used_space;
    int *ptr;
};

void create_array(struct array_in_adt *a, int tsize, int usize){

    //correct method also
    // (*a).total_space = tsize;
    // (*a).used_space = usize;
    // (*a).ptr = (int *)malloc(tsize*sizeof(int));

    a->total_space = tsize;
    a->used_space = usize;
    a->ptr = (int *)malloc(tsize*sizeof(int));
}

void getval(struct array_in_adt *b){
    
    for (int i = 0; i < b->used_space; i++)
    {
        printf("Enter the value of the array[%d]", i);
        scanf("%d", &(b->ptr)[i]);
    }
    
}

void show_val(struct array_in_adt *c){

    for (int i = 0; i < c->used_space; i++)
    {
        printf("The value of the array[%d] is %d\n", i, (c->ptr)[i]);
    }
    
}

int main(){
    struct array_in_adt check_struct;

    //You can give the value of the tsize usize by yourself by asking the user.
    create_array(&check_struct, 8, 2);

    //setting the value to the array
    getval(&check_struct);

    //Show the value in the array
    show_val(&check_struct);

    create_array(&check_struct, 8, 2);

    //setting the value to the array
    getval(&check_struct);

    //Show the value in the array
    show_val(&check_struct);

    return 0;
}