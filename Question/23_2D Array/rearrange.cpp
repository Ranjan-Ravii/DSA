#include <vector>
#include <iostream>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans(nums.size(),0);
    
    int i = 0;
    int j = 1;

    for (int k = 0; k < nums.size(); k++)
    {
        if (nums[k] > 0){
            ans[i] = nums[k];
            i += 2;
        }
        else{
            ans[j] = nums[k];
            j += 2;
        }   
    }
    return ans;
    
}

int main(){
    // vector<int> arr = {1,2,-1,3,-4,-5};
    // vector<int> arr = {-1,1};
    vector<int> arr = {-1,1,-3,-4,8,2,9,-9};
    vector<int> ans = rearrangeArray(arr);

    for(int i = 0; i< ans.size(); i++){
        cout << ans[i] << " ";
    }
    
}