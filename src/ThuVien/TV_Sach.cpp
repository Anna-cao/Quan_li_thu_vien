#include "../include/ThuVien.h"
#include"../include/Sach.h"
#include <iostream>
#include <string>
using namespace std;

void ThuVien::themSach() {
    if (soLuongTong >= Max_sach) {
        cout << "Thu vien da day, khong the them sach moi!\n";
        return;
    }
    Sach s;
    s.nhap();
    string nxb = s.getNXB();
    while (!timNXBTheoTen(nxb)) {
        cout << "NXB '" << nxb << "' khong ton tai. Nhap lai NXB (nhap 0 de huy): ";
        string tmp;
        getline(cin, tmp);
        if (tmp == "0" || tmp.size() == 0) {
            cout << "Huy them sach.\n";
            return;
        }
        s.setNXB(tmp);
        nxb = tmp;
    }
    danhSach[soLuongTong++] = s;
    cout << "Da them sach thanh cong!\n";
}

void ThuVien::hienThi() {
    cout << "\n----- DANH SACH SACH TRONG THU VIEN -----\n";
    for (int i = 0; i < soLuongTong; ++i) {
        cout << "\nThong tin cuon sach thu " << i + 1 << ":\n";
        danhSach[i].hienThiThongTin();
    }
}
void ThuVien::timTheoMa() {
    string ma;
    while(true)
    {
        cout << "Nhap ma sach can tim la: "; cin >>ma;
        bool found = false;
        for (int i = 0; i < soLuongTong; ++i) {
        if (danhSach[i].getMaSach() == ma) {
            danhSach[i].hienThiThongTin();
            found = true;
            break;
        }
    }
        if (found == false) cout << "Khong tim thay ma sach. Vui long nhap lai! \"" << ma << "\"\n";
    }
}

void ThuVien::suaSachTheoMa() {
    string ma;
    while(true)
    {
        cout << "Nhap ma cua sach can sua la: "; cin >>ma;
        bool found = false;
        for (int i = 0; i < soLuongTong; ++i) {
        if (danhSach[i].getMaSach() == ma) {
            danhSach[i].nhap();
            found = true;
            cout <<"Da sua thanh cong!"<<endl;
            break;
        }
    }
        if (found == false) cout << "Khong tim thay ma sach. Vui long nhap lai! \"" << ma << "\"\n";
    }
}

void ThuVien::xoaSachTheoMa() {
    while (true)
    {
        string ma;
        cout <<"Nhap ma sach can xoa: "; cin >> ma;
        bool found = false;
        for (int i = 0; i < soLuongTong; ++i) {
        if (danhSach[i].getMaSach() == ma) {
            for (int j = i; j < soLuongTong - 1; ++j) danhSach[j] = danhSach[j + 1];
            --soLuongTong;
            cout << "Da xoa sach co ma " << ma << "\n";
            break;
        }
    }
    if (found == false) cout << "Khong tim thay ma sach. Vui long nhap lai! \"" << ma << "\"\n";
    }
}