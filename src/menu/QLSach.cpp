#include <iostream>
#include "../include/ThuVien.h"
using namespace std;

void menuQuanLiSach(ThuVien& thuVien) {
    int chon1;
    do {
        cout << "\n--- Quan li sach ---\n";
        cout <<"1. Hien thi danh sach sach\n";
        cout <<"2. Them sach\n";
        cout <<"3. Tim sach theo ten\n";
        cout <<"4. Sua sach theo ma\n";
        cout <<"5. Xoa sach theo ma\n";
        cout <<"6. Thoat\n";
        cout <<"Lua chon: ";
        cin >> chon1;
        cin.ignore(1000,'\n');

        switch(chon1) {
            case 1: thuVien.hienThi(); break;
            case 2: thuVien.themSach(); break;
            case 3: {
                string ten;
                cout <<"Nhap ten sach: ";
                getline(cin, ten);
                thuVien.timTheoMa();
                break;
            }
            case 4: {
                string ma;
                cout <<"Nhap ma sach can sua: ";
                getline(cin, ma);
                thuVien.suaSachTheoMa();
                break;
            }
            case 5: {
                string ma;
                cout <<"Nhap ma sach can xoa: ";
                getline(cin, ma);
                thuVien.xoaSachTheoMa();
                break;
            }
            case 6: break;
            default: cout <<"Lua chon khong hop le!\n";
        }
    } while(chon1 != 6);
}
