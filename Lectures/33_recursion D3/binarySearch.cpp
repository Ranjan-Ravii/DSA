#include <iostream>
#include <vector>
using namespace std;

/*
int binarySearch(int arr[], int size, int key, int start, int end){

    int mid = start + (end - start) / 2;
    cout << size << endl;
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
*/

bool binarySearch(int *arr, int key, int start, int end) {
    // Debugging output to track the range size
    cout << "Range size: " << end - start << endl;

    // base case for element not found
    if (start > end) {
        return false;
    }

    int mid = start + (end - start) / 2;

    // base case for element found
    if (arr[mid] == key) {
        return true;
    }

    // Search left or right depending on key comparison
    if (arr[mid] > key) {
        return binarySearch(arr, key, start, mid - 1);  // Search left half
    } else {
        return binarySearch(arr, key, mid + 1, end);  // Search right half
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int key = 16;
    int size = sizeof(arr) / sizeof(arr[0]);
    bool found = binarySearch(arr, key, 0, size - 1);
    cout << "Element found: " << (found ? "Yes" : "No") << endl;
    return 0;
}