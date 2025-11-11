#ifndef DOCGIA_H
#define DOCGIA_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "TheMuon.h"

using namespace std;

class DocGia {
protected:
    static int autoID_Thuong;
    static int autoID_HoiVien;
    string maDocGia;
    string hoTen;
    string sdt;
    string email;
    string diachi;
    Date ngayLapThe;
    int soLuotMuon;
    vector<string> dsMaSachDangMuon;
    TheMuon* theMuon;  
    int status;
public:
    DocGia();                                           
    DocGia(string ten, string loai);                   
    DocGia(string ma, string ten, int soLuotMuon);     
    virtual ~DocGia();
    void nhapThongTinChung();
    string getMaDocGia() const { return maDocGia; }
    string getHoTen() const { return hoTen; }
    int getSoLuotMuon() const { return soLuotMuon; }
    TheMuon* getTheMuon() const { return theMuon; }
    const vector<string>& getDsMaSachDangMuon() const { return dsMaSachDangMuon; }
    int getStatus() const { return status; }
    virtual string getLoaiDocGia() const { return "Doc Gia Thuong"; } 
    void setTheMuon(TheMuon* tm){delete theMuon; theMuon = tm;};
    void setDsMaSachDangMuon(const vector<string>& ds) { dsMaSachDangMuon = ds; }
    void setSoLuotMuon(int s) { soLuotMuon = s; }
    void setStatus(int s) { status = s; }
    
    static string nhapMaDocGia(const string& msg);
    virtual void hienThiThongTin() const;
    void hienThiDong() const;
    static void hienThiTieuDe();

    bool muonSach(const string& maSach, const Date& ngayHienTai);
    void traSach(const string& maSach);
    void suaDocGia(const string& ma);
    void capNhatTheMuon();

    static bool kiemTraNgayHopLe(const Date& d);

    virtual void docFile(istream& in);
    virtual void ghiFile(ostream& out) const;
    static void ghiFileDocGiaThuong(const DocGia* ds[], int n, const string& file);
    static void ghiFileHoiVien(const DocGia* ds[], int n, const string& file);
    static int docFileDocGiaThuong(DocGia* ds[], int soLuongToiDa, const string& duongDan);
    static int docFileHoiVien(DocGia* ds[], int soLuongToiDa, const string& duongDan);
    static void capNhatAutoIDTuMa(const string& ma, bool isHoiVien);
};
#endif