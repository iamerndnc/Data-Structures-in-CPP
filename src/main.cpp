/** 
* @file main.cpp
* @description Dosyanın okunduğu ve metotların kullanıldığı yığıttaki verilerin ağaca eklenip postorder yazdırıldığı işlemleri içerir.
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 06.08.2023
* @author Eren Dinç eren.dinc@ogr.sakarya.edu.tr Ali Zahid Can zahid.can@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <windows.h>
#include "Stack.hpp"
#include "BinarySearchTree.hpp"
using namespace std;

int main() {
    ifstream dosya("Sayilar.txt");
    string satir;
    while (getline(dosya, satir)) {
        Stack stack;
        BinarySearchTree enYuksekAgac;
        int sonEklenenSayi = -1;
        istringstream iss(satir);
        int sayi;
        while (iss >> sayi) {
            if (sayi % 2 == 0 && (stack.isEmpty() || sayi > sonEklenenSayi)) {
                BinarySearchTree geciciAgac;
                while (!stack.isEmpty()) {
                    int sayi = stack.pop();
                    geciciAgac.ekleme(sayi);
                }
                if (geciciAgac.yukseklikGetir() > enYuksekAgac.yukseklikGetir()) {
                    enYuksekAgac = geciciAgac;
                } else if (geciciAgac.yukseklikGetir() == enYuksekAgac.yukseklikGetir()) {
                    if (geciciAgac.toplamGetir() > enYuksekAgac.toplamGetir()) {
                        enYuksekAgac = geciciAgac;
                    }
                }
            }
            stack.push(sayi);
            sonEklenenSayi = sayi;
        }

        BinarySearchTree geciciAgac;
        while (!stack.isEmpty()) {
            int sayi = stack.pop();
            geciciAgac.ekleme(sayi);
        }

        if (geciciAgac.yukseklikGetir() > enYuksekAgac.yukseklikGetir()) {
            enYuksekAgac = geciciAgac;
        } else if (geciciAgac.yukseklikGetir() == enYuksekAgac.yukseklikGetir()) {
            if (geciciAgac.toplamGetir() > enYuksekAgac.toplamGetir()) {
                enYuksekAgac = geciciAgac;
            }
        }
        
        enYuksekAgac.postorderYazdir();
        unsigned int milisaniye = 10;
        Sleep(milisaniye);
    }
    dosya.close();
    return 0;
}