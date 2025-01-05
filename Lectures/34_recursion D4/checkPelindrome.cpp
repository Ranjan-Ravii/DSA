#include <iostream>
#include <algorithm>
using namespace std;

// bool isPelindrome(string str, int i, int j)
// {
//     if (i > j){
//         return true;
//     }

//     if (str[i] != str[j]){
//         return false;
//     }
//     else{
//         return isPelindrome(str, i+1, j-1);
//     }
// }

//using single pointer
bool isPelindrome(string str, int i)
{
    int j = str.size()-1 - i ;
    if (i > j ){
        return true;
    }

    if (str[i] != str[j]){
        return false;
    }
    else{
        return isPelindrome(str, i+1);
    }
}


int main()
{
    string str = "hannah";
    int i = 0;
    int j = str.size() - 1;
    bool ans = isPelindrome(str, i);
    cout << ans << endl;
}