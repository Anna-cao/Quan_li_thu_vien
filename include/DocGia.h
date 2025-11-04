#ifndef DOCGIA_H
#define DOCGIA_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

    virtual bool muonSach(const string& maSach, const Date& ngayHienTai);
    virtual void traSach(const string& maSach);
    virtual void hienThiThongTin() const;
    const vector<string>& getDsMaSachDangMuon() const;

    friend istream& operator>>(istream& in, DocGia& dg);
    friend ostream& operator<<(ostream& out, const DocGia& dg);
    virtual void nhap();
};

#endif
