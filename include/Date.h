#ifndef DATE_H
#define DATE_H

#include<iostream>
using namespace std;

class Date {
private:
    int ngay, thang, nam;
    
    bool LaNamNhuan(int y) const;
    int SoNgayTrongThang(int m,int y) const;
public:
    explicit Date(int d = 1, int m = 1, int y = 2000);
    
    bool HopLe() const;
    void Nhap();
    void Xuat() const;
    int TinhSoNgayChenhLech(const Date& d) const;
    static Date HomNay();

    int getNgay() const;
    int getThang() const;
    int getNam() const;

    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);

};
#endif