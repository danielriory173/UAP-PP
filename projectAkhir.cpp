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
