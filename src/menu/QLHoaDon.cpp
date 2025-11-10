#include <iostream>
#include "../include/ThuVien.h"
#include "../include/Date.h"
#include "../include/DocGia.h"

using namespace std;

void menuQuanLiHoaDon(ThuVien& thuVien) {
    int chon;
    do {
        cout << "\n===== QUAN LI HOA DON =====\n";
        cout << "1. Them hoa don muon\n";
        cout << "2. Cap nhat hoa don da tra\n";
        cout << "3. Hien thi danh sach hoa don\n";
        cout << "4. Tinh phi qua han cho doc gia\n";
        cout << "5. Thoat\n";
        cout << "Lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1: {
                string maHD, maThe;
                int d1, m1, y1;
                cout << "Nhap ma hoa don: "; getline(cin, maHD);
                cout << "Nhap ma the doc gia: "; getline(cin, maThe);
                cout << "Nhap ngay muon (dd/mm/yy): ";
                cin >> d1 >> m1 >> y1; 
                cin.ignore();
                Date ngMuon(d1,m1,y1);
                Date ngTraThucTe(0,0,0);
                HoaDon hd(maHD, maThe, ngMuon, ngTraThucTe, 0, 0);
                thuVien.themHoaDon(hd);
                break;
            }
            case 2: {
                string maHD;
                cout << "Nhap ma hoa don ban: ";
                getline(cin, maHD);
                int d,m,y;
                cin.ignore();
                cout<<"Ngay nhap hien  tai(d/m/y): ";
                cin >>d >> m>>y;
                cin.ignore();
                Date ngayHienTai(d,m,y);
                thuVien.tinhTienPhatQuaHan(maHD, ngayHienTai); break;
            }
            case 3: thuVien.hienThiDanhSachHoaDon(); break;
            case 4:{
                string maDG;
                int d,m,y;
                cout <<"Nhap ma doc gia: ";
                getline(cin,maDG);
                cout <<"Nhap ngay hien tai(dd/mm/yy):";
                cin >>d>>m>>y;
                cin.ignore();
                Date ngayHienTai(d,m,y);
                thuVien.tinhTienPhatQuaHan(maDG, ngayHienTai);
                break;
            }
            case 5:
                cout << "Thoat quan li hoa don.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 5);
}

                