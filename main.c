
// Versi 4
/**
===========
- Buat fungsi gotxy, untuk mempercantik tampilan




*/

// Versi 3
/**
===========
28 - September - 2021
Mulai pindah ke Clion
===========
- Koneksikan peminjaman dengan pelanggan
- Refactor penamaan

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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define USERNAME "agus"
#define PASSWORD "agus"
#define NAMA "Agus Darmawan"

#define MAX_ID 10
#define MAX_NAMA 40
#define MAX_STRUCT 50


/* Deklarasi Fungsi */
void login();


/* implementasi fungsi */
void clrscr() {
    system("cls");
}

void enter() {
    fflush(stdin);
    getchar();
}

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
    char namaPelanggan[MAX_NAMA];
    /**
     * 0 untuk bukan anggota, dan 1 merupakan anggota
     */
    int statusPelanggan;
} DATA_PELANGGAN;

typedef struct {
    char idPeminjaman[MAX_ID];
    char idBuku[MAX_ID];
    char idPeminjam[MAX_ID];
    int lamaPinjam;
    int totalBiaya;
} DATA_PEMINJAMAN;




DATA_BUKU listBuku[MAX_STRUCT];
int banyakBuku = 0;

DATA_PELANGGAN listPelanggan[MAX_STRUCT];
int banyakPelanggan = 0;


DATA_PEMINJAMAN listPeminjaman[MAX_STRUCT];
int banyakPeminjaman = 0;

/**
Untuk mengecek apakah list buku masih kosong
*/
bool isEmptyBuku() {
    return banyakBuku == 0;
}

bool isEmptyPelanggan() {
    return banyakPelanggan == 0;
}

bool isEmptyPeminjaman() {
    return banyakPeminjaman == 0;
}

char *getStatusSewa(int status) {
    return (status == 1) ? "Dipinjam" : "Avail";
}

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


char *getStatusPelanggan(int status) {
    return status == 1 ? "Anggota" : "Bukan Anggota";
}

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
            printf("Selamat, anda berhasil meminjam buku %s\n", listBuku[pilihBuku].namaBuku);
            listBuku[pilihBuku].statusSewa = 1; // buku sudah dipinjam
        } else {
            printf("Anda membatalkan peminjaman buku %s\n", listBuku[pilihBuku].namaBuku);
        }


    } while(confirm != 'Y' && confirm != 'T');
}

int getJumlahBukuDipinjam() {
    int i;
    int jumlahBukuDipinjam = 0;
    for(i = 0; i < banyakBuku; i++) {
        // kalau bukunya dipinjam
        if(listBuku[i].statusSewa == 1) {
            jumlahBukuDipinjam++;
        }
    }

    return jumlahBukuDipinjam;
}

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

    tampilBuku(); // menampilkan semua buku yang ada

    // proses milih buku
    int pilihBuku;

    do {
        printf("                               ||Pilih buku yang ingin dikembalikan : ");
        scanf("%d", &pilihBuku);

        pilihBuku--;
    } while(listBuku[pilihBuku].statusSewa != 1 && (pilihBuku < 1 || pilihBuku > jumlahBukuDipinjam));
    printf("                               ||                                      ||\n");
    printf("                               ||======================================||\n");

    char confirm;
    do {
        printf("\n\nIngin mengembalikan buku dengan judul %s [Y/T]?", listBuku[pilihBuku].namaBuku);
        fflush(stdin);
        confirm = (char) toupper((char) getchar());

        if(confirm == 'Y') {
            printf("Selamat, anda berhasil mengembalikan buku %s\n", listBuku[pilihBuku].namaBuku);
            listBuku[pilihBuku].statusSewa = 0; // buku sudah dikembalikan
        } else {
            printf("Anda membatalkan pengembalian buku %s\n", listBuku[pilihBuku].namaBuku);
        }


    } while(confirm != 'Y' && confirm != 'T');
}



void initBuku() {
    strcpy(listBuku[banyakBuku].id, "BK-01");
    strcpy(listBuku[banyakBuku].namaBuku, "Belajar Pemrograman JAVA");
    listBuku[banyakBuku].hargaSewa = 30000;
    listBuku[banyakBuku].statusSewa = 0;
    banyakBuku++;
}

void initPelanggan() {
    strcpy(listPelanggan[banyakPelanggan].id, "PMJ-01");
    strcpy(listPelanggan[banyakPelanggan].namaPelanggan, "Hendra Maulana");
    listPelanggan[banyakPelanggan].statusPelanggan = 0;
    banyakPelanggan++;
}

void init() {
    initBuku();
    initPelanggan();
}

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

    if(pilihan == 5) {
        login();
    } // selain itu keluar (exit) program
}

void login() {

    char username[100];
    char password[100];

    printf("\n\nMasukan 0 pada username dan password untuk membatalkan login\n\n");

    printf("Masukan username : ");
    scanf("%s", username);

    printf("Masukan password : ");
    scanf("%s", password);

    if(strcmp(username, "0") == 0 && strcmp(password, "0") == 0) {
        exit(0);
    } else if(strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
        printf("Selamat Datang %s\n", NAMA);
        menuUtama();
    } else {
        printf("Username dan password tidak dikenali\n");
    }

}

int main() {

    menuUtama();

    return 0;
}
