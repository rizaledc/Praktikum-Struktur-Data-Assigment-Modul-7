#include <iostream>
using namespace std;

// Fungsi Fibonacci rekursif berdasarkan algoritma yang diberikan
int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    // Meminta pengguna untuk memasukkan nilai n
    cout << "Masukkan nilai n: ";
    cin >> n;

    // Menampilkan deret Fibonacci hingga n
    cout << "Deret Fibonacci hingga " << n << " adalah: ";
    for (int i = 1; i <= n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}