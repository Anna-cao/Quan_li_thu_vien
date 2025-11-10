#include "../include/TheMuon.h"
#include <iomanip>
#include <sstream>


int TheMuon::demThuong = 0;
int TheMuon::demHoiVien = 0;


TheMuon::TheMuon()
    : phiDangKy(0), loaiThe(THE_THUONG), gioiHanMuon(0), status("Hoat dong") {}

TheMuon::TheMuon(string ten, LoaiThe loai)
    : tenDocGia(ten), loaiThe(loai), status("Hoat dong")
{
    maThe = taoMaThe(loai);
    phiDangKy = (loai == THE_THUONG ? 50000 : 100000);
    gioiHanMuon = (loai == THE_THUONG ? 3 : 5);

    cout << "Nhap ngay lap the:\n";
    ngayLapThe.nhap();
    hanSuDung = ngayLapThe;
    hanSuDung.congNgay(365);
}


string TheMuon::taoMaThe(LoaiThe loai) {
    stringstream ss;
    if (loai == THE_THUONG) {
        ss << "TT" << setw(3) << setfill('0') << ++demThuong;
    } else {
        ss << "HV" << setw(3) << setfill('0') << ++demHoiVien;
    }
    return ss.str();
}


string TheMuon::getMaThe() const { return maThe; }
string TheMuon::getTenDocGia() const { return tenDocGia; }
LoaiThe TheMuon::getLoaiThe() const { return loaiThe; }
double TheMuon::getPhiDangKy() const { return phiDangKy; }
string TheMuon::getStatus() const { return status; }
int TheMuon::getGioiHanMuon() const { return gioiHanMuon; }
Date TheMuon::getNgayLapThe() const { return ngayLapThe; }
Date TheMuon::getHanSuDung() const { return hanSuDung; }


void TheMuon::setTenDocGia(string ten) { tenDocGia = ten; }
void TheMuon::setLoaiThe(LoaiThe loai) { loaiThe = loai; }
void TheMuon::setStatus(string st) { status = st; }
void TheMuon::setGioiHanMuon(int g) { gioiHanMuon = g; }
void TheMuon::setNgayLapThe(const Date& ngay) { ngayLapThe = ngay; }
void TheMuon::setHanSuDung(const Date& han) { hanSuDung = han; }


void TheMuon::nhap() {
    cin.ignore();
    cout << "\n=== NH?P THÔNG TIN TH? MU?N ===\n";
    cout << "Tên d?c gi?: ";
    getline(cin, tenDocGia);

    int chon;
    cout << "Lo?i th? (0 - Thu?ng, 1 - H?i viên): ";
    cin >> chon;
    loaiThe = (chon == 1 ? THE_HOI_VIEN : THE_THUONG);

    
    maThe = taoMaThe(loaiThe);

    phiDangKy = (loaiThe == THE_THUONG ? 50000 : 100000);
    gioiHanMuon = (loaiThe == THE_THUONG ? 3 : 5);
    status = "Ho?t d?ng";

    cout << "Ngày l?p th?:\n";
    ngayLapThe.nhap();
    hanSuDung = ngayLapThe;
    hanSuDung.congNgay(365);
}

void TheMuon::xuat() const {
    cout << "\n--- THÔNG TIN TH? MU?N ---\n";
    cout << "Mã th?: " << maThe << endl;
    cout << "Tên d?c gi?: " << tenDocGia << endl;
    cout << "Lo?i th?: " << (loaiThe == THE_THUONG ? "The thuong" : "Hoi vien") << endl;
    cout << "Phí dang ký: " << phiDangKy << " VND\n";
    cout << "Gi?i h?n mu?n: " << gioiHanMuon << " sach\n";
    cout << "Tr?ng thái: " << status << endl;
    cout << "Ngày l?p th?: ";
    ngayLapThe.xuat();
    cout << "H?n s? d?ng: ";
    hanSuDung.xuat();
}


void TheMuon::ghiFile(ofstream& file) const {
    if (!file.is_open()) return;
    file << maThe << endl;
    file << tenDocGia << endl;
    file << loaiThe << endl;
    file << phiDangKy << endl;
    file << status << endl;
    file << gioiHanMuon << endl;
    ngayLapThe.ghiFile(file);
    hanSuDung.ghiFile(file);
}

bool TheMuon::docFile(ifstream& file) {
    if (!file.is_open()) return false;

    getline(file, maThe);
    getline(file, tenDocGia);
    int loai;
    file >> loai;
    loaiThe = (LoaiThe)loai;
    file >> phiDangKy;
    file.ignore();
    getline(file, status);
    file >> gioiHanMuon;

    ngayLapThe.docFile(file);
    hanSuDung.docFile(file);
    file.ignore();
    return true;
}  