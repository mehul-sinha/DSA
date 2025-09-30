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

//T.C O(n)
Node* reverseIterative(Node* head){
    if(head == nullptr || head->next == nullptr) return head;

    Node* current = head;
    Node* front = nullptr;
    Node* prev = nullptr;

    while(current!=nullptr){
        front = current->next;
        current->next = prev;
        prev = current;
        current = front;
    }

    return prev;
}

//T.C O(n)
//S.C O(n) --> recursive stack space
Node* reverseRecursive(Node* head){
    if(head == nullptr || head->next==nullptr) return head; // base case

    Node* newHead = reverseRecursive(head->next);
    Node* front = newHead->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}

int main(){
    vector<int> arr = {10, 15, 13, 45, 32}; 

    Node* head = convert2LL(arr);

    head = reverseIterative(head);
    traverseLL(head);

    head = reverseIterative(head);
    traverseLL(head);

    return 0;
}