#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, int> charFreq;
        unordered_map<char, char> mapping;
        int counter = 0;
        string decoded = "";

        for(int i = 0; i < key.length(); i++){
            // cout << "Key Char: " << key[i];
            charFreq[key[i]]++;
            if(charFreq[key[i]] > 1 || key[i] == ' ') continue;
            else {
                mapping[key[i]] = 'a' + counter;
                cout << "Key Char: " << key[i] << "   Mapping: " << mapping[key[i]] << endl;
                counter++;
            }
        }

        // decode message
        for(int i = 0; i < message.length(); i++){
            if(message[i] == ' ') {
                decoded += ' ';
                continue;
            }
            cout << "Decoded Char: " << message[i] << "   " << mapping[message[i]] << endl;
            decoded += mapping[message[i]];
        }
        return decoded;
    }
};