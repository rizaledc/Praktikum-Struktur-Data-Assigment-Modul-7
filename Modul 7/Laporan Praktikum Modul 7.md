# <h1 align="center">Laporan Praktikum Modul Stack dan Queue</h1>

<p align="center">Rizal Wahyu Pratama</p>
<p align="center">2311110029</p>
<p align="center">S1SD-04-B</p>

## Tujuan Praktikum

 a. Mampu memahami konsep stack dan queue pada struktur data dan algoritma
 
 b. Mampu mengimplementasikan operasi-operasi pada stack dan queue
 
 c. Mampu memecahkan permasalahan dengan solusi stack dan queue

## Dasar Teori

Sebagai mahasiswa Sains Data semester 2 di mata kuliah algoritma dan struktur data, sudah tentunya kita akan mendapatkan materi stack dan queue karena kedua hal ini memiliki peran pentimng dalam penstrukturan data. Berikut ini adalah definisinya:

a. STACK
Stack merupakan struktur data linear yang di mana penambahan maupun pengurangan elemen dapat dilakukan di satu ujungnya saja. Operasi pada stack menggunakan penyisipan (push) serta penghapusan (pop) elemen dari salah satu ujung saja dari tumpukan data. Salah satu contohnya adalah tumpukan buku di atas meja, dimana buku yang diletakkan terakhir akan yang pertama dapat diambil, oleh karena itu stack disebut bersifat  LIFO (Last In First Out) dan objek yang terakhir masuk ke dalam stack akan menjadi benda pertama yang dikeluarkan dari stack itu [2]. Berikut ini merupakan contoh gambarannya:

<p align="center">
  <img src="https://github.com/rizaledc/Praktikum-Struktur-Data-Assigment-Modul-7/blob/main/Modul%207/SS%20Code%20and%20Output/LIFO.png" alt="Alt Text">
</p>

- Yang pertama stack masih kosong
- Lalu dimasukkan elemen pertama pada stack
- Dimasukkan elemen-elemen lainnya juga
- Ketika elemen dikeluarkan maka elemen terakhir yang akan keluar pertama
- Prinsip inilah yang disebut dengan LIFO

b. QUEUE
Queue merupakan struktur data linear, namun memiliki penambahan komponen yang dilakukan di datu ujungnya. Sementara, pengurangan akan terjadi di ujung lainnya. Queue menggunakan prinsip penyisipan yang disebut dengan enqueue serta penghapusan yang disebut dengan dequeue salah satu elemen dari ujung antrian data. Salah satu contohnya adalah antrian bioskop, dimana ketika terdapat antrian bioskop yang pertama mengantri akan pertama keluar dan mendapatkan tiketnya. Prinsip ini disebut dengan bersifat FIFO (First In First Out) dengaa cara kerja yang berbanding terbalik dengan stack [2]. Berikut ini contoh penggambaran queue:

<p align="center">
  <img src="https://github.com/rizaledc/Praktikum-Struktur-Data-Assigment-Modul-7/blob/main/Modul%207/SS%20Code%20and%20Output/FIFO.png" alt="Alt Text">
</p>

- Pada yang pertama yaitu elemen angka 2 yang akan dequeue atau keluar sehingga angka 3 akan menjadi headnya.
- berikutnya elemen angka 8 tidak lagi menjadi tail, namun digantikan dengan angka 9 yang baru masuk sebagai tail disebut enqueue.
- Hal ini merupakan penggambaran dari FIFO dan akan terus terjadi prinsipnya.

c. DEQUE
Deque (Double ended Queue) merupakan struktur data gabungan dari queue dan stack [1]. Deque memiliki kemampuan untuk menambahkan dan menghapus elemen di kedua ujungnya. Berbeda dengan queue dan stack yang hanya bisa beroprasu di satu sisi saja. Deque memungkinkan penghapusan elemen dari depan maupun dari belakang data.

## Guided 

### 1. Guided 1

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```

**Penjelasan:**

#### Bagian 1

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;
```

Kode di atas digunakan agar dapat membuat operasi input dan output pada program C++, pada namespace std digunakan agar dalam membuat fungsi tidak perlu menuliskan std lagi. Terdapat deklarasi arrayBuku dengan 5 elemen bertipe string, dengan aturan maksimal array adalah 5. top sebagai penanda posisi berikutnya untuk menambah elemen.

#### Bagian 2

```C++
bool isFull() {
    return (top == maksimal);
}
bool isEmpty() {
    return (top == 0);
}
```

Kode di atas akan mengecek stack penuh atau kosong. Mengembalikan nilai true ketika top maksimal dan mengembalikan true juga jika top sama dengan 0 atau kosong.

#### Bagian 3

```C++
void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}
```

Pada fungsi di atas menambahkan elemen baru ke dalam stack, mengecek apakah stack sudah penuh. Jika penuh akan mengeksekusi sesuai perintah, jika tidak penuh akan menambahkan data ke posisi top++.

Pada fungsi ke-2 kode di atas, akan menghapus elemen pertama dari stack, lalu mengecek apakah stack kosong dengan isEmpty. Jika kosong akan mencetak pesan yang ada, jika tidak kosong akan mengembalikan elemen di posisi top-1.

Berikutnya fungsi ke-3 dari kode akan menampilkan elemen pada posisi tertentu dari atas stack. Mengecek kekosongan stack dengan isEmpty().

#### Bagian 4

```C++
int countStack() {
    return top;
}
void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}
```

Mengembalikan jumlah elemen dalam stak dengan mengembalikan nilai top, lalu terdapat fungsi yang dari atas stack dengan nilai yang baru. Mengecek apakah posisinya melebihi jumlah elemen yang ada. Jika iya, pesan kesalahan, jika tidak maka mengurangi index.

#### Bagian 5

```C++
void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}
```

Menghapus semua elemen dalam stack dengan mengosongkan setiap elemen dari atas ke bawah dan mengatur top ke 0.

#### Bagian 6

```C++
void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}
```

Pada fungsi di atas akan menampilkan semua elemen dalam stack dari atas ke bawah. Mengecek apakah stack kosong dengan isEmpty(). Jika kosong, mencetak pesan bahwa tidak ada data yang dicetak. Jika tidak kosong, mencetak setiap elemen dari atas ke bawah.

#### Bagian 7

```C++
int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << (isFull() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data stack kosong? " << (isEmpty() ? "Ya" : "Tidak") << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```

Fungsi main atau fungsi utama ini merupakan fungsi yang pertama kali akan dieksekusi dalam program. Pada main terdapat berbagai fungsi yang telah dibuat sebelumnya sehingga pada main hanya tinggal mengatur saja posisi fungsi yang telah di buat.

#### Full Code Screenshot

<p align="center">
  <img src="https://github.com/rizaledc/Praktikum-Struktur-Data-Assigment-Modul-7/blob/main/Modul%207/SS%20Code%20and%20Output/Guidedcode1.png" alt="Alt Text">
</p>

#### Screenshot Output

<p align="center">
  <img src="https://github.com/rizaledc/Praktikum-Struktur-Data-Assigment-Modul-7/blob/main/Modul%207/SS%20Code%20and%20Output/OutputG1.png" alt="Alt Text">
</p>

#### Penjelasan

Pada output di atas, semuanya telah di atur dalam fungsi main. Dimana terdapat 4 data mata kuliah yaitu Dasar Multimedia, Bahasa Jerman, Struktur Data, dan Kalkulus. Dengan jumlah datanya setelah di hapus adalah 0.

### 2. Guided 2

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

**Penjelasan:**

#### Bagian 1

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian
```

Library iostream digunakan untuk menjalankan operasi input dan output pada program dan iomanip digunakan untuk memanipulasi lebar kolom. Lalu namespace std dipanggil agar saat penulisan fungsi tidak perlu ditambahkan std lagi. bagian const int maksimalQueue = 5 merupakan Konstanta untuk ukuran maksimal antrian, int front = 0 merupakan Variabel untuk menandai elemen depan antrian, int back = 0 merupakan Variabel untuk menandai elemen belakang antrian dan string queueTeller[5] merupakan Array statis untuk menyimpan elemen antrian.

#### Bagian 2

```C++
bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}
bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}
```

Pada fungsi pertama kode di atas mengecek apakah antrian penuh. Mengembalikan true jika variabel back sama dengan maksimalQueue.
Pada fungsi kedua kode di atas mengecek apakah antrian kosong. Mengembalikan true jika variabel back sama dengan 0.

#### Bagian 3

```C++
void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}
```

Pada fungsi di atas berguna menambahkan elemen ke antrian. Mengecek apakah antrian penuh dengan isFull(). Jika penuh, mencetak pesan "Antrian penuh".
Jika tidak penuh, dan antrian kosong, menambahkan elemen ke posisi pertama dan mengupdate front dan back.
Jika tidak penuh, dan antrian tidak kosong, menambahkan elemen ke posisi back dan mengupdate back.

#### Bagian 4

```C++
int countQueue() { // Menghitung jumlah antrian
    return back;
}
void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}
```

Pada fungsi di atas, akan berfungsi untuk mengembalikan jumlah elemen dalam antrian dengan mengembalikan nilai back. Menghapus semua elemen dalam antrian. Mengecek apakah antrian kosong dengan isEmpty(). Jika kosong, mencetak pesan "Antrian kosong". Jika tidak kosong, mengosongkan semua elemen dan mengatur back dan front ke 0.

#### Bagian 5

```C++
void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
```

Pada fungsi di atas digunakan untuk menampilkan isi antrian serta mencetak setiap elemen dalam antrian. Dapat mencetak pesan kosong jika elemen di dalamnya kosong.

#### Bagian 6

```C++
int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

Fungsi di atas merupakan fungsi main atau fungsi inti yang akan pertama kali di eksekusi pada program, dengan adanya fungsi main maka kode dapat berjalan sesuai yang kita inginkan. Seluruh fungsi yang telah di tuliskan pada program akan digunakan dalam fungsi main serta outputnya dapat disesuaikan pada fungsi main ini.

#### Full Code Screenshot

<p align="center">
  <img src="https://github.com/rizaledc/Praktikum-Struktur-Data-Assigment-Modul-7/blob/main/Modul%207/SS%20Code%20and%20Output/Guidedcode2.png" alt="Alt Text">
</p>

#### Screenshot Output

<p align="center">
  <img src="https://github.com/rizaledc/Praktikum-Struktur-Data-Assigment-Modul-7/blob/main/Modul%207/SS%20Code%20and%20Output/OutputG2.png" alt="Alt Text">
</p>

#### Penjelasan

Pada output di atas pengguna akan dapat melihat terdapat 2 orang mengantri dari 5 tempat yang disediakan yaitu Andi sebagai head lalu maya, lalu andi keluar dari antrian dilanjutkan dengan maya sebagai head sekligus tail. Lalu terakhir tidak ada antrian lagi.

## Unguided 

### 1. Unguided 1

####  Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya

**Kode Program:**

```C++
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string str) {
    stack<char> s;
    string filteredStr = "";
    
    // Filter non-alphanumeric characters and convert to lowercase
    for (char c : str) {
        if (isalnum(c)) {
            filteredStr += tolower(c);
        }
    }
    
    // Push all characters of the filtered string onto the stack
    for (char c : filteredStr) {
        s.push(c);
    }
    
    // Compare characters from the beginning with those popped from the stack
    for (char c : filteredStr) {
        if (c != s.top()) {
            return false;
        }
        s.pop();
    }
    
    return true;
}

int main() {
    string input;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, input);
    
    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }
    
    return 0;
}
```

**Penjelasan:**

#### Bagian 1

```C++
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;
```

Library iostream digunakan untuk menjalankan operasi input dan output pada program. Library stack digunakan untuk menyertakan pustaka stack. Library string digunakan untuk menggunakan tipe data string. Library cctype digunakan untuk menyertakan fungsi-fungsi karakter. Lalu namespace std dipanggil agar saat penulisan fungsi tidak perlu ditambahkan std lagi.

#### Bagian 2

```C++
bool isPalindrome(string str) {
    stack<char> s;
    string filteredStr = "";
    
    // Filter non-alphanumeric characters and convert to lowercase
    for (char c : str) {
        if (isalnum(c)) {
            filteredStr += tolower(c);
        }
    }
    
    // Push all characters of the filtered string onto the stack
    for (char c : filteredStr) {
        s.push(c);
    }
    
    // Compare characters from the beginning with those popped from the stack
    for (char c : filteredStr) {
        if (c != s.top()) {
            return false;
        }
        s.pop();
    }
    
    return true;
}
```

Kode di atas mendeklarasikan fungsi isPalindrome dalam bentuk string. stack<char> s; Mendeklarasikan stack s yang akan menyimpan karakter.Berikutnya string filteredStr = ""; Mendeklarasikan string kosong filteredStr untuk menyimpan karakter yang difilter. Berikutnya terdapat loop for di dalam fungsi di atas dengan peran yang berbeda-beda. 

#### Bagian 3

```C++
int main() {
    string input;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, input);
    
    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }
    
    return 0;
}
```

Fungsi di atas merupakan fungsi main yang berupa fungsi utama di dalam program yang disebut dengan fungsi main. Pengguna diminta untuk memasukkan sebuah kalimat menggunakan getline. Dimana kalimat yang dimasukkan akan diperiksa sebagai palindrome atau tidak.

#### Full code Screenshot:

<p align="center">
  <img src="https://github.com/rizaledc/Praktikum-Struktur-Data-Assigment-Modul-7/blob/main/Modul%207/SS%20Code%20and%20Output/Unguidedcode1.png" alt="Alt Text">
</p>

#### Screenshot Output

<p align="center">
  <img src="https://github.com/rizaledc/Praktikum-Struktur-Data-Assigment-Modul-7/blob/main/Modul%207/SS%20Code%20and%20Output/OutputUn1.png" alt="Alt Text">
</p>

#### Penjelasan

Dari output di atas kita mengetahui bahwa pengguna dapat memasukkan kalimat untuk di cek kepalindromannya. Pertama user memasukkan kata ini yang merupakan palindrom, lalu kata Rizal yang bukan palindrom, dan terakhir rizir yang merupakan palindrom.

### 2. Unguided 2

#### Ubah guided queue diatas agar menjadi program inputan user dan program menu. (Guided 2)

**Kode Program:**

```C++
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
```

**Penjelasan:**

#### Bagian 1

```C++
#include <iostream>
#include <string>

using namespace std;

int front = 0;          // Penanda depan antrian
int back = 0;           // Penanda belakang antrian
int maksimalQueue;      // Ukuran maksimal antrian
string* queueTeller;    // Array dinamis untuk menyimpan antrian
```

Library iostream digunakan untuk menjalankan operasi input dan output pada program dan Library string Menyertakan pustaka string untuk menggunakan tipe data string. Lalu namespace std dipanggil agar saat penulisan fungsi tidak perlu ditambahkan std lagi. 

int front = 0; dan int back = 0;: Inisialisasi penanda depan dan belakang antrian.
Deklarasi variabel untuk menyimpan ukuran maksimal antrian yang akan dimasukkan oleh pengguna sebagai int maksimalQueue. Berikutnya string* queueTeller merupakan Pointer ke array dinamis untuk menyimpan elemen-elemen antrian.

#### Bagian 2

```C++
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
```

Pada kode di atas terdapat tiga fungsi. Pada fungsi pertama mengecek apakah antrian penuh dengan membandingkan back dengan maksimalQueue. Pada fungsi kedua akan mengecek apakah antrian kosong dengan memeriksa apakah back bernilai 0.
Fungsi berikutnya adalah enqueueAntrian() yang digunakan untuk menambahkan elemen baru ke antrian. Jika antrian penuh, mencetak pesan. Jika tidak, menambahkan elemen pada posisi back dan meningkatkan nilai back.

#### Bagian 3

```C++
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
```

Fungsi di atas akan menjalankan program untuk menghapus elemen dari antrian. Jika antrian kosong, mencetak pesan. Jika tidak, menggeser semua elemen ke depan dan mengurangi nilai back

#### Bagian 4

```C++
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
```

Pada kode di atas terdapat dua fungsi, dimana fungsi pertama yaitu fungsi countQUeue yang mengembalikan jumlah elemen dalam antrian. Berikutnya pada fungsi kedua yaitu clearQueue() digunakan untuk menghapus semua elemen dari antrian. Jika antrian kosong, mencetak pesan. Jika tidak, mengosongkan setiap elemen dalam array dan mengatur back ke 0.

#### Bagian 5

```C++
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
```

Fungsi di atas digunakan untuk menampilkan semua elemen dalam antrian. Mencetak elemen satu per satu, atau "(kosong)" jika elemen tersebut kosong.

#### Bagian 6

```C++
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
```

Pada fungsi pertama yaitu displayFront() memiliki tugas untuk menampilkan elemen pertama dalam antrian apabila terdapat antriannya. Lalu untuk fungsi kedua yaitu displayBack() digunakan untuk menampilkan elemen terakhir dalam antrian apabila terdapat antriannya.

#### Bagian 7

```C++
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
```

Kode di atas merupakan fungsi inti atau fungsi main dari seluruh kode, dimana pada fungsi main ini akan dieksekusi lebih awal di dalam kode. Kode di atas akan mengeksekusi sesuai dengan interuksi dari pembuat kode, ini akan berpengaruh terhadap output dari kode nantinya. Pengguna diminta untuk memasukkan ukuran maksimal antrian, lalu pengguna dapat memilih 8 menu yang ada sesuai yang ditampilkan. Terdapat looping pada fungsi main di atas yaitu do.. while serta akan di switch pilihannya.

#### Full code Screenshot:

<p align="center">
  <img src="https://github.com/rizaledc/Praktikum-Struktur-Data-Assigment-Modul-7/blob/main/Modul%207/SS%20Code%20and%20Output/Unguidedcode2.png" alt="Alt Text">
</p>

#### Screenshot Output

<p align="center">
  <img src="https://github.com/rizaledc/Praktikum-Struktur-Data-Assigment-Modul-7/blob/main/Modul%207/SS%20Code%20and%20Output/OutputUn2.png" alt="Alt Text">
</p>

#### Penjelasan

Pada output di atas pengguna memasukkan jumlah antrian sebanyak 3. Lalu memilih menu 1 untuk memasukkan nama yaitu Wisnu, lalu Mikhael, lalu Fahmi maka antrian akan penuh. User menampilkan antrian dengan memilih menu 3, lalu memilih menu 8 untuk keluar program.

## Kesimpulan

Dalam dunia pemrograman C++, stack dan queue merupakan struktur data yang digunakan untuk mengelola maupun menyimpan elemen dengan berurutan. Dimana stack menggunakan prinsip LIFO (Last In First Out) yang menggunakan perumpamaan tumpukan buku, tumpukan buku terakhir adalah tumpukan buku yang akan pertama diambil atau keluar. Operasi stack dapat melibatkan push untuk memasukkan data dan pop untuk mengeluarkan data. Berikutnya queue yang menggunakan prinsip FIFO (First In First Out) yang menggunakan perumpamaan antrian bioskop yang antri pertama maka yang akan keluar pertama sebagai pembeli tiket bioskopnya. Operasi queue dapat melibatkan enqueue (penambahan data) dan dequeue (pengurangan data). Implementasi stack dan queue dapat digunakan pada array maupun linked list.

## Referensi

[1]	C. W. SItorus, “PENERAPAN DAN FUNGSI ALGORITMA PEMROGRAMAN,” pp. 1–13.

[2]	J. Sihombing, “Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java,” J. Ilm. Infokom, vol. 7, no. 2, pp. 15–24, 2019.
