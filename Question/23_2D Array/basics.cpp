#include<iostream>
using namespace std;

int linearSearch(int arr[][3], int target, int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(arr[row][col] == target){
                return 1;
            }
        }
        
    }
    return 0;
}


int main(){

    // create 2D array
    int arr[3][3];

    //  taking input -> row wise input
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            cin >> arr[i][j];
        }
        
    }


    // printing array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout <<  arr[i][j] << " ";
        }
        cout << endl;
        
 }

    //caling linearSearch function
    int target;
    cout<< "enter target value : ";
    cin >> target;

    bool ans = linearSearch(arr, target, 3 ,3 );

    cout << "element found : " <<  ans << endl;

    
}