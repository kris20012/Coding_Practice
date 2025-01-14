#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0, rp = height.size() - 1;
        int max = 0;
        int lower = 0;

        while(lp < rp){
            // lower = height[lp] < height[rp] ? height[lp] : height[rp];
            // cout << "Ends: " << height[lp] << "    " << height[rp] << endl;
            if(height[lp] < height[rp]){
                lower = height[lp];
            } else {
                lower = height[rp];
            }
            if(lower * (rp - lp) > max) max = lower * (rp - lp);
            if(height[lp] < height[rp]){
                lp++;
            } else {
                rp--;
            }
            // cout << "Max: " << max << endl;
        }
        return max;
    }
};