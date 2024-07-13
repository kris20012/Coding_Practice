/*

    INPUT: string s
    OUTPUT: longest substring w/o repeat char

*/

#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int count = 0;
    int longest_count = 0;

    //var to track prev and cur char
    char prevC, currC;

    //traverse thruough string
    for (int i = 0; i < s.length(); i++){
        prevC = currC;
        currC = s[i];

        if(currC == prevC){
            if(count > longest_count){
                longest_count = count;
            }
            count = 0;
        } else {
            count++;
        }

        if(s[i+1] == '\0'){
            if(count > longest_count){
                longest_count = count;
            }
        }

    }

    return longest_count;
}

int main() {
    string myString = "Hello, World!";
    //string myString = "pwwkew";

    int total = lengthOfLongestSubstring(myString);

    cout << "Total Length: " << total << endl;
    return 0;
}