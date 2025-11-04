#ifndef THUVIEN_H
#define THUVIEN_H

#include "Sach.h"
#include "HoaDon.h"
#include "DocGia.h"
#include "TheMuon.h"
#include "NhaXuatBan.h"
#include <fstream>
#include <sstream>

#define Max_sach 200
#define Max_docgia 200
#define Max_hoadon 200
#define Max_NXB 200

class ThuVien {
private:
    Sach danhSach[Max_sach];
    int n;
    DocGia* danhSachDocGia[Max_docgia];
    int soDocGia;
    HoaDon danhSachHoaDon[Max_hoadon];
    int soHoaDon;
    NhaXuatBan* danhSachNXB[Max_NXB];
    int soNXB;
public:
    ThuVien();
    ~ThuVien();
    // QL SÁCH
    void hienThi();
    void themSach();
    void timTheoTen(string ten);
    void suaSachTheoMa(string ma);
    void xoaSachTheoMa(string ma);
    // QL DG
    bool themDocGia(DocGia* dg);
    void hienThiDanhSachDocGia() const;
    DocGia* timDocGiaTheoMa(const string& ma) const;
    void capNhatTheMuonChoDocGia(const string& maDocGia, TheMuon* the);
    // QLHD
    void themHoaDon(const HoaDon& hd);
    void hienThiDanhSachHoaDon() const;
    void tinhTienPhatQuaHan(const string& maDocGia, const Date& ngayHienTai);
    // TK
    void thongKeMuonTra(const Date& ngayHienTai) const;
    void thongKeSachTheoNXB() const;
    // QL NXB
    bool themNXB(const string& tenNXB);
    void hienThiDanhSachNXB() const;
    NhaXuatBan* timNXBTheoTen(const string& tenNXB) const;
    void themSachVaoNXB(const string& maSach, const string& tenNXB);

};
#endif
