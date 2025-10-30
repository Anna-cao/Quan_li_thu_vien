#include "TheMuon.h"

TheMuon::TheMuon():gioiHanMuon(0), trangThai(true) {}

TheMuon::TheMuon(string maThe, string maDocGia, Date ngLapThe, Date HSD, int gioiHanMuon, bool status)
    : maThe(maThe), maDocGia(maDocGia), ngLapThe(ngLapThe), HSD(HSD), gioiHanMuon(gioiHanMuon), status(status) {}

string TheMuon::getMaThe() const { return maThe; }
string TheMuon::getMaDocGia() const { return maDocGia; }
int TheMuon::getGioiHanMuon() const { return gioiHanMuon; }
bool TheMuon::getStatus() const { return trangThai; }
void TheMuon::setGioiHanMuon(int g) { gioiHanMuon = g; }
void TheMuon::setStatus(bool t) { trangThai = t; }

bool TheMuon::kiemTraHieuLuc(const Date& ngayHienTai) const 
{
    return (HSD >= ngayHienTai); 
}

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

