#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
         mid = start + (end - start) / 2;

        if (nums[0] <= nums[mid])
        {
            start = mid + 1;
        }else{
            end = mid; 
        }
    }
    return start;
}

int main()
{
    vector<int> arr = {3,1};

    int ans = search(arr);
    cout << ans;
}