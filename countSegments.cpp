#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>  // For std::priority_queue

using namespace std;

int countSegments(string s) {
    int count = 0;

    if(s == "") return 0;

    for(int i = 0, j = 1; i < s.size() && j < s.size(); i++, j++){
        if(s[i] != ' ' && s[j] == ' ') count++;
    }

    count += (s[s.size() - 1] != ' ') ? 1 : 0;

    return count;
}

int main() {
    string s = "hello";
    int num = countSegments(s);
    cout << s << " has " << num << " segments\n";

    s = "Hello, my name is John";
    num = countSegments(s);
    cout << s << " has " << num << " segments\n";

    return 0;
}