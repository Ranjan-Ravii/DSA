#include <iostream>
#include <algorithm>
using namespace std;

//reverse the string using recursion

void reverseString(string & str, int i, int j){
    //base case
    if(i>j){
        return ;
    }

    swap(str[i],str[j]);
    i++;
    j--;
    reverseString(str,i,j);

}




int main(){
    string str = "RAVIRANJAN";
    reverseString(str,0,str.size()-1);

    cout << str << endl;

}