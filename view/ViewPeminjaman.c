//
// Created by adarm on 9/15/2022.
//

#include "ViewPeminjaman.h"

int getLatestIDPeminjaman() {
    int latest = -1;
    while(listPeminjaman[latest++].idPeminjaman != 0) {
        // statement kosong
    }

    return latest;
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

        if(listBuku[pilihBuku-1].statusPinjam == 1) {
            printf("                               || Buku sedang dipinjam, silahkan pilih yang lain\n");
        }

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
            totalBiaya = lamaPinjam * listBuku[pilihBuku].hargaPinjam;

            listPeminjaman[banyakPeminjaman].idPeminjaman = getLatestIDPeminjaman() + 1;
            strcpy(listPeminjaman[banyakPeminjaman].idBuku, listBuku[pilihBuku].id);
            strcpy(listPeminjaman[banyakPeminjaman].idPelanggan, username);
            listPeminjaman[banyakPeminjaman].lamaPinjam = lamaPinjam;
            listPeminjaman[banyakPeminjaman].totalBiaya = totalBiaya;
            strcpy(listPeminjaman[banyakPeminjaman].status, "Pinjam");

            banyakPeminjaman++;

            printf("Selamat, anda berhasil meminjam buku %s\n", listBuku[pilihBuku].namaBuku);
            listBuku[pilihBuku].statusPinjam = 1; // buku sudah dipinjam
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
