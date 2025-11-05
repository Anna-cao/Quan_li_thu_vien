#include "../include/Sach.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
using namespace std;

Sach::Sach() {
    this->maSach = "";
    this->tenSach = "";
    this->tacGia = "";
    this->NXB = "";
    this->type = "";
    this->soTrang = 0;
    this->soLuongTong = 0;
    this->soLuongDaMuon = 0;
    this->giaTien = 0;
}

Sach::Sach(string maSach, string tenSach, string tacGia, string NXB, string type, int soTrang, int soLuongTong, int soLuongDaMuon, double giaTien) : maSach(maSach), tenSach(tenSach), tacGia(tacGia), NXB(NXB), type(type),
soTrang(soTrang), soLuongTong(soLuongTong), soLuongDaMuon(soLuongDaMuon), giaTien(giaTien) {}

int Sach::soSachConLai() const {
    return soLuongTong - soLuongDaMuon;
}

bool Sach::muonSach() {
    if (soSachConLai() > 0) {
        soLuongDaMuon++;
        cout << "Da muon thanh cong! So sach con lai: " << soSachConLai() << endl;
        return true;
    } else {
        cout << "Khong du so luong sach de muon!" << endl;
        return false;
    }
}

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
    cout << "----- NHAP THONG TIN SACH -----\n";
    cout << "Ma sach: "; getline(cin, maSach);
    cout << "Ten sach: "; getline(cin, tenSach);
    cout << "Tac gia: "; getline(cin, tacGia);
    cout << "Nha xuat ban: "; getline(cin, NXB);
    cout << "The loai: "; getline(cin, type);

    cout << "So trang: "; cin >> soTrang;
    cout << "So luong tong: "; cin >> soLuongTong;
    cout << "So luong da muon: "; cin >> soLuongDaMuon;
    cout << "Gia tien: "; cin >> giaTien;
}

void Sach::hienThiThongTin() {
    cout << "\n----- THONG TIN SACH -----\n";
    cout << "Ma sach: " << maSach << endl;
    cout << "Ten sach: " << tenSach << endl;
    cout << "Tac gia: " << tacGia << endl;
    cout << "Nha xuat ban: " << NXB << endl;
    cout << "The loai: " << type << endl;
    cout << "So trang: " << soTrang << endl;
    cout << "So luong tong: " << soLuongTong << endl;
    cout << "So luong da muon: " << soLuongDaMuon << endl;
    cout << "So luong con lai: " << soSachConLai() << endl;
    cout << "Gia tien: " << giaTien << endl;
}
bool Sach::ghiFile(ofstream& out) const {
    if (!out.good()) return false;
    out << maSach << "," << tenSach << "," << tacGia << "," << NXB << ","
        << type << "," << soTrang << "," << soLuongTong << ","
        << soLuongDaMuon << "," << giaTien << "\n";
    return true;
}

bool Sach::docFile(ifstream& in) {
    string line;
    if (!getline(in, line) || line.empty()) return false;
    stringstream ss(line);
    string soTrangStr, tongStr, daMuonStr, giaStr;

    getline(ss, maSach, ',');
    getline(ss, tenSach, ',');
    getline(ss, tacGia, ',');
    getline(ss, NXB, ',');
    getline(ss, type, ',');
    getline(ss, soTrangStr, ',');
    getline(ss, tongStr, ',');
    getline(ss, daMuonStr, ',');
    getline(ss, giaStr, ',');

    try {
        soTrang = stoi(soTrangStr);
        soLuongTong = stoi(tongStr);
        soLuongDaMuon = stoi(daMuonStr);
        giaTien = stod(giaStr);
    } catch (...) {
        return false;
    }
    return true;
}