#include "../include/TheMuon.h"
#include<sstream>
#include <fstream>
#include <vector>
using namespace std;

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
static vector<TheMuon> docFileTheMuon_vector(const string& path) {
    vector<TheMuon> list;
    ifstream in(path);
    if (!in.is_open()) return list;
    string maThe;
    while (true) {
        if (!getline(in, maThe)) break;
        if (maThe.size() == 0) continue;
        string maDocGia;
        getline(in, maDocGia);
        int d1,m1,y1,d2,m2,y2;
        in >> d1 >> m1 >> y1;
        in >> d2 >> m2 >> y2;
        int gioiHan; in >> gioiHan;
        int st; in >> st;
        in.ignore();
        Date ngLap(d1,m1,y1), HSD(d2,m2,y2);
        list.emplace_back(maThe, maDocGia, ngLap, HSD, gioiHan, st==1);
    }
    in.close();
    return list;
}

static void ghiFileTheMuon_vector(const vector<TheMuon>& list, const string& path) {
    ofstream out(path);
    if (!out.is_open()) return;
    for (const auto& t : list) {
        out << t.getMaThe() << "\n";
        out << t.getMaDocGia() << "\n";
        out << t.getNgayLap().getNgay() << " " << t.getNgayLap().getThang() << " " << t.getNgayLap().getNam() << "\n";
        out << t.getHSD().getNgay() << " " << t.getHSD().getThang() << " " << t.getHSD().getNam() << "\n";
        out << t.getGioiHanMuon() << "\n";
        out << (t.getStatus() ? 1 : 0) << "\n\n";
    }
    out.close();
}

int TheMuon::docFileTheMuon(TheMuon danhSach[], int soLuongToiDa, const string& duongDan) {
    vector<TheMuon> list = docFileTheMuon_vector(duongDan);
    int n = (int)list.size();
    int cap = min(n, soLuongToiDa);
    for (int i = 0; i < cap; ++i) danhSach[i] = list[i];
    return cap;
}

void TheMuon::ghiFileTheMuon(const TheMuon danhSach[], int soLuong, const string& duongDan) {
    vector<TheMuon> list;
    list.reserve(soLuong);
    for (int i = 0; i < soLuong; ++i) list.push_back(danhSach[i]);
    ghiFileTheMuon_vector(list, duongDan);
}
