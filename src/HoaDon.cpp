#include "../include/HoaDon.h"
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int HoaDon::autoID = 0;
HoaDon::HoaDon() : phiQuaHan(0), tongPhi(0), tiencoc(0), status(0) {}
HoaDon::HoaDon(string maHD, string maT, Date muon, Date tra, double phi, double tong)
    : maHoaDon(maHD), maThe(maT), ngMuon(muon), ngTraThucTe(tra),
      phiQuaHan(phi), tongPhi(tong), tiencoc(0), status(0) {}
void HoaDon::taoMaTuDong() {
    ++autoID;
    stringstream ss;
    ss << "HD" << setw(3) << setfill('0') << autoID;
    maHoaDon = ss.str();
}

void HoaDon::capNhatAutoID(int id) {
    if (id > autoID) autoID = id;
}
void HoaDon::tinhPhiQuaHan(const DocGia* dg, const Date& ngayTra) {
    if (status != 0) return;  
    if (!ngayTra.HopLe()) return;

    int soNgay = ngMuon.TinhSoNgay(ngayTra);
    if (soNgay < 0) return;

    int quaHan = soNgay - 14;
    if (quaHan <= 0) {
        phiQuaHan = 0;
        tongPhi = tiencoc;
        return;
    }
    int soTuan = (quaHan + 6) / 7;  
    double phi1Tuan = (dg && dg->getLoaiDocGia() == "HoiVien") ? 5000 : 10000;

    phiQuaHan = soTuan * phi1Tuan;
    tongPhi = phiQuaHan + tiencoc;
}
void HoaDon::hienThiThongTin() const {
    stringstream ssMuon, ssTra;
    ssMuon << setw(2) << setfill('0') << ngMuon.getNgay() << "/"
           << setw(2) << setfill('0') << ngMuon.getThang() << "/"
           << ngMuon.getNam();
    ssTra << setw(2) << setfill('0') << ngTraThucTe.getNgay() << "/"
          << setw(2) << setfill('0') << ngTraThucTe.getThang() << "/"
          << ngTraThucTe.getNam();

    cout << left
         << setw(10) << maHoaDon
         << setw(10) << maThe
         << setw(15) << ssMuon.str()
         << setw(15) << ssTra.str()
         << setw(12) << fixed << setprecision(0) << phiQuaHan
         << setw(12) << tongPhi
         << setw(12) << tiencoc
         << setw(6)  << (status == 0 ? "Chua tra" : "Da tra")
         << endl;

    if (!dsSachMuon.empty()) {
        cout << "  Sach muon:\n";
        for (const auto& p : dsSachMuon) {
            cout << "    - " << p.first << " (x" << p.second << ")\n";
        }
    }
}
void HoaDon::setDaTra(const Date& ngayTra) {
    ngTraThucTe = ngayTra;
    status = 1;  
}
void HoaDon::DocFile(ifstream& file) {
    if (file.eof()) return;

    file >> maHoaDon >> maThe;

    int d1, m1, y1, d2, m2, y2;
    file >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    ngMuon = Date(d1, m1, y1);
    ngTraThucTe = Date(d2, m2, y2);

    file >> phiQuaHan >> tongPhi >> tiencoc >> status;
    try {
        if (maHoaDon.size() > 2) {
            int id = stoi(maHoaDon.substr(2));
            capNhatAutoID(id);
        }
    } catch (...) {}
    int soSach;
    file >> soSach;
    dsSachMuon.clear();
    for (int i = 0; i < soSach; ++i) {
        string ma; int sl;
        file >> ma >> sl;
        dsSachMuon.emplace_back(ma, sl);
    }
}
int HoaDon::docFileHoaDon(HoaDon danhSach[], int soLuongToiDa, const string& duongDan) {
    ifstream in(duongDan);
    if (!in.is_open()) {
        cerr << "Khong mo duoc file: " << duongDan << endl;
        return 0;
    }
    int soLuong = 0;
    while (soLuong < soLuongToiDa && !in.eof()) {
        HoaDon hd;
        hd.DocFile(in);  
        if (hd.getMaHoaDon().empty()) break;
        danhSach[soLuong++] = hd;
    }
    in.close();
    return soLuong;
}
void HoaDon::ghiFileHoaDon(const HoaDon danhSach[], int soLuong, const string& duongDan) {
    ofstream out(duongDan);
    if (!out.is_open()) {
        cerr << "Khong ghi duoc file: " << duongDan << endl;
        return;
    }
    for (int i = 0; i < soLuong; ++i) {
        const HoaDon& h = danhSach[i];
        out << h.maHoaDon << "\n";
        out << h.maThe << "\n";
        out << h.ngMuon.getNgay() << " " << h.ngMuon.getThang() << " " << h.ngMuon.getNam() << " ";
        out << h.ngTraThucTe.getNgay() << " " << h.ngTraThucTe.getThang() << " " << h.ngTraThucTe.getNam() << "\n";
        out << h.phiQuaHan << " " << h.tongPhi << " " << h.tiencoc << " " << h.status << "\n";
        out << h.dsSachMuon.size() << "\n";
        for (const auto& p : h.dsSachMuon) {
            out << p.first << " " << p.second << "\n";
        }
        out << "\n";  
    }
    out.close();
}