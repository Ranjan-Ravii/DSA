#include <iostream>
#include<vector>
 using namespace std;

 int main(){

    int arr[10] = {1,3,4,5,7,2};
/*
    // ways to acess the address of array
    cout << "base address of arr : " << arr << endl;          // base address int*
    cout << "base address of arr : " << &arr << endl;          // address to the entire array int(*)[10]
    cout << "base address of arr : " << arr + 1 << endl;        // address next to the base address
    cout << "base address of arr : " << &arr + 1 << endl;       // address next to the entire array
    
    // ways to access the value
    cout << "1st element : " << arr[0] << endl;
    cout << "1st element : " << *arr << endl;

    cout << "incrementing value of 1st element by 1 : " << *arr + 1 << endl;
    cout << "value of 2nd element : " << *(arr + 2) << endl;
  */

    // experimenting with the size of array and pointer
    int temp[10] = {1,2,4,5,6,7,8,9,10};
    int *ptr = &temp[0];

    // cout << sizeof(temp) << endl;
    // cout << sizeof(ptr) << endl;
    // cout << sizeof(*ptr) << endl;
    // cout << sizeof(&ptr) << endl;

    // int arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    int *ptr1 = &arr[0];
    int *ptr2 = ptr1 + 3;
    cout<<*ptr2<<" ";
    cout<< ptr2 - ptr1;


 }