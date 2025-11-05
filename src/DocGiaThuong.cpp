#include "../include/DocGiaThuong.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
DocGiaThuong::DocGiaThuong() : DocGia(), gioiHanMuon(5) {}

DocGiaThuong::DocGiaThuong(string maSo, string ten, int soSachDaMuon, int gioiHanMuon)
    : DocGia(maSo, ten, soSachDaMuon), gioiHanMuon(gioiHanMuon) {}

int DocGiaThuong::getGioiHanMuon() const { return gioiHanMuon; }
void DocGiaThuong::setGioiHanMuon(int gioiHan) { gioiHanMuon = gioiHan; }

void DocGiaThuong::hienThiThongTin() const {
    cout << "=== THONG TIN DOC GIA THUONG ===" << endl;
    cout << "Gioi han muon: " << gioiHanMuon << " quyen" << endl;
    cout << "===============================" << endl;
}

bool DocGiaThuong::ghiFile(ofstream &out) const {
    if (!out.good()) return false;
    out << "Thuong" << "," << maDocGia << "," << hoTen << "," << soLuotMuon << ",";
    if (theMuon) out << theMuon->getMaThe(); else out << "null";
    out << ",";
    for (size_t i = 0; i < dsMaSachDangMuon.size(); ++i) {
        out << dsMaSachDangMuon[i];
        if (i + 1 < dsMaSachDangMuon.size()) out << ";";
    }
    out << "," << gioiHanMuon << "\n";
    return true;
}

/* ĐỌC TỪ 1 DÒNG CHUỖI */
bool DocGiaThuong::docFileFromString(const std::string& line) {
    if (line.empty()) return false;
    stringstream ss(line);
    string loai;
    getline(ss, loai, ',');

    string ma, ten, soLuotStr, maThe, dsSachStr, gioiHanStr;

    if (loai == "Thuong") {
        getline(ss, ma, ',');
        getline(ss, ten, ',');
        getline(ss, soLuotStr, ',');
        getline(ss, maThe, ',');
        getline(ss, dsSachStr, ',');
        getline(ss, gioiHanStr, ',');
    } else {
        // file thiếu loại: loai read chính là maDocGia
        ma = loai;
        getline(ss, ten, ',');
        getline(ss, soLuotStr, ',');
        getline(ss, maThe, ',');
        getline(ss, dsSachStr, ',');
        getline(ss, gioiHanStr, ',');
    }

    maDocGia = ma;
    hoTen = ten;
    try { soLuotMuon = stoi(soLuotStr); } catch(...) { soLuotMuon = 0; }

    dsMaSachDangMuon.clear();
    if (!dsSachStr.empty()) {
        string token;
        stringstream list(dsSachStr);
        while (getline(list, token, ';')) if (!token.empty()) dsMaSachDangMuon.push_back(token);
    }

    try { gioiHanMuon = stoi(gioiHanStr); } catch(...) { gioiHanMuon = 5; }

    theMuon = nullptr;
    return true;
}

/* ĐỌC FILE (mỗi lần đọc 1 dòng) */
bool DocGiaThuong::docFile(ifstream &in) {
    string line;
    if (!getline(in, line) || line.empty()) return false;
    return docFileFromString(line);
}