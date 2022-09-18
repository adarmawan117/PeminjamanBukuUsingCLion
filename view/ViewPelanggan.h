//
// Created by adarm on 9/15/2022.
//

#ifndef PEMINJAMANBUKUUSINGCLION_VIEWPELANGGAN_H
#define PEMINJAMANBUKUUSINGCLION_VIEWPELANGGAN_H

#include <stdbool.h>

#include "..\validasi.h"
#include "..\method\conio.h"

#define MAX_ID 10
#define MAX_NAMA 40
#define MAX_STRUCT 50

#define MAX_STRING_LOGIN 100

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

int sizePelanggan(DATA_PELANGGAN listPelanggan[]);
bool isEmptyPelanggan(DATA_PELANGGAN listPelanggan[]);
bool authPelanggan(DATA_PELANGGAN listPelanggan[], char username[], char password[]);

char *getStatusPelanggan(int status);
void tampilPelanggan(DATA_PELANGGAN listPelanggan[]);
void tampilListPelanggan(DATA_PELANGGAN listPelanggan[]);
void tambahPelanggan(DATA_PELANGGAN listPelanggan[]);
void initPelanggan(DATA_PELANGGAN listPelanggan[]);
char *getNamaPengguna(DATA_PELANGGAN listPelanggan[], char username[]);
void registrasi(DATA_PELANGGAN listPelanggan[]);

#endif //PEMINJAMANBUKUUSINGCLION_VIEWPELANGGAN_H
