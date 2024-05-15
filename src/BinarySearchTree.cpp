/** 
* @file BinarySearchTree.cpp
* @description İkili arama ağacının metotlarını bulunduran kaynak dosyası
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 06.08.2023
* @author Eren Dinç eren.dinc@ogr.sakarya.edu.tr Ali Zahid Can zahid.can@ogr.sakarya.edu.tr
*/
#include "BinarySearchTree.hpp"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() : kok(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    
}

void BinarySearchTree::ekleme(int deger) {
    eklemeFonksiyonu(kok, deger);
}

void BinarySearchTree::eklemeFonksiyonu(agacDugum*& dugum, int deger) {
    if (dugum == nullptr) {
        dugum = new agacDugum(deger);
        return;
    }

    if (deger < dugum->veri) {
        eklemeFonksiyonu(dugum->sol, deger);
    } else if (deger > dugum->veri) {
        eklemeFonksiyonu(dugum->sag, deger);
    }
}

void BinarySearchTree::postorderYazdir() const {
    postorderYazdirmaFonksiyonu(kok);
    cout << endl;
}

void BinarySearchTree::postorderYazdirmaFonksiyonu(agacDugum* dugum) const {
    if (dugum == nullptr) {
        return;
    }

    postorderYazdirmaFonksiyonu(dugum->sol);
    postorderYazdirmaFonksiyonu(dugum->sag);
    cout << static_cast<char>(dugum->veri) << " "; // ASCII
}

int BinarySearchTree::yukseklikGetir() const {
    return yukseklikGetirmeFonksiyonu(kok);
}

int BinarySearchTree::toplamGetir() const {
    return toplamGetirmeFonksiyonu(kok);
}

int BinarySearchTree::yukseklikGetirmeFonksiyonu(agacDugum* dugum) const {
    if (dugum == nullptr) {
        return 0;
    }

    int solYukseklik = yukseklikGetirmeFonksiyonu(dugum->sol);
    int sagYukseklik = yukseklikGetirmeFonksiyonu(dugum->sag);
    return 1 + max(solYukseklik, sagYukseklik);
}

int BinarySearchTree::toplamGetirmeFonksiyonu(agacDugum* dugum) const {
    if (dugum == nullptr) {
        return 0;
    }

    return dugum->veri + toplamGetirmeFonksiyonu(dugum->sol) + toplamGetirmeFonksiyonu(dugum->sag);
}
