//
// Created by adarm on 9/15/2022.
//

#include "ViewPelanggan.h"

/**
Untuk mengecek apakah list pelanggan masih kosong
*/
bool isEmptyPelanggan() {
    return banyakPelanggan == 0;
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
 * Inisialisasi awal (terhadap list pelanggan) ketika program pertama kali dijalankan
 */
void initPelanggan() {
    strcpy(listPelanggan[banyakPelanggan].id, "PMJ-01");
    strcpy(listPelanggan[banyakPelanggan].username, "hendra");
    strcpy(listPelanggan[banyakPelanggan].password, "hendra");
    strcpy(listPelanggan[banyakPelanggan].namaPelanggan, "Hendra Maulana");
    listPelanggan[banyakPelanggan].statusPelanggan = 0;
    banyakPelanggan++;
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
        // daftar menjadi anggota
        listPelanggan[banyakPelanggan].statusPelanggan = 0;
    } else {
        // daftar tanpa menjadi anggota
        listPelanggan[banyakPelanggan].statusPelanggan = 1;
    }

    printf("\n\nPelanggan \"%s\" Berhasil Disimpan\n", listPelanggan[banyakPelanggan].namaPelanggan);
    banyakPelanggan++;
}
