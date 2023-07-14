#include <iostream>
#include <queue>

using namespace std;

// Struktur data untuk tiket
struct Ticket {
    string name;
    int quantity;
};

int main() {
    queue<Ticket> ticketQueue; // Deklarasi queue untuk antrian tiket

    int choice;
    while (true) {
        cout << "=== ANTRIAN LOKET TIKET ===" << endl;
        cout << "1. Tambah Tiket" << endl;
        cout << "2. Proses Tiket" << endl;
        cout << "3. Jumlah Tiket yang Tersedia" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Ticket newTicket;
                cout << "Nama Tiket: ";
                cin >> newTicket.name;
                cout << "Jumlah Tiket: ";
                cin >> newTicket.quantity;

                ticketQueue.push(newTicket); // Menambahkan tiket ke dalam antrian
                cout << "Tiket berhasil ditambahkan ke antrian." << endl;
                break;
            }
            case 2: {
                if (!ticketQueue.empty()) {
                    Ticket currentTicket = ticketQueue.front(); // Mengambil tiket pertama dalam antrian
                    ticketQueue.pop(); // Menghapus tiket pertama dari antrian
                    cout << "Tiket '" << currentTicket.name << "' telah diproses." << endl;
                } else {
                    cout << "Antrian kosong. Tidak ada tiket yang dapat diproses." << endl;
                }
                break;
            }
            case 3: {
                cout << "Jumlah Tiket yang Tersedia: " << ticketQueue.size() << endl;
                break;
            }
            case 4: {
                cout << "Terima kasih telah menggunakan program." << endl;
                return 0;
            }
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
        cout << endl;
    }
}