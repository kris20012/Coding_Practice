#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int>& nums) {
    int maxCount = 0;
    int count = 0;
    int maxNum = 0;
    int num = 0;
    int previousNum = 0;

    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());

    if(nums.size() == 1) return nums[0];

    for(int i = 0; i < nums.size(); i++){
        previousNum = num;
        num = sortedNums[i];
        cout << "Number: " << num << "      Previous Number: " << previousNum << endl;
        if(num == previousNum){
            count++;
        } else {
            count = 0;
        }

        if(count > maxCount){
            maxCount = count;
            maxNum = num;
        }
        
    }

    return maxNum;

}

