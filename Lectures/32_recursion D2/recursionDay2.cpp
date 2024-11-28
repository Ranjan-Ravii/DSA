#include <iostream>
#include <vector>
using namespace std;

// leetcode Q70. Climbing Stairs
int climbStairs(int n)
{
    // if person is taking step back then he may go negative,
    // in case of when he is taking 2 steps at a time;
    if (n < 0)
    {
        return 0;
    }
    // if person is already at 0th step, then the only way to get
    // to that stair is one i,e. from that stair to itself stair
    if (n == 0)
    {
        return 1;
    }

    // person can reach to nth stair either takin 1 step or 2 step.
    return climbStairs(n - 1) + climbStairs(n - 2);
}\


// lecture question
void saydigit(int n, string arr[]){
    if(n == 0){
        return ;
    }
    int digit = n % 10;
    n /= 10;
    saydigit(n, arr);
    cout << arr[digit] << " " ;
}

int main(){

    int stairs = 44;
    cout << "expected for n = 44 : 1134903170" << endl;
    // cout << "No of ways : " << climbStairs(stairs) << endl;

    // 2nd question's paramters

    string mapedDigit[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int digit = 145;
    saydigit(digit, mapedDigit);

}
