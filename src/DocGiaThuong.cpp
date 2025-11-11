#include "../include/DocGiaThuong.h"
#include <iostream>
using namespace std;

DocGiaThuong::DocGiaThuong() : DocGia(), gioiHanMuon(5) {}

DocGiaThuong::DocGiaThuong(string ten, string maSo, int soSachDaMuon, int gioiHanMuon)
    : DocGia(ten, maSo, soSachDaMuon), gioiHanMuon(gioiHanMuon) {};

int DocGiaThuong::getGioiHanMuon() const { return gioiHanMuon; }
void DocGiaThuong::setGioiHanMuon(int gioiHan) { gioiHanMuon = gioiHan; }

void DocGiaThuong::nhapGioiHanMuon() {
    int limit;
    do {
        cout << "Nhap gioi han muon (so sach toi da, >0): ";
        cin >> limit;
        if (limit <= 0) cout << "Phai lon hon 0!\n";
    } while (limit <= 0);
    cin.ignore();
    gioiHanMuon = limit;
}

void DocGiaThuong::docFile(istream& in) {
    DocGia::docFile(in);
    if (!(in >> gioiHanMuon)) {
        gioiHanMuon = 5;   
    }
    in.ignore(); 
}
void DocGiaThuong::ghiFile(ostream& out) const {
    DocGia::ghiFile(out);
    out << gioiHanMuon << "\n";
}
void DocGiaThuong::hienThiThongTin() const {
    cout << "=== DOC GIA THUONG ===\n";
    cout << "Gioi han muon: " << gioiHanMuon << " quyen\n";
    cout << "======================\n";
}