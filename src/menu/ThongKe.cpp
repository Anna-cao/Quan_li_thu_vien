
#include "../include/menu/ThongKe.h"
#include "../include/Kho.h"
#include <iostream>
#include <limits>
using namespace std;

void menuThongKe(ThuVien& thuVien) {
    int chon;
    do {
        cout << "\n===== MENU THONG KE =====\n";
        cout << "1. Thong ke tong quan\n";
        cout << "2. Thoat\n";
        cout << "Lua chon: ";

        if (!(cin >> chon)) {
            cout << "Vui long nhap so!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore();

        switch (chon) {
            case 1: {
                int d, m, y;
                while (true) {
                    cout << "Nhap ngay hien tai (d m y): ";
                    if (cin >> d >> m >> y) {
                        Date today(d, m, y);
                        if (today.HopLe()) {
                            cin.ignore();
                            thuVien.thongKeMuonTra(today);
                            break;
                        } else {
                            cout << "Ngay khong hop le! Nhap lai.\n";
                        }
                    } else {
                        cout << "Nhap sai dinh dang! Nhap lai.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                break;
            }
            case 2:
                cout << "Thoat menu thong ke.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 2);
}