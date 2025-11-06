#include <iostream>
#include "../include/ThuVien.h"
using namespace std;

void menuThongKe(ThuVien& thuVien) {
    int chon5;
    do {
        cout << "\n===== MENU THONG KE =====\n";
        cout << "1. Thong ke muon/tra/qua han\n";
        cout << "2. Thong ke sach theo NXB\n";
        cout << "3. Thong ke doanh thu ban sach\n";
        cout << "4. Tong tien phat qua han\n";
        cout << "5. Thong ke sach ban chay\n";
        cout << "6. Thoat\n";
        cout << "Lua chon: ";
        cin >> chon5;
        cin.ignore();

        switch (chon5) {
            case 1: {
                int d, m, y;
                cout << "Nhap ngay hien tai (d m y): ";
                cin >> d >> m >> y; cin.ignore();
                Date today(d, m, y);
                thuVien.thongKeMuonTra(today);
                break;
            }
            case 2:
                thuVien.thongKeSachTheoNXB();
                break;
            case 3: {
                int d1, m1, y1, d2, m2, y2;
                cout << "Nhap ngay bat dau (d m y): ";
                cin >> d1 >> m1 >> y1; cin.ignore();
                cout << "Nhap ngay ket thuc (d m y): ";
                cin >> d2 >> m2 >> y2; cin.ignore();
                Date tu(d1, m1, y1), den(d2, m2, y2);
                thuVien.thongKeDoanhThu(tu, den);
                break;
            }
            case 4: {
                double tongPhat = thuVien.tongTienPhat();
                cout << "Tong tien phat qua han: " << tongPhat << " VND\n";
                break;
}
            case 5:
                thuVien.thongKeSachBanChay();
                break;
            case 6:
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (chon5 != 6);
}
