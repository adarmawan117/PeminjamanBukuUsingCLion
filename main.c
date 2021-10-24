// versi 6
/**
 - Buat validasi agar input int bisa sesuai
     Caranya dengan memasukan nilai kedalam string dahulu, kemudian lakukan pengecekan tiap karakternya
     Kalau terdapat bukan int, keluarkan error dan minta input lagi
     <Lihat playlist ke 12>
 */

// Versi 5
/**
 - Buat fungsi gotxy, untuk mempercantik tampilan
 */


// Versi 4
/**
 * 14-Oktober-2021
===========
 - Buat fungsi untuk register              = DONE
 - Validasi input register dan login       = DONE
 - Kalau login sebagai user biasa, maka hanya boleh melihat list buku, dan historynya saja

 - Buat fungsi untuk menambah buku
 - Buat fungsi untuk merubah buku
 - Buat fungsi untuk menghapus buku

 - Buat fungsi untuk menghapus pelanggan
 - Buat fungsi untuk merubah pelanggan

 - Simpan data buku kedalam file
 - Simpan data pelanggan kedalam file
 - Simpan data peminjaman kedalam file

 - Modularisasi file (pisahkan fungsi tertentu kedalam file terpisah)




*/

// Versi 3
/**
===========
28 - September - 2021
Mulai pindah ke Clion
===========
- Koneksikan peminjaman dengan pelanggan   = DONE
- Refactor penamaan                        = DONE

*/

// Versi 2
/**
===========
27-September-2021
===========
- Tambah pelanggan        = DONE
- Lihat list peminjam     = DONE
- Mengembalikan buku      = DONE
- Logout                  = DONE
- Update login agar bisa membatalkan login (exit program) = DONE


DATA Pelanggan
-------------
id
nama
statusPelanggan => 0 untuk bukan anggota, dan 1 untuk anggota
*/

// Versi 1
/**
===========
26-September-2021
===========
Peminjaman BUKU
- Login              = DONE
- Tampil list buku   = DONE
- Pinjam Buku        = DONE

DATA BUKU
----------
id
nama
pengarang
hargaSewa perhari
statusSewa

*/



#include <ctype.h>
#include <stdbool.h>

#include "validasi.h"

#define MAX_ID 10
#define MAX_NAMA 40
#define MAX_STRUCT 50

#define MAX_STRING_LOGIN 100


/* Deklarasi Fungsi */
void login();
/* Akhir deklarasi fungsi */


/* implementasi fungsi */
void clrscr() {
    system("cls");
}

void enter() {
    fflush(stdin);
    getchar();
}
/* Akhir implementasi fungsi */


/* Deklarasi struct */
typedef struct {
    char id[MAX_ID];
    char namaBuku[MAX_NAMA];
    /**
     * Lama sewa untuk satu hari
     */
    int hargaSewa;
    /**
     * 0 untuk avail, 1 untuk dipinjam
    */
    int statusSewa;
} DATA_BUKU;

typedef struct {
    char id[MAX_ID];
    char username[MAX_STRING_LOGIN];
    char password[MAX_STRING_LOGIN];
    char namaPelanggan[MAX_NAMA];
    /**
     * 0 untuk bukan anggota, dan 1 merupakan anggota
     */
    int statusPelanggan;
} DATA_PELANGGAN;

typedef struct {
    /**
     * "Pinjam" ketika sebuah buku dipinjam
     * "Kembali" ketika sebuah buku dikembalikan
     */
    char status[MAX_NAMA];
} STATUS_PEMINJAMAN;

typedef struct {
    /**
     * auto increment
     */
    int idPeminjaman;
    char idBuku[MAX_ID];
    char idPelanggan[MAX_ID];
    int lamaPinjam;
    int totalBiaya;
    /**
     * statusPeminjaman[0] = "Pinjam"
     * statusPeminjaman[1] = "Kembali
     */
    STATUS_PEMINJAMAN statusPeminjaman[2];
} DATA_PEMINJAMAN;
/* Akhir deklarasi struct */


/* Pembuatan variabel struct */
DATA_BUKU listBuku[MAX_STRUCT];
DATA_PELANGGAN listPelanggan[MAX_STRUCT];
DATA_PEMINJAMAN listPeminjaman[MAX_STRUCT];
/* Akhir pembuatan variabel struct */


/* Pembuatan variabel pendukung list struct */
int banyakBuku = 0;
int banyakPelanggan = 0;
int banyakPeminjaman = 0;
/* Akhir pembuatan variabel pendukung list struct */

/* Global Variable */
char username[MAX_STRING_LOGIN];
char password[MAX_STRING_LOGIN];
/* Akhir global variabel */

/**
Untuk mengecek apakah list buku masih kosong
*/
bool isEmptyBuku() {
    return banyakBuku == 0;
}

/**
Untuk mengecek apakah list pelanggan masih kosong
*/
bool isEmptyPelanggan() {
    return banyakPelanggan == 0;
}

/**
Untuk mengecek apakah list peminjaman masih kosong
*/
bool isEmptyPeminjaman() {
    return banyakPeminjaman == 0;
}

int getLatestIDPeminjaman() {
    int latest = -1;
    while(listPeminjaman[latest++].idPeminjaman != 0) {
        // statement kosong
    }

    return latest;
}

/**
 * Fungsi untuk mencari status sebuah buku apakah Dipinjam atau Tersedia
 * @param status status sewa dari sebuah buku (0 atau 1)
 * @return Dipinjam jika statusnya 1<br>Avail jika statusnya 0
 */
char *getStatusSewa(int status) {
    return (status == 1) ? "Dipinjam" : "Avail";
}

/**
 * Untuk menampilkan semua list buku (tanpa keterangan header)
 */
void tampilBuku() {

    int i;

    printf("========================================================================================================\n");
    printf("||%-5s||%-10s||%-40s||%-15s||%-22s||\n", "No", "ID", "Nama", "Harga", "Status Peminjaman");
    printf("========================================================================================================\n");
    for(i = 0; i < banyakBuku; i++) {
        printf("||%-5d||%-10s||%-40s||%-15d||%-22s||\n", (i+1), listBuku[i].id, listBuku[i].namaBuku, listBuku[i].hargaSewa,
               getStatusSewa(listBuku[i].statusSewa));
    }
    printf("========================================================================================================\n");



}

/**
 * Untuk menampilkan semua list buku (dengan keterangan header)
 */
void tampilListBuku() {

    clrscr();
    printf("\n\n\n");
    printf("                               ||======================================||\n");
    printf("                               ||    HALAMAN TAMPIL SEMUA LIST BUKU    ||\n");
    printf("                               ||======================================||\n");

    if(isEmptyBuku()) {
        printf("                               ||                                      ||\n");
        printf("                               ||          Buku masih kosong!          ||\n");
        printf("                               ||                                      ||\n");
        printf("                               ||======================================||\n");
        return;
    }

    printf("\n");
    tampilBuku();
}

/**
 * Fungsi untuk mencari status seorang pelanggan apakah Anggota atau Bukan Anggota
 * @param status Status Anggota dari seorang pelanggan (0 atau 1)
 * @return Anggota jika statusnya 1<br>Bukan anggota jika statusnya 0
 */
char *getStatusPelanggan(int status) {
    return status == 1 ? "Anggota" : "Bukan Anggota";
}

/**
 * Untuk menampilkan semua list pelanggan (tanpa keterangan header)
 */
void tampilPelanggan() {
    int i;
    printf("==========================================================================================\n");
    printf("||%-5s||%-10s||%-40s||%-25s||\n", "No", "ID", "Nama", "Status Anggota");
    printf("==========================================================================================\n");
    for(i = 0; i < banyakPelanggan; i++) {
        printf("||%-5d||%-10s||%-40s||%-25s||\n", (i+1), listPelanggan[i].id, listPelanggan[i].namaPelanggan,
               getStatusPelanggan(listPelanggan[i].statusPelanggan));
    }
    printf("==========================================================================================\n");
}

/**
 * Untuk menampilkan semua list pelanggan (dengan keterangan header)
 */
void tampilListPelanggan() {

    clrscr();
    printf("\n\n\n");
    printf("                        ||======================================||\n");
    printf("                        || HALAMAN TAMPIL SEMUA LIST PELANGGAN  ||\n");
    printf("                        ||======================================||\n");

    if(isEmptyPelanggan()) {
        printf("                        ||                                      ||\n");
        printf("                        ||       Pelanggan masih kosong!        ||\n");
        printf("                        ||                                      ||\n");
        printf("                        ||======================================||\n");
        return;
    }

    printf("\n");
    tampilPelanggan();
}

/**
 * Untuk menambah pelanggan baru kedalam list
 */
void tambahPelanggan() {
    int panjangID;
    do {

        clrscr();
        printf("\n\n\n");
        printf("||======================================||\n");
        printf("||       HALAMAN TAMBAH PELANGGAN       ||\n");
        printf("||======================================||\n");
        printf("||                                      ||\n");
        printf("|| Masukan ID pelanggan   : ");
        fflush(stdin);
        scanf("%[^\n]", listPelanggan[banyakPelanggan].id);

        panjangID = (int) strlen(listPelanggan[banyakPelanggan].id);

        if(panjangID > MAX_ID) {
            printf("** Panjang ID tidak boleh lebih dari %d karakter **\n", MAX_ID);
            printf("||                                      ||\n");
        }

    } while(panjangID > MAX_ID);

    int panjangNama;
    do {
        printf("|| Masukan nama pelanggan : ");
        fflush(stdin);
        scanf("%[^\n]", listPelanggan[banyakPelanggan].namaPelanggan);

        panjangNama = (int) strlen(listPelanggan[banyakPelanggan].namaPelanggan);

        if(panjangNama > MAX_NAMA) {
            printf("** Panjang nama tidak boleh lebih dari %d karakter **\n", MAX_NAMA);
            printf("||                                      ||\n");
        }

    } while(panjangNama > MAX_NAMA);

    char confirm;
    do {
        printf("\n\nIngin menyimpan %s [Y/T] : ", listPelanggan[banyakPelanggan].namaPelanggan);
        fflush(stdin);
        confirm = (char) toupper((char) getchar());

        if(confirm == 'Y') {
            printf("Selamat, pelanggan \"%s\" berhasil ditambahkan\n", listPelanggan[banyakPelanggan].namaPelanggan);
            banyakPelanggan++;
        } else {
            printf("Anda batal menambahkan pelanggan %s\n", listPelanggan[banyakPelanggan].namaPelanggan);
        }


    } while(confirm != 'Y' && confirm != 'T');
}





/**
 * Menu untuk meminjam buku.
 */
void pinjamBuku() {

    clrscr();
    printf("\n\n\n");
    printf("                               ||======================================||\n");
    printf("                               ||          HALAMAN PINJAM BUKU         ||\n");
    printf("                               ||======================================||\n");

    if(isEmptyBuku()) {
        printf("                               ||                                      ||\n");
        printf("                               ||          Buku masih kosong!          ||\n");
        printf("                               ||                                      ||\n");
        printf("                               ||======================================||\n");
        return;
    }

    int pilihBuku;
    tampilBuku();

    do {
        printf("                               || Pilih buku no : ");
        scanf("%d", &pilihBuku);
    } while(pilihBuku < 1 || pilihBuku > banyakBuku);
    printf("                               ||======================================||\n");

    pilihBuku--;
    char confirm;
    do {
        printf("\n\nIngin meminjam buku dengan judul %s [Y/T]?", listBuku[pilihBuku].namaBuku);
        fflush(stdin);
        confirm = (char) toupper((char) getchar());

        if(confirm == 'Y') {
            /* simpan transaksi kedalam struct*/
            int lamaPinjam;
            int totalBiaya;

            printf("Masukan lama pinjam : ");
            scanf("%d", &lamaPinjam);
            totalBiaya = lamaPinjam * listBuku[pilihBuku].hargaSewa;

            listPeminjaman[banyakPeminjaman].idPeminjaman = getLatestIDPeminjaman() + 1;
            strcpy(listPeminjaman[banyakPeminjaman].idBuku, listBuku[pilihBuku].id);
            strcpy(listPeminjaman[banyakPeminjaman].idPelanggan, username);
            listPeminjaman[banyakPeminjaman].lamaPinjam = lamaPinjam;
            listPeminjaman[banyakPeminjaman].totalBiaya = totalBiaya;
            strcpy(listPeminjaman[banyakPeminjaman].statusPeminjaman[0].status, "Pinjam");

            banyakPeminjaman++;

            printf("Selamat, anda berhasil meminjam buku %s\n", listBuku[pilihBuku].namaBuku);
            listBuku[pilihBuku].statusSewa = 1; // buku sudah dipinjam
        } else {
            printf("Anda membatalkan peminjaman buku %s\n", listBuku[pilihBuku].namaBuku);
        }


    } while(confirm != 'Y' && confirm != 'T');
}

/**
 * Untuk mendapatkan jumlah buku yang dipinjam
 * @return Mengambalikan jumlah buku yang dipinjam
 */
int getJumlahBukuDipinjam() {
    int i;
    int jumlahBukuDipinjam = 0;
    for(i = 0; i < banyakPeminjaman; i++) {
        // kalau yang meminjam adalah orang yagn login, maka tambahkan jumlahBukuDipinjam
        if(strcmp(listPeminjaman[i].idPelanggan, username) == 0) {
            jumlahBukuDipinjam++;
        }
    }

    return jumlahBukuDipinjam;
}

char * getNamaBuku(char idBuku[]) {
    int i;
    char * namaBuku = malloc(MAX_NAMA);
    for(i = 0; i < banyakBuku; i++) {
        if(strcmp(listBuku[i].id, idBuku) == 0) {
            strcpy(namaBuku, listBuku[i].namaBuku);
        }
    }

    return namaBuku;
}

int getIdxBuku(char idBuku[]) {
    int i;
    for(i = 0; i < banyakBuku; i++) {
        if(strcmp(listBuku[i].id, idBuku) == 0) {
            return i;
        }
    }

    return -1;
}

/**
 * Menu untuk mengembalikan buku yang dipinjam pelanggan
 */
void kembalikanBuku() {

    clrscr();
    printf("\n\n\n");
    printf("                               ||======================================||\n");
    printf("                               ||        HALAMAN KEMBALIKAN BUKU       ||\n");
    printf("                               ||======================================||\n");

    if(isEmptyBuku()) {
        printf("                               ||                                      ||\n");
        printf("                               ||          Buku masih kosong!          ||\n");
        printf("                               ||                                      ||\n");
        printf("                               ||======================================||\n");
        return;
    }


    int jumlahBukuDipinjam = getJumlahBukuDipinjam();
    if(jumlahBukuDipinjam == 0) {
        printf("                               ||                                      ||\n");
        printf("                               ||     Tidak ada buku yang dipinjam!    ||\n");
        printf("                               ||                                      ||\n");
        printf("                               ||======================================||\n");
        return;
    }

    DATA_PEMINJAMAN tempPeminjaman[jumlahBukuDipinjam];
    int idxTemp = 0;

    printf("==============================================================\n");
    printf("||%-5s||%-5s||%-10s||%-15s||%-15s||\n", "No", "ID", "ID Buku", "Lama Pinjam", "Total Biaya");
    printf("==============================================================\n");
    int i;
    for(i = 0; i < banyakPeminjaman; i++) {
        if(strcmp(listPeminjaman[i].idPelanggan, username) == 0) {
            printf("||%-5d||%-5d||%-10s||%-15d||%-15d||\n", (i + 1), listPeminjaman[i].idPeminjaman,
                   listPeminjaman[i].idBuku, listPeminjaman[i].lamaPinjam, listPeminjaman[i].totalBiaya);
            tempPeminjaman[idxTemp] = listPeminjaman[i];
        }
    }
    printf("==============================================================\n");

    // proses milih buku
    int pilihBuku;

    do {
        printf("                               ||Pilih buku yang ingin dikembalikan : ");
        scanf("%d", &pilihBuku);

    } while(pilihBuku < 1 || pilihBuku > jumlahBukuDipinjam);
    pilihBuku--;

    printf("                               ||                                      ||\n");
    printf("                               ||======================================||\n");

    char confirm;
    char namaBuku[MAX_NAMA];
    strcpy(namaBuku, getNamaBuku(tempPeminjaman[pilihBuku].idBuku));
    do {
        printf("\n\nIngin mengembalikan buku dengan judul %s [Y/T]?", namaBuku);
        fflush(stdin);
        confirm = (char) toupper((char) getchar());

        if(confirm == 'Y') {
            int idxBuku = getIdxBuku(tempPeminjaman[pilihBuku].idBuku);
            listBuku[idxBuku].statusSewa = 0; // buku sudah dikembalikan
            strcpy(listPeminjaman[pilihBuku].statusPeminjaman[1].status, "Kembali");

            printf("Selamat, anda berhasil mengembalikan buku %s\n", namaBuku);
        } else if(confirm == 'T') {
            printf("Anda membatalkan pengembalian buku %s\n", namaBuku);
        }


    } while(confirm != 'Y' && confirm != 'T');
}


/**
 * Inisialisasi awal (terhadap list buku) ketika program pertama kali dijalankan
 */
void initBuku() {
    strcpy(listBuku[banyakBuku].id, "BK-01");
    strcpy(listBuku[banyakBuku].namaBuku, "Belajar Pemrograman JAVA");
    listBuku[banyakBuku].hargaSewa = 30000;
    listBuku[banyakBuku].statusSewa = 0;
    banyakBuku++;
}

/**
 * Inisialisasi awal (terhadap list pelanggan) ketika program pertama kali dijalankan
 */
void initPelanggan() {
    strcpy(listPelanggan[banyakPelanggan].id, "PMJ-01");
    strcpy(listPelanggan[banyakPelanggan].namaPelanggan, "Hendra Maulana");
    listPelanggan[banyakPelanggan].statusPelanggan = 0;
    banyakPelanggan++;
}

/**
 * Inisialisasi semua komponen, ketika program pertama kali dijalankan
 */
void init() {
    initBuku();
    initPelanggan();
}

/**
 * Tampil menu utama
 */
void menuUtama() {

    int pilihan;
    init();

    do {
        clrscr();
        printf("||======================================||\n");
        printf("||              MENU UTAMA              ||\n");
        printf("||======================================||\n");
        printf("||                                      ||\n");
        printf("|| 1. Tampil List Buku                  ||\n");
        printf("|| 2. Pinjam Buku                       ||\n");
        printf("|| 3. Kembalikan Buku                   ||\n");
        printf("|| 4. Tampil List Pelanggan             ||\n");
        printf("|| 5. Tambah Pelanggan                  ||\n");
        printf("|| 6. Logout                            ||\n");
        printf("|| 7. Keluar                            ||\n");
        printf("||                                      ||\n");
        printf("||======================================||\n");
        printf("||                                      ||\n");
        printf("|| Pilihan >> ");
        scanf("%d", &pilihan);
        printf("||                                      ||\n");
        printf("||======================================||\n");

        switch(pilihan) {
            case 1:
                tampilListBuku();
                break;
            case 2:
                pinjamBuku();
                break;
            case 3:
                kembalikanBuku();
                break;
            case 4:
                tampilListPelanggan();
                break;
            case 5:
                tambahPelanggan();
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                printf("Pilihan hanya dari 1 - 7 saja!\n");
        }
        enter();
    } while(pilihan != 6 && pilihan != 7);

    if(pilihan == 6) {
        login();
    } // selain itu keluar (exit) program
}

/**
 * Untuk mengecek apakah username dan password sesuai
 * @param username username login
 * @param password password login
 * @return true jika username ada di dalam database<br>false jika tidak ada
 */
bool authLogin() {
    bool status = false;
    int i;
    for(i = 0; i < banyakPelanggan; i++) {
        if((strcmp(listPelanggan[i].username, username) == 0) && (strcmp(listPelanggan[i].password, password) == 0)) {
            status = true;
            break;
        }
    }

    return status;
}

char *getNamaPengguna() {
    char *nama;
    nama = malloc(sizeof(char) * MAX_NAMA);

    int i;
    for(i = 0; i < banyakPelanggan; i++) {
        if(strcmp(listPelanggan[i].username, username) == 0) {
            strcpy(nama, listPelanggan[i].namaPelanggan);
            break;
        }
    }

    return nama;
}

void registrasi() {
    strcpy(listPelanggan[banyakPelanggan].id,
           inputStringMax("Masukan ID       : ", MAX_ID));

    strcpy(listPelanggan[banyakPelanggan].namaPelanggan,
           inputStringMax("Masukan nama     : ", MAX_NAMA));

    strcpy(listPelanggan[banyakPelanggan].username,
           inputStringMax("Masukan username : ", MAX_STRING_LOGIN));

    strcpy(listPelanggan[banyakPelanggan].password,
           inputStringMax("Masukan password : ", MAX_STRING_LOGIN));

    char anggota = confirm("Apakah anda ingin menjadi anggota? [Y/T] : ");
    if(anggota == 'Y') {
        listPelanggan[banyakPelanggan].statusPelanggan = 0;
    } else {
        listPelanggan[banyakPelanggan].statusPelanggan = 1;
    }

    printf("\n\nPelanggan \"%s\" Berhasil Disimpan\n", listPelanggan[banyakPelanggan].namaPelanggan);
    banyakPelanggan++;
}

/**
 * Halaman login admin
 */
void login() {
    do {
        printf("\n\nMasukan 0 pada username dan password untuk membatalkan login\n");
        printf("Masukan 1 pada username dan password untuk membatalkan register\n\n");

        strcpy(username, inputStringMax("Masukan username : ", MAX_STRING_LOGIN));

        strcpy(password, inputStringMax("Masukan password : ", MAX_STRING_LOGIN));

        if (strcmp(username, "1") == 0 && strcmp(password, "1") == 0) {
            registrasi();
        } else if (strcmp(username, "0") == 0 && strcmp(password, "0") == 0) {
            exit(0);
        } else if (authLogin()) {
            printf("Selamat Datang %s\n", getNamaPengguna());
            menuUtama();
        } else {
            printf("Username dan password tidak dikenali\n");
        }
    } while((strcmp(username, "0") != 0 && strcmp(password, "0") != 0));
}

/**
 * Main menu
 * @return 0 jika program sukses<br>Selain 0 jika program ada masalah
 */
int main() {

    login();

    return 0;
}
