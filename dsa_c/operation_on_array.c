#include<stdio.h>

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Basic Insertion method for an array
int basic_insertion(int arr[], int size, int capacity, int element, int index){

    if (size>=capacity)
    {
        printf("No space to add any element\n");
        return 0;
    }

    // size-1 = last index number
    for (int i = (size-1); i <= index; i--)
    {
        // arr[i+1] is the empty space in the array where arr[i] value is going.
        arr[i+1] = arr[i];
    }
    arr[index] = element;

    return 0;
}

//Basic Deletion method for an array
int basic_deletion(int arr[], int size, int index){

    // size-1 = last index number
    for (int i = index; i < (size-1); i++)
    {
        // arr[i] is the empty space in the array where arr[i+1] value is going.
        arr[i] = arr[i+1];
    }

    return 0;
}

void linearsearch(int arr[], int size, int element) {
    for (int i = 0; i < (size-1); i++)
    {
        if (arr[i] == element)
        {
            printf("Element found at index[%d]\n", i);
        }   
    }
    
}

void binarysearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;

    //By hamid need assistance or have to see this code once again
    /*
    mid = (low+high)/2;
    for (int i = low; i <= high; i++)
    {
        if (arr[i]==element)
        {
            printf("Element found at index[%d]\n", i);
        }

        else if (arr[mid]>element)
        {
            high = mid;
            continue;
        }

        else if (arr[mid]<element) {
            low = mid;
            continue;
        }
    } 
    */

   //Method on YT
   while (low<=high){

    mid = (low+high)/2;

    if (arr[mid] == element)
    {
        printf("Element found at index[%d]\n", mid);
        break;
    }
    else if (arr[mid]>element)
    {
        high = mid - 1;
    }
    else if (arr[mid]<element) {
        low = mid + 1;
    }
    
   }
   
}

int main() {
    int arr[] = {1,22,2,33,221,21,24,4,9};
    int arr1[] = {1,22,33,44,99};
    int element_to_be_added, index, capacity = 10, element;
    //Size of array is 36 here because of 9 "(9*4)" elements in the array with each size(int) "4".
    int size = sizeof(arr)/sizeof(int);
    int size1 = sizeof(arr1)/sizeof(int);

    // //Traversal of array to print
    display(arr, size);

    // //Basic Insertion method for an array
    printf("Enter the index number where you want to add number: ");
    scanf("%d", &index);

    printf("Enter the number you want to add at index[%d]: ", index);
    scanf("%d", &element_to_be_added);

    basic_insertion(arr, size, capacity, element_to_be_added, index);
    size++;
    display(arr, size);

    // //Basic Deletion method for an array
    printf("Enter the index number of element, which you want to delete: ");
    scanf("%d", &index);

    basic_deletion(arr, size, index);
    size--;
    display(arr, size);

    //linear search in sorted/unsorted array
    printf("Enter the number you want to search in the array: ");
    scanf("%d", &element);
    linearsearch(arr, size, element);
    
    //binary search for sorted array 
    printf("Enter the number you want to search in the array: ");
    scanf("%d", &element);
    binarysearch(arr1, size1, element);

    return 0;
}