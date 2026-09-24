#include <iostream>
using namespace std;

#define MAX 6
int queue[MAX];
int front = -1, rear = -1; 

// TODO : Enqueue
void enqueue( int value ) {
    if (rear == MAX - 1) {
        cout << "Queue penuh!\n";
    } else {
        if (front == -1) front = 0; 
        rear++;
        queue[rear] = value;
        cout << value << " ditambahkan ke queue.\n";
    }   
}

// TODO : Dequeue
void dequeue() {
    if (front == -1 || front > rear){
        cout << "Queue kosong!\n";
    } else {
        cout << "\n" << queue[front] << " keluar dari queue.\n";
        front++;
    }
}

// TODO : Nampilin isi queue
void display() {
    if (front == -1 || front > rear) {
        cout << "Queue kosong!\n";
    } else {
        cout << "\nIsi queue: \n";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main () {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    enqueue(6);
    display();

    dequeue();
    display();

    return 0;
}