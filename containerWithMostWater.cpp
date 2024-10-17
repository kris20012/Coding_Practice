#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int calculateArea(int start, int end, int width){
if(start < end){
    return start * width;
} else {
    return end * width;
}
}

int maxArea(vector<int>& height) {
    int max = 0;
    int area = 0;
    int width = 0;
    int left = 0;
    int right = 0;

    // Naive approach doesn't fit run time
    // for(int i = 0; i < height.size(); i++){
    //     for(int j = i + 1; j < height.size(); j++){
    //         cout << "I: " << height[i] << "     J: " << height[j] << endl;
    //         width = i < j ? j - i : i - j;
    //         area = calculateArea(height[i], height[j], width);
    //         if(area > max) max = area;
    //     }
    // }

    left = 0;
    right = height.size() - 1;

    while(right >= 0 && left < height.size()){
        cout << "Left: " << height[left] << "     Right: " << height[right] << endl;
        width = right - left;
        area = calculateArea(height[left], height[right], width);
        if(area > max) max = area;
        if(left > right) break;
        if(height[left] > height[right]){
            right--;
        } else {
            left++;
        }

    }

    return max;

}