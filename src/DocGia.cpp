#include "../include/DocGia.h"
#include "../include/Date.h"
#include "../include/HoiVien.h"
#include "../include/DocGiaThuong.h"
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;
int DocGia::autoID_Thuong = 1;
int DocGia::autoID_HoiVien = 1;
DocGia::DocGia() : soLuotMuon(0), theMuon(nullptr), status(1) {
    stringstream ss;
    ss << "DG" << setw(3) << setfill('0') << autoID_Thuong++;
    maDocGia = ss.str();
    ngayLapThe = Date::HomNay();
}
DocGia::DocGia(string ten, string loai)
    : hoTen(ten), soLuotMuon(0), theMuon(nullptr), status(1)
{
    stringstream ss;
    if (loai == "Doc Gia Thuong") {
        ss << "DG" << setw(3) << setfill('0') << autoID_Thuong++;
    } else {
        ss << "HV" << setw(3) << setfill('0') << autoID_HoiVien++;
    }
    maDocGia = ss.str();
    ngayLapThe = Date::HomNay();
    theMuon = new TheMuon(loai, ngayLapThe);  
}
DocGia::DocGia(string ma, string ten, int soLuotMuon)
    : maDocGia(ma), hoTen(ten), soLuotMuon(soLuotMuon), theMuon(nullptr), status(1)
{ ngayLapThe = Date::HomNay();}
DocGia::~DocGia() { delete theMuon; }
string DocGia::nhapMaDocGia(const string& msg) {
    string ma;
    while (true) {
        cout << msg;
        getline(cin >> ws, ma);
        if (ma == "0") {
            cout << "Da huy.\n";
            return "";
        }
        if (ma.empty()) {
            cout << "Ma khong duoc de trong! Nhap lai.\n";
            continue;
        }
        return ma;
    }
}
void DocGia::nhapThongTinChung() {
    cout << "SDT: ";
    while (!(cin >> sdt) || sdt.length() != 10) {  
        cout << "SDT khong hop le! Nhap lai: ";
        cin.clear(); cin.ignore(1000, '\n');
    }
    cin.ignore();
    cout << "Email: "; getline(cin, email);
    cout << "Dia chi: "; getline(cin, diachi);
    ngayLapThe = Date::HomNay();
}
void DocGia::hienThiThongTin() const {
    if (status == 0) return; 
    cout << left << setw(8) << maDocGia
         << setw(20) << hoTen
         << setw(15) << sdt
         << setw(25) << email
         << setw(20) << diachi;
    ngayLapThe.Xuat();
    cout << " | ";
    if (theMuon) theMuon->hienThi();
    else cout << "Chua co the";
    cout << endl;
}
void DocGia::hienThiDong() const {
    if (status == 0) return;
    hienThiThongTin();
}
void DocGia::hienThiTieuDe() {
    cout << left << setw(8) << "Ma DG"
         << setw(20) << "Ho Ten"
         << setw(15) << "SDT"
         << setw(25) << "Email"
         << setw(20) << "Dia chi"
         << "Ngay lap the     | Thong tin the\n";
    cout << string(110, '-') << endl;
}
void DocGia::docFile(istream& in) {
    getline(in, maDocGia);
    getline(in, hoTen);
    getline(in, sdt);
    getline(in, email);
    getline(in, diachi);
    int d, m, y;
    in >> d >> m >> y; in.ignore();
    ngayLapThe = Date(d, m, y);
    string loai;
    getline(in, loai);
    in >> status; in.ignore();
    string masach_line;
    getline(in, masach_line);
    stringstream masach_ss(masach_line);
    string maSach;
    dsMaSachDangMuon.clear();
    while (masach_ss >> maSach) {
        dsMaSachDangMuon.push_back(maSach);
    }
}
void DocGia::ghiFile(ostream& out) const {
    out << maDocGia << "\n"
        << hoTen << "\n"
        << sdt << "\n"
        << email << "\n"
        << diachi << "\n";
    out << ngayLapThe.getNgay() << " " << ngayLapThe.getThang() << " " << ngayLapThe.getNam() << "\n";
    out << getLoaiDocGia() << "\n";
    out << status << "\n";
    for (size_t i = 0; i < dsMaSachDangMuon.size(); ++i) {
        out << dsMaSachDangMuon[i];
        if (i < dsMaSachDangMuon.size() - 1) out << " ";
    }
    out << "\n"; 
}

void DocGia::ghiFileDocGiaThuong(const DocGia* ds[], int n, const string& file) {
    ofstream out(file);
    if (!out.is_open()) return;
    for (int i = 0; i < n; ++i) {
        if (ds[i] && ds[i]->getStatus() == 1 && ds[i]->getLoaiDocGia() == "Doc Gia Thuong") {
            ds[i]->ghiFile(out);
            out << "\n\n";  
        }
    }
    out.close();
}
void DocGia::ghiFileHoiVien(const DocGia* ds[], int n, const string& file) {
    ofstream out(file);
    if (!out.is_open()) return;
    for (int i = 0; i < n; ++i) {
        if (ds[i] && ds[i]->getStatus() == 1 && ds[i]->getLoaiDocGia() == "HoiVien") {
            ds[i]->ghiFile(out);
            out << "\n\n";
        }
    }
    out.close();
}
void DocGia::capNhatAutoIDTuMa(const string& ma, bool isHoiVien) {
    if (ma.length() < 5) return;
    try {
        int id = stoi(ma.substr(2)); 
        if (isHoiVien) {
            if (id >= autoID_HoiVien) autoID_HoiVien = id + 1;
        } else {
            if (id >= autoID_Thuong) autoID_Thuong = id + 1;
        }
    } catch (...) {}
}
int DocGia::docFileDocGiaThuong(DocGia* ds[], int soLuongToiDa, const string& duongDan) {
    ifstream in(duongDan);
    if (!in.is_open()) return 0;
    int n = 0;
    string line;
    while (n < soLuongToiDa && getline(in, line)) {
        if (line.empty()) continue;
        string ma = line;
        string ten, sdt, email, diachi;
        int d, m, y, status;
        string masach_line, gioihan_line;
        if (!getline(in, ten)) break;
        if (!getline(in, sdt)) break;
        if (!getline(in, email)) break;
        if (!getline(in, diachi)) break;
        if (!getline(in, line)) break; 
        stringstream(line) >> d >> m >> y;
        if (!getline(in, line)) break; 
        if (!getline(in, line)) break; 
        stringstream(line) >> status;
        if (!getline(in, masach_line)) break;
        if (!getline(in, gioihan_line)) break;
        DocGiaThuong* dg = new DocGiaThuong();
        dg->maDocGia = ma;
        dg->hoTen = ten;
        dg->sdt = sdt;
        dg->email = email;
        dg->diachi = diachi;
        dg->ngayLapThe = Date(d, m, y);
        dg->status = status;
        int gioiHan;
        stringstream ss(gioihan_line);
        if (ss >> gioiHan) dg->setGioiHanMuon(gioiHan);
        stringstream masach_ss(masach_line);
        string maSach;
        while (masach_ss >> maSach) dg->dsMaSachDangMuon.push_back(maSach);
        capNhatAutoIDTuMa(ma, false);
        ds[n++] = dg;
        while (getline(in, line) && line.empty());
        if (!line.empty()) in.seekg(-static_cast<long long>(line.size() + 1), ios::cur);
    }
    in.close();
    return n;
}
int DocGia::docFileHoiVien(DocGia* ds[], int soLuongToiDa, const string& duongDan) {
    ifstream in(duongDan);
    if (!in.is_open()) return 0;
    int n = 0;
    string line;
    while (n < soLuongToiDa && getline(in, line)) {
        if (line.empty()) continue;
        string ma = line;
        string ten, sdt, email, diachi;
        int d, m, y, status;
        string masach_line, extra_line, dk, hh;
        int tg; double tl;
        if (!getline(in, ten)) break;
        if (!getline(in, sdt)) break;
        if (!getline(in, email)) break;
        if (!getline(in, diachi)) break;
        if (!getline(in, line)) break; 
        stringstream(line) >> d >> m >> y;
        if (!getline(in, line)) break;
        if (!getline(in, line)) break; 
        stringstream(line) >> status;
        if (!getline(in, masach_line)) break;
        if (!getline(in, extra_line)) break;
        if (!getline(in, dk)) break;
        if (!getline(in, hh)) break;
        stringstream(extra_line) >> tg >> tl;
        HoiVien* dg = new HoiVien(ten, ma, 0, tg, tl, dk, hh);
        dg->maDocGia = ma;
        dg->hoTen = ten;
        dg->sdt = sdt;
        dg->email = email;
        dg->diachi = diachi;
        dg->ngayLapThe = Date(d, m, y);
        dg->status = status;
        stringstream ss(masach_line);
        string maSach;
        while (ss >> maSach) dg->dsMaSachDangMuon.push_back(maSach);
        capNhatAutoIDTuMa(ma, true);
        ds[n++] = dg;
        while (getline(in, line) && line.empty());
        if (!line.empty()) in.seekg(-static_cast<long long>(line.size() + 1), ios::cur);
    }
    in.close();
    return n;
}