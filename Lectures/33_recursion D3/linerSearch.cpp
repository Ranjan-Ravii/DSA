#include <iostream>
#include <vector>

using namespace std;

int linearSearch(int arr[], int size, int key, int index = 0){
    //base case
    if (index >= size){
        return -1;
    }
    if(arr[index] == key){
        return index;
    }

    // recusrsive call
    int ans = linearSearch(arr, size, key, index+1);
    return ans;    

}



int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 5;

    int ans = linearSearch(arr, size, key);

    cout << key << " found at index : " << ans << endl;

    return 0;
}