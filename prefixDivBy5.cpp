#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>  
#include <math.h>   

using namespace std;

void printArr(vector<bool> array){
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}

vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> tmp;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] * pow(2, nums.size() - i - 1);
            //cout << "SUM: " << sum ;
            //cout << "  EXP: " << pow(2, nums.size() - i - 1) << endl;
        }

        for(int i = 0; i < nums.size(); i++){
            if(sum % 5 == 0){
                tmp.push_back(true);
            } else {
                tmp.push_back(false);
            }
            //cout << "NEW: " << sum << endl;
            sum = sum >> 1;  
        }

        reverse(tmp.begin(), tmp.end());

        return tmp;
    }

vector<bool> prefixesDivBy5_v2(vector<int>& nums) {
        vector<bool> tmp;
        int sum = nums[0];
        if(sum % 5 == 0){
                tmp.push_back(true);
            } else {
                tmp.push_back(false);
            }
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == 0){
                sum += sum * 2;
            } else {
                sum += sum * 2 + 1;
            }
            if(sum % 5 == 0){
                tmp.push_back(true);
            } else {
                tmp.push_back(false);
            }
            cout << "SUM: " << sum << endl;
        }
    
        return tmp;
    }

int main() {
    // 0, 1, and 3
    vector <int> num = {0,1,1};
    cout << "ANSWER: \n";
    printArr(prefixesDivBy5_v3(num));

    // 1, 3, and 7
    num = {1,1,1};
    cout << "ANSWER: \n";
    printArr(prefixesDivBy5_v3(num));

    return 0;
}