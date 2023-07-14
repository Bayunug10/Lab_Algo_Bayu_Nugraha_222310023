#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Book {
    string title;
    string rack;
};

bool compareTitles(const Book& book1, const Book& book2) {
    return book1.title < book2.title;
}

int binarySearch(const std::vector<Book>& books, const string& targetTitle) {
    int low = 0;
    int high = books.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (books[mid].title == targetTitle) {
            return mid;  // Mengembalikan indeks jika ditemukan
        } else if (books[mid].title < targetTitle) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Mengembalikan -1 jika tidak ditemukan
}

int main() {
    vector<Book> library = {
        {"Buku A", "Rak 1"},
        {"Buku B", "Rak 2"},
        {"Buku C", "Rak 3"},
        {"Buku D", "Rak 1"},
        {"Buku E", "Rak 2"},
        {"Buku F", "Rak 3"}
    };

    string targetTitle;

    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(std::cin, targetTitle);

    // Urutkan library berdasarkan judul buku untuk menggunakan binary search
    sort(library.begin(), library.end(), compareTitles);

    int index = binarySearch(library, targetTitle);

    if (index != -1) {
    cout << "Buku dengan judul \"" << targetTitle << "\" ditemukan pada rak: " << library[index].rack << std::endl;
    } else {
    cout << "Buku dengan judul \"" << targetTitle << "\" tidak ditemukan" << std::endl;
    }

    return 0;
}