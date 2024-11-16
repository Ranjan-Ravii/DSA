#include <iostream>
using namespace std;

// linear searching function
bool linearSearch(int arr[][3], int target, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

// printing array
void printArray(int arr[][3])
{
    for (int i = 0; i < 3; i++)
    {
        {
            for (int j = 0; j < 3; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void takeInput(int arr[][3]){
        for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
        
    }
}

int main()
{
    int arr[3][3];

    cout << "enter the elements " << endl;
    takeInput(arr);
    printArray(arr);

    cout << "enter target : ";
    int target;
    cin >> target;
    int ans = linearSearch(arr, target, 3,3);
    cout << "element found  : " <<  ans << endl;

}