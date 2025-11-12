#include "../include/ThuVien.h"
#include"../include/Sach.h"
#include <iostream>
#include <string>
using namespace std;

void ThuVien::themSach() {
    if (soLuongTong >= Max_sach) {
        cout << "Thu vien da day!\n";
        return;
    }
    Sach s;
    s.nhap(); 
    string nxb = s.getNXB();
    while (true) {
        if (timNXBTheoTen(nxb) != nullptr) {
            break; 
        }

        cout << "NXB '" << nxb << "' KHONG TON TAI! Nhap lai (0 huy): ";
        string tmp;
        if (!getline(cin >> ws, tmp)) {
            cout << "Loi nhap. Huy.\n";
            return;
        }
        if (tmp == "0") {
            cout << "Huy.\n";
            return;
        }
        nxb = tmp;
        s.setNXB(nxb); 
    }
    danhSach[soLuongTong++] = s;
    saveDuLieu();
    cout << "Them thanh cong! Ma: " << s.getMaSach() << endl;
}
void ThuVien::hienThi() {
    cout << "\n----- DANH SACH SACH TRONG THU VIEN -----\n";
    for (int i = 0; i < soLuongTong; ++i) {
        cout << "\nThong tin cuon sach thu " << i + 1 << ":\n";
        danhSach[i].hienThiThongTin();
    }
}
Sach* ThuVien::timSachTheoMa(const string& maSach) const {
    for (int i = 0; i < soLuongTong; ++i) {
        if (danhSach[i].getMaSach() == maSach) {
            return const_cast<Sach*>(&danhSach[i]);  // Vì const, nhưng cần mutable để muonSach()
        }
    }
    return nullptr;
}
Sach* ThuVien::timSachTheoTen(const string& ten) const {
   for (int i = 0; i < soLuongTong; ++i) {
        if (danhSach[i].getTenSach() == ten) {
            return const_cast<Sach*>(&danhSach[i]);
        }
    }
    return nullptr;
}

void ThuVien::suaSachTheoTen() {
    string ten;
    cout << "Nhap ten sach can sua: ";
    getline(cin, ten);
    Sach* s= timSachTheoTen(ten);
    if (!s) {
        cout << "Khong tim thay sach!\n";
        return;
    }
    cout << "Nhap thong tin moi:\n";
    s->nhap();  
    saveDuLieu();  
    cout << "Da sua thanh cong!\n";
}

void ThuVien::xoaSachTheoTen() {
    string ten;
    cout << "Nhap ten sach can xoa: ";
    getline(cin, ten);

    for (int i = 0; i < soLuongTong; ++i) {
        if (danhSach[i].getTenSach() == ten) {
            for (int j = i; j < soLuongTong - 1; ++j) {
                danhSach[j] = danhSach[j + 1];
            }
            --soLuongTong;
            saveDuLieu();  
            cout << "Da xoa sach!\n";
            return;
        }
    }
    cout << "Khong tim thay sach!\n";
}
void ThuVien::timVaHienThiSach(const string& ten) const {
    Sach* s = const_cast<ThuVien*>(this)->timSachTheoTen(ten);
    if (s) {
        s->hienThiThongTin();
    } else {
        cout << "Khong tim thay!\n";
    }
}