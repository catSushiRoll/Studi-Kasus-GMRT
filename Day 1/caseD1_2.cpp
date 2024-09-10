#include <iostream>
#include <cstdlib>  // Untuk fungsi rand() dan srand()
#include <ctime>    // Untuk fungsi time()

using namespace std;

int main() {
    int array[10];

    // Mengisi array dengan 10 angka random
    srand(time(0));  // Seed untuk random number generator
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 10 + 1;  // Angka random antara 1 dan 100
    }

    // Menampilkan array sebelum di-sort
    cout << "Array sebelum di-sort: ";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Bubble Sort dari terbesar ke terkecil
    int n = 10;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                // Menukar elemen jika elemen sekarang lebih kecil dari elemen berikutnya
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Menampilkan array setelah di-sort
    cout << "Array setelah di-sort: ";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
