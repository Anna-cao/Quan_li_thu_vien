#include "../include/Date.h"
#include <bits/stdc++.h>

Date::Date(int d, int m, int y) : ngay(d), thang(m), nam(y){}

bool Date::LaNamNhuan(int y) const{
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);    
}
int Date::SoNgayTrongThang(int m, int y) const{
    static int ngayThang[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m == 2 && LaNamNhuan(y)) return 29;
    return ngayThang[m];
}
bool Date::HopLe() const{
    if(nam < 0 || thang < 1 || thang > 12 || ngay < 1) return false;
    return ngay <= SoNgayTrongThang(thang, nam);
}
void Date::Nhap(){
    do{
        cout << "Nhap ngay: " ; cin >> this->ngay;
        cout << "Nhap thang: "; cin >> this->thang;
        cout << "Nhap nam: "; cin >> this->nam;
        if (!HopLe()) cout <<"Ngay khong hop le. Vui long nhap lai!\n";
    } while (!HopLe());
}
void Date::Xuat() const{
    cout << (ngay < 10 ? "0" : "") << this->ngay <<"/"
         << (thang < 10 ? "0" : "") << this->thang <<"/"
         << this->nam;
}
int Date::TinhSoNgayChenhLech(const Date& d) const{
    tm a = {0, 0, 0, this->ngay, this->thang-1, this->nam -1900 };
    tm b = {0, 0, 0, d.ngay, d.thang - 1, d.nam - 1900 };
    time_t x = mktime(&a);
    time_t y = mktime(&b);
    double diff = difftime(y, x) / 86400;
    return static_cast<int>(diff);
}
Date Date::HomNay(){
    time_t now = time(0);
    tm * ltm = localtime(& now);
    return Date(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
}
int Date::getNgay() const {return ngay;}
int Date::getThang() const {return thang;}
int Date::getNam() const {return nam;}

ostream& operator<<(ostream& out, const Date& d){
    out << d.ngay << " " << d.thang << " " << d.nam;
    return out;
}
istream& operator>>(istream& in, Date& d){
    in >> d.ngay >> d.thang >> d.nam;
    return in;
}