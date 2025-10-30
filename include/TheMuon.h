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

    friend istream& operator>>(istream& in, TheMuon& tm);
    friend ostream& operator<<(ostream& out, const TheMuon& tm);
};

#endif

