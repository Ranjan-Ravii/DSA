#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findDuplicate(int nums[], int size)
{
    int ans = -1;
    unordered_map<int, int> map;

    for (int i = 0; i < size; i++){
    
        // for (int j = i+1; j < size; j++)
        // {
        //    if (nums[i] == nums[j])
        //    {
        //       return nums[i]; 
        //    }
           
        // }

        if (map[nums[i]] == 1)
        {
            return nums[i];
        }
        map[nums[i]]++;
        
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int res = findDuplicate(arr,size);
    cout << res <<endl;

}