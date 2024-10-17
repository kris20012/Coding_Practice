#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindromeHelper(vector<int> & array, int left, int right){
        if(left == right) { //121
            cout << "\nLefty: " << left << "    Righty: " << right << endl;
            return true; 
        } else if (left + 1 == right && array[left] == array[right]){ //1221
            cout << "\nLefty2: " << left << "    Righty2: " << right << endl;
            return true; 
        }
        if (left > right) {
            return false;
        }
        cout << "\nLeft: " << array[left] << "    Right: " << array[right] << endl;
        if(array[left] == array[right]) return isPalindromeHelper(array, left+1, right-1);
        else return false;

    }

    bool isPalindrome(int x) {
        vector <int> pal;
        if(x < 0) return false;

        cout << "Array: ";
        while(true){
            pal.push_back(x % 10);
            cout << x % 10;
            x /= 10;
            if(x == 0) break;
        }

        return isPalindromeHelper(pal, 0, pal.size() - 1);
    }