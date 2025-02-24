#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "size of stack is " << st.size() << endl;

    cout << "popping form stack " << endl;
    st.pop();
    st.pop();
    cout << "size of stack is " << st.size() << endl;


    if(st.empty()){
        cout << "stack is empty" << endl;
    }
    else{
        cout << "stack is not empty" << endl;
    }

}