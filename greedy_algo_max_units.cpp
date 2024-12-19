#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), 
        [](auto const &a, auto const &b) { return a[1] > b[1]; });
        // for(int i = 0; i < boxTypes.size(); i++){
        //     cout << "Element: " << boxTypes[i][0] << "   " << boxTypes[i][1] << endl;
        // }

        int j = 0;
        // vector<vector<int>> greedySelection;
        int total = 0;
        while(truckSize > 0 && j < boxTypes.size()){
            if(boxTypes[j][0] <= truckSize){
                // greedySelection.push_back({boxTypes[j][0], boxTypes[j][1]});
                total += boxTypes[j][0] * boxTypes[j][1];
                truckSize -= boxTypes[j][0];
            } else if(boxTypes[j][0] > truckSize){
                // greedySelection.push_back({truckSize, boxTypes[j][1]});
                total += truckSize * boxTypes[j][1];
                truckSize -= truckSize;
            }
            // cout << "Greedy: " << greedySelection[j][0] << "   " << greedySelection[j][1] << endl;
            cout << "Greedy: " << boxTypes[j][0] << "   " << boxTypes[j][1] << endl;
            j++;
        }

        // int total = 0;
        // for(int i = 0; i < greedySelection.size(); i++){
        //     total += greedySelection[i][0] * greedySelection[i][1];
        // }

        cout << "Total: " << total << endl;

        return total;
    }
};