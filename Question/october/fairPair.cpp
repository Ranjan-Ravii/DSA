#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> countFairPairs(vector<int> &nums, int lower, int upper)
{

    vector<pair<int, int>> result;

    for (int i = 0; i < nums.size(); i++){
        for (int j = i+1; j < nums.size(); j++){
            if( nums[i] + nums[j] >= lower && nums[i] + nums[j] <= upper ){
                result.push_back({i,j});
            }
        }
        
    }

    return result;
}

int main()
{

    // vector<int> nums = {0,1,7,4,4,5};
    vector<int> nums = {1,7,9,2,5};
    int lower = 11, upper = 11;
    
    vector<pair<int, int>> pairs = countFairPairs(nums, lower, upper);
    
    // Print the pairs
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }
}