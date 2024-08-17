#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class listNode {
    private:
        char key;
        listNode* next;
    public:
        listNode(char c);
        char getKey() const;
        listNode* getNext() const;
        void setKey(char c);
        void print() const;
};

listNode::listNode(char c){
    key = c;
    next = nullptr;
}

char listNode::getKey() const{
    return key;
}

listNode* listNode::getNext() const{
    return next;
}

void listNode::setKey(char c){
    key = c;
}

void listNode::print() const{
    cout << key;
}

class linkedList{
    private:
        listNode* head;
    public:
        linkedList();
        void insertNode(char c);
        void travel(char stop);
};

linkedList::linkedList(){
    head = nullptr;
}

linkedList::insertNode(char c){
    listNode* newNode = new listNode(c);

    // if empty
    if(head == nullptr){
        head = newNode;
        return;
    }

    listNode* tmp = head;
    while(tmp->getNext != nullptr){
        tmp = tmp->getNext;
    }

}

string reversePrefix(string word, char ch) {
        
    }