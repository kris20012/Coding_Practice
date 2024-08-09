#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycleHelper(ListNode *current, vector <ListNode *> list){
    for (int i = 0; i < list.size(); i++)
    {
        /* code */
        if(list[i] == current){
            cout << "List Ptr Val: " << list[i] << endl;
            return true;
        }
    }
    return false;
}
 
bool hasCycle(ListNode *head) {
    vector <ListNode *> seenPointers;
    ListNode *current = head;

    while(current!=nullptr){
        cout << "Current Value: " << current << endl;
        if(hasCycleHelper(current, seenPointers)){
            return true;
        }
        seenPointers.push_back(current);
        current = current -> next;
    }
    return false;
}
