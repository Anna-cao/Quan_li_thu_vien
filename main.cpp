#include <iostream>
#include "../include/auth.h"
#include "../include/ThuVien.h"
#include "../include/menu/QLSach.h"
#include "../include/menu/QLDocGia.h"
#include "../include/menu/QLHoaDon.h"
#include "../include/menu/QLNXB.h"
#include "../include/menu/ThongKe.h"
using namespace std;

int main() {
    Auth auth;
    auth.docFile("data/auth.txt");  
    string ten, mk;
    bool daDangNhap = false;

    cout << "===== DANG NHAP HE THONG =====\n";
    while (!daDangNhap) {
        cout << "Ten dang nhap: ";
        cin >> ten;
        cout << "Mat khau: ";
        cin >> mk;

        if (auth.dangNhap(ten, mk)) {
            cout << "Chao mung " << auth.getNguoiDungHienTai()->getTenDangNhap() << "!\n";
            daDangNhap = true;
        } else {
            cout << "Sai thong tin, vui long thu lai!\n";
        }
    }
    ThuVien thuVien;
    int chon;

    do {
        cout << "\n===== MENU QUAN LY THU VIEN =====\n";
        cout << "1. Quan li sach\n";
        cout << "2. Quan li doc gia\n";
        cout << "3. Quan li hoa don\n";
        cout << "4. Quan li nha xuat ban\n";
        cout << "5. Thong ke\n";
        cout << "6. Dang xuat va thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon; while (cin.get() != '\n');

        switch(chon) {
            case 1: menuQuanLiSach(thuVien); break;
            case 2: menuQuanLiDocGia(thuVien); break;
            case 3: menuQuanLiHoaDon(thuVien); break;
            case 4: menuQuanLiNXB(thuVien); break;
            case 5: menuThongKe(thuVien); break;
            case 6:
                cout << "Dang xuat...\n";
                auth.dangXuat();
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 6);

    cout << "Tam biet!\n";
    return 0;
}
