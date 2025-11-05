#include <iostream>
#include "../include/ThuVien.h"
#include "../include/menu/QLSach.h"
#include "../include/menu/QLDocGia.h"
#include "../include/menu/QLHoaDon.h"
#include "../include/menu/QLNXB.h"
#include "../include/menu/ThongKe.h"
using namespace std;

int main() {
    ThuVien thuVien;
    int chon;

    do {
        cout << "\n===== MENU QUAN LY THU VIEN =====\n";
        cout << "1. Quan li sach\n";
        cout << "2. Quan li doc gia\n";
        cout << "3. Quan li hoa don\n";
        cout << "4. Quan li nha xuat ban\n";
        cout << "5. Thong ke\n";
        cout << "6. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon; cin.ignore();

        switch(chon) {
            case 1: menuQuanLiSach(thuVien); break;
            case 2: menuQuanLiDocGia(thuVien); break;
            case 3: menuQuanLiHoaDon(thuVien); break;
            case 4: menuQuanLiNXB(thuVien); break;
            case 5: menuThongKe(thuVien); break;
            case 6: cout << "Thoat chuong trinh...\n"; break;
            default: cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 6);
    return 0;
}
