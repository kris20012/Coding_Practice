#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

double average(vector<int>& salary) {
    double sum = 0;
    int min = 999999, max = 0;
    for(int i = 0; i < salary.size(); i++){
        sum += salary[i];
        min = (salary[i] < min) ? salary[i] : min;
        max = (salary[i] > max) ? salary[i]: max;
    }
    sum -= (min + max);
    return sum/(salary.size()-2);
}

int main (){
    vector<int> count = {4000,3000,1000,2000};
    count = {1000,2000,3000};
    cout << average(count) << endl;
    return 0;
}