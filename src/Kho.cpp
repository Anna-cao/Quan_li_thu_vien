// Kho.cpp
#include "../include/Kho.h"
#include <iostream>
#include <iomanip>
using namespace std;

Kho::Kho(int tong, int muon) 
    : soLuongTong(tong), soLuongDaMuon(muon), soNXB(0) {
    for (int i = 0; i < Max_NXB; ++i) {
        danhSachNXB[i] = nullptr;
    }
}

Kho::~Kho() {}
bool Kho::themNXB(NhaXuatBan* nxb) {
    if (!nxb || soNXB >= Max_NXB) return false;
    for (int i = 0; i < soNXB; ++i) {
        if (danhSachNXB[i]->getNXB() == nxb->getNXB()) return false;
    }
    danhSachNXB[soNXB++] = nxb;
    return true;
}

bool Kho::coNXB(const string& ten) const {
    for (int i = 0; i < soNXB; ++i) {
        if (danhSachNXB[i] && danhSachNXB[i]->getNXB() == ten) return true;
    }
    return false;
}

void Kho::HienThiKho() const {
    cout << "-----THONG TIN TRONG KHO-----\n";
    cout << "Tong sach trong: " << soLuongTong << endl;
    cout << "So luong sach da muon: " << soLuongDaMuon << endl;
    cout << "So luong sach con lai: " << soSachConLai() << endl;
    cout << "Danh sach nha xuat ban:\n";

    if (soNXB == 0) {
        cout << "Khong co nha xuat ban nao\n";
    } else {
        for (int i = 0; i < soNXB; ++i) {
            if (danhSachNXB[i]) {
                cout << i + 1 << ". " << danhSachNXB[i]->getNXB() << endl;
            }
        }
    }
}