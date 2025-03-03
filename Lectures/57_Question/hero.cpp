#include <iostream>
using namespace std;
#include <stack>
#include <vector>

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
 
        int row = mat.size();
        int col = mat.size();
        int n = mat.size();

        stack<int> st;
        
        for(int i = 0; i < n; i++){
            
            int colcount = 0;
            for(int j = 0; j < col; j++){
                int curr = mat[i][j];
                if(curr == 0){
                    colcount++;
                }
            }

            
            
        }
         
    }
};

int main(){

}