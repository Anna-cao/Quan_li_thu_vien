#ifndef THEMUON_H
#define THEMUON_H

#include <iostream>
#include <string>
#include "Date.h"    
using namespace std;

class TheMuon 
{
private:
    string maThe;
    string maDocGia;
    Date ngLapThe;
    Date HSD;
    int gioiHanMuon;
    bool status;  
public:
    TheMuon();
    TheMuon(string maThe, string maDocGia, Date ngLapThe, Date HSD, int gioiHanMuon, bool status);

    string getMaThe() const;
    string getMaDocGia() const;
    int getGioiHanMuon() const;
    bool getStatus() const;
    void setGioiHanMuon(int g);
    void setStatus(bool t);

    bool kiemTraHieuLuc(const Date& ngayHienTai) const;

    Date getNgayLap() const { return ngLapThe; }
    Date getHSD() const { return HSD; }

    void nhap();  
    friend ostream& operator<<(ostream& out, const TheMuon& tm);
    static int docFileTheMuon(TheMuon danhSach[], int soLuongToiDa, const std::string& duongDan = "data/themuon.txt");
    static void ghiFileTheMuon(const TheMuon danhSach[], int soLuong, const std::string& duongDan = "data/themuon.txt");
};

#endif
