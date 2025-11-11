#include "../include/ThuVien.h"
#include "../include/NhaXuatBan.h"

#include "../include/Kho.h"

#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

ThuVien::ThuVien() {
    soLuongTong = 0;
    soDocGia = 0;
    soHoaDon = 0;
    soNXB = 0; 
    for (int i = 0; i < Max_NXB; ++i) {
        danhSachNXB[i] = nullptr;
    }
}
string nhapNXBHopLe(ThuVien& tv) {
    string ten;
    while (true) {
        cout << "Nhap NXB (0 de huy): ";
        getline(cin, ten);
        if (ten == "0") {
            cout << "Huy thao tac.\n";
            return "";
        }
        if (tv.timNXBTheoTen(ten) != nullptr) {
            return ten;
        }
        cout << "NXB '" << ten << "' KHONG TON TAI! Nhap lai:\n";
    }
}

ThuVien::~ThuVien() {
    for (int i = 0; i < soDocGia; i++) delete danhSachDocGia[i];
    for (int i = 0; i < soNXB; i++) delete danhSachNXB[i];
}
void ThuVien::loadDuLieu() {
    const string path = "data/";
    system("mkdir data 2>nul"); 
    auth.docFile(path + "auth.txt");
    kho.docFileKho(path + "Kho.txt"); 
    soNXB = NhaXuatBan::docFileNXB(danhSachNXB, Max_NXB, path + "nhaxuatban.txt");
    soLuongTong = Sach::docFileSach(danhSach, Max_sach, path + "sach.txt");
    soHoaDon = HoaDon::docFileHoaDon(danhSachHoaDon, Max_hoadon, path + "hoadon.txt");
    soDocGia = DocGia::docFileDocGia(danhSachDocGia, Max_docgia, path + "docgia.txt");
}

void ThuVien::saveDuLieu() {
    const string path = "data/";
    system("mkdir data 2>nul");
    User::ghiFileUser(auth.getDanhSach(), auth.getSoNguoiDung(), path + "auth.txt");
    kho.ghiFileKho(path + "kho.txt");
    NhaXuatBan::ghiFileNXB(danhSachNXB, soNXB, path + "nxb.txt");
    Sach::ghiFileSach(danhSach, soLuongTong, path + "sach.txt");
    HoaDon::ghiFileHoaDon(danhSachHoaDon, soHoaDon, path + "hoadon.txt");
    DocGia::ghiFileDocGia((const DocGia**)danhSachDocGia, soDocGia, path + "docgia.txt");
}