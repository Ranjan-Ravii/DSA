#include <iostream>
#include <vector>
using namespace std;

int isPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i < n; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}


int countPrime(int n){
    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
        
    }
    return count;
}

int sieveOfErstosthenes(int n){

    vector<bool>prime(n+1, true);
    prime[0] = prime[1] = false;
    int count = 0;

    for(int i = 2; i*i< n; i++){
        for (int j = 2*i; j < n; j = j+i){
           prime[j] = false;
        }   
    } 

    for (int i = 0; i < n; i++)
    {
       if (prime[i])
        count++;
    }
    
    return count;
}

int main()
{
    int num;
    cout << "enter a number : ";
    cin >> num;
    cout << isPrime(num) << endl;

    cout << "total prime number below " << num << " is : " << sieveOfErstosthenes(num)<< endl;
}
