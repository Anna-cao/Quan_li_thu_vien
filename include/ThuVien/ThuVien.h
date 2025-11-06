#ifndef THUVIEN_H #define THUVIEN_H
#include "Sach.h" 
#include "HoaDon.h" 
#include "DocGia.h" 
#include "HoaDonBan.h" 
#include "TheMuon.h" 
#include "NhaXuatBan.h"
#include<iostream>
#include<string>

#define Max_docgia 200 
#define Max_hoadon 200 
#define Max_NXB 200 
#define Max_hoadonban 200
class ThuVien { 
    private: 
    double tongTienPhat() const; 
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
public: ThuVien(); ~ThuVien(); 
// QL Sach 
void hienThi(); 
void themSach(); 
void timTheoTen(const string& ten);
void suaSachTheoMa(string ma); 
void xoaSachTheoMa(string ma); 
// QL DG 
bool themDocGia(DocGia* dg); 
void hienThiDanhSachDocGia() const;
 bool suaThongTinDocGia(const string& maDocGia); 
 bool xoaDocGia(const string& maDocGia); 
 DocGia* timDocGiaTheoMa(const string& ma) const; 
 void suaDocGia(const string& ma, const DocGia& dgMoi); 
 void capNhatTheMuonChoDocGia(const string& maDocGia, TheMuon* the); 
 // QLHD 
 void themHoaDon(const HoaDon& hd); 
 void hienThiDanhSachHoaDon() const; 
 void tinhTienPhatQuaHan(const string& maDocGia, const Date& ngayHienTai); 
 void themHoaDonBan(const HoaDonBan& hdb); void hienThiDanhSachHoaDonBan() const;
// TK
void thongKeMuonTra(const Date& ngayHienTai) const;
void thongKeSachTheoNXB() const;
void thongKeDoanhThu(const Date& tu, const Date& den) const;
void thongKeSachBanChay() const;
double tongTienPhat();
// QL NXB
bool themNXB(const string& tenNXB);
void hienThiDanhSachNXB() const;
NhaXuatBan* timNXBTheoTen(const string& tenNXB) const;
void themSachVaoNXB(const string& maSach, const string& tenNXB);
void suaNXB(const string& tenCu, const string& tenMoi);
void xoaNXB(const string& ten);


}; 
#endif
