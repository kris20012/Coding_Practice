#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int countBits(int n) {
    int count = 0;
    while (n > 0) {
        if(n%2 == 1) {
            count++;
        }
        n/=2;
    }
    return count;
}

bool isPrime(int n) {
    if(n == 1 || n == 0) return false;

    int count = 0;
    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            count++;
        }
    }
    if(count == 2){
        return true;
    } else {
        return false;
    }
}

int countPrimeSetBits(int left, int right) {

    int count = 0;

    for(int i = left; i <= right; i++){
        if(isPrime(countBits(i))){
            count++;
        }
    }

    return count;
}

int main (){
    cout << "Bit Num: " << countBits(6) << endl;
    cout << "Bit Num: " << countBits(7) << endl;
    cout << "Bit Num: " << countBits(10) << endl;

    cout << "Prime? " << isPrime(1) << endl;
    cout << "Prime? " << isPrime(2) << endl;
    cout << "Prime? " << isPrime(3) << endl;
    cout << "Prime? " << isPrime(4) << endl;
    cout << "Prime? " << isPrime(5) << endl;
    cout << "Prime? " << isPrime(6) << endl;

    cout << "Ans: " << countPrimeSetBits(6, 10) << endl;
    cout << "Ans: " << countPrimeSetBits(10, 15) << endl;
    return 0;
}