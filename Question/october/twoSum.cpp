#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> ans;
    int start = 0;
    int end = numbers.size() -1;
    int mid;

    for (int i = 0; i < numbers.size(); i++)
    {
        int start = i+1;
        int end = numbers.size() -1;

        int requiredNum = target - numbers[i];

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (numbers[mid] == requiredNum)
            {
                ans.push_back(i);
                ans.push_back(mid);
                return ans;
            }
            else if (numbers[mid] > requiredNum)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return ans;
}

int main()
{
    // vector<int> arr = {2, 3, 4};
    vector<int> arr = {2,7,11,15};
    // int target = 6;
    int target = 9;

    vector<int> result = twoSum(arr, target);

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " " ;
    }
}