#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        if(digits[digits.size()-1] != 9){
            cout << "Last: " << digits[digits.size()-1] << endl;
            digits[digits.size()-1]++;
        } else {
            for(int i = digits.size()-1; i >= 0; i--){
                cout << "Val: " << digits[i] << endl;
                if(digits[i] < 9){
                    digits[i]++;
                    return digits;
                }
                digits[i] = 0;
                if(i == 0){
                    digits.insert(digits.begin(), 1);
                }
               
            }
            
        }
        return digits;
    }
};