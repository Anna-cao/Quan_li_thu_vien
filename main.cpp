#include <iostream>
#include "ThuVien.h"
#include "NhaXuatBan.h"
#include "HoaDon.h"
#include "DocGiaThuong.h"
#include "HoiVien.h"
#include "NhaXuatBan.h"

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
        cin >> chon;
        cin.ignore();
        switch (chon) {
        case 1: {
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
                cin.ignore();
                switch (chon1) {
                    case 1: thuVien.hienThi(); break;
                    case 2: thuVien.themSach(); break;
                    case 3: {
                        string ten;
                        cout <<"Nhap ten sach: ";
                        getline(cin, ten);
                        thuVien.timTheoTen(ten);
                        break;
                    }
                    case 4: {
                        string ma;
                        cout << "Nhap ma sach can sua: ";
                        getline(cin, ma);
                        thuVien.suaSachTheoMa(ma);
                        break;
                    }
                    case 5: {
                        string ma;
                        cout << "Nhap ma sach can xoa: ";
                        getline(cin, ma);
                        thuVien.xoaSachTheoMa(ma);
                        break;
                    }
                    case 6: cout <<"Quay lai menu chinh\n"; break;
                    default: cout <<"Lua chon khong hop le!\n";
                }
            } 
            while(chon1 != 6);
            break;
        }
        case 2: {
            int chon2;
            do {
                cout << "\n--- Quan li doc gia ---\n";
                cout <<"1. Them doc gia\n";
                cout <<"2. Hien thi danh sach doc gia\n";
                cout <<"3. Tim doc gia theo ma\n";
                cout <<"4. Cap nhat the muon cho doc gia\n";
                cout <<"5. Thoat\n";
                cout <<"Lua chon: ";
                cin >> chon2;
                cin.ignore();

                switch (chon2) {
                    case 1: {
                        int loai;
                        cout << "Loai (1: Thuong, 2: Hoi vien): ";
                        cin >> loai; cin.ignore();
                        DocGia* dg = nullptr;
                        if (loai == 1) dg = new DocGiaThuong();
                        else if (loai == 2) dg = new HoiVien();
                        else { cout << "Loai khong hop le!\n"; break; }
                        cout << "Nhap thong tin:\n";
                        dg->nhap();            
                        thuVien.themDocGia(dg);
                        break;
                    }
                    case 2: thuVien.hienThiDanhSachDocGia(); break;
                    case 3: {
                        string ma;
                        cout << "Nhap ma doc gia: ";
                        getline(cin, ma);
                        DocGia* dg = thuVien.timDocGiaTheoMa(ma);
                        if (dg) dg->hienThiThongTin();
                        else cout << "Khong tim thay doc gia!\n";
                        break;
                    }
                    case 4: {
                        string ma;
                        cout << "Nhap ma doc gia can cap nhat the: ";
                        getline(cin, ma);
                        TheMuon* the = new TheMuon();
                        cin >> *the;   
                        thuVien.capNhatTheMuonChoDocGia(ma, the);
                        break;
                    }
                    case 5: cout <<"Quay lai menu chinh\n"; break;
                    default: cout <<"Lua chon khong hop le!\n";
                }
            }
            while(chon2 != 5);
            break;
        }
        case 3: {
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
                        cin >> d1 >> m1 >> y1;
                        cin.ignore();
                        cout << "Nhap ngay tra thuc te (d m y). Neu chua tra, nhap 0 0 0: ";
                        cin >> d2 >> m2 >> y2;
                        cin.ignore();
                        Date ngMuon(d1, m1, y1);
                        Date ngTra(d2, m2, y2);
                        HoaDon hd(maHD, maThe, ngMuon, ngTra, phi, tong);
                        thuVien.themHoaDon(hd);
                        break;
                    }
                    case 2: thuVien.hienThiDanhSachHoaDon(); break;
                    case 3: cout <<"Quay lai menu chinh\n"; break;
                    default: cout <<"Lua chon khong hop le!\n";
                }
            } while(chon3 != 3);
            break;
        }
        case 4: {
            int chon4;
            do {
                cout << "\n--- Quan li Nha Xuat Ban ---\n";
                cout <<"1. Them NXB\n";
                cout <<"2. Hien thi danh sach NXB\n";
                cout <<"3. Tim NXB theo ten\n";
                cout <<"4. Thoat\n";
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
                    case 2:
                        thuVien.hienThiDanhSachNXB();
                        break;
                    case 3: {
                        string ten;
                        cout << "Nhap ten NXB can tim: ";
                        getline(cin, ten);
                        NhaXuatBan* nxb = thuVien.timNXBTheoTen(ten);
                        if (nxb) {
                            cout << "Tim thay NXB:\n";
                            nxb->hienThiDSNXB();
                        } else {
                            cout << "Khong tim thay NXB co ten: " << ten << "\n";
                        }
                        break;
                    }
                    case 4: cout <<"Quay lai menu chinh\n"; break;
                    default: cout <<"Lua chon khong hop le!\n";
                }
            } while (chon4 != 4);
            break;
        }
        case 5: {
            int chon5;
            cout << "\n--- Thong ke ---\n";
            cout << "1. Thong ke muon/tra/qua han\n";
            cout << "2. Thong ke theo NXB\n";
            cout << "Lua chon: ";
            cin >> chon5;
            cin.ignore();

            if (chon5 == 1) {
                int d,m,y;
                cout << "Nhap ngay hien tai (d m y): ";
                cin >> d >> m >> y;
                cin.ignore();
                Date today(d,m,y);
                thuVien.thongKeMuonTra(today);
            } else if (chon5 == 2) {
                thuVien.thongKeSachTheoNXB();
            } else {
                cout << "Lua chon khong hop le!\n";
            }
            break;
        }

        case 6:
            cout << "\nThoat chuong trinh...\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 6);

    return 0;
}
