#include <iostream>
using namespace std;

class test_Array
{
private:
    int *ptr;
    int total_size;
    int used_size;
    int size;
public:
    //Constructor
    test_Array(test_Array *arr_obj, int tsize, int usize, int size);

    void get_array_value() {

        for (int i = 0; i < used_size; i++)
        {
            cout<<"Enter the value for the array ["<<i<<"]\n";
            cin>>ptr[i];
        }
    }

    void display_Array() {

        for (int i = 0; i < size; i++)
        {
            cout<<"The value of the array["<<i<<"] is: "<<ptr[i]<<endl;
        }
    }

    void basic_insertion(int element, int index){

        if (size >= total_size)
        {
            cout<<"\nArray Overflow\n";
        }
        else if (size < total_size)
        {
            for (int i = (size-1); i >= index; i--)
            {
                ptr[i+1] = ptr[i];
            }

            ptr[index] = element;
            size++;
        }
    }

    void basic_deletion(int index) {

        if (size == 0)
        {
            cout<<"\nArray Underflow\n";
        }
        
        else if (size > 0 && size <= total_size)
        {
            for (int i = index; i < size; i++)
            {
                ptr[index] = ptr[index+1];
            }

            size--;
        }
    }

    void binary_search(int element) {
        int low = 0;
        int high = size-1;
        int mid;

        while (low<=high)
        {
            mid = (high+low)/2;

            if (ptr[mid] == element)
            {
                cout<<"Element "<<element<<" found at index["<<mid<<"]\n";
                break;
            }
            else if (ptr[mid]< element)
            {
                low = mid + 1;
            }
            else if (ptr[mid]> element)
            {
                high = mid - 1;
            }
        }
        
    }

    void linear_search(int element_to_search) {
        int s=0;
        for (int i = 0; i < size; i++)
        {
            if (ptr[i] = element_to_search)
            {
                cout<<"Element "<<element_to_search<<" found at index["<<i<<"]\n";
            }
            s++;
        }

        if (s==(size-1))
        {
            cout<<"Element not found!\n";
        }
        
    }

    void bubblesort() {
        int temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = i+1; j < size; j++)
            {
                if (ptr[j]>ptr[j+1])
                {
                    temp = ptr[i];
                    ptr[i] = ptr[j];
                    ptr[j] = temp;
                }
            }
               
        }

    }

};

test_Array::test_Array(test_Array *arr_obj, int tsize, int usize, int sizeo)
{
    arr_obj->total_size = tsize;
    arr_obj->used_size = usize;
    arr_obj->ptr = new int[tsize];
    arr_obj->size = sizeo;
}

int main() {

    int tsize, usize, op = 1;
    int element_to_add, index;
    int element_to_search, inp;

    cout<<"Enter the total size of the array you want: ";
    cin>>tsize;
    cout<<"Enter the size you want to use from "<<tsize<<" of the array: ";
    cin>>usize;
    int size = usize;

    test_Array obj(&obj, tsize, usize, size);

    while (op != 0)
    {
        
        cout<<"\nEnter the operation you want to do in array:\n";
        cout<<"0. Enter 0 to Quit\n";
        cout<<"1. Enter 1 for Displaying array\n";
        cout<<"2. Enter 2 for Simply Adding the value in array whole\n";
        cout<<"3. Enter 3 for Insertion operation in array\n";
        cout<<"4. Enter 4 for Deleting operation in array\n";
        cout<<"5. Enter 5 for searching element with binary search in array\n";
        cout<<"6. Enter 6 for searching element with linear search in array\n";

        cin>>op;

        switch (op)
        {
        case 1:

            obj.display_Array();

            break;

        case 2:

            obj.get_array_value();

            break;

        case 3:

            cout<<"Enter the index number where you want to add\n";
            cin>>index;
            cout<<"Enter the element you want to add\n";
            cin>>element_to_add;

            obj.basic_insertion(element_to_add, index);

            break;

        case 4:

            cout<<"Enter the number you want to delete\n";
            cin>>index;

            obj.basic_deletion(index);

            break;

        case 5:
            cout<<"Enter the element you want to search\n";
            cin>>element_to_search;
            obj.binary_search(element_to_search);
            break;
        case 6:

            cout<<"Is your array is sorted?\n"<<endl<<"Press 1 for Yes and 0 for No\n";
            cin>>inp;
            if (inp == 1)
            {
                cout<<"Enter the element you want to search\n";
                cin>>element_to_search;
                obj.linear_search(element_to_search);   
            }

            else if(inp == 0) {

                obj.bubblesort();
                cout<<"Enter the element you want to search\n";
                cin>>element_to_search;
                obj.linear_search(element_to_search);   

            }

            break;
        
        default:
            cout<<"\nError!\n";
            break;
        }
    }
    
    return 0;
}