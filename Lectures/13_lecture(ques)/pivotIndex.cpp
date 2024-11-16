#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> &arr)
{

    int k = 0;

    while (k < arr.size())
    {
        int leftSum = 0;
        int rightSum = arr[k + 1];

        if (leftSum < rightSum)
        {
            k++;
            leftSum += arr[k - 1];
        }
        else if (leftSum > rightSum)
        {
            if (leftSum == rightSum + (arr[(k + 1)] + arr[k + 2]))
            {
                return k;
            }
            else if (leftSum < rightSum + (arr[(k + 1)] + arr[k + 2]))
            {
                k++;
                leftSum += arr[k + 1];
            }
        }
        return k;
    }
}

int main()
{
    vector<int> nums{1, 7, 3, 6, 5, 6};

    int ans = findPivot(nums);
    cout << ans;
}