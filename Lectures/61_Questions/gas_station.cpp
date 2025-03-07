#include <iostream>
#include <vector>
using namespace std;


// int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//     int n = gas.size();
//     int balance = 0;
//     int rear = 0;
//     int front = 0;
//     int start = 0;

//     for(int i = 0; i <= n; ++i ){
//         balance = balance + gas[rear] - cost[rear];

//         if(balance >= 0){
//             rear += 1;
//             if(rear == n-1){
//                 rear = 0;
//             }
//         }
//         else{
//             front = rear + 1;
//             start = front;
//             rear = start;
//             balance = 0;
//             i = 0;
//         }
//     }
//     if(rear == start){
//         return start;
//     }
//     return -1;
// }

 int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int balance = 0;
    int deficit = 0;
    int start = 0;

    for (int i = 0; i < n; i++){
        balance += gas[i] - cost[i];
        if (balance < 0){
            deficit += balance;
            balance = 0;
            start =  i + 1;
        }
    }

    if (balance + deficit >= 0){
        return start;
    }
    else{
        return -1;
    }
    
    
 }

int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    
    int ans = canCompleteCircuit(gas, cost);
    cout << ans << endl;
}
