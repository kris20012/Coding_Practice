
#include <iostream>
#include <string>
#include <vector>
using namespace std;

    bool isVowel (char c){
        switch(c){
            case 'a':
                return true;
                break;
            case 'e':
                return true;
                break;
            case 'i':
                return true;
                break;
            case 'o':
                return true;
                break;
            case 'u':
                return true;
                break;
            default:
                return false;
        }
    }

    int maxVowels(string s, int k) {
        int maxLen = 0;
        int prevMax = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                maxLen++;
            } else {
                if(maxLen > prevMax){
                    prevMax = maxLen;
                    maxLen = 0;
                }
            }
        }
        if(maxLen > prevMax){
            prevMax = maxLen;
        }
        if(prevMax > k){
            return k;
        } else {
            return prevMax;
        }
    }

    int main(){
        cout << maxVowels("aeiou", 2) << endl;
        cout << maxVowels("abciiidef", 3) << endl;
        cout << maxVowels("leetcode", 3) << endl;


        return 0;
    }
 