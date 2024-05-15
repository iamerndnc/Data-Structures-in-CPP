/** 
* @file Stack.cpp
* @description Yığıt veri yapısının metotlarını bulunduran kaynak dosyası
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 06.08.2023
* @author Eren Dinç eren.dinc@ogr.sakarya.edu.tr Ali Zahid Can zahid.can@ogr.sakarya.edu.tr
*/
#include "Stack.hpp"

Stack::Stack() : tepe(nullptr), boyut(0) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int deger) {
    StackDugum* newDugum = new StackDugum(deger);
    newDugum->sonraki = tepe;
    tepe = newDugum;
    boyut++;
}

int Stack::pop() {
    if (isEmpty()) {
        return -1;
    }

    int deger = tepe->veri;
    StackDugum* gecici = tepe;
    tepe = tepe->sonraki;
    delete gecici;
    boyut--;

    return deger;
}

bool Stack::isEmpty() const {
    return boyut == 0;
}

int Stack::peek() const {
    if (isEmpty()) {
        return -1;
    }

    return tepe->veri;
}
