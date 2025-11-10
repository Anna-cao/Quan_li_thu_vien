
#include "../include/TheMuon.h"
#include <sstream>
int TheMuon::autoID = 1;

TheMuon::TheMuon() {
    stringstream ss;
    ss << "TM" << setw(3) << setfill('0') << autoID++;
    maThe = ss.str();

    loaiThe = "Thuong";
    ngayLap = Date();
    status = true;
    tinhPhiVaGioiHan();
}

TheMuon::TheMuon(string loai, Date date) : loaiThe(loai), ngayLap(date), status(true) {
    stringstream ss;
    ss << "TM" << setw(3) << setfill('0') << autoID++;
    maThe = ss.str();
    tinhPhiVaGioiHan();
}

void TheMuon::tinhPhiVaGioiHan() {
    if (loaiThe == "HoiVien") { phiDangKy = 150000; gioiHanSach = 10; }
    else { phiDangKy = 50000; gioiHanSach = 5; }
}

void TheMuon::hienThi() const {
    cout << left << setw(10) << maThe
         << setw(12) << loaiThe
         << setw(12) << fixed << setprecision(0) << phiDangKy
         << setw(10) << gioiHanSach;
    ngayLap.xuat();
    cout << setw(10) << (status ? "Con han" : "Het han") << endl;
}

void TheMuon::ghiFile(ofstream& file) const {
    file << maThe << " " << loaiThe << " " << phiDangKy << " "
         << gioiHanSach << " ";
    ngayLap.ghi(file);
    file << " " << status << endl;
}

void TheMuon::docFile(ifstream& file) {
    file >> maThe >> loaiThe >> phiDangKy >> gioiHanSach;
    ngayLap.doc(file);
    file >> status;

    int id = stoi(maThe.substr(2));
    capNhatAutoID(id + 1);
}

void TheMuon::capNhatAutoID(int id) {
    if (id > autoID) autoID = id;
}