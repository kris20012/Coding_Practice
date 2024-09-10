#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>  
#include <math.h> 
using namespace std;

void printArr(vector<string> array){
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}

bool isExist(vector<string> array, string s){
    for(int i = 0; i < array.size(); i++){
        if(s == array[i]) {
            return true;
        }
    }
    return false;
}

string stringExtractor(int start, int end, string s){
    string tmp;

    for(int i = start; i < end + 1; i++){
        tmp += s[i];
    }
    
    return tmp;
}

vector<string> findRepeatedDnaSequences(string s) {
    vector <string> tmp;
    string seq, check;

    for(int j = 0; j + 9 < s.size(); j++){
        seq = stringExtractor(j, 9 + j, s);
        for(int i = j + 1; 9 + i < s.size(); i++){
            check = stringExtractor(i, 9 + i, s);
            if (seq == check && !isExist(tmp, check)){
                tmp.push_back(seq);
            }
        }
    }

    return tmp;

}

int main() {
    string test = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> eval;

    cout << "ANSWER: \n";
    eval = findRepeatedDnaSequences(test);
    printArr(eval);

    test = "AAAAAAAAAAAAAAAAAAAAAAAAAA";
    cout << "ANSWER: \n";
    eval = findRepeatedDnaSequences(test);
    printArr(eval);

    return 0;
}