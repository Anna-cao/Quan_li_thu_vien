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

void pauseAndClear() {
    cout << "\nNhan Enter de tiep tuc...";
    cin.get();
    cin.clear();
    cin.ignore(10000, '\n');
}

int main() {
    Auth auth;
    auth.docFile("data/auth.txt");

    if (auth.getSoNguoiDung() == 0) {
        auth.dangKy("admin", "123456", 2);
        cout << "Da tao tai khoan Admin mac dinh: admin / 123456\n";
        pauseAndClear();
    }

    ThuVien thuVien;
    thuVien.loadDuLieu();

    while (true) {
        int luaChon, lanThu = 0;
        bool daDangNhap = false;

        do {
            system("cls");
            cout << "========================================\n";
            cout << "     HE THONG QUAN LY THU VIEN          \n";
            cout << "========================================\n";
            cout << "1. Dang nhap\n";
            cout << "2. Dang ky tai khoan\n";
            cout << "3. Thoat chuong trinh\n";
            cout << "----------------------------------------\n";
            cout << "Chon: ";
            cin >> luaChon; cin.ignore();

            if (luaChon == 1) {
                string ten, mk = "";
                char ch;
                system("cls");
                cout << "--- DANG NHAP ---\n";
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
                } else if (lanThu >= 3) {
                    cout << "\nBan da nhap sai 3 lan. Tro ve menu chinh...\n";
                    pauseAndClear();
                } else {
                    cout << "\nSai thong tin. Vui long thu lai!\n";
                    pauseAndClear();
                }

            } else if (luaChon == 2) {
                string ten, mk1, mk2;
                system("cls");
                cout << "--- DANG KY TAI KHOAN MOI ---\n";
                cout << "Ten dang nhap: "; getline(cin, ten);
                do {
                    cout << "Mat khau: "; mk1 = "";
                    char ch;
                    while ((ch = _getch()) != '\r') {
                        if (ch == '\b' && !mk1.empty()) { mk1.pop_back(); cout << "\b \b"; }
                        else if (ch >= 32 && ch <= 126) { mk1 += ch; cout << '*'; }
                    }
                    cout << endl << "Nhap lai mat khau: "; mk2 = "";
                    while ((ch = _getch()) != '\r') {
                        if (ch == '\b' && !mk2.empty()) { mk2.pop_back(); cout << "\b \b"; }
                        else if (ch >= 32 && ch <= 126) { mk2 += ch; cout << '*'; }
                    }
                    cout << endl;
                    if (mk1 != mk2) cout << "Mat khau khong khop!\n";
                } while (mk1 != mk2);

                auth.dangKy(ten, mk1, 0);
                cout << "\nDang ky thanh cong!\n";
                pauseAndClear();

            } else if (luaChon == 3) {
                cout << "\nDang luu du lieu...\n";
                thuVien.saveDuLieu();
                auth.luuFile();
                cout << "Cam on ban da su dung he thong!\n";
                return 0;
            }

        } while (!daDangNhap);

        int chon;
        do {
            system("cls");
            int role = auth.getNguoiDungHienTai()->getVaiTro();
            string loai = (role == 2) ? "ADMIN" : (role == 1) ? "THU THU" : "DOC GIA";

            cout << "========================================\n";
            cout << "     MENU CHINH (" << loai << ")           \n";
            cout << "========================================\n";
            cout << "1. Quan li sach\n";
            cout << "2. Quan li doc gia\n";
            cout << "3. Quan li hoa don\n";
            cout << "4. Quan li nha xuat ban\n";
            cout << "5. Thong ke\n";
            cout << "6. Doi mat khau\n";
            if (role == 2) cout << "7. Xoa tai khoan\n";
            cout << "8. Dang xuat\n";
            cout << "----------------------------------------\n";
            cout << "Chon: ";
            cin >> chon; cin.ignore();

            switch (chon) {
                case 1: menuQuanLiSach(thuVien); break;
                case 2: menuQuanLiDocGia(thuVien); break;
                case 3: menuQuanLiHoaDon(thuVien); break;
                case 4: menuQuanLiNXB(thuVien); break;
                case 5: menuThongKe(thuVien); break;
                case 6: {
                    string mkCu, mkMoi;
                    system("cls");
                    cout << "--- DOI MAT KHAU ---\n";
                    cout << "Mat khau cu: ";
                    char ch;
                    while ((ch = _getch()) != '\r') {
                        if (ch >= 32 && ch <= 126) { mkCu += ch; cout << '*'; }
                        else if (ch == '\b' && !mkCu.empty()) { mkCu.pop_back(); cout << "\b \b"; }
                    }
                    cout << endl << "Mat khau moi: ";
                    while ((ch = _getch()) != '\r') {
                        if (ch >= 32 && ch <= 126) { mkMoi += ch; cout << '*'; }
                        else if (ch == '\b' && !mkMoi.empty()) { mkMoi.pop_back(); cout << "\b \b"; }
                    }
                    cout << endl;
                    auth.doiMatKhau(mkCu, mkMoi);
                    pauseAndClear();
                    break;
                }
                case 7: if (role == 2) {
                    string tenXoa;
                    system("cls");
                    cout << "--- XOA TAI KHOAN ---\n";
                    cout << "Nhap ten: "; getline(cin, tenXoa);
                    auth.xoaTaiKhoan(tenXoa);
                    pauseAndClear();
                } break;
                case 8:
                    auth.dangXuat();
                    cout << "\nDa dang xuat. Quay lai dang nhap...\n";
                    pauseAndClear();
                    break;
                default:
                    cout << "Lua chon khong hop le!\n";
                    pauseAndClear();
                    break;
            }
        } while (chon != 8);
    }

    return 0;
}