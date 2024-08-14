#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

// [x1, y1, x2, y2] 

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    
    if((rec2[0] < rec1[2] && rec1[0] < rec2[2])){
        if(rec2[1] < rec1[3] && rec1[1] < rec2[3]){
            return true;
        }
    }

    return false;
}

int main (){
    vector <int> first = {4,4,14,7};
    vector <int> second = {4,3,8,8};

    //isRectangleOverlap(first, second);

    first = {-4,-9,-2,3};
    second = {1,-5,9,-1};

    isRectangleOverlap(first, second);
}