#include <iostream>
using namespace std;

int factorial(int n){

    if (n == 0)
        return 1;

    int ans = 1;
    ans = n * factorial(n - 1);
    return ans;
}

int main(){
    int num = 6;
    int ans = factorial(num);
    cout << ans << endl;
}