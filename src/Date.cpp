#include "../include/Date.h"
#include <bits/stdc++.h>
#include <string>
Date::Date(int d, int m, int y) : ngay(d), thang(m), nam(y){}
bool Date::LaNamNhuan(int y) const{
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));    
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
int Date::TinhSoNgay(const Date& d) const {
    auto toDays = [](int ngay, int thang, int nam) {
        if (thang < 3) { nam--; thang += 12; }
        return 365 * nam + nam / 4 - nam / 100 + nam / 400 + (153 * (thang - 3) + 2) / 5 + ngay;
    };
    return toDays(d.ngay, d.thang, d.nam) - toDays(ngay, thang, nam);
}
void Date::congNgay(int n) {
    if (n == 0) return;
    int maxNgay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && nam % 4 == 0 && (nam % 100 != 0 || nam % 400 == 0)) {
        maxNgay[2] = 29;
    }
    ngay += n;
    while (ngay > maxNgay[thang]) {
        ngay -= maxNgay[thang];
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
            maxNgay[2] = (nam % 4 == 0 && (nam % 100 != 0 || nam % 400 == 0)) ? 29 : 28;
        }
    }
}
Date Date::HomNay(){
    time_t now = time(0);
    tm * ltm = localtime(& now);
    return Date(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
}
ostream& operator<<(ostream& out, const Date& d){
    out << d.ngay << " " << d.thang << " " << d.nam;
    return out;
}
istream& operator>>(istream& in, Date& d){
    in >> d.ngay >> d.thang >> d.nam;
    return in;
}
bool Date::operator>(const Date& other) const {
    if (nam != other.nam) return nam > other.nam;
    if (thang != other.thang) return thang > other.thang;
    return ngay > other.ngay;
}
int Date::operator-(const Date& other) const {
    return -TinhSoNgay(other);  
}
bool Date::operator<(const Date& other) const {
    if (nam != other.nam) return nam < other.nam;
    if (thang != other.thang) return thang < other.thang;
    return ngay < other.ngay;
}
void Date::ghiFile(ostream& out) const {
    out << ngay << " " << thang << " " << nam;
}
void Date::docFile(istream& in) {
    in >> ngay >> thang >> nam;
}
Date Date::NhapTuChuoi(const string& msg) {
    string s;
    int d, m, y;
    while (true) {
        cout << msg;
        getline(cin >> ws, s);
        vector<string> parts;
        string token;
        stringstream ss(s);
        while (getline(ss, token, '/')) {
            parts.push_back(token);
        }
        if (parts.size() != 3) {
            cout << "Phai nhap dung dinh dang: dd/mm/yyyy\n";
            continue;
        }
        try {
            d = stoi(parts[0]);
            m = stoi(parts[1]);
            y = stoi(parts[2]);
        } catch (...) {
            cout << "Phai nhap dung dinh dang: dd/mm/yyyy\n";
            continue;
        }
        if (y < 1900 || y > 2100) {
            cout << "Nam khong hop le! Nhap lai.\n";
            continue;
        }
        Date temp(d, m, y);
        if (temp.HopLe()) {
            return temp;
        }
        cout << "Ngay khong hop le! Nhap lai.\n";
    }
}
void Date::XuatDinhDang() const {
    if (ngay < 10) cout << "0";
    cout << ngay << "/";
    if (thang < 10) cout << "0";
    cout << thang << "/" << nam;
}
Date Date::NhapNgayHopLe(const string& msg) {
    int d, m, y;
    while (true) {
        cout << msg;
        if (cin >> d >> m >> y) {
            Date temp(d, m, y);
            if (temp.HopLe()) {
                cin.ignore(10000, '\n');
                return temp;
            }
        } else {
            cin.clear();
        }
        cin.ignore(10000, '\n');
        cout << "Ngay khong hop le! Nhap lai.\n";
    }
}