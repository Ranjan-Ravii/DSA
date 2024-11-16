#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    vector<int> result;
    int i = 1;

    while (i < nums.size())
    {
        if (nums[i] != nums[i - 1])
        {
            result.push_back(nums[i - 1]);
            i++;
        }
        else
        {
            i++;
        }
       
    }
    return result.size();
}




int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << sizeof(nums) << endl;
    cout << removeDuplicates(nums);

}