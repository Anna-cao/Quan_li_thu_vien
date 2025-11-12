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
                    cout << "Them thanh cong! Ma: " << dg->getMaDocGia() ;
                } else {
                    cout << "Them that bai!\n";
                }
                break;
            }
                case 2: {
                int loai;
                cout << "1. Doc gia thuong\n2. Hoi vien\n3. Tat ca\nChon: ";
                if (!(cin >> loai) || loai < 1 || loai > 3) {
                    cout << "Lua chon khong hop le!\n";
                    cin.clear(); cin.ignore(1000, '\n');
                    break;
                }
                cin.ignore();
                cout << "Tong so doc gia trong he thong: " << thuVien.getSoDocGia()<<endl; 
                int countThuong = 0, countHoiVien = 0;
                for (int i = 0; i < thuVien.getSoDocGia(); ++i) {
                    DocGia* dg = thuVien.getDanhSachDocGia()[i];
                    if (dg && dg->getStatus() == 1) {
                        string l = dg->getLoaiDocGia();
                        if (l == "Doc Gia Thuong" || l == "DocGiaThuong") countThuong++;
                        else if (l == "HoiVien" || l == "Hoi Vien") countHoiVien++;
                    }
                }
                if (loai == 1 || loai == 3) {
                    cout << "\n--- DOC GIA THUONG (" << countThuong << ") ---\n";
                    if (countThuong > 0) {
                        DocGia::hienThiTieuDe();
                        for (int i = 0; i < thuVien.getSoDocGia(); ++i) {
                            DocGia* dg = thuVien.getDanhSachDocGia()[i];
                            if (dg && dg->getStatus() == 1 && 
                                (dg->getLoaiDocGia() == "Doc Gia Thuong" || dg->getLoaiDocGia() == "DocGiaThuong")) {
                                dg->hienThiDong();
                            }
                        }
                    } else {
                        cout << "  (Khong co du lieu)\n";
                    }
                }
                if (loai == 2 || loai == 3) {
                    cout << "\n--- HOI VIEN (" << countHoiVien << ") ---\n";
                    if (countHoiVien > 0) {
                        DocGia::hienThiTieuDe();
                        for (int i = 0; i < thuVien.getSoDocGia(); ++i) {
                            DocGia* dg = thuVien.getDanhSachDocGia()[i];
                            if (dg && dg->getStatus() == 1 && 
                                (dg->getLoaiDocGia() == "HoiVien" || dg->getLoaiDocGia() == "Hoi Vien")) {
                                dg->hienThiDong();
                            }
                        }
                    } else {
                        cout << "  (Khong co du lieu)\n";
                    }
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
                DocGia* dg = thuVien.timDocGiaTheoMa(ma);
                if (!dg) {
                    cout << "Khong tim thay doc gia ma: " << ma << endl;
                    break;
                }
                LoaiThe loai = (ma.substr(0, 2) == "DG") ? THE_THUONG : THE_HOI_VIEN;
                TheMuon* the = new TheMuon(dg->getHoTen(), loai);
                thuVien.capNhatTheMuonChoDocGia(ma, the);
                cout << "Da cap nhat the muon thanh cong!\n";
                the->hienThi();
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
            default: cout << "Lua chon khong hop le!\n";
        }
    } while (true);  
}