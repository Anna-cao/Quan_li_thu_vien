#include "DocGiaThuong.h"
#include <iostream>
using namespace std;
DocGiaThuong::DocGiaThuong() : DocGia(), gioiHanMuon(5) {}

DocGiaThuong::DocGiaThuong(string ten, string maSo, int soSachDaMuon, int gioiHanMuon)
    : DocGia (ten, maSo, soSachDaMuon), gioiHanMuon(gioiHanMuon) {};

int DocGiaThuong::getGioiHanMuon() const { return gioiHanMuon; }
void DocGiaThuong::setGioiHanMuon(int gioiHan) { gioiHanMuon = gioiHan; }

void DocGiaThuong::hienThiThongTin() const {
    std::cout << "=== THONG TIN DOC GIA THUONG ===" << std::endl;
    cout << "Gioi han muon: " << gioiHanMuon << " quyen" << endl;
    cout << "===============================" << endl;
}