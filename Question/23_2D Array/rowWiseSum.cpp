#include <iostream>
#include <vector>

#include <unordered_map>
#include <string>
using namespace std;

vector<int> rowWiseSum(int arr[][3], int row, int col){

    vector<int>ans(col);
     for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans[i] += arr[i][j];
        }
       
    }
    return ans;
}

int largestRawSum(int arr[][3], int row, int col){
    int maxi = INT8_MIN;
    
    int rowIndex = -1;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }

        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = i;
        }
        
        
       
    }
    cout << "Maximum value of row sum : " << maxi << endl;
    return rowIndex;

}

int main(){
    int arr[][3] = {1,2,3,4,5,6,7,8,9};

    vector<int> result = rowWiseSum(arr, 3,3); 

    for(int i = 0; i<3; i++){
        cout << result[i] << " ";
    }
    cout << endl;
    int ans = largestRawSum(arr, 3, 3);
    cout << "Largest row sum index : " << ans << endl;





class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> mapStr; // Tracks the last seen position of each character
        int maxLength = 0;
        int start = 0; // The start of the current substring

        for (int i = 0; i < s.size(); i++) {
            // If the character is already in the map and its position is within the current window
            if (mapStr.find(s[i]) != mapStr.end() && mapStr[s[i]] >= start) {
                // Move the start to the right of the previous occurrence of the current character
                start = mapStr[s[i]] + 1;
            }

            // Update the last seen position of the character
            mapStr[s[i]] = i;

            // Calculate the max length of the substring without repeating characters
            maxLength = std::max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};





}