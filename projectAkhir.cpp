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

int main(){
    
}
