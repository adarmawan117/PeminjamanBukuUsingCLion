//
// Created by adarm on 9/15/2022.
//

#ifndef PEMINJAMANBUKUUSINGCLION_VIEWBUKU_H
#define PEMINJAMANBUKUUSINGCLION_VIEWBUKU_H

#include <stdbool.h>

#include "..\validasi.h"
#include "..\method\conio.h"

#define MAX_ID 10
#define MAX_NAMA 40
#define MAX_STRUCT 50

/* Deklarasi struct */
typedef struct {
    char id[MAX_ID];
    char namaBuku[MAX_NAMA];
    int hargaSewa;
    /**
     * 0 untuk avail, 1 untuk dipinjam
    */
    int statusSewa;
} DATA_BUKU;

DATA_BUKU listBuku[MAX_STRUCT];
int banyakBuku = 0;


#endif //PEMINJAMANBUKUUSINGCLION_VIEWBUKU_H
