#include <iostream>
#include "../include/ThuVien/ThuVien.h"
#include "../include/NhaXuatBan.h"
using namespace std;

void menuQuanLiNXB(ThuVien& thuVien) {
    int chon4;
    do {
        cout << "\n--- Quan li Nha Xuat Ban ---\n";
        cout <<"1. Them NXB\n";
        cout <<"2. Hien thi danh sach NXB\n";
        cout <<"3. Tim NXB theo ten\n";
        cout <<"4. Sua ten NXB\n";
        cout <<"5. Xoa NXB\n";
        cout <<"6. Thoat\n";  
        cout <<"Lua chon: ";
        cin >> chon4;
        cin.ignore();

        switch (chon4) {
            case 1: {
                string ten;
                cout << "Nhap ten NXB: ";
                getline(cin, ten);
                thuVien.themNXB(ten); 
                break;
            }
            case 2: thuVien.hienThiDanhSachNXB(); break;
            case 3: {
                string ten;
                cout << "Nhap ten NXB can tim: ";
                getline(cin, ten);
                NhaXuatBan* nxb = thuVien.timNXBTheoTen(ten);
                if (nxb) {
                    cout << "Tim thay NXB:\n";
                    nxb->hienThiDSNXB();
                } else cout << "Khong tim thay NXB!\n";
                break;
            }
            case 4: {
                string tenCu, tenMoi;
                cout << "Nhap ten NXB cu: "; getline(cin, tenCu);
                cout << "Nhap ten moi: "; getline(cin, tenMoi);
                thuVien.suaNXB(tenCu, tenMoi);
                 break;
            }
            case 5: {
                string ten;
                cout << "Nhap ten NXB can xoa: "; getline(cin, ten);
                thuVien.xoaNXB(ten);
                break;
            } 
            case 6: break;
            default: cout <<"Lua chon khong hop le!\n";
        }
    } while (chon4 != 6);
}
