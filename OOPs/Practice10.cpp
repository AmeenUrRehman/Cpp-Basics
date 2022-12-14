#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;


    //Constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }


};

void InsertionAtHead(Node* &head , int d){

    //New Node Create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertionarTail(Node* &tail , int d){

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void InsertionatPosition(Node* &tail, Node* &head, int position , int d){

    if(position == 1){
        InsertionAtHead(head , d);
        return;
    }
    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1){
        temp = temp->next;
        cnt++;
    }

    if(temp -> next == NULL){
        InsertionarTail(tail , d);
        return ;
    }

    Node* nodetoInsert = new Node(d);
    nodetoInsert -> next = temp -> next ;
    temp -> next = nodetoInsert;
    
}


void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next ;

    }
    cout << endl;
}

int main(){
    Node* node1 = new Node(10);
  /*
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;
*/
    Node* head = node1;
    Node* tail = node1;

    InsertionarTail(tail,12);
    print(head);
    InsertionarTail(tail,15);
    print(head);

    InsertionatPosition(tail, head,3,22);
    print(head);



    return 0;
}