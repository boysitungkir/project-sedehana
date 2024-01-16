// Tugas Besar Akhir Kelompok 3
// Pembuatan aplikasi kasir dengan fungsi menampilkan data, menambahkan data, menghaspus data, pencarian data,
// sorting data, dan fungsi diskon pada transaksi pada aplikasi c++

// Nama anggota kelompok 3 Mata Kuliah Logika & Pemograman Universitas 17 Agustus 1945 Jakarta
// 1. Boy Betrand Situngkir
// 2. Leo Berliandri Ramadhan
// 3. Ariq Ramadhan
// 4. M. Fadlil Hakim
// 5. Revansyah Arestio
// 6. Muhammad Maulana Yusuf


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Produk { //definisikan tipe data untuk menggabungkan item data dari jenis yang berbeda
    string nama;
    double harga;
    int jumlah;
};
class Kasir { 
private:
    vector<Produk> produk; 
public:
	
//	Fungsi menambahkan barang
    void tambahProduk(string nama, double harga, int jumlah) {
        Produk newProduk = {nama, harga, jumlah};
        this->produk.push_back(newProduk);
    }
    
    // Fungsi untuk menampilkan data
    void tampilkanProduk() {
        cout << "==========================================" << endl;
        cout << "               DAFTAR PRODUK" << endl;
        cout << "==========================================" << endl;
        cout << setw(20) << left << "Nama Produk" << setw(10) << "Harga" << setw(10) << "Jumlah" << endl;
        cout << "------------------------------------------" << endl;
        for (Produk produk : this->produk) {
            cout << setw(20) << left << produk.nama << setw(10) << produk.harga << setw(10) << produk.jumlah << endl;
        }
        cout << "==========================================" << endl;
    }
    
	//Fungsi pencarian data berdasarkan nama barang
    void cariProduk() {
        cout << "Masukkan nama produk yang dicari: ";
        string namaProduk;
        cin >> namaProduk;
        for (Produk &produk : this->produk) {
            if (produk.nama == namaProduk) {
                cout << "Nama Produk: " << produk.nama << ", Harga: " << produk.harga << ", Jumlah: " << produk.jumlah << endl;
                return;
            }
        }
        cout << "Produk tidak ditemukan." << endl;
    }
    
	//Fungsi transaksi barang
    void prosesTransaksi() {
        double total = 0;
        tampilkanProduk();
        cout << "Masukkan nama produk yang akan dibeli: ";
        string namaProduk;
        cin >> namaProduk;
        for (Produk &produk : this->produk) {
            if (produk.nama == namaProduk) {
                int jumlah;
                cout << "Masukkan jumlah " << namaProduk << " yang akan dibeli: ";
                cin >> jumlah;
                if (jumlah <= produk.jumlah) {
                    total += produk.harga * jumlah;
                    produk.jumlah -= jumlah;
                } else {
                    cout << "Maaf, stok tidak mencukupi." << endl;
                }
            }
        }
        cout << "Total belanja sebelum diskon: " << total << endl;
        cout << "Apakah ada diskon? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            double diskon;
            cout << "Masukkan persentase diskon (0-100): ";
            cin >> diskon;
            total -= (diskon / 100) * total;
        }
        cout << "Total belanja setelah diskon: " << total << endl;
    }
    
	//Fungsi sorting data berdasarkan jumlah barang
    void urutkanProduk() {
        sort(produk.begin(), produk.end(), [](const Produk &a, const Produk &b) {
            return a.jumlah < b.jumlah;
        });
    }
    
	//Fungsi hapus data
    void hapusProduk() {
        cout << "Masukkan nama produk yang akan dihapus: ";
        string namaProduk;
        cin >> namaProduk;
        for (auto it = produk.begin(); it != produk.end(); ++it) {
            if (it->nama == namaProduk) {
                produk.erase(it);
                cout << "Produk berhasil dihapus." << endl;
                return;
            }
        }
        cout << "Produk tidak ditemukan." << endl;
    }
};
int main() { //Untuk menambahkan data secara manual
    Kasir kasir;
    kasir.tambahProduk("Beras", 10000, 10);
    kasir.tambahProduk("Gula", 8000, 15);
    kasir.tambahProduk("Minyak Goreng", 15000, 8);
    kasir.tambahProduk("Sabun", 5000, 48);
    kasir.tambahProduk("Korek", 15000, 8);
    
    int pilihan; // Menampilkan pilihan perintah untuk transaksi dalam bentuk angka
    do {
        cout << "==========================================" << endl;
        cout << "           APLIKASI KASIR" << endl;
        cout << "==========================================" << endl;
        cout << "1. Tampilkan Daftar Produk" << endl;
        cout << "2. Proses Transaksi" << endl;
        cout << "3. Cari Produk" << endl;
        cout << "4. Urutkan Produk Berdasarkan Jumlah" << endl;
        cout << "5. Tambah Barang" << endl;
        cout << "6. Hapus Barang" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilihan: ";
        
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                kasir.tampilkanProduk();
                break;
            case 2:
                kasir.prosesTransaksi();
                break;
            case 3:
                kasir.cariProduk();
                break;
            case 4:
                kasir.urutkanProduk();
                break;
            case 5: {
                string nama;
                double harga;
                int jumlah;
                cout << "Masukkan nama barang: ";
                cin >> nama;
                cout << "Masukkan harga barang: ";
                cin >> harga;
                cout << "Masukkan jumlah barang: ";
                cin >> jumlah;
                kasir.tambahProduk(nama, harga, jumlah);
                break;
            }
            case 6:
                kasir.hapusProduk();
                break;
            case 7:
                cout << "Terima kasih telah menggunakan aplikasi kasir." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 7);
    return 0;
}