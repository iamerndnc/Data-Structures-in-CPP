#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "agacDugum.hpp"

class BinarySearchTree {
private:
    agacDugum* kok;

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void ekleme(int deger);
    void postorderYazdir() const;
    int yukseklikGetir() const;
    int toplamGetir() const;

private:
    void eklemeFonksiyonu(agacDugum*& dugum, int deger);
    void postorderYazdirmaFonksiyonu(agacDugum* dugum) const;
    int yukseklikGetirmeFonksiyonu(agacDugum* dugum) const;
    int toplamGetirmeFonksiyonu(agacDugum* dugum) const;
};

#endif
