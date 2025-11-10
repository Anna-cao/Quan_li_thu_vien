<<<<<<< Updated upstream
#include "TheMuon.h"
=======
#include "../include/TheMuon.h"
#include <iomanip>
#include <sstream>
>>>>>>> Stashed changes


int TheMuon::demThuong = 0;
int TheMuon::demHoiVien = 0;


TheMuon::TheMuon()
    : phiDangKy(0), loaiThe(THE_THUONG), gioiHanMuon(0), status("Hoạt động") {}

TheMuon::TheMuon(string ten, LoaiThe loai)
    : tenDocGia(ten), loaiThe(loai), status("Hoạt động")
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


<<<<<<< Updated upstream
istream& operator>>(istream& in, TheMuon& tm) 
{
    cout << "Nhap ma the: "; getline(in, tm.maThe);
    cout << "Nhap ma doc gia: "; getline(in, tm.maDocGia);
    cout << "Nhap ngay lap: "; in >> tm.ngLapThe;
    cout << "Nhap han su dung: "; in >> tm.HSD;
    cout << "Nhap gioi han muon: "; in >> tm.gioiHanMuon;
    tm.status = true;
    in.ignore();
    return in;
}

ostream& operator<<(ostream& out, const TheMuon& tm) 
{
    out << "Ma the: " << tm.maThe << ", Ma doc gia: " << tm.maDocGia
        << ", Ngay lap: " << tm.ngLapThe
        << ", Han su dung: " << tm.HSD
        << ", Gioi han muon: " << tm.gioiHanMuon
        << ", Trang thai: " << (tm.status ? "Con han" : "Het han") << endl;
    return out;
}

=======
void TheMuon::nhap() {
    cin.ignore();
    cout << "\n=== NHẬP THÔNG TIN THẺ MƯỢN ===\n";
    cout << "Tên độc giả: ";
    getline(cin, tenDocGia);

    int chon;
    cout << "Loại thẻ (0 - Thường, 1 - Hội viên): ";
    cin >> chon;
    loaiThe = (chon == 1 ? THE_HOI_VIEN : THE_THUONG);

    
    maThe = taoMaThe(loaiThe);

    phiDangKy = (loaiThe == THE_THUONG ? 50000 : 100000);
    gioiHanMuon = (loaiThe == THE_THUONG ? 3 : 5);
    status = "Hoạt động";

    cout << "Ngày lập thẻ:\n";
    ngayLapThe.nhap();
    hanSuDung = ngayLapThe;
    hanSuDung.congNgay(365);
}

void TheMuon::xuat() const {
    cout << "\n--- THÔNG TIN THẺ MƯỢN ---\n";
    cout << "Mã thẻ: " << maThe << endl;
    cout << "Tên độc giả: " << tenDocGia << endl;
    cout << "Loại thẻ: " << (loaiThe == THE_THUONG ? "Thẻ thường" : "Hội viên") << endl;
    cout << "Phí đăng ký: " << phiDangKy << " VND\n";
    cout << "Giới hạn mượn: " << gioiHanMuon << " sách\n";
    cout << "Trạng thái: " << status << endl;
    cout << "Ngày lập thẻ: ";
    ngayLapThe.xuat();
    cout << "Hạn sử dụng: ";
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
>>>>>>> Stashed changes
