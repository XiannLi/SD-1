#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertFirst(int n) {
    Node *newNode = new Node(); // Diperbaiki
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(int n) {
    Node *newNode = new Node(); // Diperbaiki
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter(int n, int check) {
    if (head == NULL){
        cout << "List kosong. Silakan insert di depan. \n";
        return;
    }

    Node *newNode = new Node(); // Diperbaiki
    newNode->value = n;
    newNode->next = NULL;

    Node *p = head;
    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p == NULL){
        cout << "Node dengan nilai " << check << " tidak ketemu. \n";
        delete newNode; // Ini sudah benar untuk mencegah memory leak jika gagal insert
    } else {
        newNode->next = p->next;
        p->next = newNode;
        if (p == tail) {
            tail = newNode;
        }
    }
}

void printList() {
    Node *temp = head;
    cout << "Isi dari linked list : ";
    while(temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main () {
    insertFirst(10);
    insertLast(20);
    insertLast(30);
    insertAfter(25, 20);
    insertFirst(5);

    printList();
    return 0;
}