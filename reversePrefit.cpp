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
        void setNext(listNode* n);
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

void listNode::setNext(listNode* n) {
    next = n;
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
        string master;
    public:
        linkedList();
        void insertNode(char c);
        void printRev();
        void update(char c);
        string answer();
};

linkedList::linkedList(){
    head = nullptr;
    master = "";
}

void linkedList::insertNode(char c){
    listNode* newNode = new listNode(c);

    // if empty
    if(head == nullptr){
        head = newNode;
    } else {
        newNode->setNext(head);
        head = newNode;
    }
}

void linkedList::printRev(){
    listNode* tmp = head;
    while(tmp!=nullptr){
        update(tmp->getKey());
        tmp = tmp->getNext();
    }
}

void linkedList::update(char c){
    master += c;
}

string linkedList::answer(){
    return master;
}

string reversePrefix(string word, char ch) {
    linkedList reverse;
    bool chFound = false;
    for(int i = 0; i < word.size(); i++){
        if(word[i] != ch && !chFound){
            reverse.insertNode(word[i]);
        } else {
            if(!chFound) {
                reverse.insertNode(word[i]);
                reverse.printRev();
                chFound = true;
                continue;
            }
            reverse.update(word[i]);
        }
    }
    if(!chFound) return word;
    return reverse.answer();
}

int main (){
    cout << reversePrefix("abcdefd", 'd');
    cout << "\n";
    return 0;
}