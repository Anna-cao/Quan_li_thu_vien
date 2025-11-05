#ifndef DOCGIA_H
#define DOCGIA_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "TheMuon.h"
using namespace std;

class DocGia 
{
protected:
    string maDocGia;                    
    string hoTen;                       
    int soLuotMuon;                     
    vector<string> dsMaSachDangMuon;    
    TheMuon* theMuon;                   

public:
    DocGia();
    DocGia(string ma, string ten, int soLuotMuon = 0);
    DocGia(string ma, string ten, TheMuon* tm);
    virtual ~DocGia();  

    string getMaDocGia() const;
    string getHoTen() const;
    int getSoLuotMuon() const;
    TheMuon* getTheMuon() const;
    void setTheMuon(TheMuon* tm);
    const vector<string>& getDsMaSachDangMuon() const;

    virtual bool muonSach(const string& maSach, const Date& ngayHienTai);   
    virtual void traSach(const string& maSach);    
    virtual void hienThiThongTin() const;          
    virtual void nhap();

    // ==== THÊM PHẦN NÀY ====
    bool ghiFile(ofstream& out) const;   // Ghi 1 dòng CSV
    bool docFile(ifstream& in);          // Đọc 1 dòng CSV

    friend istream& operator>>(istream& in, DocGia& dg);
    friend ostream& operator<<(ostream& out, const DocGia& dg);
};

#endif
