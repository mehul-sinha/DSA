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

Node* deleteKthElement(Node* head, int key){
    //if the LL is empty
    if(head == nullptr) return head;

    //if key == 1;
    if(key == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    //If key is any other element
    Node* temp = head;
    // have to store prev head to delete the next head
    Node* prev = nullptr;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == key){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;    
}

int main(){
    vector<int> arr = {10, 15, 13, 45, 32}; 

    Node* head = convert2LL(arr);

    // T.C: O(k)
    head = deleteKthElement(head, 2);

    traverseLL(head);
    return 0;
}