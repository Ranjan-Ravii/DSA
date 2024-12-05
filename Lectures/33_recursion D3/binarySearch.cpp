#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int arr[], int size, int key, int start, int end){

    int mid = start + (end - start) / 2;

    // base case
    if (start > end)
    {
        return -1;
    }

    // shift start or end;
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key){
        end = mid - 1;
    }
    else{
        start = mid + 1;
    }

    int ans = binarySearch(arr, size, key, start, end);
    return ans;
    
}


int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 8;
    int start = 0;
    int end = size - 1;

    int ans = binarySearch(arr, size, key, start, end );
    cout << key << " found at index : " << ans << endl;

}