#include <iostream>
#include <string>
#include "../include/ThuVien.h"
#include "../include/DocGiaThuong.h"
#include "../include/HoiVien.h"
#include "../include/DocGia.h"
using namespace std;
void menuQuanLiDocGia(ThuVien& thuVien) {
    int chon;
    do {
        cout << "\n--- QUAN LI DOC GIA ---\n";
        cout << "1. Them doc gia\n";
        cout << "2. Hien thi danh sach doc gia\n";
        cout << "3. Tim doc gia theo ma\n";
        cout << "4. Cap nhat the muon cho doc gia\n";
        cout << "5. Sua thong tin doc gia theo ma\n";
        cout << "6. Xoa doc gia theo ma\n";
        cout << "7. Thoat\n";
        cout << "0. Thoat ve chuong trinh chinh\n";
        cout << "Lua chon: ";
        if (!(cin >> chon)) {
            cout << "Nhap sai! Vui long nhap so.\n";
            cin.clear(); cin.ignore(1000, '\n');
            continue; 
        }
        cin.ignore();

        switch (chon) {
            case 1: {
                int loai;
                cout << "Loai (1: Thuong, 2: Hoi vien): ";
                if (!(cin >> loai) || (loai != 1 && loai != 2)) {
                    cout << "Loai khong hop le!\n";
                    cin.clear(); cin.ignore(1000, '\n');
                    break;
                }
                cin.ignore();
                string ten;
                cout << "Ho ten: "; getline(cin, ten);
                DocGia* dg = nullptr;
                if (loai == 1) {
                    dg = new DocGiaThuong(ten);  
                    static_cast<DocGiaThuong*>(dg)->nhapGioiHanMuon();
                } else {
                    dg = new HoiVien(ten);  
                }
                dg->nhapThongTinChung();
                if (thuVien.themDocGia(dg)) {
                    cout << "Them thanh cong! Ma: " << dg->getMaDocGia() << endl;
                } else {
                    cout << "Them that bai!\n";
                }
                break;
            }
            case 2: {
                int loai;
                cout << "1. Doc gia thuong\n2. Hoi vien\n3. Tat ca\nChon: ";
                if (!(cin >> loai) || (loai < 1 || loai > 3)) {
                    cout << "Lua chon khong hop le!\n";
                    cin.clear(); cin.ignore(1000, '\n');
                    break;
                }
                cin.ignore();
                DocGia* ds[Max_docgia];  
                int n = 0;
                if (loai == 1 || loai == 3) {
                    n = DocGia::docFileDocGiaThuong(ds, Max_docgia, "docgiathuong.txt");
                    cout << "\n--- DOC GIA THUONG (" << n << ") ---\n";
                    DocGia::hienThiTieuDe();
                    cout << string(110, '-') << endl;
                    for (int i = 0; i < n; ++i) {
                        if (ds[i] && ds[i]->getStatus() == 1) ds[i]->hienThiDong();
                    }
                    cout << string(110, '-') << endl;
                    for (int i = 0; i < n; ++i) delete ds[i];
                }
                if (loai == 2 || loai == 3) {
                    n = DocGia::docFileHoiVien(ds, Max_docgia, "hoivien.txt");
                    cout << "\n--- HOI VIEN (" << n << ") ---\n";
                    DocGia::hienThiTieuDe();
                    cout << string(110, '-') << endl;
                    for (int i = 0; i < n; ++i) {
                        if (ds[i] && ds[i]->getStatus() == 1) ds[i]->hienThiDong();
                    }
                    cout << string(110, '-') << endl;
                    for (int i = 0; i < n; ++i) delete ds[i];
                }
                break;
            }
            case 3: {
                string ma = DocGia::nhapMaDocGia("Nhap ma doc gia (0 de huy): ");
                if (ma.empty()) break;
                DocGia* dg = thuVien.timDocGiaTheoMa(ma);
                if (dg) {
                    dg->hienThiThongTin();
                } else {
                    cout << "Khong tim thay!\n";
                }
                break;
            }
            case 4: {
                string ma = DocGia::nhapMaDocGia("Nhap ma doc gia (0 de huy): ");
                if (ma.empty()) break;
                TheMuon* the = new TheMuon();
                cout << "Nhap thong tin the moi:\n";
                the->nhap();
                thuVien.capNhatTheMuonChoDocGia(ma, the);
                break;
            }
            case 5: {
                string ma = DocGia::nhapMaDocGia("Nhap ma doc gia (0 de huy): ");
                if (ma.empty()) break;
                if (thuVien.suaThongTinDocGia(ma)) {
                    DocGia* dg = thuVien.timDocGiaTheoMa(ma);
                    if (dg) {
                        cout << "Da sua thanh cong!\n";
                        dg->hienThiThongTin();
                    }
                } else {
                    cout << "Khong tim thay hoac loi!\n";
                }
                break;
            }
            case 6: {
                string ma = DocGia::nhapMaDocGia("Nhap ma doc gia (0 de huy): ");
                if (ma.empty()) break;
                if (thuVien.xoaDocGia(ma)) {
                    cout << "Da xoa thanh cong!\n";
                } else {
                    cout << "Khong tim thay!\n";
                }
                break;
            }
            case 7:
                cout << "Thoat quan li doc gia...\n";
                return;  
            case 0:
                cout << "Thoat ve chuong trinh chinh...\n";
                return;  
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (true);  
}