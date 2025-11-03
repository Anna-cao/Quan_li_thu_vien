#ifndef THUVIEN_H
#define THUVIEN_H

#include "Sach.h"
#include "HoaDon.h"
#include "DocGia.h"
#include "TheMuon.h"

#include <string>
using namespace std;

#define Max_sach 200
#define Max_docgia  200
#define Max_hoadon 200

class ThuVien {
private:
    Sach danhSach[Max_sach];
    int n;

    DocGia* danhSachDocGia[Max_docgia];
    int soDocGia;
    
    HoaDon danhSachHoaDon[Max_hoadon];
    int soHoaDon;
public:
    ThuVien(); 
    ~ThuVien();
    //QLDSS
    void hienThi();
    void themSach();
    void timTheoTen(string ten);
    void suaSachTheoMa(string ma);
    void xoaSachTheoMa(string ma);
    //QLDSDG
    void themDocGia(DocGia* dg);
    void hienThiDanhSachDocGia() const;
    DocGia* timDocGiaTheoMa(const string& ma) const;
    void capNhatTheMuonChoDocGia(const string& maDocGia, TheMuon* the);
    //QL muon/tra sach
    bool muonSach(const string& maDocGia, const string& maSach, const Date& ngayMuon);
    bool traSach(const string& maDocGia, const string& maSach, const Date& ngayTra);
    //QL HD
    void themHoaDon(const HoaDon& hd);
    void hienThiDanhSachHoaDon() const;
    void tinhTienPhatQuaHan(const string& maDocGia, const Date& ngayHienTai);
    //TK&TK
    void thongKeSachDangMuon() const;
    void thongKeDocGiaQuaHan() const;
};

#endif