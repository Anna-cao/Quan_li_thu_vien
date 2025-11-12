#include <iostream>
#include "../include/ThuVien.h"
#include "../include/Date.h"
#include "../include/DocGia.h"
#include "../include/HoaDon.h"
#include "../include/DocGiaThuong.h"

using namespace std;
void menuQuanLiHoaDon(ThuVien& thuVien) {
    int chon;
    while (true) {
        cout << "\n===== QUAN LI HOA DON =====\n";
        cout << "1. Them hoa don muon\n";
        cout << "2. Cap nhat hoa don da tra\n";
        cout << "3. Hien thi danh sach hoa don\n";
        cout << "4. Tinh phi qua han cho doc gia\n";
        cout << "5. Thoat\n";
        cout << "Lua chon: ";
        if (!(cin >> chon)) {
            cout << "Lua chon khong hop le! Vui long nhap so.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(10000, '\n');

        if (chon == 5) {
            cout << "Thoat quan li hoa don.\n";
            break;
        }
        switch (chon) {
           case 1: {
                string maDocGia;
                cout << "Nhap ma doc gia: ";  
                getline(cin >> ws, maDocGia);
                DocGia* dg = thuVien.timDocGiaTheoMa(maDocGia);
                if (!dg) {
                    cout << "Khong tim thay doc gia!\n"; break;
        }
                TheMuon* the = dg->getTheMuon();
                if (!the) {
                    cout << "Doc gia chua duoc cap the muon!\n"; break;
        }
                string maThe = the->getMaThe();  
                cout << "Doc gia: " << dg->getHoTen() << " | Ma the: " << maThe << endl;
                Date ngMuon = Date::NhapTuChuoi("Nhap ngay muon (dd/mm/yyyy): ");
                if (!ngMuon.HopLe()) {
                    cout << "Ngay muon khong hop le!\n";
                    break;
        }
                int daMuon = dg->getDsMaSachDangMuon().size();
                int gioiHan = (dg->getLoaiDocGia() == "Doc Gia Thuong") 
                    ? static_cast<DocGiaThuong*>(dg)->getGioiHanMuon() : 10; 
                if (daMuon > 0) {
                cout << "Doc gia dang muon " << daMuon << " sach. ";
                if (daMuon >= gioiHan) {
                    cout << "Da vuot gioi han!\n"; break;
        }
                cout << "Con duoc muon toi da " << (gioiHan - daMuon) << " sach.\n";
        }
                vector<pair<string, int>> dsSach;
                double tongCoc = 0.0;
                string maSach;
                cout << "Nhap ma sach va so luong (nhap 'x' de ket thuc):\n";
                while (true) {
                    cout << "Ma sach: ";
                    getline(cin, maSach);
                    if (maSach == "x" || maSach == "X") break;
                    Sach* s = thuVien.timSachTheoMa(maSach);
                    if (!s) {
                        cout << "Khong tim thay sach!\n"; continue;
        }
                if (s->soSachConLai() <= 0) {
                    cout << "Sach da het!\n"; continue;
        }
                int sl;
                cout << "So luong muon: ";
                if (!(cin >> sl) || sl <= 0 || sl > s->soSachConLai()) {
                    cin.clear(); cin.ignore(1000, '\n');
                    continue;
        }
                cin.ignore();
                dsSach.emplace_back(maSach, sl);
                tongCoc += (s->getGiaTien() * 0.5 * sl);
                for (int j = 0; j < sl; ++j) {
                    s->muonSach();
        }
    }
                if (dsSach.empty()) {
                    cout << "Chua chon sach nao!\n"; break;
    }
                HoaDon hd;
                hd.taoMaTuDong();
                hd.setMaThe(maThe);
                hd.setNgayMuon(ngMuon);
                hd.setNgayTraThucTe(Date(0,0,0));
                hd.setTienCoc(tongCoc);
                hd.setDsSachMuon(dsSach);
                thuVien.themHoaDon(hd);
                cout << "Them hoa don thanh cong! Ma HD: " << hd.getMaHoaDon() << endl;break;
}
            case 2: {
                string maHD;
                cout << "Nhap ma hoa don: ";
                if (!getline(cin >> ws, maHD) || maHD.empty()) {
                    cout << "Ma hoa don khong duoc de trong!\n";
                    break;
                }
                Date ngayTra = Date::NhapTuChuoi("Nhap ngay tra (dd/mm/yyyy): ");
                thuVien.capNhatHoaDonDaTra(maHD, ngayTra);
                break;
            }
            case 3:
                thuVien.hienThiDanhSachHoaDon();
                break;
           case 4: {
                string maDG;
                cout << "Nhap ma doc gia: ";  
                if (!getline(cin >> ws, maDG) || maDG.empty()) {
                    cout << "Ma doc gia khong duoc de trong!\n";
                     break;
            }
                Date ngayHienTai = Date::NhapTuChuoi("Nhap ngay hien tai (dd/mm/yyyy): ");
                 thuVien.tinhTienPhatQuaHan(maDG, ngayHienTai);
                break;
}
            default:
                cout << "Lua chon khong hop le! Vui long chon tu 1-5.\n";
        }
    }
}