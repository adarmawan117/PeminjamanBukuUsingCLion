//
// Created by adarm on 9/15/2022.
//

#include "ViewPelanggan.h"

int sizePelanggan(DATA_PELANGGAN listPelanggan[]) {
    int idx = 0;
    while(strcmp(listPelanggan[idx].username, "") != 0) {
        idx++;
    }

    return idx;
}

bool isEmptyPelanggan(DATA_PELANGGAN listPelanggan[]) {
    return sizePelanggan(listPelanggan) == 0;
}

bool authPelanggan(DATA_PELANGGAN listPelanggan[], char username[], char password[]) {
    bool status = false;
    int banyakPelanggan = sizePelanggan(listPelanggan);
    int i;
    for(i = 0; i < banyakPelanggan; i++) {
        if((strcmp(listPelanggan[i].username, username) == 0) && (strcmp(listPelanggan[i].password, password) == 0)) {
            status = true;
            break;
        }
    }

    return status;
}

char *getStatusPelanggan(int status) {
    return status == 1 ? "Anggota" : "Bukan Anggota";
}

void tampilPelanggan(DATA_PELANGGAN listPelanggan[]) {
    int i;
    int banyakPelanggan = sizePelanggan(listPelanggan);

    printf("==========================================================================================\n");
    printf("||%-5s||%-10s||%-40s||%-25s||\n", "No", "ID", "Nama", "Status Anggota");
    printf("==========================================================================================\n");
    for(i = 0; i < banyakPelanggan; i++) {
        printf("||%-5d||%-10s||%-40s||%-25s||\n", (i+1), listPelanggan[i].id, listPelanggan[i].namaPelanggan,
               getStatusPelanggan(listPelanggan[i].statusPelanggan));
    }
    printf("==========================================================================================\n");
}

void tampilListPelanggan(DATA_PELANGGAN listPelanggan[]) {

    clrscr();
    printf("\n\n\n");
    printf("                        ||======================================||\n");
    printf("                        || HALAMAN TAMPIL SEMUA LIST PELANGGAN  ||\n");
    printf("                        ||======================================||\n");

    if(isEmptyPelanggan(listPelanggan)) {
        printf("                        ||                                      ||\n");
        printf("                        ||       Pelanggan masih kosong!        ||\n");
        printf("                        ||                                      ||\n");
        printf("                        ||======================================||\n");
        return;
    }

    printf("\n");
    tampilPelanggan(listPelanggan);
}

void tambahPelanggan(DATA_PELANGGAN listPelanggan[]) {
    int panjangID;
    int banyakPelanggan = sizePelanggan(listPelanggan);

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

void initPelanggan(DATA_PELANGGAN listPelanggan[]) {
    int banyakPelanggan = 0;
    strcpy(listPelanggan[banyakPelanggan].id, "PMJ-01");
    strcpy(listPelanggan[banyakPelanggan].username, "hendra");
    strcpy(listPelanggan[banyakPelanggan].password, "hendra");
    strcpy(listPelanggan[banyakPelanggan].namaPelanggan, "Hendra Maulana");
    listPelanggan[banyakPelanggan].statusPelanggan = 0;
    banyakPelanggan++;
}

char *getNamaPengguna(DATA_PELANGGAN listPelanggan[], char username[]) {
    char *nama;
    nama = malloc(sizeof(char) * MAX_NAMA);

    int banyakPelanggan = sizePelanggan(listPelanggan);
    int i;
    for(i = 0; i < banyakPelanggan; i++) {
        if(strcmp(listPelanggan[i].username, username) == 0) {
            strcpy(nama, listPelanggan[i].namaPelanggan);
            break;
        }
    }

    return nama;
}

void registrasi(DATA_PELANGGAN listPelanggan[]) {
    int banyakPelanggan = sizePelanggan(listPelanggan);
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
