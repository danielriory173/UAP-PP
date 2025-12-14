#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <fstream>

#define LEBAR 30
#define TINGGI 20
#define UKURAN_ULAR_AWAL 3
#define UKURAN_ULAR_MAKS 100
#define SKOR_BOOSTER 50

struck titik{
int x,y;
};

enum JenisMakanan{BIASA,BOOSTER};

class PermainanUlar{
private:
int skor;
Titik ular [UKURAN_ULAR_MAKS];

int panjangUlar;
Titik makanan;
JenisMakanan jenisMakanan;
int arah X, int arah Y;
bool permainanSelesai;
std::string namaPemain;

public:
PermainanUlar(const std::string&nama) {
skor = 0;
arah X = 1;
arah Y = 0;
permainanSlesai = false;
panjangUlar = UKURAN_ULAR_AWAL;
namaPemain = nama;

for (int i = 0; i < panjangUlar; i++){
    ular[i] = {panjangUlar - i - 1, tinggi / 2};
}
    buat makanan();
}
void buatMakanan(){
    bool valid = false;
    while {!valid} {
        makanan.x = rand() % (LEBAR - 2) + 1;
        makanan.y = tand() % (TINGGI - 2) + 1;

        valid = true;
        for (int i = 0; i < panjangUlar; i++){
            if (ular[i].x == makanan.x && ular[i].y == makanan.y){
                valid = false;
                break;
            }
        }
    }
                


}
if (rand() % 5 == 0) {  
        jenisMakanan = BOOSTER;  
    } else {  
        jenisMakanan = BIASA;  
    }  
}  

void gambarPapan() {  
    clear();  
    for (int i = 0; i < LEBAR; ++i) {  
        mvaddch(0, i, '#');  
        mvaddch(TINGGI - 1, i, '#');  
    }  
    for (int i = 0; i < TINGGI; ++i) {  
        mvaddch(i, 0, '#');  
        mvaddch(i, LEBAR - 1, '#');  
    }  

    for (int i = 0; i < panjangUlar; ++i) {  
        mvaddch(ular[i].y, ular[i].x, (i == 0) ? '@' : 'O');  
    }  

    if (jenisMakanan == BIASA) {  
        mvaddch(makanan.y, makanan.x, '*');  
    } else {  
        mvaddch(makanan.y, makanan.x, 'B');  
    }  

    mvprintw(0, LEBAR + 2, "Pemain: %s", namaPemain.c_str());  
    mvprintw(1, LEBAR + 2, "Skor: %d", skor);  
    refresh();  
}  

void gerakUlar() {  
    Titik kepalaBaru = ular[0];  
    kepalaBaru.x += arahX;  
    kepalaBaru.y += arahY;  

    if (kepalaBaru.x == 0 || kepalaBaru.x == LEBAR - 1 || kepalaBaru.y == 0 || kepalaBaru.y == TINGGI - 1) {  
        permainanSelesai = true;  
        return;  
    }  
    for (int i = 0; i < panjangUlar; ++i) {  
        if (ular[i].x == kepalaBaru.x && ular[i].y == kepalaBaru.y) {  
            permainanSelesai = true;  
            return;  
        }  
    }  

    for (int i = panjangUlar - 1; i > 0; --i) {  
        ular[i] = ular[i - 1];  
    }  

    ular[0] = kepalaBaru;  

    if (kepalaBaru.x == makanan.x && kepalaBaru.y == makanan.y) {  
        if (jenisMakanan == BIASA) {  
            skor += 10;  
        } else {  
            skor += SKOR_BOOSTER;  
        }  

        if (panjangUlar < UKURAN_ULAR_MAKS) {  
            panjangUlar++;  
        }  
        buatMakanan();  
    }  
}  

void prosesInput() {  
    timeout(100);  
    int masukan = getch();  
    switch (masukan) {  
    case KEY_UP:  
        if (arahY == 0) {  
            arahX = 0;  
            arahY = -1;  
        }  
        break;  
    case KEY_DOWN:  
        if (arahY == 0) {  
            arahX = 0;  
            arahY = 1;  
        }  
        break;  
    case KEY_LEFT:  
        if (arahX == 0) {  
            arahX = -1;  
            arahY = 0;  
        }  
        break;  
    case KEY_RIGHT:  
        if (arahX == 0) {  
            arahX = 1;  
            arahY = 0;  
        }  
        break;  
    case 'q':  
        permainanSelesai = true;  
        break;  
    }  
}  

bool cekPermainanSelesai() {  
    return permainanSelesai;  
}  

void jalankan() {  
    while (!permainanSelesai) {  
        prosesInput();  
        gerakUlar();  
        gambarPapan();  
    }  
}

};

