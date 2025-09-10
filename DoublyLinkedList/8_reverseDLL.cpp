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

// brute force solution, O(2N), TWO passes required
// T.C: O(2n) and S.C: O(n)
Node* reverseDLLbruteForce(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
 
    Node* temp = head;
    stack<int> st;
    while(temp != nullptr){
        st.push(temp->data);
        temp=temp->next;
    }

    temp = head;
    while(temp != nullptr){
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }
    return head;

}

// T.C: O(n), S.C: O(1)
Node* reverseDLLoptimal(Node* head){
    if(head == nullptr || head->next == nullptr) return head;

    Node* current = head;
    Node* prev = nullptr;

    while(current != nullptr){
        prev = current -> back;
        current->back = current->next;
        current->next = prev;

        //move ahead
        current = current->back;
    }

    return prev->back;
}

int main(){
    vector<int> arr = {10, 15, 13, 45, 32};

    Node* head = convertTODLL(arr);

    head = reverseDLLbruteForce(head);
    traverseDLL(head);

    head = reverseDLLoptimal(head);
    traverseDLL(head);

    return 0;
}