#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(Node* head) {
    cout << "Isi Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insertFront(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head; 
    head = newNode; 
    display(head);
}

void insertBack(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    display(head);
}

void insertAfter(Node* head, int searchData, int newData) {
    Node* temp = head;
    
    while (temp != NULL && temp->data != searchData) {
        temp = temp->next;
    }
    
    if (temp != NULL) {
        Node* newNode = createNode(newData);
        newNode->next = temp->next; 
        temp->next = newNode; 
        display(head);
    } else {
        cout << "Nilai " << searchData << " tidak ditemukan dalam linked list.\n";
    }
}

void deleteNode(Node*& head, int data) {
    // Jika linked list kosong
    if (head == NULL) {
        cout << "Linked list kosong.\n";
        return;
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next; 
        delete temp;  
        display(head);
        return;
    }

    Node* temp = head;
    Node* prev = NULL;
    
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Nilai " << data << " tidak ditemukan.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    display(head);
}

int main() {
    Node* head = NULL;
    int pilihan, data, searchData;

    do {
        cout << "\n--- MENU SINGLE LINKED LIST ---\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan linked list\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> data;
                insertFront(head, data);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> data;
                insertBack(head, data);
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> data;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> searchData;
                insertAfter(head, searchData, data);
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> data;
                deleteNode(head, data);
                break;
            case 5:
                display(head);
                break;
            case 0:
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    } while (pilihan != 0);
    
    return 0;
}