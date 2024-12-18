#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

int minCostToMoveChips(vector<int>& position) {
        // Naive approach
        // unordered_map <int, int> ht;
        // for(int i = 0; i < position.size(); i++){
        //     ht[position[i]]++;
        // }

        // int max = 0;
        // int mode = 0;

        // for(unordered_map<int, int>::iterator it = ht.begin(); it != ht.end(); it++) {
        //     cout << "Elements: " << it->first << " " << it->second << endl;
        //     if(it->second > max){
        //         max = it->second;
        //         mode = it->first;
        //     }
        // }

        // cout << "Mode: " << mode << endl;
        // int cost = 0;
        // for(int i = 0; i < position.size(); i++){
        //     if(position[i] == mode) continue;
        //     else if(position[i] - mode == 1 || position[i] - mode == -1) cost++;
        //     else if(position[i] - mode > 2 || position[i] - mode < -2) cost++;
        // }
        // cout << "Min Cost: " << cost << endl;

        // Using hints
        int cost = 0, odd = 0, even = 0;
        for(int i = 0; i < position.size(); i++){
            if(position[i] % 2 == 1) odd++;
            else even++;
        }

        if(odd == position.size() || even == position.size()) return 0;

        cost = min(odd, even);

        return cost;
    }