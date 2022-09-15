//
// Created by adarm on 9/15/2022.
//

#include "ViewBuku.h"

bool isEmptyBuku() {
    return banyakBuku == 0;
}

char *getStatusPinjam(int status) {
    return (status == 1) ? "Dipinjam" : "Avail";
}

void tampilBuku() {

    int i;

    printf("========================================================================================================\n");
    printf("||%-5s||%-10s||%-40s||%-15s||%-22s||\n", "No", "ID", "Nama", "Harga", "Status Peminjaman");
    printf("========================================================================================================\n");
    for(i = 0; i < banyakBuku; i++) {
        printf("||%-5d||%-10s||%-40s||%-15d||%-22s||\n", (i+1), listBuku[i].id, listBuku[i].namaBuku, listBuku[i].hargaPinjam,
               getStatusPinjam(listBuku[i].statusPinjam));
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

void tambahBuku() {
    DATA_BUKU bukuBaru;
    strcpy(bukuBaru.id, inputStringMax("Masukan ID buku    : ", MAX_ID));
    strcpy(bukuBaru.namaBuku, inputStringMax("Masukan nama buku  : ", MAX_NAMA));
    bukuBaru.hargaPinjam = inputInt("Masukan harga pinjam : ");
    bukuBaru.statusPinjam = inputInt("Masukan status pinjam (0 tersedia 1 dipinjam)  : ");

    listBuku[banyakBuku] = bukuBaru;

    printf("Buku '%s' berhasil disimpan\n", bukuBaru.namaBuku);
    banyakBuku++;
}

void rubahBuku() {
    if(isEmptyBuku()) {
        printf("Data buku masih kosong!\nSilahkan tambah buku terlebih dahulu\n");
        return;
    }

    tampilListBuku();
    int bukuDipilih;
    do {
        printf("Pilih buku [1 - %d] : ", banyakBuku);
        scanf("%d", &bukuDipilih);
    } while(bukuDipilih < 1 || bukuDipilih > banyakBuku);
    bukuDipilih--;

    printf("\n\nMasukan data baru\n");

    DATA_BUKU bukuBaru;
    strcpy(bukuBaru.id, inputStringMax("Masukan ID buku    : ", MAX_ID));
    strcpy(bukuBaru.namaBuku, inputStringMax("Masukan nama buku  : ", MAX_NAMA));
    bukuBaru.hargaPinjam = inputInt("Masukan harga pinjam : ");
    bukuBaru.statusPinjam = inputInt("Masukan status pinjam (0 tersedia 1 dipinjam)  : ");

    listBuku[bukuDipilih] = bukuBaru;

    printf("Buku '%s' berhasil dirubah\n", bukuBaru.namaBuku);
}

void hapusBuku() {
    if(isEmptyBuku()) {
        printf("Data buku masih kosong!\nSilahkan tambah buku terlebih dahulu\n");
        enter();
        return;
    }

    tampilListBuku();
    int bukuDipilih;
    do {
        printf("Pilih buku [1 - %d] : ", banyakBuku);
        scanf("%d", &bukuDipilih);
    } while(bukuDipilih < 1 || bukuDipilih > banyakBuku);
    bukuDipilih--;

    printf("\n\nYakin ingin menghapus '%s? '", listBuku[bukuDipilih].namaBuku);
    char confirm = confirmWithoutMessages();

    char bukuDihapus[MAX_NAMA];
    strcpy(bukuDihapus, listBuku[bukuDipilih].namaBuku);
    if(confirm == 'Y') {
        // hapus data
        DATA_BUKU bukuBaru = {
                "\0",
                "\0",
                0,
                0
        };

        if(bukuDipilih == banyakBuku-1) {
            listBuku[bukuDipilih] = bukuBaru;
        } else {
            int i;
            for(i = 0; i < banyakBuku-1; i++) {
                listBuku[i] = listBuku[i+1];
            }
            listBuku[i] = bukuBaru;
        }

        printf("Buku '%s' berhasil dirubah\n", bukuDihapus);
        banyakBuku--;
    } else {
        // penghapusan dibatalkan
    }
}

void manageBuku() {

    int pilihan;

    do {
        clrscr();
        printf("||======================================||\n");
        printf("||              MANAGE BUKU             ||\n");
        printf("||======================================||\n");
        printf("||                                      ||\n");
        printf("|| 1. Tambah Buku                       ||\n");
        printf("|| 2. Tampil Buku                       ||\n");
        printf("|| 3. Rubah Buku                        ||\n");
        printf("|| 4. Hapus Buku                        ||\n");
        printf("|| 5. Menu Utama                        ||\n");
        printf("||                                      ||\n");
        printf("||======================================||\n");
        printf("||                                      ||\n");
        printf("|| Pilihan >> ");
        scanf("%d", &pilihan);
        printf("||                                      ||\n");
        printf("||======================================||\n");

        switch(pilihan) {
            case 1:
                tambahBuku();
                break;
            case 2:
                tampilListBuku();
                break;
            case 3:
                rubahBuku();
                break;
            case 4:
                hapusBuku();
                break;
            case 5:
                break;
            default:
                printf("Pilihan hanya dari 1 - 5 saja!\n");
        }
        enter();
    } while(pilihan != 5);

}

void initBuku() {
    strcpy(listBuku[banyakBuku].id, "BK-01");
    strcpy(listBuku[banyakBuku].namaBuku, "Belajar Pemrograman JAVA");
    listBuku[banyakBuku].hargaPinjam = 30000;
    listBuku[banyakBuku].statusPinjam = 0;
    banyakBuku++;
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
