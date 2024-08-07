#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int bitwiseComplement(int n) {
    if (n == 0){
        return 1;
    }
    
    string binary = bitset<32>(n).to_string(); //to binary
    //cout<<binary<<"\n";

    int startIndex = 0;

    // find index of 1st zero
    for(int i = 0; i < binary.length(); i++){
        if (binary[i] == '1') {
            startIndex = i;
            //cout << startIndex << endl;
            break;
        } 
    }
    string complement = "";
    // take from end of string and flip
    for (int i = startIndex; i < binary.length(); i++)
    {
       //cout << binary[i] << "\n";

        if (binary[i] == '0')
        {
            complement.append("1");
        } else
        {
            complement.append("0");
        }

    }
    
    cout << complement << endl;
    return stoi(complement, nullptr, 2);
}

int main(){
    
    cout << bitwiseComplement(127) << endl;
    cout << bitwiseComplement(5) << endl;
    cout << bitwiseComplement(10) << endl;
    cout << bitwiseComplement(0) << endl;

    return 0;
}