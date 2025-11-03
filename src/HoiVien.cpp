#include "../include/HoiVien.h"
#include <iostream>
using namespace std;

HoiVien::HoiVien() : DocGia(), thoiGianMuonMax(30), tileGiamGia(0.1), 
                     ngayDangKy(""), ngayHetHan("") {}
HoiVien::HoiVien(string ten, string maSo, int soSachDaMuon, 
                 int thoiGianMuonMax, double tileGiamGia, 
                 string ngayDangKy, string ngayHetHan)
    : DocGia  (ten, maSo, soSachDaMuon), 
      thoiGianMuonMax(thoiGianMuonMax), 
      tileGiamGia(tileGiamGia),
      ngayDangKy(ngayDangKy), 
      ngayHetHan(ngayHetHan) {}
int HoiVien::getThoiGianMuonMax() const {
    return thoiGianMuonMax;
}
void HoiVien::setThoiGianMuonMax(int thoiGian) {
    thoiGianMuonMax = thoiGian;
}
double HoiVien::getTileGiamGia() const {
    return tileGiamGia;
}
void HoiVien::setTileGiamGia(double tile) {
    tileGiamGia = tile;
}
string HoiVien::getNgayDangKy() const {
    return ngayDangKy;
}
void HoiVien::setNgayDangKy(string ngay) {
    ngayDangKy = ngay;
}
string HoiVien::getNgayHetHan() const {
    return ngayHetHan;
}
void HoiVien::setNgayHetHan(string ngay) {
    ngayHetHan = ngay;
}
void HoiVien::hienThiThongTin() const {
    cout << "=== THONG TIN HOI VIEN ===" << endl;
    cout << "Ten: " << getTen() << endl;
    cout << "Ma so: " << getMaSo() << endl;
    cout << "So sach da muon: " << getSoSachDaMuon() << endl;
    cout << "Thoi gian muon toi da: " << thoiGianMuonMax << " ngay" << endl;
    cout << "Ti le giam gia: " << (tileGiamGia * 100) << "%" << endl;
    cout << "Ngay dang ky: " << ngayDangKy << endl;
    cout << "Ngay het han: " << ngayHetHan << endl;
    cout << "==========================" << endl;
}
