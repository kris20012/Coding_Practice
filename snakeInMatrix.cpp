#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ver = 0, hor = 0; // i and j
        for(int i = 0; i < commands.size(); i++){
            if(commands[i] == "LEFT") hor--;
            else if(commands[i] == "RIGHT") hor++;
            else if(commands[i] == "UP") ver--;
            else if(commands[i] == "DOWN") ver++;
            else cout << "INVALID" << endl;
        }
    
        return (ver * n) + hor;
    }
};