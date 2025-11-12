#include "../include/ThuVien.h"
#include "../include/NhaXuatBan.h"
#include "../include/DocGia.h"
#include "../include/Kho.h"
#include "../include/DocGiaThuong.h"
#include "../include/HoiVien.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <type_traits>
using namespace std;
string nhapNXBHopLe(ThuVien& tv) {
    string ten;
    while (true) {
        cout << "Nhap NXB (0 de huy): ";
        getline(cin >> ws, ten); 
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
ThuVien::ThuVien() {
    soLuongTong = 0;
    soDocGia = 0;
    soHoaDon = 0;
    soNXB = 0; 
    for (int i = 0; i < Max_NXB; ++i) {
        danhSachNXB[i] = nullptr;
    }
}
ThuVien::~ThuVien() {
    for (int i = 0; i < soDocGia; ++i) delete danhSachDocGia[i];
    for (int i = 0; i < soNXB; ++i) delete danhSachNXB[i];
}
void ThuVien::loadDuLieu() {
    const string path = "data/";
    system("mkdir data 2>nul"); 
    auth.docFile(path + "auth.txt");
    kho.docFileKho(path + "Kho.txt"); 
    soNXB = NhaXuatBan::docFileNXB(danhSachNXB, Max_NXB, path + "nhaxuatban.txt");
    soLuongTong = Sach::docFileSach(danhSach, Max_sach, path + "sach.txt");
    soHoaDon = HoaDon::docFileHoaDon(danhSachHoaDon, Max_hoadon, path + "hoadon.txt");
    soDocGia = 0;
    int nThuong = DocGia::docFileDocGiaThuong(danhSachDocGia, Max_docgia, "data/DocGiaThuong.txt");
    soDocGia += nThuong;
    int nHoiVien = DocGia::docFileHoiVien(danhSachDocGia + soDocGia, Max_docgia - soDocGia, "data/HoiVien.txt");
    soDocGia += nHoiVien;
}
void ThuVien::saveDuLieu() {
    const string path = "data/";
    system("mkdir data 2>nul");
    DocGia::ghiFileDocGiaThuong((const DocGia**)danhSachDocGia, soDocGia, "data/DocGiaThuong.txt");
    DocGia::ghiFileHoiVien((const DocGia**)danhSachDocGia, soDocGia, "data/HoiVien.txt");
    User::ghiFileUser(auth.getDanhSach(), auth.getSoNguoiDung(), path + "auth.txt");
    kho.ghiFileKho(path + "Kho.txt");
    NhaXuatBan::ghiFileNXB(danhSachNXB, soNXB, path + "nhaxuatban.txt");
    Sach::ghiFileSach(danhSach, soLuongTong, path + "sach.txt");
    vector<const DocGia*> thuong;
    vector<const DocGia*> hoivien;
    for (int i = 0; i < soDocGia; ++i) {
        const DocGia* dg = danhSachDocGia[i];
        if (!dg || dg->getStatus() == 0) continue;

        if (dg->getLoaiDocGia() == "Doc Gia Thuong" || dg->getLoaiDocGia() == "DocGiaThuong")
            thuong.push_back(dg);
        else if (dg->getLoaiDocGia() == "HoiVien" || dg->getLoaiDocGia() == "Hoi Vien")
            hoivien.push_back(dg);
    }
    if (!thuong.empty())
        DocGia::ghiFileDocGiaThuong(thuong.data(), thuong.size(), "data/DocGiaThuong.txt");
    if (!hoivien.empty())
        DocGia::ghiFileHoiVien(hoivien.data(), hoivien.size(), "data/HoiVien.txt");
}


