#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> hashtable;
        for(int i = 0; i <= nums.size(); i++){
            hashtable.insert(make_pair(i, 1));
            cout << "Element: " << hashtable[i] << endl;
        }

        for(int i = 0; i < nums.size(); i++){
            cout << "num: " << nums[i] << endl;
            if(hashtable[nums[i]] == 1){
                cout << "Value: " << hashtable[nums[i]] << endl;
                hashtable[nums[i]] -= 1;
            } else {
                cout << "Ans: " << nums[i] << endl;
            }
        }

        for (auto itr = hashtable.begin(); itr != hashtable.end(); itr++){
            cout << (*itr).first << ": " << (*itr).second << endl;
            if(itr->second == 1) return itr->first;
        }
        return -1;
    }
};