#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> allCombinations;
    vector<int> combination;
    for(int i = 0; i < nums.size(); i++){
        combination.push_back(nums[i]);
        for(int j = 0; j < nums.size(); j++){
            if(i == j) continue;
            combination.push_back(nums[j]);
        }
        // cout << "Out: " << combination[0] << ", " << combination[1] << ", " << combination[2] << endl;
        allCombinations.push_back(combination);
        combination.clear();

        if(nums.size() < 3) continue;

        combination.push_back(nums[i]);
        for(int j = nums.size()-1; j >= 0; j--){
            if(i == j) continue;
            combination.push_back(nums[j]);
        }
        allCombinations.push_back(combination);
        combination.clear();
    }
    return allCombinations;
}