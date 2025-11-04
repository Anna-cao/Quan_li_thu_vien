#include "../include/TheMuon.h"
#include<sstream>

TheMuon::TheMuon():gioiHanMuon(0), status(true) {}

TheMuon::TheMuon(string maThe, string maDocGia, Date ngLapThe, Date HSD, int gioiHanMuon, bool status)
    : maThe(maThe), maDocGia(maDocGia), ngLapThe(ngLapThe), HSD(HSD), gioiHanMuon(gioiHanMuon), status(status) {}

string TheMuon::getMaThe() const { return maThe; }
string TheMuon::getMaDocGia() const { return maDocGia; }
int TheMuon::getGioiHanMuon() const { return gioiHanMuon; }
bool TheMuon::getStatus() const { return status; }
void TheMuon::setGioiHanMuon(int g) { gioiHanMuon = g; }
void TheMuon::setStatus(bool t) { status = t; }

bool TheMuon::kiemTraHieuLuc(const Date& ngayHienTai) const 
{
    return (HSD >= ngayHienTai); 
}

void TheMuon::nhap() {
    cout << "Nhap ma the: ";
    getline(cin, maThe);
    cout << "Nhap ma doc gia: ";
    getline(cin, maDocGia);
    string line;
    int d, m, y;

    cout << "Nhap ngay lap (d m y): ";
    getline(cin, line);
    stringstream(line) >> d >> m >> y;
    ngLapThe = Date(d, m, y);

    cout << "Nhap han su dung (d m y): ";
    getline(cin, line);
    stringstream(line) >> d >> m >> y;
    HSD = Date(d, m, y);
    cout << "Nhap gioi han muon: ";
    getline(cin, line);
    stringstream(line) >> gioiHanMuon;
    status = true;
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
