#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int arr[], int size){
    for (int i = 1; i < size; i++)
    {
       int temp = arr[i];
       int j = i-1;

       while ( j >= 0 && arr[j] > temp )
       {
            arr[j+1] = arr[j];
            j--; 
       }
       arr[j+1] = temp;
    }
    
}


int main(){
    int arr[ ] = {1,7,3,2,8,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<< " " ;
    }
    
}