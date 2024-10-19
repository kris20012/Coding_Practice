#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool check(unordered_map <char, int> digits){
        for(unordered_map<char, int>::iterator it= digits.begin(); it != digits.end(); it++){
            cout << "Col Value: " << it->first << "      Count: " << it->second << endl;
            if(it->first == '.'){

            } else {
                if(it->second > 1) return false;
            }
        }
        return true;
    }

    bool processGrid (vector<vector<char>>& board, unordered_map <char, int>& ht, int startRow, int startCol){
        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                // cout << "Char: " << board[i][j] << endl;
                ht[board[i][j]]++;
            }
        }

        for(unordered_map<char, int>::iterator it= ht.begin(); it != ht.end(); it++){
            // cout << "Grid Value: " << it->first << "      Count: " << it->second << endl;
            if(it->first == '.'){
                continue;
            } else {
                if(it->second > 1) {
                    cout << "FALSE" << endl;
                    return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map <char, int> hashTable;
        bool rowCheck, colCheck, gridCheck;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                // cout << "Char: " << board[i][j] << endl;
                hashTable[board[i][j]]++;
            }
            rowCheck = check(hashTable);
            // cout << "Row End" << endl;
            if(rowCheck == false)
                    goto c1;
            hashTable.clear();
        }
        c1:
        cout << "COLUMN\n";
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                // cout << "Char: " << board[j][i] << endl;
                hashTable[board[j][i]]++;
            }
            colCheck = check(hashTable);
            cout << "Col End" << endl;
            if(colCheck == false)
                    goto c2;
            hashTable.clear();
        }
        c2:
        for(int i = 0; i < board.size(); i+=3){
            for(int j = 0; j < board[0].size(); j+=3){
                gridCheck = processGrid(board, hashTable, i, j);
                hashTable.clear();
                if(gridCheck == false)
                    goto end;
                // cout << "Char: " << board[i/3*3][j/3] << endl;
            }
        }
        end:
        cout << "Row: " << rowCheck << " Col: " << colCheck << " Grid: " << gridCheck << endl;
        if(gridCheck == true && rowCheck == true && colCheck == true){
            return true;
        } else {
            return false;
        }
    }
    
};