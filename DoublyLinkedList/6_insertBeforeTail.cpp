#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }

    Node(int data, Node* next,  Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }
};

Node* convertTODLL(vector<int> &v){
    Node* head = new Node(v[0]);
    Node* prev = head;

    for(int i = 1; i < v.size(); i++){
        Node* temp = new Node(v[i]);
        temp->back = prev;
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}

void traverseDLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}

Node* insertBeforeHead(Node* head, int val){
    if(head==nullptr) return new Node(val);

    Node* newHead = new Node(val);
    newHead->next = head;
    head->back = newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head, int val){
    if(head==nullptr) return new Node(val);
    if(head->next == nullptr){ // only one element, same as inserting before head
        return insertBeforeHead(head, val);
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp= temp->next;
    }

    Node* newNode = new Node(val);
    Node* prev = temp->back;
    prev->next = newNode;
    newNode->back = prev;
    newNode->next = temp;
    temp->back = newNode;
    
    return head;
}

int main(){
    vector<int> arr = {10, 15, 13, 45, 32};

    Node* head = convertTODLL(arr);

    head = insertBeforeTail(head, 8);

    traverseDLL(head);

    return 0;
}