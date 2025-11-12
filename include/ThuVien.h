#ifndef THUVIEN_H
#define THUVIEN_H

#include "../include/Sach.h"
#include "../include/HoaDon.h"
#include "../include/DocGia.h"
#include "../include/Kho.h"

#include "../include/TheMuon.h"
#include "../include/NhaXuatBan.h"
#include "../include/Kho.h"
#include "../include/Date.h"
#include "../include/Auth.h"


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
protected:
    Sach danhSach[Max_sach];
    int soLuongTong;

    DocGia* danhSachDocGia[Max_docgia];
    int soDocGia;

    HoaDon danhSachHoaDon[Max_hoadon];
    int soHoaDon;

    NhaXuatBan* danhSachNXB[Max_NXB];
    int soNXB;
    
    Kho kho;
    Auth auth;
public:
    ThuVien();
    ~ThuVien();
    void loadDuLieu();
    void saveDuLieu();
//SACH
    void themSach();
    void hienThi();
    Sach* timSachTheoTen(const string& ten)const;
    void suaSachTheoTen();
    void timVaHienThiSach(const string& ten) const;
    void xoaSachTheoTen();
    Sach* timSachTheoMa(const string& maSach) const;
//DOCGIA
    bool themDocGia(DocGia* dg);
    void hienThiDanhSachDocGia() const;
    DocGia* timDocGiaTheoMa(const string& ma) const;  
    bool suaThongTinDocGia(const string& maDocGia);
    bool xoaDocGia(const string& maDocGia);
    DocGia* timDocGiaTheoMaThe(const string& maThe) const;
    void capNhatTheMuonChoDocGia(const string& maDocGia, TheMuon* the);
    int getSoDocGia() const { return soDocGia; };
    DocGia** getDanhSachDocGia() { return danhSachDocGia; };
//HD 
    void themHoaDon(const HoaDon& hd);
    void hienThiDanhSachHoaDon() const;
    void tinhTienPhatQuaHan(const string& maDocGia, const Date& ngayHienTai);
    void capNhatHoaDonDaTra(const string& maHD, const Date& ngayTra);
//NXB
    bool themNXB(const string& tenNXB);
    void hienThiDanhSachNXB() const;
    NhaXuatBan* timNXBTheoTen(const string& tenNXB) const;
    void themSachVaoNXB(const string& maSach, const string& tenNXB);
    void suaNXB(const string& tenCu, const string& tenMoi);
    void xoaNXB(const string& ten);
//TK
    void thongKeMuonTra(const Date& ngayHienTai) const;   
    double tongTienPhat() const;                          

//KHO
    void hienThiKho() const { kho.HienThiKho();}
    Kho& getKho() { return kho;}
//AUTH
    Auth& getAuth() { return auth; }
    const Auth& getAuth() const { return auth; }
};
#endif
