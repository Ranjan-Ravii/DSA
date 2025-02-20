#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[i]> arr[j])
            {
                swap(arr[i], arr[j]);
            }
            
        }
        
    }
    
}


int main(){
    vector<int> arr = {7,2,5,6,1,8,3};
    bubbleSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " "; 
    }
    
}