#include "../include/Sach.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

Sach::Sach() {
    this->maSach = "";
    this->tenSach = "";
    this->tacGia = "";
    this->NXB = "";
    this->type = "";
    this->soTrang = 0;
    this->soLuongTong = 0;
    this->soLuongDaMuon = 0;
    this->giaTien = 0;
}
Sach::Sach(string maSach, string tenSach, double giaTien)
    : maSach(maSach), tenSach(tenSach), tacGia(""), NXB(""), type(""),
      soTrang(0), soLuongTong(0), soLuongDaMuon(0), giaTien(giaTien) {}

int Sach::soSachConLai() const {
    return soLuongTong - soLuongDaMuon;
}
bool Sach::muonSach() {
    if (soSachConLai() > 0) {
        soLuongDaMuon++;
        cout << "Da muon thanh cong! So sach con lai: " << soSachConLai() << endl;
        return true;
    } else {
        cout << "Khong du so luong sach de muon!" << endl;
        return false;
    }
}
bool Sach::traSach() {
    if (soLuongDaMuon > 0) {
        soLuongDaMuon--;
        cout << "Tra sach thanh cong! So sach con lai: " << soSachConLai() << endl;
        return true;
    } else {
        cout << "Khong co sach nao de tra!" << endl;
        return false;
    }
}

void Sach::nhap() {
    cout << "\n----- NHAP THONG TIN SACH -----\n";
    
    cout << "Ma sach: "; getline(cin, maSach);
    cout << "Ten sach: "; getline(cin, tenSach);
    cout << "Tac gia: "; getline(cin, tacGia);
    cout << "Nha xuat ban: "; getline(cin, NXB);
    cout << "The loai: "; getline(cin, type);
    cout << "So trang: "; cin >> soTrang;
    cout << "So luong tong: "; cin >> soLuongTong;
    cout << "So luong da muon: "; cin >> soLuongDaMuon;
    cout << "Gia tien 1 quyen: "; cin >> giaTien;
    cin.ignore(1, '\n');
}
void Sach::hienThiThongTin() {
    cout << "\n----- THONG TIN SACH -----\n";
    cout << "Ma sach: " << maSach << endl;
    cout << "Ten sach: " << tenSach << endl;
    cout << "Tac gia: " << tacGia << endl;
    cout << "Nha xuat ban: " << NXB << endl;
    cout << "The loai: " << type << endl;
    cout << "So trang: " << soTrang << endl;
    cout << "So luong tong: " << soLuongTong << endl;
    cout << "So luong da muon: " << soLuongDaMuon << endl;
    cout << "So luong con lai: " << soSachConLai() << endl;
    cout << "Gia tien: " << giaTien << endl;
}

int Sach::docFileSach(Sach danhSach[], int soLuongToiDa, const string& duongDan) {
    ifstream in(duongDan);
    if (!in.is_open()) return 0;
    string line;
    int soLuong = 0;
    while (getline(in, line)) {
        if (line.size() == 0) continue;
        if (soLuong >= soLuongToiDa) break;
        string ma = line;
        string ten; if (!getline(in, ten)) break;
        string tacgia; if (!getline(in, tacgia)) break;
        string nxb; if (!getline(in, nxb)) break;
        string theloai; if (!getline(in, theloai)) break;
        string tmp;
        if (!getline(in, tmp)) break; int sotrang = tmp.size()? stoi(tmp) : 0;
        if (!getline(in, tmp)) break; int soLuongTong = tmp.size()? stoi(tmp) : 0;
        if (!getline(in, tmp)) break; int soLuongDaMuon = tmp.size()? stoi(tmp) : 0;
        if (!getline(in, tmp)) break; double gia = tmp.size()? stod(tmp) : 0.0;
        Sach s(ma, ten, gia);
        s.setTacGia(tacgia);
        s.setNXB(nxb);
        s.setType(theloai);
        s.setSoTrang(sotrang);
        s.setSoLuongTong(soLuongTong);
        s.setSoLuongDaMuon(soLuongDaMuon);
        danhSach[soLuong++] = s;
    }
    in.close();
    return soLuong;
}

void Sach::ghiFileSach(const Sach danhSach[], int soLuong, const string& duongDan) {
    ofstream out(duongDan);
    if (!out.is_open()) return;
    for (int i = 0; i < soLuong; ++i) {
        const Sach &s = danhSach[i];
        out << s.getMaSach() << "\n";
        out << s.getTenSach() << "\n";
        out << s.getTacGia() << "\n";
        out << s.getNXB() << "\n";
        out << s.getType() << "\n";
        out << s.getSoTrang() << "\n";
        out << s.getSoLuongTong() << "\n";
        out << s.getSoLuongDaMuon() << "\n";
        out <<fixed << setprecision(0) << s.getGiaTien() << "\n\n";
    }
    out.close();
}
