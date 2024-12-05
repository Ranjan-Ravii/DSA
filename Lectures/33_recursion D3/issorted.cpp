#include <iostream>
#include <vector>

using namespace std;

bool isSorted(int nums[], int n){
    
    //base case
    if(n == 1 || n == 0){
        return true;
    }
    if (nums[0] > nums[1])
    {
        return false;
    }
    
    bool ans = isSorted( nums + 1, n-1 );
    return ans;
}


int main(){
    int x[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(x)/sizeof(x[0]);
    bool ans = isSorted(x,size);
    cout << "is array sorted : "<< ans << endl;
    for (int i = 0; i < size; i++)
    {
        cout << x[i] << " " ; 
    }
    
   

}