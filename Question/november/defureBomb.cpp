#include <iostream>
#include <vector>
using namespace std;

    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n = code.size();
        int sum = 0;

        if (k > 0) {
            for (int i = 0; i < code.size(); i++) {
                int j = 1;
                sum = 0;
                while (j  <= k) {
                    sum += code[(j + i) % n];
                    j++;
                }
                ans.push_back(sum);
            }
        }
        if (k == 0) {
            for (int i = 0; i < code.size(); i++) {
                ans.push_back(0);
            }
        }
        if (k < 0) {
            for (int i = 0; i < code.size(); i++) {
                int j = 1;
                sum = 0;
                while (j <= -k) { 
                sum += code[(i - j + n) % n]; 
                j++;
            }
                ans.push_back(sum);
            }
        }
        return ans;
    }
    
    
    
    int main(){
        vector<int> code = {2,4, 9,3};
        int k = -2;
        
        vector<int> result = decrypt(code, k);
        
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << " " ;
        }
        
    }
    
    
    
    
    
    
    
    
    
    
