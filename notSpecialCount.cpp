#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

bool isSpecial(int n){
    int half = n/2;
    //cout << "HAlf: " << half<<  endl;

    int count = 0;

    for(int i = 1; i <=half ; i++){
        if(n % i ==0){
            count++;
        }
    }
    if(count == 2){
       // cout << "SPECIAL: " << n << endl;
    }
    return (count == 2) ? true : false;
}

int nonSpecialCount(int l, int r) {
    int count = 0;
    for(int i = l; i <= r; i++){
        if(!isSpecial(i)){
            count++;
        }
        //cout << "Count: " << count << endl;
    }
    return count;
}

int main (){
    //cout << isSpecial(6) << endl;
    //cout << isSpecial(4) << endl;

    //cout << nonSpecialCount(5, 7) << endl;
    cout << nonSpecialCount(4, 16) << endl;
}