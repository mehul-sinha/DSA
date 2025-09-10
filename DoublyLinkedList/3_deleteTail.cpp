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

Node* deleteTail(Node* head){

    //if head is null or DLL has only one element, nothing can be deleted
    if(head == nullptr || head->next == nullptr) return head;

    Node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->back->next = nullptr;
    temp->back = nullptr;
    delete temp;

    return head;
}

int main(){
    vector<int> arr = {10, 15, 13, 45, 32};

    Node* head = convertTODLL(arr);

    head = deleteTail(head);

    traverseDLL(head);

    return 0;
}