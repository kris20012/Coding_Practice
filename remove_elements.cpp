/*
    Program Requirements:
    - INPUT: int array nums, int val
    - Func: Remove all places of val in nums. Return number of elements not equal to val (k)
    - OUTPUT: k, change array to remove all vals

*/

#include <iostream>
using namespace std;

#include <vector>

int removeElement(vector <int> & nums, int val) {
    int notVal = 0;
    int* nextValue = 0;
    
    for (int i = 0; i < nums.size(); i++){
        if(i + 1 < nums.size()) nextValue = &nums[i+1];
        if(nums[i] == val){
            if (*nextValue != val) nums[i] = *nextValue;
            *nextValue = -1;

            i--;
            //cout << "Value: " << nums[i] << endl;
        } else if(nums[i] == -1) {
            // search for next valid number and replace
            for(int counter = 1; counter + i < nums.size(); counter++){
                if(nums[i + counter] != -1)
                    nums[i] = nums[i + counter];
                    nums[i + counter] = -1;
                    break;
            }
        } else {
            notVal++;
            //cout << "Not Value: " << nums[i] << endl;
        }
    }  

    for(int i = 0; i < nums.size(); i++){
        cout << "Array Position: " << nums[i] << endl;
    }
    return notVal;     
}
int removeElementAns(vector <int> & nums, int val) {
    int index = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            cout << "Array Position: " << nums[i] << endl;
        }
        cout << "Index: " << index << endl;
        return index;
}
int main() {
    vector<int> numbers = {10, 25, 5, 30, 15, 30, 40};
    //vector<int> numbers = {3,2,2,3};
    int keyToFind = 30;
    //int keyToFind = 3;

    int index = removeElementAns(numbers, keyToFind);
    return 0;
}