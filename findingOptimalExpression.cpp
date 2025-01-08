#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int calculator(string expression){
        string op1, op2, op3, op4;
        int pos_lb, pos_rb, pos_p;
        cout << "Assess: " << expression << endl;
        for(int i = 0; i < expression.length(); i++){
            if(expression[i] == '('){
                op1 = expression.substr(0,i);
                pos_lb = i;
            } else if(expression[i] == ')'){
                op2 = expression.substr(i+1);
                pos_rb = i;
                op4 = expression.substr(pos_p+1, pos_rb - pos_p - 1);
            } else if(expression[i] == '+'){
                op3 = expression.substr(pos_lb + 1, i - pos_lb - 1);
                pos_p = i;
            }
        }
        if(op1 == "" || op1 == "(") op1 = "1";
        if(op2 == "" || op2 == ")") op2 = "1";
        cout << "Op1: " << op1 << "     Op2: " << op2 << "      Op3: " << op3 << "      Op4: " << op4 << endl;
        int total = 0;
        total = stoi(op1) * (stoi(op3) + stoi(op4)) * stoi(op2);
        cout << "Total: " << total << endl;

        return total;
    }

    string minimizeResult(string expression) {
        int smallestVal = 99999999;
        string smallest = "";
        string modify = expression;
        int trans = expression.length();
        for (int i = 0; i < trans; i++){ // i is lb pos and j is rb pos
            for(int j = expression.length(); j > 0; j--){
                modify = expression;
                if(expression[j-1] == '+') break;
                modify = modify.insert(i, "(");
                modify = modify.insert(j+1, ")");
                cout << "New: " << modify << "  J: " << j << "   I: " << i << endl;

                int calcExp = calculator(modify);
                if(calcExp < smallestVal) {
                    smallest = modify;
                    smallestVal = calcExp;
                }
            }
            if(expression[i+1] == '+') trans = i;
        }
        //calculator(expression);
        return smallest;
    }
};