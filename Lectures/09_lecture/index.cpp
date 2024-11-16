#include <iostream>
#include <vector>
using namespace std;

int minSwaps(string s)
{

    int openBraces = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '[')
        {
            openBraces++;
        }
    }

    return (openBraces + 1) / 2;
}

vector<int> findDuplicates(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;

    vector<int> ans;

    while (low < high)
    {
        if (nums[low] != nums[high])
        {
            continue;
        }
        else
        {
            ans.push_back(nums[low]);
        }

        low++;
        high--;
    }
    return ans;
}

int main()
{

    // string str = "]][]][[[][";
    // int result = minSwaps(str);
    // cout << result;

    vector<int> arr;
    arr = {4, 3, 2, 7, 8, 2, 3, 1};

    
    vector<int>ans;
    ans = findDuplicates(arr);
    for (int num : ans) {
        cout << num << " ";
    }
    



}