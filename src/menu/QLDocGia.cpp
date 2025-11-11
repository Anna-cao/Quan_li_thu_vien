#include <iostream>
#include <string>
#include "../include/ThuVien.h"
#include "../include/DocGiaThuong.h"
#include "../include/HoiVien.h"
using namespace std;

void menuQuanLiDocGia(ThuVien& thuVien) {
    int chon2;
    do {
        system("cls");
        cout << "\n--- Quan li doc gia ---\n";
        cout << "1. Them doc gia\n";
        cout << "2. Hien thi danh sach doc gia\n";
        cout << "3. Tim doc gia theo ma\n";
        cout << "4. Cap nhat the muon cho doc gia\n";
        cout << "5. Sua thong tin the muon cho doc gia theo ma\n";
        cout << "6. Xoa doc gia theo ma\n";
        cout << "7. Thoat\n";
        cout << "Lua chon: ";
        cin >> chon2;
        cin.ignore();

        switch (chon2) {
            case 1: {
            int loai;
            cout << "Loai (1: Thuong, 2: Hoi vien): ";
            cin >> loai; cin.ignore();
            DocGia* dg = nullptr;
            if (loai == 1) {
                dg = new DocGiaThuong();
                cout << "Nhap thong tin doc gia thuong:\n";
                dg->nhap();  
                static_cast<DocGiaThuong*>(dg)->nhapGioiHanMuon(); 
    }
    else if (loai == 2) {
        dg = new HoiVien();
        cout << "Nhap thong tin hoi vien:\n";
        dg->nhap();
    }
    else {
        cout << "Loai khong hop le!\n"; system("pause"); break;
    }
    thuVien.themDocGia(dg);
    system("pause");
    break;
}
            case 2: 
                thuVien.hienThiDanhSachDocGia(); 
                system("pause"); 
                break;
            case 3: {
                string ma;
                cout << "Nhap ma doc gia: ";
                getline(cin, ma);
                DocGia* dg = thuVien.timDocGiaTheoMa(ma);
                if (dg) {
                    cout << "\n=== THONG TIN DOC GIA ===\n";
                    dg->hienThiThongTin();
                } else {
                    cout << "Khong tim thay doc gia!\n";
                }
                system("pause");
                break;
            }
            case 4: {
                string ma;
                cout << "Nhap ma doc gia can cap nhat the: ";
                getline(cin, ma);
                TheMuon* the = new TheMuon();
                the->nhap();   
                thuVien.capNhatTheMuonChoDocGia(ma, the);
                system("pause");
                break;
            }
            case 5: {
                string ma;
                cout << "Nhap ma doc gia can sua: ";
                getline(cin, ma);
                thuVien.suaThongTinDocGia(ma);
                system("pause");
                break;
            }
            case 6: {
                string ma;
                cout << "Nhap ma doc gia can xoa: ";
                getline(cin, ma);
                thuVien.xoaDocGia(ma);
                system("pause");
                break;
            }
            case 7: 
                cout << "Thoat quan li doc gia...\n"; 
                break;
            default: 
                cout << "Lua chon khong hop le!\n"; 
                system("pause");
        }
    } while (chon2 != 7);
}