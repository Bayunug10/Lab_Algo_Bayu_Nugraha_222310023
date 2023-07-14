#include <iostream>

int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Mengembalikan indeks jika ditemukan
        }
    }
    return -1;  // Mengembalikan -1 jika tidak ditemukan
}

int main() {
    int arr[] = {0, 6, 12, 18, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    std::cout << "Masukkan angka yang ingin dicari: ";
    std::cin >> target;

    int index = sequentialSearch(arr, n, target);

    if (index != -1) {
        std::cout << "Angka ditemukan pada indeks ke-" << index << std::endl;
    } else {
        std::cout << "Angka tidak ditemukan" << std::endl;
    }

    return 0;
}