#include <iostream>
#include <string>

using namespace std;

int front = 0;
int back = 0;
int maksimalQueue;
string* queueTeller;

bool isFull() {
    return back == maksimalQueue;
}

bool isEmpty() {
    return back == 0;
}

void enqueueAntrian(const string &data) {
    if (isFull()) {
        cout << "Antrian penuh!" << endl;
    } else {
        queueTeller[back++] = data;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[--back].clear();
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i].clear();
        }
        back = 0;
    }
}

void viewQueue() {
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (!queueTeller[i].empty()) {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

void displayFront() {
    if (!isEmpty()) {
        cout << "Elemen terdepan: " << queueTeller[0] << endl;
    } else {
        cout << "Antrian kosong!" << endl;
    }
}

void displayBack() {
    if (!isEmpty()) {
        cout << "Elemen terakhir: " << queueTeller[back - 1] << endl;
    } else {
        cout << "Antrian kosong!" << endl;
    }
}

int main() {
    cout << "Masukkan ukuran maksimal antrian: ";
    cin >> maksimalQueue;

    queueTeller = new string[maksimalQueue];

    int pilihan;
    string nama;

    do {
        cout << "\n===== Menu Queue Teller =====" << endl;
        cout << "1. Enqueue (Memasukkan antrian)" << endl;
        cout << "2. Dequeue (Mengeluarkan antrian)" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Hitung Antrian" << endl;
        cout << "5. Hapus Antrian" << endl;
        cout << "6. Tampilkan Elemen Terdepan" << endl;
        cout << "7. Tampilkan Elemen Terakhir" << endl;
        cout << "8. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                enqueueAntrian(nama);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                cout << "Jumlah antrian: " << countQueue() << endl;
                break;
            case 5:
                clearQueue();
                break;
            case 6:
                displayFront();
                break;
            case 7:
                displayBack();
                break;
            case 8:
                cout << "Terima kasih! Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 8);

    delete[] queueTeller; // Membersihkan memori yang dialokasikan
    return 0;
}