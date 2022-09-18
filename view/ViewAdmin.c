//
// Created by adarm on 9/18/2022.
//

#include "ViewAdmin.h"

int sizeAdmin(DATA_ADMIN listAdmin[]) {
    int idx = 0;
    while(strcmp(listAdmin[idx].username, "") != 0) {
        idx++;
    }

    return idx;
}

bool isEmptyAdmin(DATA_ADMIN listAdmin[]) {
    return sizeAdmin(listAdmin) == 0;
}

bool authAdmin(DATA_ADMIN listAdmin[], char username[], char password[]) {
    bool status = false;
    int banyakAdmin = sizeAdmin(listAdmin);
    int i;
    for(i = 0; i < banyakAdmin; i++) {
        if((strcmp(listAdmin[i].username, username) == 0) && (strcmp(listAdmin[i].password, password) == 0)) {
            status = true;
            break;
        }
    }

    return status;
}