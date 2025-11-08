#include "../include/HoaDonBan.h"
#include "../include/Sach.h"
#include <iostream>
using namespace std;
#include <fstream>

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
        string maSach;
        getline(file, maSach);
        Sach s(maSach, "", 0.0);
        dsSachBan.push_back(s);
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

double HoaDonBan::getTongTienBan() const { return tongTienBan; }
int HoaDonBan::getSoLuongSachBan() const { return (int)dsSachBan.size(); }
string HoaDonBan::getMaSachBan(int idx) const {
    if (idx < 0 || idx >= (int)dsSachBan.size()) return string();
    return dsSachBan[idx].getMaSach();
}

int HoaDonBan::docFileHoaDonBan(HoaDonBan danhSach[], int soLuongToiDa, const string& duongDan) {
    ifstream in(duongDan);
    if (!in.is_open()) return 0;
    int soLuong = 0;
    while (!in.eof() && soLuong < soLuongToiDa) {
        HoaDonBan hd;
        hd.DocFile(in);
        if (hd.getMaHoaDon().empty()) break;
        danhSach[soLuong++] = hd;
    }
    in.close();
    return soLuong;
}

void HoaDonBan::ghiFileHoaDonBan(const HoaDonBan danhSach[], int soLuong, const string& duongDan) {
    ofstream out(duongDan);
    if (!out.is_open()) return;
    for (int i = 0; i < soLuong; ++i) {
        const HoaDonBan &h = danhSach[i];
        out << h.getMaHoaDon() << "\n";
        out << h.getMaThe() << "\n";
        Date d1 = h.getNgayMuon();
        Date d2 = h.getNgayTraThucTe();
        out << d1.getNgay() << " " << d1.getThang() << " " << d1.getNam() << " ";
        out << d2.getNgay() << " " << d2.getThang() << " " << d2.getNam() << "\n";
        int nSach = h.getSoLuongSachBan();
        out << nSach << "\n";
        for (int j = 0; j < nSach; ++j) out << h.getMaSachBan(j) << "\n";
        out << h.getTongTienBan() << "\n\n";
    }
    out.close();
}
