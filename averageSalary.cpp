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
        if(salary[i] < min){
            min = salary[i];
        } 
        if(salary[i] > max){
            max = salary[i];
        }
    }
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Sum: " << min << endl;
    sum -= (min + max);
    return sum/(salary.size()-2);
}

int main (){
    vector<int> count = {4000,3000,1000,2000};
    count = {1000,2000,3000};
    cout << average(count) << endl;
    return 0;
}