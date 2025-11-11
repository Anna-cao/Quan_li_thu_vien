#include <fstream>
#include <sstream>
#include "../include/Kho.h"
#include <istream>
#include <ostream>
#include <iomanip>
#include <iostream>
#include <string>

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
int Kho::docFileKho(const string& duongDan) {
    ifstream in(duongDan);
    if (!in.is_open()) return 0;

    in >> soLuongTong >> soLuongDaMuon;
    in.ignore();

    soNXB = 0;
    string tenNXB;
    while (getline(in, tenNXB) && soNXB < Max_NXB) {
        if (tenNXB.empty()) continue;
        danhSachNXB[soNXB++] = new NhaXuatBan(tenNXB);
    }

    in.close();
    return 1;
}

void Kho::ghiFileKho(const string& duongDan) const {
    ofstream out(duongDan);
    if (!out.is_open()) return;

    out << soLuongTong << "\n";
    out << soLuongDaMuon << "\n";
    for (int i = 0; i < soNXB; ++i) {
        if (danhSachNXB[i]) {
            out << danhSachNXB[i]->getNXB() << "\n";
        }
    }
    out.close();
}