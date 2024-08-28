#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
using namespace std;

bool isIndexInArray(int element, vector <int> array){
    for(int i = 0; i < array.size(); i++){
        if(array[i] == element) return true;
    }
    return false;
}

void printArr(vector<int> array){
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}

int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    multimap<int, int, greater<int>> orderedMultiMapR1;
    multimap<int, int, greater<int>> orderedMultiMapR2;

    for (int i = 0; i < reward1.size(); i++) {
        //orderedMapR1[reward1[i]] = i;
        orderedMultiMapR1.insert({reward1[i], i});
    }

    for (int i = 0; i < reward2.size(); i++) {
         orderedMultiMapR2.insert({reward2[i], i});
    }

    int count = 0;
    vector <int> typeInd1;
    for (const pair<int, int>& pair : orderedMultiMapR1) {
        cout << "Value: " << pair.first << ", Index: " << pair.second << endl;
        if(count == k) break;
        typeInd1.push_back(pair.second);
        count++;
    }
    cout << "ARRAY OF INDICES 1: ";
    printArr(typeInd1);
    count = 0;
    vector <int> typeInd2;
    for (const pair<int, int>& pair : orderedMultiMapR2) {
        cout << "Value: " << pair.first << ", Index: " << pair.second << endl;
        if(count == k) break;
        if(!isIndexInArray(pair.second, typeInd1)){
            typeInd2.push_back(pair.second);
            count++;
        }
    }
    cout << "ARRAY OF INDICES 2: ";
    printArr(typeInd2);

    int sum = 0;
    for(int i = 0; i < typeInd1.size(); i++){
        sum += reward1[typeInd1[i]];
    }
    for(int i = 0; i < typeInd2.size(); i++){
        sum += reward2[typeInd2[i]];
    }
    return sum;
}

int main() {
    // Example array of integers
    vector<int> rew1 = {1,1,3,4}, rew2 = {4,4,1,1}; 
    int n = 2;

    cout << "Answer: ";
    cout << miceAndCheese(rew1, rew2, n) << endl;

    //reward1 = [1,1], reward2 = [1,1], k = 2
    rew1 = {1,1}, rew2 = {1,1};
    n = 2;

    cout << "Answer: ";
    cout << miceAndCheese(rew1, rew2, n) << endl;

    return 0;
}