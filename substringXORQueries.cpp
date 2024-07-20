#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to convert binary to decimal
int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

vector<int> substringHelper(int first, int second, string s) {
        int min = 9999;
        vector<int> minAns = {-1, -1};

        
        for(int i = 0; i < s.size()+1; i++){
            for(int j = 0; j < s.size()+1; j++){
                /*
                char *cstr = new char[str.size() + 1];
                std::strcpy(cstr, str.c_str());
                // do stuff
                delete [] cstr;
                */
                
                //char * str = s.substr(i, j).data();

                char * cstr = new char[s.size()+1];
                strcpy(cstr, s.substr(i,j).c_str());
                int charNum = s.substr(i,j).size();
                cout << "Char Num: " << charNum << endl;
                int val = atoi(cstr);
                val = binaryToDecimal(val);
                //int val = stoi(s.substr(i,j), nullptr, 2);
                cout << cstr << " : " << val << endl;
                if((val ^ first) == second && (charNum < min && charNum != 0)){
                    cout << "Match: " << val << "       i: " << i << "       j: " << j+i-1 << endl;
                    min = charNum;
                    minAns = {i, j+i-1};
                }
            }
        }
        
        return minAns;
}

vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        
        for(int i = 0; i < queries.size(); i++){
            cout << "\nQuery #" << i << endl;
            ans.push_back(substringHelper(queries[i][0], queries[i][1], s));
        }
        
        return ans;
}

void subStringPrint(vector<vector<int>>& ss){
    for (int i = 0; i < ss.size(); i++)
    {
        for(int j = 0; j < ss[i].size(); j++){
            cout << ss[i][j];
        }
        cout << endl;
    }
    
}

int main(){
    vector<vector<int>> queries; 
    string s; 
    vector<vector<int>> subString;
   
    s = "101101";
    queries = {{0,5},{1,2}};
    subString = substringXorQueries(s, queries);
    cout << "Printing Queries\n";
    subStringPrint(queries);

    cout << "Printing Answer\n";
    subStringPrint(subString);
    cout << "---------------------------DONE----------------------------\n";

    s = "0101";
    queries = {{12,8}};
    subString = substringXorQueries(s, queries);
    cout << "Printing Queries\n";
    subStringPrint(queries);

    cout << "Printing Answer\n";
    subStringPrint(subString);
    cout << "---------------------------DONE----------------------------\n";

    s = "1";
    queries = {{4,5}};
    subString = substringXorQueries(s, queries);
    cout << "Printing Queries\n";
    subStringPrint(queries);

    cout << "Printing Answer\n";
    subStringPrint(subString);
    cout << "---------------------------DONE----------------------------\n";

    s = "111010110";
    //queries = {{4,2},{3,3},{6,4},{9,9},{10,28},{0,470},{5,83},{10,28},{8,15},{6,464},{0,3},{5,8},{7,7},{8,8},{6,208},{9,15},{2,2},{9,95}};
    queries = {{4,2},{3,3},{6,4}};//,{9,9},{10,28},{0,470},{5,83},{10,28},{8,15},{6,464},{0,3},{5,8},{7,7},{8,8},{6,208},{9,15},{2,2},{9,95}};
    subString = substringXorQueries(s, queries);
    cout << "Printing Queries\n";
    subStringPrint(queries);

    cout << "Printing Answer\n";
    subStringPrint(subString);
    cout << "---------------------------DONE----------------------------\n";

    s = "11101010111";
    //queries = {{4,2},{3,3},{6,4},{9,9},{10,28},{0,470},{5,83},{10,28},{8,15},{6,464},{0,3},{5,8},{7,7},{8,8},{6,208},{9,15},{2,2},{9,95}};
    queries = {{8,1887}};
    subString = substringXorQueries(s, queries);
    cout << "Printing Queries\n";
    subStringPrint(queries);

    cout << "Printing Answer\n";
    subStringPrint(subString);
    cout << "---------------------------DONE----------------------------\n";

    return 0;
}