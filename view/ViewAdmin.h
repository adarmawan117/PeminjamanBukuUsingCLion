//
// Created by adarm on 9/18/2022.
//

#ifndef PEMINJAMANBUKUUSINGCLION_VIEWADMIN_H
#define PEMINJAMANBUKUUSINGCLION_VIEWADMIN_H

typedef struct {
    char username[MAX_STRING_LOGIN];
    char password[MAX_STRING_LOGIN];
} DATA_ADMIN;

int sizeAdmin(DATA_ADMIN listAdmin[]);
bool isEmptyAdmin(DATA_ADMIN listAdmin[]);
bool authAdmin(DATA_ADMIN listAdmin[], char username[], char password[]);

#endif //PEMINJAMANBUKUUSINGCLION_VIEWADMIN_H
