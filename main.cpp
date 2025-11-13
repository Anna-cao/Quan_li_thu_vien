#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtemplate-body"
#pragma GCC diagnostic pop

#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <string>
#include <iomanip>
#include "../include/auth.h"
#include "../include/ThuVien.h"
#include "../include/menu/QLSach.h"
#include "../include/menu/QLDocGia.h"
#include "../include/menu/QLHoaDon.h"
#include "../include/menu/QLNXB.h"
#include "../include/menu/ThongKe.h"

using namespace std;

// ----------------- MENU ADMIN -----------------
void menuAdmin(ThuVien &thuVien, Auth &auth) {
    int chon;
    do {
        system("cls");
        cout << "\nXin chao, " << auth.getNguoiDungHienTai()->getTenDangNhap() << " (Admin)!\n";
        cout << "=========== QUAN LY THU VIEN ===========\n";
        cout << "1. Quan li sach\n";
        cout << "2. Quan li doc gia\n";
        cout << "3. Quan li hoa don\n";
        cout << "4. Quan li nha xuat ban\n";
        cout << "5. Thong ke\n";
        cout << "6. Doi mat khau\n";
        cout << "7. Xoa tai khoan\n";
        cout << "8. Dang xuat\n";
        cout << "----------------------------------------\n";
        cout << "Lua chon: ";

        if (!(cin >> chon)) { cin.clear(); cin.ignore(1000,'\n'); continue; }
        cin.ignore();

        switch(chon) {
            case 1: menuQuanLiSach(thuVien); break;
            case 2: menuQuanLiDocGia(thuVien); break;
            case 3: menuQuanLiHoaDon(thuVien); break;
            case 4: menuQuanLiNXB(thuVien); break;
            case 5: menuThongKe(thuVien); break;
            case 6: {
                string mkCu, mkMoi; char ch;
                system("cls");
                cout << "--- DOI MAT KHAU ---\n";
                cout << "Mat khau cu: ";
                mkCu = "";
                while ((ch = _getch()) != '\r') {
                    if (ch == '\b' && !mkCu.empty()) { mkCu.pop_back(); cout << "\b \b"; }
                    else if (ch >= 32 && ch <= 126) { mkCu += ch; cout << '*'; }
                }
                cout << "\nMat khau moi: ";
                mkMoi = "";
                while ((ch = _getch()) != '\r') {
                    if (ch == '\b' && !mkMoi.empty()) { mkMoi.pop_back(); cout << "\b \b"; }
                    else if (ch >= 32 && ch <= 126) { mkMoi += ch; cout << '*'; }
                }
                cout << endl;
                auth.doiMatKhau(mkCu, mkMoi);
                this_thread::sleep_for(chrono::milliseconds(1000));
                break;
            }
            case 7: {
                string tenXoa;
                system("cls");
                cout << "--- XOA TAI KHOAN ---\n";
                cout << "Nhap ten dang nhap can xoa: ";
                getline(cin, tenXoa);
                auth.xoaTaiKhoan(tenXoa);
                cout << "\nNhan phim bat ky de quay lai...";
                _getch();
                break;
            }
            case 8: auth.dangXuat(); break;
            default: cout << "Lua chon khong hop le!\n";
                     this_thread::sleep_for(chrono::milliseconds(800));
        }
    } while (chon != 8);
}

// ----------------- MENU THU THU -----------------
void menuThuThu(ThuVien &thuVien, Auth &auth) {
    int chon;
    do {
        system("cls");
        cout << "\nXin chao, " << auth.getNguoiDungHienTai()->getTenDangNhap() << " (Thu Thu)!\n";
        cout << "=========== QUAN LY THU VIEN ===========\n";
        cout << "1. Quan li sach\n";
        cout << "2. Quan li doc gia\n";
        cout << "3. Quan li hoa don\n";
        cout << "4. Quan li nha xuat ban\n";
        cout << "5. Thong ke\n";
        cout << "6. Doi mat khau\n";
        cout << "7. Dang xuat\n";
        cout << "----------------------------------------\n";
        cout << "Lua chon: ";

        if (!(cin >> chon)) { cin.clear(); cin.ignore(1000,'\n'); continue; }
        cin.ignore();

        switch(chon) {
            case 1: menuQuanLiSach(thuVien); break;
            case 2: menuQuanLiDocGia(thuVien); break;
            case 3: menuQuanLiHoaDon(thuVien); break;
            case 4: menuQuanLiNXB(thuVien); break;
            case 5: menuThongKe(thuVien); break;
            case 6: {
                string mkCu, mkMoi; char ch;
                system("cls");
                cout << "--- DOI MAT KHAU ---\n";
                cout << "Mat khau cu: ";
                mkCu = "";
                while ((ch = _getch()) != '\r') {
                    if (ch == '\b' && !mkCu.empty()) { mkCu.pop_back(); cout << "\b \b"; }
                    else if (ch >= 32 && ch <= 126) { mkCu += ch; cout << '*'; }
                }
                cout << "\nMat khau moi: ";
                mkMoi = "";
                while ((ch = _getch()) != '\r') {
                    if (ch == '\b' && !mkMoi.empty()) { mkMoi.pop_back(); cout << "\b \b"; }
                    else if (ch >= 32 && ch <= 126) { mkMoi += ch; cout << '*'; }
                }
                cout << endl;
                auth.doiMatKhau(mkCu, mkMoi);
                this_thread::sleep_for(chrono::milliseconds(1000));
                break;
            }
            case 7: auth.dangXuat(); break;
            default: cout << "Lua chon khong hop le!\n";
                     this_thread::sleep_for(chrono::milliseconds(800));
        }
    } while (chon != 7);
}

// ----------------- XEM SÁCH + CHI TIẾT -----------------
void xemSachVaChiTiet(ThuVien &thuVien) {
    string maSach;
    while (true) {
        system("cls");
        cout << "\n--- DANH SACH SACH ---\n";
        thuVien.xemTatCaSach();

        cout << "\nNhap ma sach de xem chi tiet (0 de quay lai): ";
        getline(cin, maSach);
        if (maSach == "0") return;

        system("cls");
        cout << "\n--- CHI TIET SACH ---\n";
        if (!thuVien.xemChiTietSach(maSach)) {
            cout << "Khong tim thay sach voi ma nay!\n";
        }
        cout << "\nNhan phim bat ky de tiep tuc...";
        _getch();
    }
}

// ----------------- MENU BAN DOC -----------------
void menuBanDoc(ThuVien &thuVien, Auth &auth) {
    int chon;
    do {
        system("cls");
        cout << "\nXin chao, " << auth.getNguoiDungHienTai()->getTenDangNhap() << " (Ban Doc)!\n";
        cout << "=========== QUAN LY THU VIEN ===========\n";
        cout << "1. Xem danh sach sach\n";
        cout << "2. Thong ke\n";
        cout << "3. Doi mat khau\n";
        cout << "4. Dang xuat\n";
        cout << "----------------------------------------\n";
        cout << "Lua chon: ";

        if (!(cin >> chon)) { cin.clear(); cin.ignore(1000,'\n'); continue; }
        cin.ignore();

        switch(chon) {
            case 1: xemSachVaChiTiet(thuVien); break;
            case 2: menuThongKe(thuVien); break;
            case 3: {
                string mkCu, mkMoi; char ch;
                system("cls");
                cout << "--- DOI MAT KHAU ---\n";
                cout << "Mat khau cu: ";
                mkCu = "";
                while ((ch = _getch()) != '\r') {
                    if (ch == '\b' && !mkCu.empty()) { mkCu.pop_back(); cout << "\b \b"; }
                    else if (ch >= 32 && ch <= 126) { mkCu += ch; cout << '*'; }
                }
                cout << "\nMat khau moi: ";
                mkMoi = "";
                while ((ch = _getch()) != '\r') {
                    if (ch == '\b' && !mkMoi.empty()) { mkMoi.pop_back(); cout << "\b \b"; }
                    else if (ch >= 32 && ch <= 126) { mkMoi += ch; cout << '*'; }
                }
                cout << endl;
                auth.doiMatKhau(mkCu, mkMoi);
                this_thread::sleep_for(chrono::milliseconds(1000));
                break;
            }
            case 4: auth.dangXuat(); break;
            default: cout << "Lua chon khong hop le!\n";
                     this_thread::sleep_for(chrono::milliseconds(800));
        }
    } while (chon != 4);
}

// ----------------- MAIN -----------------
int main() {
    Auth auth;
    auth.docFile("data/auth.txt");

    if (auth.getSoNguoiDung() == 0) {
        auth.dangKy("admin", "123456", 2);
        cout << "Da tao tai khoan Admin mac dinh: admin / 123456\n";
        this_thread::sleep_for(chrono::milliseconds(1500));
    }

    ThuVien thuVien;
    thuVien.loadDuLieu();

    while (true) {
        int luaChon;
        int lanThu = 0;
        bool daDangNhap = false;

        do {
            system("cls");
            cout << "\nHE THONG QUAN LY THU VIEN\n";
            cout << "------------------------\n";
            cout << "1. Dang nhap\n";
            cout << "2. Dang ky tai khoan\n";
            cout << "3. Thoat chuong trinh\n";
            cout << "------------------------\n";
            cout << "Lua chon: ";

            if (!(cin >> luaChon)) { cin.clear(); cin.ignore(1000,'\n'); continue; }
            cin.ignore();

            switch(luaChon) {
                case 1: {
                    string ten, mk = "";
                    char ch;
                    system("cls");
                    cout << "--- DANG NHAP ---\n";
                    if (lanThu > 0) cout << "Con " << (3 - lanThu) << " lan thu.\n";
                    cout << "Ten dang nhap: ";
                    getline(cin, ten);
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
                    } else {
                        lanThu++;
                        if (lanThu >= 3) {
                            system("cls");
                            cout << "Nhap sai 3 lan. Tro ve menu chinh...\n";
                            this_thread::sleep_for(chrono::milliseconds(1500));
                            break;
                        } else {
                            cout << "Sai ten dang nhap hoac mat khau!\n";
                            this_thread::sleep_for(chrono::milliseconds(1000));
                        }
                    }
                    break;
                }
                case 2: {
                    string ten, mk = "";
                    char ch;
                    system("cls");
                    cout << "--- DANG KY ---\n";
                    cout << "Ten dang nhap: ";
                    getline(cin, ten);
                    cout << "Mat khau: ";
                    while ((ch = _getch()) != '\r') {
                        if (ch == '\b' && !mk.empty()) { mk.pop_back(); cout << "\b \b"; }
                        else if (ch >= 32 && ch <= 126) { mk += ch; cout << '*'; }
                    }
                    cout << endl;
                    if (auth.dangKy(ten, mk, 0)) {
                        cout << "Dang ky thanh cong! Vui long dang nhap.\n";
                    } else {
                        cout << "Ten dang nhap da ton tai!\n";
                    }
                    this_thread::sleep_for(chrono::milliseconds(1200));
                    break;
                }
                case 3:
                    cout << "Tam biet!\n";
                    this_thread::sleep_for(chrono::milliseconds(800));
                    return 0;
                default:
                    cout << "Lua chon khong hop le!\n";
                    this_thread::sleep_for(chrono::milliseconds(800));
            }
        } while (!daDangNhap && lanThu < 3);

        if (!daDangNhap) continue;

        int role = auth.getNguoiDungHienTai()->getVaiTro();
        if (role == 2) menuAdmin(thuVien, auth);
        else if (role == 1) menuThuThu(thuVien, auth);
        else menuBanDoc(thuVien, auth);
    }

    return 0;
}