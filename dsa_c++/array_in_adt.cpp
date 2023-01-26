#include<iostream>
using namespace std;

class array_in_adt
{
private:
    int total_size;
    int used_size;
    int *ptr;
public:

    array_in_adt(array_in_adt *arr_obj, int t_size, int u_size){
        arr_obj->total_size = t_size;
        arr_obj->used_size = u_size;
        arr_obj->ptr = new int[t_size];
    }

    void getval(class array_in_adt *b){
    
        for (int i = 0; i < b->used_size; i++)
        {
            cout<<"Enter the value of the array["<<i<<"]"<<endl;
            cin>>(b->ptr)[i];
        }
    
    }

    void show_val(class array_in_adt *c){

        for (int i = 0; i < c->used_size; i++)
        {
            cout<<"The value of the array["<<i<<"] is:"<<(c->ptr)[i]<<endl;
        }
    
    }
};

int main() {
    
    //You can give the value of the tsize usize by yourself by asking the user.
    array_in_adt arr_obj(&arr_obj, 4, 2);
    
    //setting the value to the array
    arr_obj.getval(&arr_obj);

    //Show the value in the array
    arr_obj.show_val(&arr_obj);

    return 0;
}