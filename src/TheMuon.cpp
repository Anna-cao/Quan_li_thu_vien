#include "../include/TheMuon.h"
#include <sstream>
#include <iomanip>
using namespace std;

int TheMuon::autoID = 1;
int TheMuon::demThuong = 0;
int TheMuon::demHoiVien = 0;

string TheMuon::taoMaThe(LoaiThe loai) {
    stringstream ss;
    ss << "TM" << setw(3) << setfill('0') << autoID++;
    if (loai == THE_HOI_VIEN) demHoiVien++;
    else demThuong++;
    return ss.str();
}

void TheMuon::tinhPhiVaGioiHan() {
    if (loaiThe == THE_HOI_VIEN) {
        phiDangKy = 150000;
        gioiHanMuon = 10;
        hanSuDung = ngayLapThe;
        hanSuDung.congNgay(365); 
    } else {
        phiDangKy = 10000;
        gioiHanMuon = 5;
        hanSuDung = ngayLapThe;
        hanSuDung.congNgay(180); 
    }
    status = "Con han";
}

TheMuon::TheMuon() {
    loaiThe = THE_THUONG;
    ngayLapThe = Date::HomNay();
    maThe = taoMaThe(loaiThe);
    tenDocGia = "";
    tinhPhiVaGioiHan();
}

TheMuon::TheMuon(string ten, LoaiThe loai) {
    tenDocGia = ten;
    loaiThe = loai;
    ngayLapThe = Date::HomNay();
    maThe = taoMaThe(loai);
    tinhPhiVaGioiHan();
}

TheMuon::TheMuon(string loaiStr, Date ngayLap) {
    ngayLapThe = ngayLap;
    loaiThe = (loaiStr == "HoiVien") ? THE_HOI_VIEN : THE_THUONG;
    maThe = taoMaThe(loaiThe);
    tenDocGia = "";
    tinhPhiVaGioiHan();
}

void TheMuon::setNgayLapThe(const Date& ngay) {
    ngayLapThe = ngay;
    tinhPhiVaGioiHan();
}
void TheMuon::nhap() {
    cout << "Ten doc gia: ";
    getline(cin, tenDocGia);

    string loaiStr;
    do {
        cout << "Loai the (Thuong/HoiVien): ";
        getline(cin, loaiStr);
        if (loaiStr == "HoiVien") loaiThe = THE_HOI_VIEN;
        else if (loaiStr == "Thuong") loaiThe = THE_THUONG;
        else cout << "Chi nhap Thuong hoac HoiVien!\n";
    } while (loaiStr != "Thuong" && loaiStr != "HoiVien");

    tinhPhiVaGioiHan();
    maThe = taoMaThe(loaiThe); 
}
void TheMuon::hienThi() const {
    string loaiStr = (loaiThe == THE_HOI_VIEN) ? "HoiVien" : "Thuong";
    cout << left << setw(10) << maThe
         << setw(20) << tenDocGia
         << setw(12) << loaiStr
         << setw(12) << fixed << setprecision(0) << phiDangKy
         << setw(10) << gioiHanMuon;
    ngayLapThe.XuatDinhDang();
    cout << " | Han: "; hanSuDung.XuatDinhDang();
    cout << " | " << status << endl;
}
void TheMuon::capNhatAutoID(int id) {
    if (id > autoID) autoID = id;
}
void TheMuon::ghiFile(ostream& out) const {
    out << maThe << "\n"
        << tenDocGia << "\n"
        << (loaiThe == THE_HOI_VIEN ? "HoiVien" : "Thuong") << "\n"
        << phiDangKy << "\n"
        << status << "\n"
        << gioiHanMuon << "\n";
    ngayLapThe.ghiFile(out); out << "\n";
    hanSuDung.ghiFile(out); out << "\n";
}

void TheMuon::docFile(istream& in) {
    getline(in, maThe);
    getline(in, tenDocGia);
    string loaiStr;
    getline(in, loaiStr);
    loaiThe = (loaiStr == "HoiVien") ? THE_HOI_VIEN : THE_THUONG;

    string tmp;
    getline(in, tmp);
    if (!tmp.empty()) phiDangKy = stod(tmp);

    getline(in, tmp);
    if (!tmp.empty()) status = tmp;

    getline(in, tmp);
    if (!tmp.empty()) gioiHanMuon = stoi(tmp);

    ngayLapThe.docFile(in);
    in.ignore(); 
    hanSuDung.docFile(in);
}