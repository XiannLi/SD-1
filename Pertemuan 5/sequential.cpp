#include <iostream>
using namespace std;

int main() {
    int n, key, posisi = -1;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    int data[n];

    cout << "Masukkan elemen data: ";
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    cout << "Masukkan elemen yang dicari: ";
    cin >> key;

    //TODO: Proses pencarian sequential/linear
    for (int i = 0; i < n; i++) {
        if (data[i] == key) {
            posisi = i; //simpan posisi ketika ketemu
            break; //karena data sudah ketemu
        }
    }

    //Output Hasil
    if (posisi != -1) {
        cout << "Data ditemukan di posisi ke-" << posisi + 1 << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}