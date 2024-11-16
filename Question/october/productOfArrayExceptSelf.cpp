#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(const vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 1); 

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ans[i] *= nums[j]; 
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1,2,3,4};

    vector<int>anser = productExceptSelf(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << anser[i] << " ";
    }
    
}