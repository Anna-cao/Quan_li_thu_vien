#include <iostream>
#include "../include/ThuVien/ThuVien.h"
using namespace std;

void menuQuanLiHoaDon(ThuVien& thuVien) {
    int chon;
    do {
        cout << "\n===== QUAN LI HOA DON =====\n";
        cout << "1. Them hoa don MUON\n";
        cout << "2. Them hoa don BAN\n";
        cout << "3. Hien thi danh sach hoa don MUON\n";
        cout << "4. Hien thi danh sach hoa don BAN\n";
        cout << "5. Thoat\n";
        cout << "Lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1: {
                string maHD, maThe;
                int d1, m1, y1, d2, m2, y2;
                double phi = 0, tong = 0;

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
            case 2: {
                string maHD;
                cout << "Nhap ma hoa don ban: ";
                getline(cin, maHD);
                HoaDonBan hdb(maHD);

                int soSach;
                cout << "Nhap so luong sach ban: ";
                cin >> soSach;
                cin.ignore();

                for (int i = 0; i < soSach; ++i) {
                    string maSach, tenSach;
                    double gia;
                    int soLuong;

                    cout << "\nSach " << i + 1 << ":\n";
                    cout << "Ma sach: "; getline(cin, maSach);
                    cout << "Ten sach: "; getline(cin, tenSach);
                    cout << "Gia tien: "; cin >> gia; cin.ignore();
                    cout << "So luong ban: "; cin >> soLuong; cin.ignore();

                    Sach s(maSach, tenSach, gia);
                    hdb.themSach(s, soLuong);
                }

                hdb.tinhPhiQuaHan(); 
                thuVien.themHoaDonBan(hdb);
                break;
            }
            case 3:thuVien.hienThiDanhSachHoaDon();break;
            case 4:thuVien.hienThiDanhSachHoaDonBan();break;
            case 5:break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 5);
}

