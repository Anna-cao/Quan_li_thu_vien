#include <iostream>
#include "../include/ThuVien.h"
using namespace std;

void menuQuanLiHoaDon(ThuVien& thuVien) {
    int chon3;
    do {
        cout << "\n--- Quan li hoa don ---\n";
        cout <<"1. Them hoa don\n";
        cout <<"2. Hien thi danh sach hoa don\n";
        cout <<"3. Thoat\n";
        cout <<"Lua chon: ";
        cin >> chon3;
        cin.ignore();

        switch (chon3) {
            case 1: {
                string maHD, maThe;
                int d1,m1,y1, d2,m2,y2;
                double phi=0, tong=0;
                cout << "Nhap ma hoa don: "; getline(cin, maHD);
                cout << "Nhap ma the (ma the muon): "; getline(cin, maThe);
                cout << "Nhap ngay muon (d m y): ";
                cin >> d1 >> m1 >> y1; cin.ignore();
                cout << "Nhap ngay tra thuc te (d m y). Neu chua tra, nhap 0 0 0: ";
                cin >> d2 >> m2 >> y2; cin.ignore();
                Date ngMuon(d1, m1, y1);
                Date ngTra(d2, m2, y2);
                HoaDon hd(maHD, maThe, ngMuon, ngTra, phi, tong);
                thuVien.themHoaDon(hd);
                break;
            }
            case 2: thuVien.hienThiDanhSachHoaDon(); break;
            case 3: break;
            default: cout <<"Lua chon khong hop le!\n";
        }
    } while(chon3 != 3);
}
