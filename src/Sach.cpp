#include "../include/Sach.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <ostream>
using namespace std;
int Sach::autoID = 0;

Sach::Sach() {
    this->maSach ="";
    this->tenSach = "";
    this->tacGia = "";
    this->NXB = "";
    this->type = "";
    this->giaTien = 0;
    this->soLuongTong = 0;
    this->soLuongDaMuon = 0;
};
Sach::Sach( string tenSach, double giaTien)
    : maSach(""),
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
bool Sach::muonSach() {
    if (soLuongDaMuon < soLuongTong) {
        soLuongDaMuon++;
        cout << "Muon sach thanh cong! Con lai: " << soSachConLai() << endl;
        return true;
    } else {
        cout << "Het sach de muon!\n";
        return false;
    }
}
void Sach::nhap() {
    cout << "\n----- NHAP THONG TIN SACH -----\n";
    autoID++;
    stringstream ss;
    ss << "S" << setw(3) << setfill('0') << autoID;
    maSach = ss.str();
    cout << "Ma sach hien tai: " << maSach << endl;
    cout << "Ten sach: "; getline(cin >> ws, tenSach);  
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
            cout << "The loai khong hop le! Vui long nhap lai.\n";
        }
    } while (!check);
    cout << "Gia tien 1 quyen: "; 
    while (!(cin >> giaTien) || giaTien < 0) {
        cout << "Gia tien phai >= 0. Nhap lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore(); 

    cout << "So luong tong: "; 
    while (!(cin >> soLuongTong) || soLuongTong < 0) {
        cout << "So luong phai >= 0. Nhap lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    soLuongDaMuon = 0;
    cin.ignore(); 
}

void Sach::hienThiThongTin() const {
    cout << left
         << setw(10) << "Ma sach"
         << setw(30) << "Ten sach"
         << setw(20) << "Tac gia"
         << setw(20) << "Nha xuat ban"
         << setw(20) << "The loai"
         << setw(12) << "Gia tien 1 quyen" 
         << setw(8) << "Tong sach"
         << setw(8) << "Da muon" 
         << setw(8) << "Con lai" << endl;
    cout << left
         << setw(10) << maSach
         << setw(30) << tenSach
         << setw(20) << tacGia
         << setw(20) << NXB
         << setw(20) << type
         << setw(12) << giaTien 
         << setw(8) << soLuongTong
         << setw(8) << soLuongDaMuon
         << setw(8) << soSachConLai() << endl;
}

int Sach::soSachConLai() const {
    return soLuongTong - soLuongDaMuon;
}
int Sach::docFileSach(Sach danhSach[], int soLuongToiDa, const string& duongDan) {
    ifstream in(duongDan);
    if (!in.is_open()) return 0;

    int soLuong = 0;
    string line;
    while (soLuong < soLuongToiDa && getline(in, line)) {
        if (line.empty()) continue;

        string maSach, tenSach, tacGia, NXB, theLoai, tmp;
        int soLuongTong = 0, soLuongDaMuon = 0;
        double giaTien = 0.0;

        maSach = line;

        if (!getline(in, tenSach)) { break; }
        if (!getline(in, tacGia)) { break; }
        if (!getline(in, NXB)) { break; }
        if (!getline(in, theLoai)) { break; }
        if (!getline(in, tmp)) { break; }
        soLuongTong = stoi(tmp);  
        if (!getline(in, tmp)) { break; }
        soLuongDaMuon = stoi(tmp);  
        if (!getline(in, tmp)) { break; }
        giaTien = stod(tmp);  
        if (!getline(in, line)) { break; }  

        Sach s;
        s.maSach = maSach;
        s.tenSach = tenSach;
        s.tacGia = tacGia;
        s.NXB = NXB;
        s.type = theLoai;
        s.soLuongTong = soLuongTong;
        s.soLuongDaMuon = soLuongDaMuon;
        s.giaTien = giaTien;

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
        cerr << "Khong ghi duoc file: " << duongDan << endl;
        return;
    }

    for (int i = 0; i < soLuong; ++i) {
        const Sach& s = danhSach[i];
        out << s.maSach << "\n";
        out << s.tenSach << "\n";
        out << s.tacGia << "\n";
        out << s.NXB << "\n";
        out << s.type << "\n";
        out << s.soLuongTong << "\n";
        out << s.soLuongDaMuon << "\n";
        out << fixed << setprecision(0) << s.giaTien << "\n"; 
        out << "\n"; 
    }
    out.close();
}

void Sach::capNhatAutoID(int id) {
    if (id > autoID) autoID = id;
}