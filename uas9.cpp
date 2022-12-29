#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_FILM = 10;
const int MAX_JAM = 3;

struct film
{
    string judul;
    int durasi;
    int jam_tayang[MAX_JAM];
    int harga;
};

film daftar_film[MAX_FILM];

void input_film()
{
    for (int i = 0; i < MAX_FILM; i++)
    {
        cout << "Masukkan judul film: ";
        getline(cin, daftar_film[i].judul);
        cout << "Masukkan durasi film (dalam menit): ";
        cin >> daftar_film[i].durasi;
        for (int j = 0; j < MAX_JAM; j++)
        {
            cout << "Masukkan jam tayang ke-" << (j + 1) << ": ";
            cin >> daftar_film[i].jam_tayang[j];
        }

        cout << "Masukkan harga tiket: ";
        cin >> daftar_film[i].harga;

        cin.ignore(); // mengabaikan karakter Enter setelah input harga tiket
    }
}

void tampil_film()
{
    cout << "Daftar Film:" << endl;
    for (int i = 0; i < MAX_FILM; i++)
    {
        cout << (i + 1) << ". " << daftar_film[i].judul << " (" << daftar_film[i].durasi << " menit)" << endl;
        cout << "Jam tayang: ";
        for (int j = 0; j < MAX_JAM; j++)
        {
            cout << daftar_film[i].jam_tayang[j] << " ";
        }
        cout << endl;
        cout << "Harga tiket: Rp" << daftar_film[i].harga << endl;
    }
}

void sortir_film()
{
    sort(daftar_film, daftar_film + MAX_FILM, [](film a, film b)
         { return a.judul < b.judul; });
}

void pemesanan_tiket()
{
    int pilihan, jumlah_tiket, total_harga;
    cout << "Pilih film yang ingin ditonton (1-" << MAX_FILM << "): ";
    cin >> pilihan;

    cout << "Masukkan jumlah tiket yang ingin dibeli: ";
    cin >> jumlah_tiket;

    total_harga = jumlah_tiket * daftar_film[pilihan - 1].harga;
    void pembayaran_tiket(int total_harga)
    {
        int pilihan_pembayaran;
        cout << "Total harga tiket: Rp" << total_harga << endl;
        cout << "Pilih metode pembayaran:" << endl;
        cout << "1. Kartu" << endl;
        cout << "2. Tunai" << endl;
        cin >> pilihan_pembayaran;

        switch (pilihan_pembayaran)
        {
        case 1:
            cout << "Pembayaran dengan kartu sedang diproses..." << endl;
            break;
        case 2:
            cout << "Pembayaran dengan tunai sedang diproses..." << endl;
            break;
        default:
            cout << "Pilihan pembayaran tidak valid." << endl;
        }
    }

    int main()
    {
        input_film();
        tampil_film();
        sortir_film();
        tampil_film();
        pemesanan_tiket();
        pembayaran_tiket(total_harga);
        return 0;
    }