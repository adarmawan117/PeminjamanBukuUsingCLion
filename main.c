/**
 <h1>Versi 7</h1>
 - Implementasi penyimpanan data kedalam database MySQL / SQLite <br>
 */

/**
 <h1>Versi 6</h1>
 - Buat validasi agar input int bisa sesuai<br>
     Caranya dengan memasukan nilai kedalam string dahulu, kemudian lakukan pengecekan tiap karakternya<br>
     Kalau terdapat bukan int, keluarkan error dan minta input lagi<br>
     <Lihat playlist ke 12><br>
 */

/**
 <h1>Versi 5</h1>
 - Buat fungsi gotxy, untuk mempercantik tampilan<br>
 */


/**
 <h1>Versi 4.1</h1>
 <h2>28 Maret 2022</h2>
 - <s>Untuk menambah pelanggan, harus admin</s><br>
 - Buatkan login sebagai admin atau sebagai pelanggan<br><br><br>

 * 18 September 2022 *<br>
 * Video playlist ke 26 *<br>
 - Implementasi project menjadi linked list<br>
    Agar bisa meminimalisir penggunaan variabel global<br>
 */

/**
 <h1>Versi 4</h1>
 <h2>14 Oktober 2021</h2>
 - <s>Buat fungsi untuk register</s><br>
 - <s>Validasi input register dan login</s><br><br><br>

 <h2>28 Maret 2022</h2>
 - <s>Kalau login sebagai user biasa, maka hanya boleh melihat list buku</s><br><br><br>

 <h2>14 September 2022</h2>
 - <s>Buat fungsi untuk menambah buku</s><br>
 - <s>Buat fungsi untuk merubah buku</s><br>
 - <s>Buat fungsi untuk menghapus buku</s><br><br><br>

 - Buat fungsi untuk menghapus pelanggan<br>
 - Buat fungsi untuk merubah pelanggan<br><br>

 - Simpan data buku kedalam file<br>
 - Simpan data pelanggan kedalam file<br>
 - Simpan data peminjaman kedalam file<br><br><br>

 <h2>15 September 2022</h2>
 - <s>Modularisasi file</s><br>
 - <s>Penyesuaian nama didalam program</s><br><br>

 - <s>Mempercantik dokumentasi</s><br>
*/


/**
 <h1>Versi 3</h1>
 <h2>28 September 2021</h2>
Mulai pindah ke Clion<br>
===========<br>
- <s>Koneksikan peminjaman dengan pelanggan</s><br>
- <s>Refactor penamaan</s><br>

*/

/**
 <h1>Versi 2</h1>
 <h2>27 September 2021</h2>
===========<br>
- <s>Tambah pelanggan</s><br>
- <s>Lihat list peminjam</s><br>
- <s>Mengembalikan buku</s><br>
- <s>Logout</s><br>
- <s>Update login agar bisa membatalkan login (exit program)</s><br>

*/



/**
 <h1>Versi 1</h1>
 <h2>26 September 2021</h2>
===========<br>
- <s>Login</s><br>
- <s>Tampil list buku</s><br>
- <s>Pinjam Buku</s><br>

*/



#include "view/ViewBuku.c"
#include "view/ViewPelanggan.c"
#include "view/ViewPeminjaman.c"
#include "view/ViewAdmin.c"

char username[MAX_STRING_LOGIN];
char password[MAX_STRING_LOGIN];

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


    int jumlahBukuDipinjam = getJumlahBukuDipinjam(username);
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
            // auth admin
        } else if(authAdmin()) {
        // atuh pelanggan
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
