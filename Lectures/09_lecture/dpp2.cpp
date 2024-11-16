#include <iostream>
#include <vector>
using namespace std;

int findRamp(int arr[], int size) {
    int ramp = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (( i<j )&& (arr[i] <= arr[j])){
                int temp = j-i;
                if (ramp <= temp)
                {
                    temp = temp;
                }
                else{
                    continue;
                }
                ramp = temp;
            }
            {
                continue;
            }
            
        }
        
    }
    return ramp;
    
}



// sort array by parity 
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        vector<int> ans;

        int i = 0, j = 0;
        int n = nums.size();

        while (i < n/2 && j >= 0) {

            if (nums[i] % 2 == 0) {
                ans[j] = nums[i];
            } else {
                ans[n - j] = nums[i];
            }
            i++;
            j++;
        }
        return ans;
    }
};


// sort 0 1 2 
  vector<int> sortArrayByParity(vector<int>& nums) {
    int n = nums.size();
    int i = 0; 
    int j = nums.size() - 1;
     int temp;

    while ( i < n && j > 0 )
    {
        if (nums[i] == 0 )
        {
            i++;
        }
        if (nums[j] == 2)
        {
            j--;
        }
        if (nums[i] == 2 && nums[j] == 0)
        {
            swap(nums[i], nums[j]);
            i++ ; 
            j--;
        }
        if (nums[i] == 2 && nums[j] == 1)
        {
            swap(nums[i], nums[j]);
            j--;
        }
        if (nums[i] == 1 && nums[j] == 0)
        {
            swap(nums[i] , nums[j]);
            i++;
        }
        if (nums[i] == 1)
        {
            temp = i;
            i++;
        }
        
    }
    return nums;

  }



int main(){

int nums[] = {9,8,1,0,1,9,4,0,4,1};
int size = sizeof(nums)/ sizeof(nums[1]);

int result = findRamp(nums, size);
cout <<  result;



}