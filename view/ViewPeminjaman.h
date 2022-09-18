//
// Created by adarm on 9/15/2022.
//

#ifndef PEMINJAMANBUKUUSINGCLION_VIEWPEMINJAMAN_H
#define PEMINJAMANBUKUUSINGCLION_VIEWPEMINJAMAN_H

typedef struct {
    int idPeminjaman;
    char idBuku[MAX_ID];
    char idPelanggan[MAX_ID];
    int lamaPinjam;
    int totalBiaya;
    char status[MAX_NAMA];
} DATA_PEMINJAMAN;

DATA_PEMINJAMAN listPeminjaman[MAX_STRUCT];

int banyakPeminjaman = 0;

#endif //PEMINJAMANBUKUUSINGCLION_VIEWPEMINJAMAN_H
