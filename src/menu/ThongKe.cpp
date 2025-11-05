#include <iostream>
#include "../include/ThuVien.h"
using namespace std;

void menuThongKe(ThuVien& thuVien) {
    int chon5;
    cout << "\n--- Thong ke ---\n";
    cout << "1. Thong ke muon/tra/qua han\n";
    cout << "2. Thong ke theo NXB\n";
    cout << "Lua chon: ";
    cin >> chon5;
    cin.ignore();

    if (chon5 == 1) {
        int d,m,y;
        cout << "Nhap ngay hien tai (d m y): ";
        cin >> d >> m >> y;
        cin.ignore();
        Date today(d,m,y);
        thuVien.thongKeMuonTra(today);
    } else if (chon5 == 2) {
        thuVien.thongKeSachTheoNXB();
    } else {
        cout << "Lua chon khong hop le!\n";
    }
}
