#include <iostream>
#include <vector>

using namespace std;

int getSum(int arr[], int size){

    if(size == 1){
        return arr[0];
    }
    int sum = arr[0] + getSum(arr + 1, size - 1);
    return sum;
}

int main(){
    int x[] = {1,2,3,4};
    int size = sizeof(x)/sizeof(x[0]);

    int ans = getSum(x, size);
    cout << ans << endl;
}