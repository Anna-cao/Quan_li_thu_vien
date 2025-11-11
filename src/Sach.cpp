#include "../include/Sach.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include"Kho.h"

Sach::Sach() {
    this->maSach = "";
    this->tenSach = "";
    this->tacGia = "";
    this->NXB = "";
    this->type = "";
    this->giaTien = 0;
}
Sach::Sach(string maSach, string tenSach, double giaTien)
    : maSach(maSach), tenSach(tenSach), tacGia(""), NXB(""), type(""), giaTien(giaTien) {}

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
    cout << "\n----- NHAP THONG TIN SACH -----\n";
    
    cout << "Ma sach: "; getline(cin, maSach);
    cout << "Ten sach: "; getline(cin, tenSach);
    cout << "Tac gia: "; getline(cin, tacGia);
    cout << "Nha xuat ban: "; getline(cin, NXB);
    cout << "The loai sach(Sach bai tap, Tai lieu tham khao, Giao trinh, Luan an): "; getline(cin, type);
    cout << "Gia tien 1 quyen: "; cin >> giaTien;
    cin.ignore(1, '\n');
}
void Sach::hienThiThongTin() {
    cout << left
         << setw(10) << "Ma sach: "
         << setw(20) << "Ten sach: "
         << setw(15) << "Tac gia:"
         << setw(15) << "Nha xuat ban: "
         << setw(15) << "The loai sach: "
         << setw(10) << "Gia tien 1 quyen: " << endl;
    cout << left
         << setw(10) << maSach
         << setw(20) << tenSach
         << setw(15) << tacGia
         << setw(15) << NXB
         << setw(15) << type
         << setw(10) << giaTien << endl;
}
int Sach::soSachConLai() const {
    return soLuongTong - soLuongDaMuon;
}

// int Sach::docFileSach(Sach danhSach[], int soLuongToiDa, const string& duongDan) {
//     ifstream in(duongDan);
//     if (!in.is_open()) return 0;
//     string line;
//     int soLuong = 0;
//     while (getline(in, line)) {
//         if (line.size() == 0) continue;
//         if (soLuong >= soLuongToiDa) break;
//         string ma = line;
//         string ten; if (!getline(in, ten)) break;
//         string tacgia; if (!getline(in, tacgia)) break;
//         string nxb; if (!getline(in, nxb)) break;
//         string theloai; if (!getline(in, theloai)) break;
//         string tmp;
//         if (!getline(in, tmp)) break; int sotrang = tmp.size()? stoi(tmp) : 0;
//         if (!getline(in, tmp)) break; int soLuongTong = tmp.size()? stoi(tmp) : 0;
//         if (!getline(in, tmp)) break; int soLuongDaMuon = tmp.size()? stoi(tmp) : 0;
//         if (!getline(in, tmp)) break; double gia = tmp.size()? stod(tmp) : 0.0;
//         Sach s(ma, ten, gia);
//         s.setTacGia(tacgia);
//         s.setNXB(nxb);
//         s.setType(theloai);
//         danhSach[soLuong++] = s;
//     }
//     in.close();
//     return soLuong;
// }

// void Sach::ghiFileSach(const Sach danhSach[], int soLuong, const string& duongDan) {
//     ofstream out(duongDan);
//     if (!out.is_open()) return;
//     for (int i = 0; i < soLuong; ++i) {
//         const Sach &s = danhSach[i];
//         out << s.getMaSach() << "\n";
//         out << s.getTenSach() << "\n";
//         out << s.getTacGia() << "\n";
//         out << s.getNXB() << "\n";
//         out << s.getType() << "\n";
//         out <<fixed << setprecision(0) << s.getGiaTien() << "\n\n";
//     }
//     out.close();
// }
