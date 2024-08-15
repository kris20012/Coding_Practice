#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
void printArray (vector <int> & n){
    for (int i = 0; i < n.size(); i++)
    {
        cout << n[i];
    }
    cout << "\n";
}

long long countInterestingSubarrays(vector<int>& nums, int modulo, int b) {
        int count = 0;
        bool endSubArray = false;
        // find all subarrays
       for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int subCount = 0;
                for (int k = i; k <= j; k++) {
                    //cout<<nums[k]<< " ";
                    if(nums[k] % modulo == b){
                        //cout << "\nInteresting\n \tCount: " << count << endl;
                        //cout << "Trigger";
                        subCount++;
                        //endSubArray = true;
                    }
                }
                if(subCount % modulo == b){
                    //cout << "UPDATE";
                    count++;
                }
                //cout<<endl;
                //if(endSubArray){
                //    continue;
                //}
            }
            //cout<<endl;
        }
    return count;
    
}

int main (){
    vector <int> n = {3,2,4};
    cout << countInterestingSubarrays(n, 2, 1) << "here" << endl;

    n = {3,1,9,6};
    cout << countInterestingSubarrays(n, 3, 0) << "here" << endl;
    return 0;
}