#ifndef THUVIEN_H
#define THUVIEN_H

#include "../include/Sach.h"
#include "../include/HoaDon.h"
#include "../include/DocGia.h"
#include "../include/HoaDonBan.h"
#include "../include/TheMuon.h"
#include "../include/NhaXuatBan.h"
#include "../include/Date.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define Max_sach 200
#define Max_docgia 200
#define Max_hoadon 200
#define Max_hoadonban 200
#define Max_NXB 200
class ThuVien {
private:
    Sach danhSach[Max_sach];
    int n;

    DocGia* danhSachDocGia[Max_docgia];
    int soDocGia;

    HoaDon danhSachHoaDon[Max_hoadon];
    int soHoaDon;

    HoaDonBan danhSachHoaDonBan[Max_hoadonban];
    int soHoaDonBan;

    NhaXuatBan* danhSachNXB[Max_NXB];
    int soNXB;

public:
    ThuVien();
    ~ThuVien();
//SACH
    void themSach();
    void hienThi();
    void timTheoTen(const string& ten);
    void suaSachTheoMa(const string& ma);
    void xoaSachTheoMa(const string& ma);
//DOCGIA
    bool themDocGia(DocGia* dg);
    void hienThiDanhSachDocGia() const;
    DocGia* timDocGiaTheoMa(const string& ma) const;
    void capNhatTheMuonChoDocGia(const string& maDocGia, TheMuon* the);
    bool suaThongTinDocGia(const std::string& maDocGia);
    bool xoaDocGia(const std::string& maDocGia);
//HD MUON
    void themHoaDon(const HoaDon& hd);
    void hienThiDanhSachHoaDon() const;
    void tinhTienPhatQuaHan(const string& maDocGia, const Date& ngayHienTai);
//HD BAN
    void themHoaDonBan(const HoaDonBan& hdb);
    void hienThiDanhSachHoaDonBan() const;
//NXB
    bool themNXB(const string& tenNXB);
    void hienThiDanhSachNXB() const;
    NhaXuatBan* timNXBTheoTen(const string& tenNXB) const;
    void themSachVaoNXB(const string& maSach, const string& tenNXB);
    void suaNXB(const string& tenCu, const string& tenMoi);
    void xoaNXB(const string& ten);
//TK
    void thongKeMuonTra(const Date& ngayHienTai) const;
    void thongKeSachTheoNXB() const;
    void thongKeDoanhThu(const Date& tu, const Date& den) const;
    void thongKeSachBanChay(int topN = 5) const;
    double tongTienPhat() const;
};

#endif
