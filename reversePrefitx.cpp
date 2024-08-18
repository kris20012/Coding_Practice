#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class listNode {
    private:
        //char key;
        //listNode* next;
    public:
        char key;
        listNode* next;
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
    public:
        linkedList();
        void insertNode(char c);
        void printRev();
};

linkedList::linkedList(){
    head = nullptr;
}

void linkedList::insertNode(char c){
    listNode* newNode = new listNode(c);

    // if empty
    if(head == nullptr){
        head = newNode;
    } else {
        listNode* tmp = head;
        while(tmp->getNext() != nullptr){
            tmp = tmp->getNext();
        }
        tmp->setNext(newNode);
    }
}

void linkedList::printRev(){
    listNode* tmp = head;
    cout << tmp << endl;
    cout << tmp->getNext();
    cout << "\nTrack\n";
    cout << tmp << endl;
    cout << tmp->getNext() << endl;
    cout << tmp->next->next << endl;
    cout << tmp->next->next->next << endl;
    while(tmp!=nullptr){
        //cout << tmp->getKey();
        cout << tmp << endl;
        cout << tmp->getNext() << endl;

        tmp->setNext(tmp->getNext());
        cout << "SECOND: " << tmp->getNext()<< endl;
        cout << "THIRD: " << tmp->next<< endl;
    }
}

string reversePrefix(string word, char ch) {
    linkedList reverse;
    bool chFound = false;
    for(int i = 0; i < word.size(); i++){
        cout << "HERE\n";
        if(word[i] != ch && !chFound){
            reverse.insertNode(word[i]);
        } else {
            if(!chFound) {
                reverse.printRev();
            }
            chFound = true;
            cout << word[i];
        }
    }
}

int main (){
    reversePrefix("abcdefd", 'd');
    return 0;
}