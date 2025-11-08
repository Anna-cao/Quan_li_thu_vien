#include "../include/HoaDonBan.h"
#include "../include/Sach.h"
#include <iostream>
using namespace std;

HoaDonBan::HoaDonBan() {
    tongTienBan = 0;
    tongPhi = 0;
}

void HoaDonBan::DocFile(ifstream &file) {
    HoaDon::DocFile(file);
    int soSach;
    file >> soSach;
    file.ignore();
    for(int i = 0; i < soSach; i++) {
        Sach sach;
        // Đọc thông tin sách từ file
        string maSach;
        getline(file, maSach);
        // Tạm thời chỉ đọc mã sách
        dsSachBan.push_back(sach);
    }
    file >> tongTienBan;
    file.ignore();
}

HoaDonBan::HoaDonBan(string maHD) {
    this->maHoaDon = maHD;
    tongTienBan = 0;
    tongPhi = 0;
}

void HoaDonBan::themSach(const Sach &sach, int soLuong) {
    dsSachBan.push_back(sach);
    tongTienBan += sach.getGiaTien() * soLuong;
    tongPhi = tongTienBan; 
}
Date HoaDonBan::getNgayBan() const { return ngayBan; }
void HoaDonBan::setNgayBan(const Date& d) { ngayBan = d; }

void HoaDonBan::tinhPhiQuaHan() {
    phiQuaHan = 0;
    tongPhi = tongTienBan;
}

void HoaDonBan::hienThiThongTin() const {
    cout << "\n--- HOA DON BAN SACH ---";
    cout << "\nMa hoa don: " << maHoaDon;
    cout << "\nSo sach ban: " << dsSachBan.size();
    cout << "\nTong tien: " << tongTienBan;
}
