
#include <iostream>
#include <string>
#include <vector>
using namespace std;

    int isPrefixOfWord(string sentence, string searchWord) {
        vector <string> array;
        string tmpStr = sentence;
        int arrind = 0;
        int start = 0;

        for(int i = 0; i < sentence.size(); i++){
        
            if(sentence[i] == ' '){
                array.push_back(sentence.substr(start, i - start));
                cout << "Count: " << arrind << endl << array.back << endl;
                arrind++;
                start = i+1;
                //array[arrind] = sentence.substr(start);
                //cout << "Count: " << arrind << endl << array[arrind]<< endl;
            } 
        }
        array.push_back(sentence.substr(start));
        cout << "Count: " << arrind << endl << array.back << endl;
        cout << array << endl;

        for(int i = 0; i < array.size(); i++){
            cout << "Word: " << array[i] << endl;
            if(array[i].find(searchWord) == 0){
                cout << "word found\n";
                return i+1;
            }
        }
        return -1;
    }

    int main(){
        cout << isPrefixOfWord("i love eating burgers", "burg") << endl;

        return 0;
    }
 