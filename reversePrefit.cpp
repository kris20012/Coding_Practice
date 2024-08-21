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
        void deleteNode(int nodeOffset);
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

void linkedList::deleteNode(int nodeOffset) 
{ 
    listNode *temp1 = head, *temp2 = NULL; 
    int ListLen = 0; 
  
    if (head == NULL) { 
        cout << "List empty." << endl; 
        return; 
    } 
  
    // Find length of the linked-list. 
    while (temp1 != NULL) { 
        temp1 = temp1->getNext(); 
        ListLen++; 
    } 
  
    // Check if the position to be 
    // deleted is greater than the length 
    // of the linked list. 
    if (ListLen < nodeOffset) { 
        cout << "Index out of range"
             << endl; 
        return; 
    } 
  
    // Declare temp1 
    temp1 = head; 
  
    // Deleting the head. 
    if (nodeOffset == 1) { 
  
        // Update head 
        head = head->getNext(); 
        delete temp1; 
        return; 
    } 
  
    // Traverse the list to 
    // find the node to be deleted. 
    while (nodeOffset-- > 1) { 
  
        // Update temp2 
        temp2 = temp1; 
  
        // Update temp1 
        temp1 = temp1->getNext(); 
    } 
  
    // Change the next pointer 
    // of the previous node. 
    temp2->setNext(temp1->getNext); 
  
    // Delete the node 
    delete temp1; 
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