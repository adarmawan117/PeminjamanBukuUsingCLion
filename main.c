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


// versi 4.1
/**
 * 28 Maret 2022
 - Untuk menambah pelanggan, harus admin
 - Buatkan login sebagai admin atau sebagai pelanggan
 */

// Versi 4
/**
 * 14-Oktober-2021
===========
 - Buat fungsi untuk register.........................................s= DONE
 - Validasi input register dan login..................................= DONE

 *** 28 Maret 2022
 - Kalau login sebagai user biasa, maka hanya boleh melihat list buku.= DONE

 *** 14 September 2022
 - Buat fungsi untuk menambah buku....................................= DONE
 - Buat fungsi untuk merubah buku.....................................= DONE
 - Buat fungsi untuk menghapus buku...................................= DONE

 - Buat fungsi untuk menghapus pelanggan
 - Buat fungsi untuk merubah pelanggan

 - Simpan data buku kedalam file
 - Simpan data pelanggan kedalam file
 - Simpan data peminjaman kedalam file

 *** 15 September 2022
 - Modularisasi file (pisahkan fungsi tertentu kedalam file terpisah)...= DONE
 - Penyesuaian nama didalam program (tidak ada lagi peminjaman, penyewaan, dkk dll)....= DONE

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
hargaPinjam perhari
statusPinjam

*/



#include "view/ViewBuku.c"
#include "view/ViewPelanggan.c"
#include "view/ViewPeminjaman.c"

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

    printf("==========================================================================\n");
    printf("||%-5s||%-5s||%-10s||%-15s||%-15s||%-10s||\n", "No", "ID", "ID Buku", "Lama Pinjam", "Total Biaya", "Status");
    printf("==========================================================================\n");
    int i;
    for(i = 0; i < banyakPeminjaman; i++) {
        if(strcmp(listPeminjaman[i].idPelanggan, username) == 0) {
            printf("||%-5d||%-5d||%-10s||%-15d||%-15d||%-10s||\n", (i + 1), listPeminjaman[i].idPeminjaman,
                   listPeminjaman[i].idBuku, listPeminjaman[i].lamaPinjam, listPeminjaman[i].totalBiaya, listPeminjaman[i].status);
            tempPeminjaman[idxTemp] = listPeminjaman[i];
        }
    }
    printf("==========================================================================\n");

    // proses milih buku
    int pilihBuku;

    do {
        printf("                               ||Pilih buku yang ingin dikembalikan : ");
        scanf("%d", &pilihBuku);

        if(strcmp(listPeminjaman[pilihBuku-1].status, "Kembali") == 0) {
            printf("                               ||Buku sudah dikembalikan\n");
            printf("                               ||                                      ||\n");
            printf("                               ||======================================||\n");
            continue;
        }

    } while((pilihBuku < 1 || pilihBuku > jumlahBukuDipinjam) || strcmp(listPeminjaman[pilihBuku-1].status, "Kembali") == 0);
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
            listBuku[idxBuku].statusPinjam = 0; // buku sudah dikembalikan
            strcpy(listPeminjaman[pilihBuku].status, "Kembali");

            printf("Selamat, anda berhasil mengembalikan buku %s\n", namaBuku);
        } else if(confirm == 'T') {
            printf("Anda membatalkan pengembalian buku %s\n", namaBuku);
        }


    } while(confirm != 'Y' && confirm != 'T');
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
void menuUtamaSetelahLogin() {

    int pilihan;
//    init();

    do {
        clrscr();
        printf("||======================================||\n");
        printf("||              MENU UTAMA              ||\n");
        printf("||======================================||\n");
        printf("||                                      ||\n");
        printf("|| 1. Manage Buku                       ||\n");
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
                manageBuku();
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
                exit(0);
                break;
            default:
                printf("Pilihan hanya dari 1 - 7 saja!\n");
        }
        enter();
    } while(pilihan != 6);

}

void menuUtamaGuestAccount() {

    int pilihan;
//    init();

    do {
        clrscr();
        printf("||======================================||\n");
        printf("||       MENU UTAMA GUEST ACCOUNT       ||\n");
        printf("||======================================||\n");
        printf("||                                      ||\n");
        printf("|| 1. Tampil List Buku                  ||\n");
        printf("|| 2. Login                             ||\n");
        printf("|| 3. Keluar                            ||\n");
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
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Pilihan hanya dari 1 - 3 saja!\n");
        }
        enter();
    } while(pilihan != 2);

}

/**
 * Halaman login admin
 */
void login() {
    do {
        printf("\n\nMasukan 0 pada username dan password untuk membatalkan login\n");
        printf("Masukan 1 pada username dan password untuk melakukan register\n\n");
        printf("Masukan 2 pada username dan password untuk login \"Guest Account\"\n\n");

//        strcpy(username, inputStringMax("Masukan username : ", MAX_STRING_LOGIN));
//        strcpy(password, inputStringMax("Masukan password : ", MAX_STRING_LOGIN));


        strcpy(username, "hendra");
        strcpy(password, "hendra");
        if (strcmp(username, "1") == 0 && strcmp(password, "1") == 0) {
            registrasi();
        } else if (strcmp(username, "2") == 0 && strcmp(password, "2") == 0) {
            menuUtamaGuestAccount();
        } else if (strcmp(username, "0") == 0 && strcmp(password, "0") == 0) {
            exit(0);
        } else if (authLogin()) {
            printf("Selamat Datang %s\n", getNamaPengguna());

            menuUtamaSetelahLogin();
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

    init();
    login();

    return 0;
}
