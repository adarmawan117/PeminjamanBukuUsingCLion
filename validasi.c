// versi 1
// 24 Oktober 2021
/**
 * Created by adarmawan117<br>
 */

#include "validasi.h"

/**
 * Input string dengan maksimal 100 karakter
 * @param pesan pesan input user
 * @return string
 */
char *inputString(char pesan[]) {

    char *string = malloc(sizeof(char) * 100);

    printf("%s", pesan);
    fflush(stdin);
    scanf("%[^\n]", string);

    return string;
}

char *inputStringMax(char pesan[], int maxChar) {

    char *string;
    int len;

    do {
        string = malloc(sizeof(char) * maxChar);
        printf("%s", pesan);
        fflush(stdin);
        scanf("%[^\n]", string);
        len = (int) strlen(string);

        if(len < 1) {
            printf("Input tidak boleh kosong!\n\n");
        } else if(len > maxChar) {
            printf("Karakter yang dimasukan tidak boleh lebih dari %d\n\n", maxChar);
        }

    } while(len < 1 || len > maxChar);

    return string;
}

int inputInt(char pesan[]) {
    int nilai;

    printf("%s", pesan);
    scanf("%d", &nilai);

    return nilai;
}

int inputIntMin(char pesan[], int min) {
    int nilai;

    do {
        printf("%s", pesan);
        scanf("%d", &nilai);

        if(nilai < min) {
            printf("Input tidak boleh kurang dari %d\n", min);
        }

    } while(nilai < min);

    return nilai;
}

int inputIntMinMax(char pesan[], int min, int max) {
    int nilai;

    do {
        printf("%s", pesan);
        scanf("%d", &nilai);

        if(nilai < min) {
            printf("Input tidak boleh kurang dari %d\n", min);
        } else if(nilai > max) {
            printf("Input tidak boleh lebih dari %d\n", max);
        }

    } while(nilai < min);

    return nilai;
}

double inputDouble(char pesan[]) {
    double nilai;

    printf("%s", pesan);
    scanf("%lf", &nilai);

    return nilai;
}

double inputDoubleMin(char pesan[], double min) {
    double nilai;

    do {
        printf("%s", pesan);
        scanf("%lf", &nilai);

        if(nilai < min) {
            printf("Input tidak boleh kurang dari %lf\n", min);
        }

    } while(nilai < min);

    return nilai;
}

double inputDoubleMinMax(char pesan[], double min, double max) {
    double nilai;

    do {
        printf("%s", pesan);
        scanf("%lf", &nilai);

        if(nilai < min) {
            printf("Input tidak boleh kurang dari %lf\n", min);
        } else if(nilai > max) {
            printf("Input tidak boleh lebih dari %lf\n", max);
        }

    } while(nilai < min);

    return nilai;
}

/**
 * Konfirmasi
 * @param pesan
 * @return Y atau T
 */
char confirm(char pesan[]) {
    char hasil;
    do {
        printf("%s", pesan);
        fflush(stdin);
        hasil = (char) toupper((char)getchar());
    } while(hasil != 'Y' && hasil != 'T');

    return hasil;
}