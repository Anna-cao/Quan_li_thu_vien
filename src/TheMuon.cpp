#include "../include/TheMuon.h"

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
bool TheMuon::ghiFile(ofstream& out) const {
    if (!out.good()) return false;
    out << maThe << "," << maDocGia << ","
        << ngLapThe.toString() << "," << HSD.toString() << ","
        << gioiHanMuon << "," << status << "\n";
    return true;
}

bool TheMuon::docFile(ifstream& in) {
    string line;
    if (!getline(in, line) || line.empty()) return false;
    stringstream ss(line);
    string ngLap, hsd, gioiHanStr, sttStr;

    getline(ss, maThe, ',');
    getline(ss, maDocGia, ',');
    getline(ss, ngLap, ',');
    getline(ss, hsd, ',');
    getline(ss, gioiHanStr, ',');
    getline(ss, sttStr, ',');

    ngLapThe.fromString(ngLap);
    HSD.fromString(hsd);
    gioiHanMuon = stoi(gioiHanStr);
    status = (sttStr == "1" || sttStr == "true");
    return true;
}