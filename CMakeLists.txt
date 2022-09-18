cmake_minimum_required(VERSION 3.20)
project(PeminjamanBukuUsingCLion C)

set(CMAKE_C_STANDARD 11)

add_executable(
        PeminjamanBukuUsingCLion
        main.c
        validasi.c
        validasi.h

        method/Konstanta.h
        method/conio.c
        method/conio.h

        view/ViewBuku.h
        view/ViewPelanggan.h
        view/ViewPeminjaman.h
        view/ViewAdmin.h
)
