#include <iostream>
#include "../include/ThuVien.h"
#include "../include/menu/QLSach.h"
#include <string>
using namespace std;

void menuQuanLiSach(ThuVien& thuVien) {
    int chon;
    do {
        cout << "\n--- QUAN LI SACH ---\n";
        cout << "1. Hien thi danh sach\n";
        cout << "2. Them sach\n";
        cout << "3. Tim sach theo ten\n";
        cout << "4. Sua sach theo ten\n";
        cout << "5. Xoa sach theo ten\n";
        cout << "6. Thoat\n";
        cout << "Chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1: thuVien.hienThi(); break;
            case 2: thuVien.themSach(); break;
            case 3: {
                string ten;
                cout << "Nhap ten sach can tim: ";
                getline(cin, ten);
                thuVien.timVaHienThiSach(ten);
                break;
            }
            case 4: thuVien.suaSachTheoTen(); break;
            case 5: thuVien.xoaSachTheoTen(); break;
            case 6: break;
            default: cout << "Sai!\n";
        }
    } while (chon != 6);
}