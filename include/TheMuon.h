#ifndef THEMUON_H
#define THEMUON_H

#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"   
using namespace std;

enum LoaiThe {
    THE_THUONG,
    THE_HOI_VIEN
};

class TheMuon {
private:
    string maThe;          
    string tenDocGia;      
    LoaiThe loaiThe;       
    double phiDangKy;     
    string status;         
    int gioiHanMuon;       
    Date ngayLapThe;       
    Date hanSuDung;        

    static int demThuong;  
    static int demHoiVien; 

    string taoMaThe(LoaiThe loai); 

public:
    
    TheMuon();
    TheMuon(string ten, LoaiThe loai);

    
    string getMaThe() const;
    string getTenDocGia() const;
    LoaiThe getLoaiThe() const;
    double getPhiDangKy() const;
    string getStatus() const;
    int getGioiHanMuon() const;
    Date getNgayLapThe() const;
    Date getHanSuDung() const;

    
    void setTenDocGia(string ten);
    void setLoaiThe(LoaiThe loai);
    void setStatus(string st);
    void setGioiHanMuon(int g);
    void setNgayLapThe(const Date& ngay);
    void setHanSuDung(const Date& han);

    
    void nhap();
    void xuat() const;

<<<<<<< Updated upstream
    friend istream& operator>>(istream& in, TheMuon& tm);
    friend ostream& operator<<(ostream& out, const TheMuon& tm);
=======
    
    void ghiFile(ofstream& file) const;
    bool docFile(ifstream& file);
>>>>>>> Stashed changes
};

#endif

