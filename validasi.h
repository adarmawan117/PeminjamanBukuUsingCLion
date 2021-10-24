// versi 1
// 24 Oktober 2021
/**
 * Created by adarmawan117<br>
 */
 
#ifndef PEMINJAMANBUKUUSINGCLION_VALIDASI_H
#define PEMINJAMANBUKUUSINGCLION_VALIDASI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(char pesan[]);

int inputInt(char pesan[]);
int inputIntMin(char pesan[], int min);
int inputIntMinMax(char pesan[], int min, int max);

double inputDouble(char pesan[]);
double inputDoubleMin(char pesan[], double min);
double inputDoubleMinMax(char pesan[], double min, double max);

#endif //PEMINJAMANBUKUUSINGCLION_VALIDASI_H
