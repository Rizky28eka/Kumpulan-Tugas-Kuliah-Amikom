#include <iostream>
#include <string>

using namespace std;

const int MAX_JUMLAH_PELANGGAN = 100; // jumlah maksimum pelanggan yang dapat ditangani

// Kelas Pelanggan untuk menyimpan informasi tentang pelanggan
class Pelanggan {
private:
string nama;
string alamat;
string nomor_telepon;

public:
Pelanggan(string nama, string alamat, string nomor_telepon) {
this->nama = nama;
this->alamat = alamat;
this->nomor_telepon = nomor_telepon;
}

// Getter dan setter untuk atribut nama
string getNama() {
return nama;
}
void setNama(string nama) {
this->nama = nama;
}

// Getter dan setter untuk atribut alamat
string getAlamat() {
return alamat;
}
void setAlamat(string alamat) {
this->alamat = alamat;
}

// Getter dan setter untuk atribut nomor_telepon
string getNomorTelepon() {
return nomor_telepon;
}
void setNomorTelepon(string nomor_telepon) {
this->nomor_telepon = nomor_telepon;
}
};

// Kelas Laundry untuk mengelola pelanggan-pelanggan yang memiliki cucian yang harus dicuci
class Laundry {
private:
Pelanggan pelanggans[MAX_JUMLAH_PELANGGAN]; // array untuk menyimpan pelanggan-pelanggan yang memiliki cucian yang harus dicuci
int jumlah_pelanggan; // jumlah pelanggan yang memiliki cucian yang harus dicuci

public:
Laundry() {
jumlah_pelanggan = 0;
}

// Fungsi untuk menambahkan pelanggan baru ke laundry
void tambahPelanggan(Pelanggan pelanggan) {
if (jumlah_pelanggan < MAX_JUMLAH_PELANGGAN) {
pelanggans[jumlah_pelanggan] = pelanggan;
jumlah_pelanggan++;
} else {
throw "Jumlah pelanggan sudah mencapai batas maksimum"; // exception jika jumlah pelanggan sudah mencapai batas maksimum
}
}
// Fungsi untuk mencetak daftar pelanggan yang memiliki cucian yang harus dicuci
void cetakDaftarPelanggan() {
cout << "Daftar pelanggan yang memiliki cucian yang harus dicuci:" << endl;
for (int i = 0; i < jumlah_pelanggan; i++) {
cout << i + 1 << ". " << pelanggans[i].getNama() << " (" << pelanggans[i].getAlamat() << ", " << pelanggans[i].getNomorTelepon() << ")" << endl;
}
}