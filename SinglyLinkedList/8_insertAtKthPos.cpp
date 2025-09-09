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

Node* insertAtKthPos(Node* head, int key, int val){
    // can't insert if there is no head
    if(head == nullptr) return head;

    // if head is null and key = 1, then we can only insert in the first position
    if(head==nullptr || key==1) return new Node(val);

    // if key value is 1
    if(key == 1){
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }
    
    Node* temp = head;
    Node* prev = nullptr;
    int count = 0;

    while(temp){
        count++;
        if(count == key){
            Node* newNode = new Node(val);
            prev->next = newNode;
            newNode->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node* insertAtKthPos2(Node* head, int key, int val){
    // can't insert if there is no head
    if(head == nullptr) return head;

    // if head is null and key = 1, then we can only insert in the first position
    if(head==nullptr || key==1) return new Node(val);

    // if key value is 1
    if(key == 1){
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    int count = 0;
    while(temp){
        count++;
        if(count == key-1){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int val, int data){
    // can't insert if there is no head
    if(head == nullptr) return head;

    // if key value is 1
    if(head->data == val){
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    while(temp->next){
        if(temp->next->data == val){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {10, 15, 13, 45, 32}; 

    Node* head = convert2LL(arr);

    head = insertAtKthPos(head, 3, 8);
    traverseLL(head);

    head = insertAtKthPos2(head, 2, 7);
    traverseLL(head);

    return 0;
}