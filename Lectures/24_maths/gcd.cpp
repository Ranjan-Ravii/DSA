#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    
    while (a != b){

        if (a > b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return b;
}

int main(){
    int a ,b;
    cout<<"Enter two numbers."<< endl;
    cin >> a;
    cin >> b;

    cout<< "GCD of a and b is : "<< gcd(a,b)<< endl;
}