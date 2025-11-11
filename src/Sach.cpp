#include "../include/Sach.h"
#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include "../include/Kho.h"
using namespace std;
int Sach::autoID = 0;

Sach::Sach() {
    this->maSach = "";
    this->tenSach = "";
    this->tacGia = "";
    this->NXB = "";
    this->type = "";
    this->giaTien = 0;
    this->soLuongTong = 0;
    this->soLuongDaMuon = 0;
};
Sach::Sach(string maSach, string tenSach, double giaTien)
    : maSach(maSach),
      tenSach(tenSach),
      tacGia(""),
      NXB(""),
      type(""),
      soLuongTong(0),
      soLuongDaMuon(0),
      giaTien(giaTien)
{}
bool Sach::traSach() {
    if (soLuongDaMuon > 0) {
        soLuongDaMuon--;
        cout << "Tra sach thanh cong! So sach con lai: " << soSachConLai() << endl;
        return true;
    } else {
        cout << "Khong co sach nao de tra!" << endl;
        return false;
    }
}

void Sach::nhap() {
    cout << "\n----- NHAP THONG TIN SACH -----\n";
    
    autoID++;
    stringstream ss;
    ss << "S" << setw(3) << setfill('0') << autoID;
    maSach = ss.str();
    cout << "Ma sach tu dong: " << maSach << endl;

    cout << "Ten sach: "; getline(cin, tenSach);
    cout << "Tac gia: "; getline(cin, tacGia);
    cout << "Nha xuat ban: "; getline(cin, NXB);

    bool check = false;
    do {
        cout << "The loai sach (Sach bai tap, Tai lieu tham khao, Giao trinh, Luan an): "; 
        getline(cin, type);
        
        if (type == "Sach bai tap" || type == "Tai lieu tham khao" || 
            type == "Giao trinh" || type == "Luan an") {
            check = true;
        } else {
            cout << "The loai khong hop le! Vui long nhap lai mot trong cac the loai cho phep.\n";
        }
    } while (!check);

    cout << "Gia tien 1 quyen: "; cin >> giaTien;
    cin.ignore();
}

void Sach::hienThiThongTin() {
    cout << left
         << setw(10) << "Ma sach"
         << setw(25) << "Ten sach"
         << setw(20) << "Tac gia"
         << setw(20) << "Nha xuat ban"
         << setw(20) << "The loai"
         << setw(10) << "Gia tien 1 quyen" << endl;
    cout << left
         << setw(10) << maSach
         << setw(25) << tenSach
         << setw(20) << tacGia
         << setw(20) << NXB
         << setw(20) << type
         << setw(10) << giaTien << endl;
}

int Sach::soSachConLai() const {
    return soLuongTong - soLuongDaMuon;
}

int Sach::docFileSach(Sach danhSach[], int soLuongToiDa, const string& duongDan) {
    ifstream in(duongDan);
    if (!in.is_open()) {
        cerr << "Khong mo duoc file sach: " << duongDan << endl;
        return 0;
    }

    int soLuong = 0;
    string line;

    while (soLuong < soLuongToiDa && getline(in, line)) {
        if (line.empty()) continue;

        string maSach, tenSach, tacGia, NXB, theLoai, tmp;
        int soLuongTong = 0, soLuongDaMuon = 0;
        double giaTien = 0.0;

        if (!getline(in, maSach)) break;
        if (!getline(in, tenSach)) break;
        if (!getline(in, tacGia)) break;
        if (!getline(in, NXB)) break;
        if (!getline(in, theLoai)) break;  
        if (!getline(in, tmp)) break;
        if (!tmp.empty()) {
            try { soLuongTong = stoi(tmp); } catch (...) {}  
        }

        if (!getline(in, tmp)) break;
        if (!tmp.empty()) {
            try { soLuongDaMuon = stoi(tmp); } catch (...) {}
        }

        if (!getline(in, tmp)) break;
        if (!tmp.empty()) {
            try { giaTien = stod(tmp); } catch (...) {}  
        }
        Sach s(maSach, tenSach, giaTien);  
        s.setTacGia(tacGia);
        s.setNXB(NXB);
        s.setType(theLoai);
        s.setSoLuongTong(soLuongTong);
        s.setSoLuongDaMuon(soLuongDaMuon);

        danhSach[soLuong++] = s;
        try {
            int id = stoi(maSach.substr(1)); 
            if (id > autoID) autoID = id;
        } catch (...) {}
    }

    in.close();
    return soLuong;
}

void Sach::ghiFileSach(const Sach danhSach[], int soLuong, const string& duongDan) {
    ofstream out(duongDan);
    if (!out.is_open()) {
        cerr << "Khong the ghi file sach: " << duongDan << endl;
        return;
    }

    for (int i = 0; i < soLuong; ++i) {
        const Sach &s = danhSach[i];
        out << s.getMaSach() << "\n";
        out << s.getTenSach() << "\n";
        out << s.getTacGia() << "\n";
        out << s.getNXB() << "\n";
        out << s.getType() << "\n";
        out << s.getSoLuongTong() << "\n";
        out << s.getSoLuongDaMuon() << "\n";
        out << fixed << setprecision(0) << s.getGiaTien() << "\n\n";
    }
    out.close();
}

void Sach::capNhatAutoID(int id) {
    if (id > autoID) autoID = id;
}
