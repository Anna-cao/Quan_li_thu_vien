#include "../include/menu/ThongKe.h"
#include "../include/Kho.h"
#include <iostream>
using namespace std;

void menuThongKe(ThuVien& thuVien) {
    int chon;
    do {
        cout << "\n===== MENU THONG KE =====\n";
        cout << "1. Thong ke tong quan (sach, muon, tra, qua han, doanh thu)\n";
        cout << "2. Thoat\n";
        cout << "Lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1: {
                int d, m, y;
                cout << "Nhap ngay hien tai (d/m/y): ";
                cin >> d >> m >> y;
                cin.ignore();
                Date today(d, m, y);
                if (!today.HopLe()) {
                    cout << "Ngay khong hop le!\n";
                    break;
                }
                thuVien.thongKeMuonTra(today);
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
