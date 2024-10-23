#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int i = 0, j = 1, k = 2;
    vector<vector<int>> triplets;
    while(i < nums.size() && j < nums.size() && k < nums.size()){
        cout << "I: " << i << " J: " << j << " K: " << k << endl;
        if(nums[i] + nums[j] + nums[k] == 0) 
        triplets.push_back({nums[i], nums[j], nums[k]});
        if(j == nums.size()-2) {
            j = i + 2;
            k = j;
            i++;
        } else if(k == nums.size()-1) {
            k = j + 1;
            j++;
        }
        k++;
    }
    return triplets;
}
