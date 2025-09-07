#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convert2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverseLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertNewHead(Node* head, int val){
    Node* newHead = new Node(val);
    newHead->next = head;
    return newHead;
}

int main(){
    vector<int> arr = {10, 15, 13, 45, 32}; 

    Node* head = convert2LL(arr);

    head = insertNewHead(head, 8);

    traverseLL(head);
    return 0;
}