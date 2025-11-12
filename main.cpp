#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtemplate-body"
#pragma GCC diagnostic pop
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include "../include/auth.h"
#include "../include/ThuVien.h"
#include "../include/menu/QLSach.h"
#include "../include/menu/QLDocGia.h"
#include "../include/menu/QLHoaDon.h"
#include "../include/menu/QLNXB.h"
#include "../include/menu/ThongKe.h"
using namespace std;
int main() {
    Auth auth;
    auth.docFile("data/auth.txt");
    if (auth.getSoNguoiDung() == 0) {
        auth.dangKy("admin", "123456", 2);
        cout << "Da tao tai khoan Admin mac dinh: admin / 123456\n";
    }
    ThuVien thuVien;
    thuVien.loadDuLieu();
    while (true) {
    int luaChon, lanThu = 0;
    bool daDangNhap = false;

    do {
        system("cls");
        cout << "\n";
        cout << "    HE THONG QUAN LY THU VIEN\n";
        cout << "    ------------------------\n";
        cout << "    1. Dang nhap\n";
        cout << "    2. Dang ky tai khoan\n";
        cout << "    3. Thoat chuong trinh\n";
        cout << "    ------------------------\n";
        cout << "    Lua chon: ";
        if (!(cin >> luaChon)) {
            cout << "Nhap sai! Vui long nhap so.\n";
            cin.clear(); cin.ignore(1000, '\n');
            continue; 
        }
        cin.ignore();

        switch (luaChon) {
            case 1: {
                string ten, mk = "";
                char ch;
                system("cls");
                cout << " --- DANG NHAP ---\n";
                cout << "Con " << (3 - lanThu) << " lan thu.\n\n";
                cout << "Ten dang nhap: "; getline(cin, ten);
                cout << "Mat khau: ";
                while ((ch = _getch()) != '\r') {
                    if (ch == '\b' && !mk.empty()) { mk.pop_back(); cout << "\b \b"; }
                    else if (ch >= 32 && ch <= 126) { mk += ch; cout << '*'; }
                }
                cout << endl;
                if (auth.dangNhap(ten, mk, lanThu)) {
                    daDangNhap = true;
                    system("cls");
                    cout << "Dang nhap thanh cong!\n";
                    this_thread::sleep_for(chrono::milliseconds(600));
                }
                else if (lanThu >= 3) {
                    system("cls");
                    cout << "Nhap sai 3 lan. Tro ve menu chinh...\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                }
                break;
            }
            case 2: {
                string ten, mk;
                system("cls");
                cout << "--- DANG KY ---\n";
                cout << "Ten dang nhap: "; getline(cin >> ws, ten);
                cout << "Mat khau: "; getline(cin, mk);
                auth.dangKy(ten, mk, 1);
                this_thread::sleep_for(chrono::milliseconds(1000));
                break;
            }
            case 3:
                cout << "Thoat chuong trinh...\n";
                return 0;
            default: cout << "Lua chon khong hop le!\n";
        }
    } while (!daDangNhap);

    int chon;
    do {
        system("cls");
        cout << "\n";
        cout << "              Xin chao, " << auth.getNguoiDungHienTai()->getTenDangNhap() << "!\n";
        cout << "    ========================================\n";
        cout << "    1. Quan li sach\n";
        cout << "    2. Quan li doc gia\n";
        cout << "    3. Quan li hoa don\n";
        cout << "    4. Quan li nha xuat ban\n";
        cout << "    5. Thong ke\n";
        cout << "    6. Doi mat khau\n";
        if (auth.getNguoiDungHienTai()->getVaiTro() == 2) cout << "    7. Xoa tai khoan\n";
        cout << "    8. Dang xuat\n";
        cout << "    ----------------------------------------\n";
        cout << "    Lua chon: ";
        if (!(cin >> chon)) {
            cout << "Nhap sai! Vui long nhap so.\n";
            cin.clear(); cin.ignore(1000, '\n');
            continue; 
        }
        cin.ignore();

        switch (chon) {
            case 1: menuQuanLiSach(thuVien); break;
            case 2: menuQuanLiDocGia(thuVien); break;
            case 3: menuQuanLiHoaDon(thuVien); break;
            case 4: menuQuanLiNXB(thuVien); break;
            case 5: menuThongKe(thuVien); break;
            case 6: {
                string mkCu, mkMoi;
                char ch;
                system("cls");
                cout << "--- DOI MAT KHAU ---\n";
                cout << "Mat khau cu: ";
                while ((ch = _getch()) != '\r') {
                    if (ch == '\b' && !mkCu.empty()) { mkCu.pop_back(); cout << "\b \b"; }
                    else if (ch >= 32 && ch <= 126) { mkCu += ch; cout << '*'; }
                }
                cout << endl << "Mat khau moi: ";
                while ((ch = _getch()) != '\r') {
                    if (ch == '\b' && !mkMoi.empty()) { mkMoi.pop_back(); cout << "\b \b"; }
                    else if (ch >= 32 && ch <= 126) { mkMoi += ch; cout << '*'; }
                }
                cout << endl;
                auth.doiMatKhau(mkCu, mkMoi);
                this_thread::sleep_for(chrono::milliseconds(1000));
                break;
            }
            case 7: if (auth.getNguoiDungHienTai()->getVaiTro() == 2) {
                string tenXoa;
                system("cls");
                cout << "--- XOA TAI KHOAN ---\n";
                cout << "Nhap ten: "; getline(cin, tenXoa);
                auth.xoaTaiKhoan(tenXoa);
            } break;
            case 8:
                auth.dangXuat();
                cout << "\nDa dang xuat. Quay lai dang nhap...\n";
                break;
            default: cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 8);
    }

    return 0;
}