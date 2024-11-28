#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findSum(vector<int> &vec) {
    int sum = 0;
    for (int val : vec) {
        sum += val;
    }
    return sum;
}

vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes) {
    vector<int> ans;

    // Calculate the sums of Alice's and Bob's candies
    int aliceSum = findSum(aliceSizes);
    int bobSum = findSum(bobSizes);

    // Find the signed difference
    int diff = (aliceSum - bobSum) / 2;

    // Sort Bob's sizes for binary search
    sort(bobSizes.begin(), bobSizes.end());

    for (int a : aliceSizes) {
        int target = a - diff; // Bob's candy to match the balance
        // Binary search for the target in Bob's candies
        if (binary_search(bobSizes.begin(), bobSizes.end(), target)) {
            ans = {a, target};
            break;
        }
    }
    return ans;
}

int main() {
    vector<int> vec1 = {1, 2, 5};
    vector<int> vec2 = {2, 4};

    vector<int> result = fairCandySwap(vec1, vec2);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
