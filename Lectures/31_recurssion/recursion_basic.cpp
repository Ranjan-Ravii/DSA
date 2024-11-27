#include <iostream>
#include <math.h>
using namespace std;

int factorial(int n){

    //base case ==>> base is always required,it specifies when to terminate the callback.

    if (n == 0){
        return 1;
    }

    int ans = n * factorial(n - 1);
    return ans;
}

int power(int base, int n){
    if (n == 0)
    {
        return 1;
    }
    
    int ans = base * pow(base, n-1);

    return ans;
}

// printing count 
void count(int num){

    if(num == 0){
        return ;
    }

    // printing in increasing order
    count(num - 1 );
    cout << num << endl;

    /*
    // printing in decreasing order;
    cout << num << endl;
    count(num - 1 );
    */
}


int main(){
    int num = 6;
    int fact = factorial(num);
    cout << "factorial of "<< num << " is : " << fact << endl;

    int pow = power(num,2);
    cout << "square of "<< num << " is : " << pow << endl;


// printing count
    cout << "Enter the number : ";
    cin >> num;
    count(num);


}